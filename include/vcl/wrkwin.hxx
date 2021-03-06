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

#ifndef INCLUDED_VCL_WRKWIN_HXX
#define INCLUDED_VCL_WRKWIN_HXX

#include <tools/solar.h>
#include <vcl/dllapi.h>
#include <vcl/syswin.hxx>
#include <o3tl/typed_flags_set.hxx>

namespace com { namespace sun { namespace star { namespace uno { class Any; }}}}
struct SystemParentData;


// - WorkWindow - Types -


// Presentation Flags
enum class PresentationFlags
{
    NONE           = 0x0000,
    HideAllApps    = 0x0001,
    NoFullScreen   = 0x0002,
    NoAutoShow     = 0x0004,
};
namespace o3tl
{
    template<> struct typed_flags<PresentationFlags> : is_typed_flags<PresentationFlags, 0x0007> {};
}


// - WorkWindow -


class VCL_DLLPUBLIC WorkWindow : public SystemWindow
{
private:
    PresentationFlags mnPresentationFlags;
    bool              mbPresentationMode:1,
                      mbPresentationVisible:1,
                      mbPresentationFull:1,
                      mbFullScreenMode:1;

    SAL_DLLPRIVATE void ImplInitWorkWindowData();
    SAL_DLLPRIVATE void ImplInit( vcl::Window* pParent, WinBits nStyle, const ::com::sun::star::uno::Any& aSystemWorkWindowToken );

private:
    WorkWindow( const WorkWindow& rWin ) SAL_DELETED_FUNCTION;
    WorkWindow&  operator =( const WorkWindow& rWin ) SAL_DELETED_FUNCTION;

protected:
    explicit        WorkWindow( WindowType nType );
    SAL_DLLPRIVATE void ImplInit( vcl::Window* pParent, WinBits nStyle, SystemParentData* pSystemParentData = NULL );
    SAL_DLLPRIVATE void ImplSetFrameState( sal_uLong aFrameState );

public:
    explicit        WorkWindow( vcl::Window* pParent, WinBits nStyle = WB_STDWORK );
    explicit        WorkWindow( vcl::Window* pParent, const ::com::sun::star::uno::Any& aSystemWorkWindowToken, WinBits nStyle = WB_STDWORK );
    explicit        WorkWindow( SystemParentData* pParent ); // Not in the REMOTE-Version
    virtual         ~WorkWindow();
    virtual void    dispose() SAL_OVERRIDE;

    virtual bool    Close() SAL_OVERRIDE;

    void            ShowFullScreenMode( bool bFullScreenMode,
                                        sal_Int32 nDisplayScreen );
    /**
     @overload void ShowFullScreenMode(bool bFullScreenMode, sal_Int32 nDisplayScreen)
    */
    void            ShowFullScreenMode( bool bFullScreenMode = true );
    void            EndFullScreenMode() { ShowFullScreenMode( false ); }
    bool            IsFullScreenMode() const { return mbFullScreenMode; }

    void            StartPresentationMode( bool   bPresentation,
                                           PresentationFlags nFlags,
                                           sal_Int32  nDisplayScreen );
    /**
     @overload void StartPresentationMode( bool bPresentation, sal_uInt16 nFlags, sal_uInt32 nDisplayScreen)
    */
    void            StartPresentationMode( bool   bPresentation = true,
                                           PresentationFlags nFlags = PresentationFlags::NONE );
    bool            IsPresentationMode() const { return mbPresentationMode; }

    bool            IsMinimized() const;

    bool            SetPluginParent( SystemParentData* pParent );

    void            Minimize();
    void            Restore();

    void            Maximize( bool bMaximize = true );
    bool            IsMaximized() const;
};

#endif // INCLUDED_VCL_WRKWIN_HXX

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
