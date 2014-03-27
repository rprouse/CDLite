// CDLiteDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CDLite.h"
#include "CDLiteDlg.h"
#include "SkinDlg.h"
#include "AboutDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define UPDATE_TIMER 100

/////////////////////////////////////////////////////////////////////////////
// CCDLiteDlg dialog

CCDLiteDlg::CCDLiteDlg(CWnd* pParent /*=NULL*/)
: CBmpDlg(CCDLiteDlg::IDD, pParent), m_stopOnClose(FALSE)
{
    //{{AFX_DATA_INIT(CCDLiteDlg)
    // NOTE: the ClassWizard will add member initialization here
    //}}AFX_DATA_INIT
    // Note that LoadIcon does not require a subsequent DestroyIcon in Win32
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CCDLiteDlg::~CCDLiteDlg() { }

void CCDLiteDlg::DoDataExchange(CDataExchange* pDX)
{
    CBmpDlg::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CCDLiteDlg)
    DDX_Control(pDX, IDC_TRACK, m_track);
    DDX_Control(pDX, IDC_TIME, m_time);
    DDX_Control(pDX, IDC_SYSTEM, m_system);
    DDX_Control(pDX, IDC_STOP, m_stop);
    DDX_Control(pDX, IDC_PREV, m_previous);
    DDX_Control(pDX, IDC_PLAY, m_play);
    DDX_Control(pDX, IDC_PAUSE, m_pause);
    DDX_Control(pDX, IDC_NEXT, m_next);
    DDX_Control(pDX, IDC_MINIMIZE, m_minimize);
    DDX_Control(pDX, IDC_EJECT, m_eject);
    DDX_Control(pDX, IDC_CLOSE, m_close);
    //}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCDLiteDlg, CBmpDlg)
    //{{AFX_MSG_MAP(CCDLiteDlg)
    ON_WM_SYSCOMMAND()
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_PREV, OnPrevious)
    ON_BN_CLICKED(IDC_PLAY, OnPlay)
    ON_BN_CLICKED(IDC_PAUSE, OnPause)
    ON_BN_CLICKED(IDC_STOP, OnStop)
    ON_BN_CLICKED(IDC_NEXT, OnNext)
    ON_BN_CLICKED(IDC_EJECT, OnEject)
    ON_BN_CLICKED(IDC_MINIMIZE, OnMinimize)
    ON_BN_CLICKED(IDC_CLOSE, OnClose)
    ON_BN_CLICKED(IDC_SYSTEM, OnSystem)
    ON_WM_TIMER()
    ON_WM_DESTROY()
    ON_WM_LBUTTONUP()
    ON_COMMAND(IDM_ABOUTBOX, OnAboutbox)
    ON_COMMAND(IDM_SKIN, OnSelectSkin)
    ON_COMMAND(IDM_CD1, OnCD1)
    ON_COMMAND(IDM_CD2, OnCD2)
    ON_COMMAND(IDM_CD3, OnCD3)
    ON_COMMAND(IDM_CD4, OnCD4)
    ON_COMMAND(IDM_CLOSE, OnClose)
    ON_COMMAND(IDM_EJECT, OnEject)
    ON_COMMAND(IDM_MINIMIZE, OnMinimize)
    ON_COMMAND(IDM_NEXT, OnNext)
    ON_COMMAND(IDM_PAUSE, OnPause)
    ON_COMMAND(IDM_PLAY, OnPlay)
    ON_COMMAND(IDM_PREV, OnPrevious)
    ON_COMMAND(IDM_STOP, OnStop)
    ON_BN_DOUBLECLICKED(IDC_SYSTEM, OnClose)
    ON_COMMAND(IDM_STOP_ON_CLOSE, OnStopOnClose)
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCDLiteDlg message handlers

