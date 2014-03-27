#ifndef ALTERIDEM_SKINSTATIC_H
#define ALTERIDEM_SKINSTATIC_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SkinStatic.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSkinStatic window

class CSkinStatic : public CStatic
{
    // Construction
public:
    CSkinStatic();
    
    // Attributes
public:
    
    // Operations
public:
    void SetBmp(const char * skinname);
    
    // Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CSkinStatic)
    //}}AFX_VIRTUAL
    
    // Implementation
public:
    virtual ~CSkinStatic();

private:
    CBmp m_skin;
    
    // Generated message map functions
protected:
    //{{AFX_MSG(CSkinStatic)
    afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
    afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
    
    DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif 
