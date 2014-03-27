#ifndef ALTERIDEM_SKINDLG_H
#define ALTERIDEM_SKINDLG_H

#include "SkinStatic.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SkinDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSkinDlg dialog

class CSkinDlg : public CDialog
{
    // Construction
public:
    const CString & GetSelectedSkin();
    CSkinDlg( const CString & skin, CWnd* pParent = NULL );   // standard constructor

    // Dialog Data
    //{{AFX_DATA(CSkinDlg)
    enum { IDD = IDD_SKIN };
    CButton    m_ok;
    CButton    m_cancel;
    CSkinStatic    m_skinCtrl;
    CListBox    m_skinList;
    //}}AFX_DATA


    // Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CSkinDlg)
protected:
    virtual void DoDataExchange( CDataExchange* pDX );    // DDX/DDV support
    //}}AFX_VIRTUAL

    // Implementation
protected:
    CString m_skin;

    // Generated message map functions
    //{{AFX_MSG(CSkinDlg)
    virtual BOOL OnInitDialog();
    virtual void OnCancel();
    virtual void OnOK();
    afx_msg void OnSelchangeSkinList();
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif
