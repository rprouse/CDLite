// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#ifndef ALTERIDEM_CDLITE_STDAFX_H
#define ALTERIDEM_CDLITE_STDAFX_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN			// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>			// MFC core and standard components
#include <afxext.h>			// MFC extensions
#include <afxdisp.h>			// MFC Automation classes
#include <afxdtctl.h>			// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <mmsystem.h>
#include <dbt.h>

#include <win/Bmp.h>
#include <win/BmpDlg.h>
#include <win/HoverButton.h>
#include <win/FileInfo.h>
#include <win/Registry.h>
#include <win/System.h>

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif
