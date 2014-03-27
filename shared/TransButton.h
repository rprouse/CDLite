////////////////////////////////////////////////////////////////////////////////
//  TransButton.h : header file
////////////////////////////////////////////////////////////////////////////////
#ifndef ALTERIDEM_TRANSBUTTON_H
#define ALTERIDEM_TRANSBUTTON_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// Including this allows us to get the library version
// and forces the including project to link to the
// library
#ifndef BUILDING_LIBRARY
#include <Library.h>
#endif

/// Standard button, except the background is transparent.
class CTransButton : public CButton
{
public:
    CTransButton();
    virtual ~CTransButton();

    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CTransButton)
    public:
    virtual void SetWindowText(LPCTSTR lpszString);
    //}}AFX_VIRTUAL  

protected:
    //{{AFX_MSG(CTransButton)
    afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
    //}}AFX_MSG
    
    DECLARE_MESSAGE_MAP()
};

#endif
