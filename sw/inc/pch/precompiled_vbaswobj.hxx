/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

/*
 This file has been autogenerated by update_pch.sh . It is possible to edit it
 manually (such as when an include file has been moved/renamed/removed. All such
 manual changes will be rewritten by the next run of update_pch.sh (which presumably
 also fixes all possible problems, so it's usually better to use it).
*/

#include <basic/sbuno.hxx>
#include <boost/shared_ptr.hpp>
#include <com/sun/star/awt/FontUnderline.hpp>
#include <com/sun/star/beans/NamedValue.hpp>
#include <com/sun/star/beans/PropertyAttribute.hpp>
#include <com/sun/star/beans/PropertyValue.hpp>
#include <com/sun/star/beans/PropertyVetoException.hpp>
#include <com/sun/star/beans/XPropertyContainer.hpp>
#include <com/sun/star/beans/XPropertySet.hpp>
#include <com/sun/star/container/XEnumeration.hpp>
#include <com/sun/star/container/XEnumerationAccess.hpp>
#include <com/sun/star/container/XIndexAccess.hpp>
#include <com/sun/star/container/XIndexReplace.hpp>
#include <com/sun/star/container/XNameAccess.hpp>
#include <com/sun/star/container/XNameContainer.hpp>
#include <com/sun/star/container/XNamed.hpp>
#include <com/sun/star/document/XDocumentProperties.hpp>
#include <com/sun/star/document/XDocumentPropertiesSupplier.hpp>
#include <com/sun/star/document/XRedlinesSupplier.hpp>
#include <com/sun/star/document/XTypeDetection.hpp>
#include <com/sun/star/drawing/ShapeCollection.hpp>
#include <com/sun/star/drawing/XControlShape.hpp>
#include <com/sun/star/drawing/XDrawPage.hpp>
#include <com/sun/star/drawing/XDrawPageSupplier.hpp>
#include <com/sun/star/form/XFormsSupplier.hpp>
#include <com/sun/star/frame/FrameSearchFlag.hpp>
#include <com/sun/star/frame/XComponentLoader.hpp>
#include <com/sun/star/frame/XController.hpp>
#include <com/sun/star/frame/XDesktop.hpp>
#include <com/sun/star/frame/XFrame.hpp>
#include <com/sun/star/frame/XModel.hpp>
#include <com/sun/star/frame/XStorable.hpp>
#include <com/sun/star/lang/DisposedException.hpp>
#include <com/sun/star/lang/IllegalArgumentException.hpp>
#include <com/sun/star/lang/IndexOutOfBoundsException.hpp>
#include <com/sun/star/lang/Locale.hpp>
#include <com/sun/star/lang/XComponent.hpp>
#include <com/sun/star/lang/XMultiComponentFactory.hpp>
#include <com/sun/star/lang/XServiceInfo.hpp>
#include <com/sun/star/lang/XUnoTunnel.hpp>
#include <com/sun/star/script/ModuleType.hpp>
#include <com/sun/star/script/vba/VBAEventId.hpp>
#include <com/sun/star/style/BreakType.hpp>
#include <com/sun/star/style/LineSpacingMode.hpp>
#include <com/sun/star/style/NumberingType.hpp>
#include <com/sun/star/style/ParagraphAdjust.hpp>
#include <com/sun/star/style/TabAlign.hpp>
#include <com/sun/star/style/XStyle.hpp>
#include <com/sun/star/style/XStyleFamiliesSupplier.hpp>
#include <com/sun/star/table/ShadowFormat.hpp>
#include <com/sun/star/table/ShadowLocation.hpp>
#include <com/sun/star/table/TableBorder.hpp>
#include <com/sun/star/table/XCell.hpp>
#include <com/sun/star/table/XCellRange.hpp>
#include <com/sun/star/table/XTableRows.hpp>
#include <com/sun/star/text/AutoTextContainer.hpp>
#include <com/sun/star/text/ControlCharacter.hpp>
#include <com/sun/star/text/FilenameDisplayFormat.hpp>
#include <com/sun/star/text/HoriOrientation.hpp>
#include <com/sun/star/text/WrapTextMode.hpp>
#include <com/sun/star/text/XBookmarksSupplier.hpp>
#include <com/sun/star/text/XDocumentIndexesSupplier.hpp>
#include <com/sun/star/text/XEndnotesSupplier.hpp>
#include <com/sun/star/text/XFootnotesSupplier.hpp>
#include <com/sun/star/text/XPageCursor.hpp>
#include <com/sun/star/text/XParagraphCursor.hpp>
#include <com/sun/star/text/XText.hpp>
#include <com/sun/star/text/XTextContent.hpp>
#include <com/sun/star/text/XTextDocument.hpp>
#include <com/sun/star/text/XTextFieldsSupplier.hpp>
#include <com/sun/star/text/XTextRange.hpp>
#include <com/sun/star/text/XTextRangeCompare.hpp>
#include <com/sun/star/text/XTextTable.hpp>
#include <com/sun/star/text/XTextTableCursor.hpp>
#include <com/sun/star/text/XTextTablesSupplier.hpp>
#include <com/sun/star/text/XTextViewCursor.hpp>
#include <com/sun/star/text/XTextViewCursorSupplier.hpp>
#include <com/sun/star/text/XWordCursor.hpp>
#include <com/sun/star/ucb/SimpleFileAccess.hpp>
#include <com/sun/star/uri/XUriReference.hpp>
#include <com/sun/star/uri/XUriReferenceFactory.hpp>
#include <com/sun/star/util/XCloseable.hpp>
#include <com/sun/star/util/XModifiable.hpp>
#include <com/sun/star/util/XRefreshable.hpp>
#include <com/sun/star/util/XStringSubstitution.hpp>
#include <com/sun/star/util/XUpdatable.hpp>
#include <com/sun/star/util/thePathSettings.hpp>
#include <com/sun/star/view/XLineCursor.hpp>
#include <com/sun/star/view/XSelectionSupplier.hpp>
#include <com/sun/star/view/XViewCursor.hpp>
#include <com/sun/star/view/XViewSettingsSupplier.hpp>
#include <comphelper/processfactory.hxx>
#include <comphelper/string.hxx>
#include <comphelper/unwrapargs.hxx>
#include <cppuhelper/bootstrap.hxx>
#include <cppuhelper/implbase1.hxx>
#include <cppuhelper/implbase2.hxx>
#include <cppuhelper/implbase3.hxx>
#include <cppuhelper/implementationentry.hxx>
#include <editeng/acorrcfg.hxx>
#include <i18nlangtag/languagetag.hxx>
#include <ooo/vba/XControlProvider.hpp>
#include <ooo/vba/office/MsoDocProperties.hpp>
#include <ooo/vba/word/WdBookmarkSortBy.hpp>
#include <ooo/vba/word/WdBorderType.hpp>
#include <ooo/vba/word/WdBreakType.hpp>
#include <ooo/vba/word/WdBuiltInProperty.hpp>
#include <ooo/vba/word/WdBuiltinStyle.hpp>
#include <ooo/vba/word/WdCollapseDirection.hpp>
#include <ooo/vba/word/WdColor.hpp>
#include <ooo/vba/word/WdColorIndex.hpp>
#include <ooo/vba/word/WdConstants.hpp>
#include <ooo/vba/word/WdCursorType.hpp>
#include <ooo/vba/word/WdDefaultFilePath.hpp>
#include <ooo/vba/word/WdDefaultListBehavior.hpp>
#include <ooo/vba/word/WdEnableCancelKey.hpp>
#include <ooo/vba/word/WdFieldType.hpp>
#include <ooo/vba/word/WdFindWrap.hpp>
#include <ooo/vba/word/WdGoToDirection.hpp>
#include <ooo/vba/word/WdGoToItem.hpp>
#include <ooo/vba/word/WdHeaderFooterIndex.hpp>
#include <ooo/vba/word/WdInformation.hpp>
#include <ooo/vba/word/WdLineSpacing.hpp>
#include <ooo/vba/word/WdLineStyle.hpp>
#include <ooo/vba/word/WdLineWidth.hpp>
#include <ooo/vba/word/WdListApplyTo.hpp>
#include <ooo/vba/word/WdListGalleryType.hpp>
#include <ooo/vba/word/WdListLevelAlignment.hpp>
#include <ooo/vba/word/WdListNumberStyle.hpp>
#include <ooo/vba/word/WdMovementType.hpp>
#include <ooo/vba/word/WdOrientation.hpp>
#include <ooo/vba/word/WdOutlineLevel.hpp>
#include <ooo/vba/word/WdParagraphAlignment.hpp>
#include <ooo/vba/word/WdProtectionType.hpp>
#include <ooo/vba/word/WdReplace.hpp>
#include <ooo/vba/word/WdRowAlignment.hpp>
#include <ooo/vba/word/WdRowHeightRule.hpp>
#include <ooo/vba/word/WdRulerStyle.hpp>
#include <ooo/vba/word/WdSectionStart.hpp>
#include <ooo/vba/word/WdSeekView.hpp>
#include <ooo/vba/word/WdSpecialPane.hpp>
#include <ooo/vba/word/WdStyleType.hpp>
#include <ooo/vba/word/WdTabAlignment.hpp>
#include <ooo/vba/word/WdTabLeader.hpp>
#include <ooo/vba/word/WdTrailingCharacter.hpp>
#include <ooo/vba/word/WdUnderline.hpp>
#include <ooo/vba/word/WdUnits.hpp>
#include <ooo/vba/word/WdViewType.hpp>
#include <ooo/vba/word/WdWindowState.hpp>
#include <ooo/vba/word/WdWordDialog.hpp>
#include <ooo/vba/word/WdWrapSideType.hpp>
#include <ooo/vba/word/WdWrapType.hpp>
#include <ooo/vba/word/XApplication.hpp>
#include <ooo/vba/word/XBookmark.hpp>
#include <ooo/vba/word/XBorder.hpp>
#include <ooo/vba/word/XDialog.hpp>
#include <osl/diagnose.h>
#include <osl/file.hxx>
#include <rtl/ustrbuf.hxx>
#include <sal/macros.h>
#include <sfx2/objsh.hxx>
#include <stdio.h>
#include <tools/config.hxx>
#include <tools/diagnose_ex.h>
#include <tools/urlobj.hxx>
#include <unordered_map>
#include <unotools/pathoptions.hxx>
#include <vbahelper/helperdecl.hxx>
#include <vbahelper/vbahelper.hxx>
#include <vbahelper/vbashaperange.hxx>
#include <vbahelper/vbashapes.hxx>
#include <vcl/wrkwin.hxx>

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
