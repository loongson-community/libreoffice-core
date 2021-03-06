/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * This file incorporates work covered by the following license notice:
 *
 *   Licensed to the Apache Software Foundation (ASF) under one or more
 *   contributor license agreements. See the NOTICE file distributed
 *   with this work for additional information regarding copyright
 *   ownership. The ASF licenses this file to you under the Apache
 *   License, Version 2.0 (the "License"); you may not use this file
 *   except in compliance with the License. You may obtain a copy of
 *   the License at http://www.apache.org/licenses/LICENSE-2.0 .
 */

#ifndef INCLUDED_LINGUISTIC_SOURCE_LNGOPT_HXX
#define INCLUDED_LINGUISTIC_SOURCE_LNGOPT_HXX

#include <cppuhelper/implbase5.hxx>
#include <cppuhelper/interfacecontainer.hxx>
#include <com/sun/star/beans/XPropertySet.hpp>
#include <com/sun/star/beans/XFastPropertySet.hpp>
#include <com/sun/star/beans/XPropertyAccess.hpp>
#include <com/sun/star/lang/XServiceInfo.hpp>
#include <com/sun/star/lang/XComponent.hpp>
#include <com/sun/star/linguistic2/XLinguProperties.hpp>
#include <unotools/lingucfg.hxx>
#include <svl/itemprop.hxx>
#include <unotools/configitem.hxx>
#include <unotools/linguprops.hxx>
#include <com/sun/star/uno/Any.h>
#include "linguistic/misc.hxx"
#include "defs.hxx"

namespace com { namespace sun { namespace star {
    namespace beans {
        struct PropertyChangeEvent;
    }
}}}



// LinguOptions
// This class represents all Linguistik relevant options.

class LinguOptions
{
    static SvtLinguOptions     *pData;
    static oslInterlockedCount  nRefCount;  // number of objects of this class

public:
    LinguOptions();
    LinguOptions(const LinguOptions &rOpt);
    ~LinguOptions();

    static OUString    GetName( sal_Int32 nWID );

    const ::com::sun::star::uno::Sequence< OUString >
            GetActiveDics() const   { return pData->aActiveDics; }

    const ::com::sun::star::uno::Sequence< OUString >
            GetActiveConvDics() const   { return pData->aActiveConvDics; }
};

typedef cppu::OMultiTypeInterfaceContainerHelperVar<sal_Int32>
    OPropertyListenerContainerHelper;

