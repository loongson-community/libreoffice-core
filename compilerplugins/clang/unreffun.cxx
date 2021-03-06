/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <cassert>
#include <string>

#include "clang/AST/Attr.h"
#include "clang/Sema/SemaInternal.h" // warn_unused_function

#include "compat.hxx"
#include "plugin.hxx"

namespace {

// It appears that, given a function declaration, there is no way to determine
// the language linkage of the function's type, only of the function's name
// (via FunctionDecl::isExternC); however, in a case like
//
//   extern "C" { static void f(); }
//
// the function's name does not have C language linkage while the function's
// type does (as clarified in C++11 [decl.link]); cf. <http://clang-developers.
// 42468.n3.nabble.com/Language-linkage-of-function-type-tt4037248.html>
// "Language linkage of function type":
bool hasCLanguageLinkageType(FunctionDecl const * decl) {
    assert(decl != nullptr);
    if (decl->isExternC()) {
        return true;
    }
#if (__clang_major__ == 3 && __clang_minor__ >= 3) || __clang_major__ > 3
    if (decl->isInExternCContext()) {
        return true;
    }
#else
    if (decl->getCanonicalDecl()->getDeclContext()->isExternCContext()) {
        return true;
    }
#endif
    return false;
}

bool isFriendDecl(Decl const * decl) {
    return decl->getFriendObjectKind() != Decl::FOK_None;
}

Decl const * getPreviousNonFriendDecl(Decl const * decl) {
    for (;;) {
        decl = decl->getPreviousDecl();
        if (decl == nullptr || !isFriendDecl(decl)) {
            return decl;
        }
    }
}

class UnrefFun: public RecursiveASTVisitor<UnrefFun>, public loplugin::Plugin {
public:
    explicit UnrefFun(InstantiationData const & data): Plugin(data) {}

    void run() override
    { TraverseDecl(compiler.getASTContext().getTranslationUnitDecl()); }

    bool VisitFunctionDecl(FunctionDecl const * decl);
};

bool UnrefFun::VisitFunctionDecl(FunctionDecl const * decl) {
    if (ignoreLocation(decl)) {
        return true;
    }

    //TODO, filtering out any functions relating to (class) templates for now:
    CXXRecordDecl const * r = dyn_cast<CXXRecordDecl>(decl->getDeclContext());;
    if (r != nullptr
        && (r->getTemplateSpecializationKind() != TSK_Undeclared
            || r->isDependentContext()))
    {
        return true;
    }

    if (!(decl->isThisDeclarationADefinition() || isFriendDecl(decl)
          || decl->isFunctionTemplateSpecialization()))
    {
        Decl const * prev = getPreviousNonFriendDecl(decl);
        if (prev != nullptr/* && prev != decl->getPrimaryTemplate()*/) {
            // Workaround for redeclarations that introduce visiblity attributes
            // (as is done with
            //
            //  SAL_DLLPUBLIC_EXPORT GType lok_doc_view_get_type();
            //
            // in libreofficekit/source/gtk/lokdocview.cxx):
            if (decl->getAttr<VisibilityAttr>() != nullptr
                && prev->getAttr<VisibilityAttr>() == nullptr)
            {
                return true;
            }
            report(
                DiagnosticsEngine::Warning,
                "redundant function%0 redeclaration", decl->getLocation())
                << ((decl->getTemplatedKind()
                     == FunctionDecl::TK_FunctionTemplate)
                    ? " template" : "")
                << decl->getSourceRange();
            report(
                DiagnosticsEngine::Note, "previous declaration is here",
                prev->getLocation())
                << prev->getSourceRange();
            return true;
        }
    }

    FunctionDecl const * canon = decl->getCanonicalDecl();
        //TODO: is that the first?
    if (canon->isDeleted() || canon->isReferenced()
        || !(canon->isDefined()
             ? decl->isThisDeclarationADefinition()
             : compat::isFirstDecl(*decl))
        || !compat::isInMainFile(
            compiler.getSourceManager(), canon->getLocation())
        || isInUnoIncludeFile(
            compiler.getSourceManager().getSpellingLoc(
                canon->getNameInfo().getLoc()))
        || canon->isMain()
        || (decl->getTemplatedKind() == FunctionDecl::TK_FunctionTemplate
            && (decl->getDescribedFunctionTemplate()->spec_begin()
                != decl->getDescribedFunctionTemplate()->spec_end()))
        || (compiler.getDiagnostics().getDiagnosticLevel(
                diag::warn_unused_function, decl->getLocation())
            < DiagnosticsEngine::Warning))
    {
        return true;
    }
    compat::LinkageInfo info(canon->getLinkageAndVisibility());
    if (compat::getLinkage(info) == ExternalLinkage
        && hasCLanguageLinkageType(canon) && canon->isDefined()
        && ((decl == canon && compat::getVisibility(info) == DefaultVisibility)
            || ((canon->hasAttr<ConstructorAttr>()
                 || canon->hasAttr<DestructorAttr>())
                && compat::getVisibility(info) == HiddenVisibility)))
    {
        return true;
    }
    report(
        DiagnosticsEngine::Warning,
        (canon->isDefined()
#if (__clang_major__ == 3 && __clang_minor__ >= 4) || __clang_major__ > 3
         ? (canon->isExternallyVisible()
            ? "Unreferenced externally visible function%0 definition"
            : "Unreferenced externally invisible function%0 definition")
#else
         ? "Unreferenced function%0 definition"
#endif
         : "Unreferenced function%0 declaration"),
        decl->getLocation())
        << (decl->getTemplatedKind() == FunctionDecl::TK_FunctionTemplate
            ? " template" : "")
        << decl->getSourceRange();
    if (canon->isDefined() && !compat::isFirstDecl(*decl)) {
        report(
            DiagnosticsEngine::Note, "first declaration is here",
            canon->getLocation())
            << canon->getSourceRange();
    }
    return true;
}

loplugin::Plugin::Registration<UnrefFun> X("unreffun");

}

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