BOOL CCDLiteDlg::OnInitDialog()
{
    CBmpDlg::OnInitDialog();
    
    ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
    ASSERT(IDM_ABOUTBOX < 0xF000);
    
    CMenu* pSysMenu = GetSystemMenu(FALSE);
    if (pSysMenu != NULL)
    {
	pSysMenu->AppendMenu(MF_SEPARATOR);
	pSysMenu->AppendMenu(MF_STRING, IDM_PREV,  "Pre&vious");
	pSysMenu->AppendMenu(MF_STRING, IDM_PLAY,  "&Play");
	pSysMenu->AppendMenu(MF_STRING, IDM_PAUSE, "Pa&use");
	pSysMenu->AppendMenu(MF_STRING, IDM_STOP,  "&Stop");
	pSysMenu->AppendMenu(MF_STRING, IDM_NEXT,  "&Next");
	pSysMenu->AppendMenu(MF_STRING, IDM_EJECT, "&Eject");
	CString strAboutMenu;
	strAboutMenu.LoadString(IDS_ABOUTBOX);
	if (!strAboutMenu.IsEmpty())
	{
	    pSysMenu->AppendMenu(MF_SEPARATOR);
	    pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
	}
    }
    
    // Set the icon for this dialog.  The framework does this automatically
    //  when the application's main window is not a dialog
    SetIcon(m_hIcon, TRUE);		// Set big icon
    SetIcon(m_hIcon, FALSE);		// Set small icon
    SetWindowText("CDLite");
    
    LoadRegistry();
    PositionControls();
    LoadSkin(m_skinName);
    m_cd.Attach(m_hWnd);
    m_cd.Open();
    UpdateInfo();
    SetTimer(UPDATE_TIMER, 1000, NULL);
    
    return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCDLiteDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
    switch(nID & 0xFFF0)
    {
    case IDM_ABOUTBOX:
	OnAboutbox();
	break;
    case IDM_PREV:
	OnPrevious();
	break;
    case IDM_PLAY:
	OnPlay();
	break;
    case IDM_PAUSE:
	OnPause();
	break;
    case IDM_STOP:
	OnStop();
	break;
    case IDM_NEXT:
	OnNext();
	break;
    case IDM_EJECT:
	OnEject();
	break;
    default:
	CBmpDlg::OnSysCommand(nID, lParam);
    }
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCDLiteDlg::OnPaint() 
{
    if (IsIconic())
    {
	CPaintDC dc(this); // device context for painting
	
	SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);
	
	// Center icon in client rectangle
	int cxIcon = GetSystemMetrics(SM_CXICON);
	int cyIcon = GetSystemMetrics(SM_CYICON);
	CRect rect;
	GetClientRect(&rect);
	int x = (rect.Width() - cxIcon + 1) / 2;
	int y = (rect.Height() - cyIcon + 1) / 2;
	
	// Draw the icon
	dc.DrawIcon(x, y, m_hIcon);
    }
    else
    {
	CBmpDlg::OnPaint();
    }
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCDLiteDlg::OnQueryDragIcon()
{
    return (HCURSOR) m_hIcon;
}

void CCDLiteDlg::OnPrevious() 
{
    m_cd.PrevTrack();
    UpdateInfo();
}

void CCDLiteDlg::OnPlay() 
{
    m_cd.Play();
}

void CCDLiteDlg::OnPause() 
{
    m_cd.Pause();
}

void CCDLiteDlg::OnStop() 
{
    m_cd.Stop();
}

void CCDLiteDlg::OnNext() 
{
    m_cd.NextTrack();
    UpdateInfo();
}

void CCDLiteDlg::OnEject() 
{
    m_cd.Eject();
    UpdateInfo();
}

void CCDLiteDlg::OnCD1()
{
    SwitchCDDrive(0);
}

void CCDLiteDlg::OnCD2()
{
    SwitchCDDrive(1);
}

void CCDLiteDlg::OnCD3()
{
    SwitchCDDrive(2);
}

void CCDLiteDlg::OnCD4()
{
    SwitchCDDrive(3);
}

void CCDLiteDlg::SwitchCDDrive(UINT drive)
{
    // We only support 4 drives
    ASSERT(drive < 4);

    // Switch to this drive, 0 based
    if(drive != m_cd.GetDriveID())
    {
	m_cd.Stop();
	m_cd.SetDriveID(drive);
    }
}

void CCDLiteDlg::OnMinimize() 
{
    SendMessage(WM_SYSCOMMAND, SC_MINIMIZE, 0);
}

void CCDLiteDlg::OnClose() 
{
    if(m_stopOnClose)
	m_cd.Stop();
    KillTimer(UPDATE_TIMER);
    CBmpDlg::OnOK();
}

void CCDLiteDlg::OnSystem() 
{
    CMenu menu;
    menu.LoadMenu(IDR_POPUPMENU);
    ASSERT(menu);
    CMenu * pPopup = menu.GetSubMenu(0);

    CMenu cdMenu;
    VERIFY(cdMenu.CreatePopupMenu());
    VERIFY(pPopup->InsertMenu(5, MF_POPUP | MF_BYPOSITION, (UINT)cdMenu.m_hMenu, "CD Drives"));

    CString drives(m_cd.GetDrives());

    // We only support 4 CD drives
    for(UINT i = 0; i < m_cd.GetNumDrives() && i < 4; ++i)
    {
	CString menuText;
	menuText.Format("&%c Drive", drives.GetAt(i));

	AddMenu(&cdMenu, IDM_CD1 + i, menuText, (m_cd.GetDriveID() == i));
    }

    AddMenu(pPopup, IDM_STOP_ON_CLOSE, "S&top Playback On Close", m_stopOnClose);

    CRect rect;    
    GetWindowRect(&rect);
    pPopup->TrackPopupMenu(TPM_LEFTALIGN, rect.left, rect.bottom, this);
}

void CCDLiteDlg::AddMenu(CMenu * pMenu, UINT id, LPCTSTR text, BOOL checked)
{
    UINT flags = MF_STRING | MF_ENABLED;
    if(checked)
	flags |= MF_CHECKED;
    
    VERIFY(pMenu->AppendMenu(flags, id, text));
}

void CCDLiteDlg::PositionControls()
{
    SetWindowPos(NULL, 0, 0, 186, 12, SWP_NOZORDER | SWP_NOMOVE);

    m_system  .SetWindowPos(NULL,   2, 2,  9, 10, SWP_NOZORDER);
    m_track   .SetWindowPos(NULL,  40, 3, 10,  7, SWP_NOZORDER);
    m_time    .SetWindowPos(NULL,  72, 3, 26,  7, SWP_NOZORDER);
    m_previous.SetWindowPos(NULL, 105, 2,  9, 10, SWP_NOZORDER);
    m_play    .SetWindowPos(NULL, 115, 2,  9, 10, SWP_NOZORDER);
    m_pause   .SetWindowPos(NULL, 125, 2,  9, 10, SWP_NOZORDER);
    m_stop    .SetWindowPos(NULL, 135, 2,  9, 10, SWP_NOZORDER);
    m_next    .SetWindowPos(NULL, 145, 2,  9, 10, SWP_NOZORDER);
    m_eject   .SetWindowPos(NULL, 155, 2,  9, 10, SWP_NOZORDER);
    m_minimize.SetWindowPos(NULL, 165, 2,  9, 10, SWP_NOZORDER);
    m_close   .SetWindowPos(NULL, 175, 2,  9, 10, SWP_NOZORDER);
}

bool CCDLiteDlg::LoadSkin(CString skin)
{
    bool ret = true;
    
    skin = "skins\\" + skin + ".bmp";
    
    if(!m_skin.Load(skin, true))
    {
	// Load default skin
	m_skin.Load("IDB_DEFAULT_SKIN", false);
    }
    SetBackground(m_skin, 0, 0, 186, 12);
    m_track.SetBmp(m_skin);
    m_time.SetBmp(m_skin);
    
    m_system  .SetDepressedBitmap(m_skin,  57, 14, 9, 10);
    m_previous.SetDepressedBitmap(m_skin,  68, 14, 9, 10);
    m_play    .SetDepressedBitmap(m_skin,  79, 14, 9, 10);
    m_pause   .SetDepressedBitmap(m_skin,  90, 14, 9, 10);
    m_stop    .SetDepressedBitmap(m_skin, 101, 14, 9, 10);
    m_next    .SetDepressedBitmap(m_skin, 112, 14, 9, 10);
    m_eject   .SetDepressedBitmap(m_skin, 123, 14, 9, 10);
    m_minimize.SetDepressedBitmap(m_skin, 134, 14, 9, 10);
    m_close   .SetDepressedBitmap(m_skin, 145, 14, 9, 10);

    Invalidate();
    UpdateWindow();

    return ret;
}

void CCDLiteDlg::UpdateInfo()
{
    CString buff;
    DWORD dwTMSF  = m_cd.GetPosition();
    buff.Format("%.2d", MCI_TMSF_TRACK(dwTMSF));
    m_track.SetWindowText(buff);
    buff.Format(" %.2d:%.2d", MCI_TMSF_MINUTE(dwTMSF), MCI_TMSF_SECOND(dwTMSF));
    m_time.SetWindowText(buff);
}

void CCDLiteDlg::OnTimer(UINT nIDEvent) 
{
    switch(nIDEvent)
    {
    case UPDATE_TIMER:
	UpdateInfo();
	break;
    default:
	CBmpDlg::OnTimer(nIDEvent);
	break;
    }	
}

void CCDLiteDlg::OnDestroy() 
{
    CBmpDlg::OnDestroy();
    
    SaveRegistry();    
}

void CCDLiteDlg::LoadRegistry()
{
    CRegistry reg(HKEY_CURRENT_USER, "Software\\Alteridem\\CDLite");
    if(!reg.GetValue("Skin", m_skinName))
	m_skinName = "Default";

    int x, y;
    if(reg.GetValue("XPos", &x) && reg.GetValue("YPos", &y))
    {
	SetWindowPos(&wndTopMost, x, y, 0, 0, SWP_NOSIZE);
	EnsureOnScreen();
    }
    else
    {
	SetWindowPos(&wndTopMost, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
    }

    // Which CD Drive are we using?
    SwitchCDDrive(reg.GetDWORD("Drive"));

    m_stopOnClose = (BOOL)reg.GetDWORD("Stop");
}

void CCDLiteDlg::SaveRegistry()
{
    CRegistry reg(HKEY_CURRENT_USER, "Software\\Alteridem\\CDLite");
    reg.SetValue("Skin", m_skinName);

    CRect rect;
    GetWindowRect(&rect);
    reg.SetValue("XPos",  (int)rect.left);
    reg.SetValue("YPos",  (int)rect.top);
    reg.SetDWORD("Drive", m_cd.GetDriveID());
    reg.SetDWORD("Stop",  (DWORD)m_stopOnClose);
}

void CCDLiteDlg::OnLButtonUp(UINT nFlags, CPoint point) 
{
    // Override the default behaviour, I want the player to stay
    // on the window.
    EnsureOnScreen();
    
    CBmpDlg::OnLButtonUp(nFlags, point);
}

void CCDLiteDlg::EnsureOnScreen()
{
    CRect rect;
    GetWindowRect(&rect);
    bool move = false;
    int  size = GetSystemMetrics(SM_CXSCREEN);
    if(rect.left < 0) 
    {
	rect.left = 0;
	move = true;
    } else if(rect.right > size) 
    {
	rect.left -= rect.right - size;
	move = true;
    }

    size = GetSystemMetrics(SM_CYSCREEN);
    if(rect.top < 0) 
    {
	rect.top = 0;
	move = true;
    } else if(rect.bottom > size) 
    {
	rect.top -= rect.bottom - size;
	move = true;
    }

    if(move)
	SetWindowPos(NULL, rect.left, rect.top, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
}

void CCDLiteDlg::OnAboutbox() 
{
    CAboutDlg dlgAbout;
    dlgAbout.DoModal();
}


void CCDLiteDlg::OnSelectSkin() 
{
    CSkinDlg dlg(m_skinName, this);
    dlg.DoModal();
    m_skinName = dlg.GetSelectedSkin();
    LoadSkin(m_skinName);
}

// Intercept a new CD-Audio insertion
BOOL CCDLiteDlg::OnDeviceChange( UINT nEventType, DWORD dwData ) 
{
    DEV_BROADCAST_HDR *pdbch = (DEV_BROADCAST_HDR *) dwData;
    
    switch(nEventType) 
    {
    case DBT_DEVICEARRIVAL:					// CD drawer was closed
	if (pdbch->dbch_devicetype == DBT_DEVTYP_VOLUME) 
	{
	    PDEV_BROADCAST_VOLUME pdbcv = (PDEV_BROADCAST_VOLUME)dwData;
	    if (pdbcv->dbcv_flags == DBTF_MEDIA)
	    {
		TCHAR szDrive[4];
		// pdbcv->unitmask contains the drive bits
        UINT i;
		for (i=0; !(pdbcv->dbcv_unitmask & (1<<i)); i++);
		wsprintf(szDrive, _T("%c:\\"), 'A'+i);		
		if (GetDriveType(szDrive) == DRIVE_CDROM) 
		{					
		    // Drive was closed, do something
		    //UpdateControls();					
		}
	    }
	    else 
	    {
		// It is a network drive
	    }
	    break;
	}
    case DBT_DEVICEREMOVECOMPLETE:				// CD drawer was open
	//EnableControls(FALSE, FALSE);
	break;
    }
    
    return TRUE;
}

LONG CCDLiteDlg::OnMciNotify(UINT wFlags, LONG lDevId) 
{	
    switch(wFlags) {
    case MCI_NOTIFY_SUCCESSFUL:
	//m_wndStatus.SetWindowText(_T("Playback completed"));
	break;
    case MCI_NOTIFY_FAILURE:
	//m_wndStatus.SetWindowText(_T("Playback interrupted!"));
	break;
    case MCI_NOTIFY_SUPERSEDED:
	//m_wndStatus.SetWindowText(_T("Playback stopped!"));
	break;
    }	
    return 0L;
}

void CCDLiteDlg::OnStopOnClose() 
{
    m_stopOnClose = !m_stopOnClose;
}