class LinguProps :
    public cppu::WeakImplHelper5
    <
        com::sun::star::linguistic2::XLinguProperties,
        com::sun::star::beans::XFastPropertySet,
        com::sun::star::beans::XPropertyAccess,
        com::sun::star::lang::XComponent,
        com::sun::star::lang::XServiceInfo
    >
{
    ::cppu::OInterfaceContainerHelper           aEvtListeners;
    OPropertyListenerContainerHelper            aPropListeners;

    SfxItemPropertyMap                          aPropertyMap;
    SvtLinguConfig                              aConfig;

    bool                                        bDisposing;

    LinguProps(const LinguProps &) SAL_DELETED_FUNCTION;
    LinguProps & operator = (const LinguProps &) SAL_DELETED_FUNCTION;

    void    launchEvent( const ::com::sun::star::beans::PropertyChangeEvent &rEvt ) const;

    bool getPropertyBool(const OUString& aPropertyName) throw (css::uno::RuntimeException);
    sal_Int16 getPropertyInt16(const OUString& aPropertyName) throw (css::uno::RuntimeException);
    css::lang::Locale getPropertyLocale(const OUString& aPropertyName) throw (css::uno::RuntimeException);
    void setProperty(const OUString& aPropertyName, bool p1) throw (css::uno::RuntimeException)
        { setPropertyValue( aPropertyName, css::uno::Any(p1) ); }
    void setProperty(const OUString& aPropertyName, sal_Int16 p1) throw (css::uno::RuntimeException)
        { setPropertyValue( aPropertyName, css::uno::Any(p1) ); }
    void setProperty(const OUString& aPropertyName, css::lang::Locale p1) throw (css::uno::RuntimeException)
        { setPropertyValue( aPropertyName, css::uno::Any(p1) ); }

public:
    LinguProps();

    virtual sal_Bool SAL_CALL getIsUseDictionaryList() throw (css::uno::RuntimeException, std::exception) SAL_OVERRIDE
        { return getPropertyBool(UPN_IS_USE_DICTIONARY_LIST); }
    virtual void SAL_CALL setIsUseDictionaryList(sal_Bool p1) throw (css::uno::RuntimeException, std::exception) SAL_OVERRIDE
        { setProperty(UPN_IS_USE_DICTIONARY_LIST, (bool) p1); }
    virtual sal_Bool SAL_CALL getIsIgnoreControlCharacters() throw (css::uno::RuntimeException, std::exception) SAL_OVERRIDE
        { return getPropertyBool(UPN_IS_IGNORE_CONTROL_CHARACTERS); }
    virtual void SAL_CALL setIsIgnoreControlCharacters(sal_Bool p1) throw (css::uno::RuntimeException, std::exception) SAL_OVERRIDE
        { setProperty(UPN_IS_IGNORE_CONTROL_CHARACTERS, (bool) p1); }
    virtual sal_Bool SAL_CALL getIsSpellUpperCase() throw (css::uno::RuntimeException, std::exception) SAL_OVERRIDE
        { return getPropertyBool(UPN_IS_SPELL_UPPER_CASE); }
    virtual void SAL_CALL setIsSpellUpperCase(sal_Bool p1) throw (css::uno::RuntimeException, std::exception) SAL_OVERRIDE
        { setProperty(UPN_IS_SPELL_UPPER_CASE, (bool) p1); }
    virtual sal_Bool SAL_CALL getIsSpellWithDigits() throw (css::uno::RuntimeException, std::exception) SAL_OVERRIDE
        { return getPropertyBool(UPN_IS_SPELL_WITH_DIGITS); }
    virtual void SAL_CALL setIsSpellWithDigits(sal_Bool p1) throw (css::uno::RuntimeException, std::exception) SAL_OVERRIDE
        { setProperty(UPN_IS_SPELL_WITH_DIGITS, (bool) p1); }
    virtual sal_Bool SAL_CALL getIsSpellCapitalization() throw (css::uno::RuntimeException, std::exception) SAL_OVERRIDE
        { return getPropertyBool(UPN_IS_SPELL_CAPITALIZATION); }
    virtual void SAL_CALL setIsSpellCapitalization(sal_Bool p1) throw (css::uno::RuntimeException, std::exception) SAL_OVERRIDE
        { setProperty(UPN_IS_SPELL_CAPITALIZATION, (bool) p1); }
    virtual sal_Int16 SAL_CALL getHyphMinLeading() throw (css::uno::RuntimeException, std::exception) SAL_OVERRIDE
        { return getPropertyInt16(UPN_HYPH_MIN_LEADING); }
    virtual void SAL_CALL setHyphMinLeading(sal_Int16 p1) throw (css::uno::RuntimeException, std::exception) SAL_OVERRIDE
        { setProperty(UPN_HYPH_MIN_LEADING, p1); }
    virtual sal_Int16 SAL_CALL getHyphMinTrailing() throw (css::uno::RuntimeException, std::exception) SAL_OVERRIDE
        { return getPropertyInt16(UPN_HYPH_MIN_TRAILING); }
    virtual void SAL_CALL setHyphMinTrailing(sal_Int16 p1) throw (css::uno::RuntimeException, std::exception) SAL_OVERRIDE
        { setProperty(UPN_HYPH_MIN_TRAILING, p1); }
    virtual sal_Int16 SAL_CALL getHyphMinWordLength() throw (css::uno::RuntimeException, std::exception) SAL_OVERRIDE
        { return getPropertyInt16(UPN_HYPH_MIN_WORD_LENGTH); }
    virtual void SAL_CALL setHyphMinWordLength(sal_Int16 p1) throw (css::uno::RuntimeException, std::exception) SAL_OVERRIDE
        { setProperty(UPN_HYPH_MIN_WORD_LENGTH, p1); }
    virtual com::sun::star::lang::Locale SAL_CALL getDefaultLocale() throw (css::uno::RuntimeException, std::exception) SAL_OVERRIDE
        { return getPropertyLocale(UPN_DEFAULT_LOCALE); }
    virtual void SAL_CALL setDefaultLocale(const com::sun::star::lang::Locale& p1) throw (css::uno::RuntimeException, std::exception) SAL_OVERRIDE
        { setProperty(UPN_DEFAULT_LOCALE, p1); }
    virtual sal_Bool SAL_CALL getIsHyphAuto() throw (css::uno::RuntimeException, std::exception) SAL_OVERRIDE
        { return getPropertyBool(UPN_IS_HYPH_AUTO); }
    virtual void SAL_CALL setIsHyphAuto(sal_Bool p1) throw (css::uno::RuntimeException, std::exception) SAL_OVERRIDE
        { setProperty(UPN_IS_HYPH_AUTO, (bool) p1); }
    virtual sal_Bool SAL_CALL getIsHyphSpecial() throw (css::uno::RuntimeException, std::exception) SAL_OVERRIDE
        { return getPropertyBool(UPN_IS_HYPH_SPECIAL); }
    virtual void SAL_CALL setIsHyphSpecial(sal_Bool p1) throw (css::uno::RuntimeException, std::exception) SAL_OVERRIDE
        { setProperty(UPN_IS_HYPH_SPECIAL, (bool) p1); }
    virtual sal_Bool SAL_CALL getIsSpellAuto() throw (css::uno::RuntimeException, std::exception) SAL_OVERRIDE
        { return getPropertyBool(UPN_IS_SPELL_AUTO); }
    virtual void SAL_CALL setIsSpellAuto(sal_Bool p1) throw (css::uno::RuntimeException, std::exception) SAL_OVERRIDE
        { setProperty(UPN_IS_SPELL_AUTO, (bool) p1); }
    virtual sal_Bool SAL_CALL getIsSpellSpecial() throw (css::uno::RuntimeException, std::exception) SAL_OVERRIDE
        { return getPropertyBool(UPN_IS_SPELL_SPECIAL); }
    virtual void SAL_CALL setIsSpellSpecial(sal_Bool p1) throw (css::uno::RuntimeException, std::exception) SAL_OVERRIDE
        { setProperty(UPN_IS_SPELL_SPECIAL, (bool) p1); }
    virtual sal_Bool SAL_CALL getIsWrapReverse() throw (css::uno::RuntimeException, std::exception) SAL_OVERRIDE
        { return getPropertyBool(UPN_IS_WRAP_REVERSE); }
    virtual void SAL_CALL setIsWrapReverse(sal_Bool p1) throw (css::uno::RuntimeException, std::exception) SAL_OVERRIDE
        { setProperty(UPN_IS_WRAP_REVERSE, (bool) p1); }
    virtual com::sun::star::lang::Locale SAL_CALL getDefaultLocale_CJK() throw (css::uno::RuntimeException, std::exception) SAL_OVERRIDE
        { return getPropertyLocale(UPN_DEFAULT_LOCALE_CJK); }
    virtual void SAL_CALL setDefaultLocale_CJK(const com::sun::star::lang::Locale& p1) throw (css::uno::RuntimeException, std::exception) SAL_OVERRIDE
        { setProperty(UPN_DEFAULT_LOCALE_CJK, p1); }
    virtual css::lang::Locale SAL_CALL getDefaultLocale_CTL() throw (css::uno::RuntimeException, std::exception) SAL_OVERRIDE
        { return getPropertyLocale(UPN_DEFAULT_LOCALE_CTL); }
    virtual void SAL_CALL setDefaultLocale_CTL(const com::sun::star::lang::Locale& p1) throw (css::uno::RuntimeException, std::exception) SAL_OVERRIDE
        { setProperty(UPN_DEFAULT_LOCALE_CTL, p1); }

    // XPropertySet
    virtual ::com::sun::star::uno::Reference< ::com::sun::star::beans::XPropertySetInfo > SAL_CALL getPropertySetInfo() throw(::com::sun::star::uno::RuntimeException, std::exception) SAL_OVERRIDE;
    virtual void SAL_CALL setPropertyValue( const OUString& aPropertyName, const ::com::sun::star::uno::Any& aValue ) throw(::com::sun::star::beans::UnknownPropertyException, ::com::sun::star::beans::PropertyVetoException, ::com::sun::star::lang::IllegalArgumentException, ::com::sun::star::lang::WrappedTargetException, ::com::sun::star::uno::RuntimeException, std::exception) SAL_OVERRIDE;
    virtual ::com::sun::star::uno::Any SAL_CALL getPropertyValue( const OUString& PropertyName ) throw(::com::sun::star::beans::UnknownPropertyException, ::com::sun::star::lang::WrappedTargetException, ::com::sun::star::uno::RuntimeException, std::exception) SAL_OVERRIDE;
    virtual void SAL_CALL addPropertyChangeListener( const OUString& aPropertyName, const ::com::sun::star::uno::Reference< ::com::sun::star::beans::XPropertyChangeListener >& rxListener ) throw(::com::sun::star::beans::UnknownPropertyException, ::com::sun::star::lang::WrappedTargetException, ::com::sun::star::uno::RuntimeException, std::exception) SAL_OVERRIDE;
    virtual void SAL_CALL removePropertyChangeListener( const OUString& aPropertyName, const ::com::sun::star::uno::Reference< ::com::sun::star::beans::XPropertyChangeListener >& rxListener ) throw(::com::sun::star::beans::UnknownPropertyException, ::com::sun::star::lang::WrappedTargetException, ::com::sun::star::uno::RuntimeException, std::exception) SAL_OVERRIDE;
    virtual void SAL_CALL addVetoableChangeListener( const OUString& PropertyName, const ::com::sun::star::uno::Reference< ::com::sun::star::beans::XVetoableChangeListener >& rxListener ) throw(::com::sun::star::beans::UnknownPropertyException, ::com::sun::star::lang::WrappedTargetException, ::com::sun::star::uno::RuntimeException, std::exception) SAL_OVERRIDE;
    virtual void SAL_CALL removeVetoableChangeListener( const OUString& PropertyName, const ::com::sun::star::uno::Reference< ::com::sun::star::beans::XVetoableChangeListener >& rxListener ) throw(::com::sun::star::beans::UnknownPropertyException, ::com::sun::star::lang::WrappedTargetException, ::com::sun::star::uno::RuntimeException, std::exception) SAL_OVERRIDE;

    // XFastPropertySet
    virtual void SAL_CALL setFastPropertyValue( sal_Int32 nHandle, const ::com::sun::star::uno::Any& aValue ) throw(::com::sun::star::beans::UnknownPropertyException, ::com::sun::star::beans::PropertyVetoException, ::com::sun::star::lang::IllegalArgumentException, ::com::sun::star::lang::WrappedTargetException, ::com::sun::star::uno::RuntimeException, std::exception) SAL_OVERRIDE;
    virtual ::com::sun::star::uno::Any SAL_CALL getFastPropertyValue( sal_Int32 nHandle ) throw(::com::sun::star::beans::UnknownPropertyException, ::com::sun::star::lang::WrappedTargetException, ::com::sun::star::uno::RuntimeException, std::exception) SAL_OVERRIDE;

    // XPropertyAccess
    virtual ::com::sun::star::uno::Sequence< ::com::sun::star::beans::PropertyValue > SAL_CALL getPropertyValues() throw(::com::sun::star::uno::RuntimeException, std::exception) SAL_OVERRIDE;
    virtual void SAL_CALL setPropertyValues( const ::com::sun::star::uno::Sequence< ::com::sun::star::beans::PropertyValue >& aProps ) throw(::com::sun::star::beans::UnknownPropertyException, ::com::sun::star::beans::PropertyVetoException, ::com::sun::star::lang::IllegalArgumentException, ::com::sun::star::lang::WrappedTargetException, ::com::sun::star::uno::RuntimeException, std::exception) SAL_OVERRIDE;

    // XComponent
    virtual void SAL_CALL dispose() throw(::com::sun::star::uno::RuntimeException, std::exception) SAL_OVERRIDE;
    virtual void SAL_CALL addEventListener( const ::com::sun::star::uno::Reference< ::com::sun::star::lang::XEventListener >& rxListener ) throw(::com::sun::star::uno::RuntimeException, std::exception) SAL_OVERRIDE;
    virtual void SAL_CALL removeEventListener( const ::com::sun::star::uno::Reference< ::com::sun::star::lang::XEventListener >& rxListener ) throw(::com::sun::star::uno::RuntimeException, std::exception) SAL_OVERRIDE;

    // XServiceInfo
    virtual OUString SAL_CALL getImplementationName() throw(::com::sun::star::uno::RuntimeException, std::exception) SAL_OVERRIDE;
    virtual sal_Bool SAL_CALL supportsService( const OUString& ServiceName ) throw(::com::sun::star::uno::RuntimeException, std::exception) SAL_OVERRIDE;
    virtual ::com::sun::star::uno::Sequence< OUString > SAL_CALL getSupportedServiceNames() throw(::com::sun::star::uno::RuntimeException, std::exception) SAL_OVERRIDE;


    static inline OUString getImplementationName_Static() throw();
    static com::sun::star::uno::Sequence< OUString > getSupportedServiceNames_Static() throw();
};

inline OUString LinguProps::getImplementationName_Static() throw()
{
    return OUString( "com.sun.star.lingu2.LinguProps" );
}


#endif

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
