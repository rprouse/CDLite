#ifndef ALTERIDEM_BNSTATIC_H
#define ALTERIDEM_BNSTATIC_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// BNStatic.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBmpNumberStatic window

class CBmpNumberStatic : public CStatic
{
    // Construction
public:
    CBmpNumberStatic();
    
    // Attributes
public:
    
    // Operations
public:
    void SetWindowText(LPCTSTR lpszString);
    bool SetBmp(const CBmp & bmp);
    
    // Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CBmpNumberStatic)
    //}}AFX_VIRTUAL
    
    // Implementation
public:
    virtual ~CBmpNumberStatic();
    
protected:
    CBmpStrip m_digits[12];

    // Generated message map functions
protected:
    //{{AFX_MSG(CBmpNumberStatic)
    afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
    afx_msg void OnPaint();
    //}}AFX_MSG
    
    DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif
