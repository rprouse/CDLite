/////////////////////////////////////////////////////////////////////////////
// CShadeDlg dialog
//
//////////////////////////////////////////////////////////////////////
#ifndef ALTERIDEM_SHADEDLG_H
#define ALTERIDEM_SHADEDLG_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// Including this allows us to get the library version
// and forces the including project to link to the
// library
#ifndef BUILDING_LIBRARY
#include <win/Library.h>
#endif

#ifdef BUILDING_LIBRARY
#include "xShadeButton.h"
#else
#include <win/xShadeButton.h>
#endif

class CShadeDlg : public CDialog
{
public:
    CShadeDlg();
    CShadeDlg(LPCTSTR lpszTemplateName, CWnd* pParentWnd = NULL );
    CShadeDlg(UINT nIDTemplate, CWnd* pParentWnd = NULL );
    virtual ~CShadeDlg();

    // Implementation
    virtual void SetShade(UINT shadeID=0,BYTE granularity=8,BYTE highlight=10,BYTE coloring=0,COLORREF color=0);
    
    DECLARE_DYNAMIC(CShadeDlg)

protected:
    //{{AFX_MSG(CShadeDlg)
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);
    afx_msg void OnPaint();
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()

    CxDib   m_dActive;
    BOOL    m_Border;                           //0=flat; 1=3D;
};

#endif