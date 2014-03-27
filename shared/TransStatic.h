////////////////////////////////////////////////////////////////////////////////
//  TransStatic.h : header file
////////////////////////////////////////////////////////////////////////////////
#ifndef ALTERIDEM_TRANSSTATIC_H
#define ALTERIDEM_TRANSSTATIC_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// Including this allows us to get the library version
// and forces the including project to link to the
// library
#ifndef BUILDING_LIBRARY
#include <win/Library.h>
#endif

/// Standard static component, except the background is transparent.
class CTransStatic : public CStatic
{
public:
    CTransStatic(); 
    virtual ~CTransStatic();

    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CTransStatic)
    public:
    virtual void SetWindowText(LPCTSTR lpszString);
    //}}AFX_VIRTUAL

protected:
    //{{AFX_MSG(CTransStatic)
    afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
    //}}AFX_MSG
    
    DECLARE_MESSAGE_MAP()
};

#endif 
