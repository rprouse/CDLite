// CDLite.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "CDLite.h"
#include "CDLiteDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCDLiteApp

BEGIN_MESSAGE_MAP( CCDLiteApp, CWinApp )
    //{{AFX_MSG_MAP(CCDLiteApp)
    // NOTE - the ClassWizard will add and remove mapping macros here.
    //    DO NOT EDIT what you see in these blocks of generated code!
    //}}AFX_MSG
    ON_COMMAND( ID_HELP, CWinApp::OnHelp )
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCDLiteApp construction

CCDLiteApp::CCDLiteApp() { }

/////////////////////////////////////////////////////////////////////////////
// The one and only CCDLiteApp object

CCDLiteApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CCDLiteApp initialization

BOOL CCDLiteApp::InitInstance()
{
    AfxEnableControlContainer();

#ifdef _AFXDLL
    //Enable3dControls();        // Call this when using MFC in a shared DLL
#else
    //Enable3dControlsStatic();    // Call this when linking to MFC statically
#endif
    InitCommonControls();

    CCDLiteDlg dlg;
    m_pMainWnd = &dlg;
    dlg.DoModal();

    return FALSE;
}
