// CDLiteDlg.h : header file
//
#ifndef ALTERIDEM_CDLITEDLG_H
#define ALTERIDEM_CDLITEDLG_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CDPlayer.h"
#include "BNStatic.h"

/////////////////////////////////////////////////////////////////////////////
// CCDLiteDlg dialog

class CCDLiteDlg : public CBmpDlg
{
    // Construction
public:
    CCDLiteDlg(CWnd* pParent = NULL);	// standard constructor
    virtual ~CCDLiteDlg();
    
    // Dialog Data
    //{{AFX_DATA(CCDLiteDlg)
    enum { IDD = IDD_CDLITE_DIALOG };
    CBmpNumberStatic	m_track;
    CBmpNumberStatic	m_time;
    CHoverButton	m_system;
    CHoverButton	m_stop;
    CHoverButton	m_previous;
    CHoverButton	m_play;
    CHoverButton	m_pause;
    CHoverButton	m_next;
    CHoverButton	m_minimize;
    CHoverButton	m_eject;
    CHoverButton	m_close;
    //}}AFX_DATA
    
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CCDLiteDlg)
protected:
    virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
    //}}AFX_VIRTUAL
    
    // Implementation
protected:
    HICON    m_hIcon;   
    CBmp     m_skin;
    CDPlayer m_cd;
    CString  m_skinName;
    BOOL     m_stopOnClose;

    void UpdateInfo();    
    // Generated message map functions
    //{{AFX_MSG(CCDLiteDlg)
    virtual BOOL OnInitDialog();
    afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
    afx_msg void OnPaint();
    afx_msg HCURSOR OnQueryDragIcon();
    afx_msg void OnPrevious();
    afx_msg void OnPlay();
    afx_msg void OnPause();
    afx_msg void OnStop();
    afx_msg void OnNext();
    afx_msg void OnEject();
    afx_msg void OnMinimize();
    afx_msg void OnClose();
    afx_msg void OnSystem();
    afx_msg void OnTimer(UINT nIDEvent);
    afx_msg void OnDestroy();
    afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
    afx_msg void OnAboutbox();
    afx_msg void OnSelectSkin();
    afx_msg void OnCD1();
    afx_msg void OnCD2();
    afx_msg void OnCD3();
    afx_msg void OnCD4();
    afx_msg void OnStopOnClose();
    //}}AFX_MSG
    afx_msg BOOL OnDeviceChange( UINT nEventType, DWORD dwData );
    afx_msg LONG OnMciNotify(UINT wParam, LONG lDevId);
    DECLARE_MESSAGE_MAP()
private:
    void EnsureOnScreen();
    void SaveRegistry();
    void LoadRegistry();
    bool LoadSkin(CString skin);
    void PositionControls();
    void SwitchCDDrive(UINT drive);

    static void AddMenu(CMenu * pMenu, UINT id, LPCTSTR text, BOOL checked);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif
