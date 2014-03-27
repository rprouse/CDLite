// SkinDlg.cpp : implementation file
//

#include "stdafx.h"
#include "cdlite.h"
#include "SkinDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSkinDlg dialog


CSkinDlg::CSkinDlg( const CString & skin, CWnd* pParent )
: CDialog( CSkinDlg::IDD, pParent ), m_skin( skin )
{
    //{{AFX_DATA_INIT(CSkinDlg)
    // NOTE: the ClassWizard will add member initialization here
    //}}AFX_DATA_INIT
}


void CSkinDlg::DoDataExchange( CDataExchange* pDX )
{
    CDialog::DoDataExchange( pDX );
    //{{AFX_DATA_MAP(CSkinDlg)
    DDX_Control( pDX, IDOK, m_ok );
    DDX_Control( pDX, IDCANCEL, m_cancel );
    DDX_Control( pDX, IDC_SKIN, m_skinCtrl );
    DDX_Control( pDX, IDC_SKIN_LIST, m_skinList );
    //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP( CSkinDlg, CDialog )
    //{{AFX_MSG_MAP(CSkinDlg)
    ON_LBN_SELCHANGE( IDC_SKIN_LIST, OnSelchangeSkinList )
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSkinDlg message handlers

BOOL CSkinDlg::OnInitDialog()
{
    CDialog::OnInitDialog();

    m_skinList.AddString( _T( "Default" ) );

    // TODO: Add extra initialization here
    CFileInfoArray fia;
    fia.AddDir( "skins\\", "*.bmp", FALSE );
    int size = fia.GetSize();

    for ( int i = 0; i < size; i++ )
    {
        m_skinList.AddString( fia[i].GetFileTitle() );
    }

    m_skinList.SetCurSel( 0 );
    if ( m_skinList.SelectString( -1, m_skin ) == LB_ERR )
    {
        m_skin = "Default";
    }
    m_skinCtrl.SetBmp( m_skin );

    SetWindowPos( NULL, 0, 0, 288, 256, SWP_NOMOVE | SWP_NOZORDER );
    m_skinCtrl.SetWindowPos( NULL, 10, 10, 0, 0, SWP_NOSIZE | SWP_NOZORDER );
    m_skinList.SetWindowPos( NULL, 10, 31, 186, 190, SWP_NOZORDER );
    m_ok.SetWindowPos( NULL, 204, 10, 70, 25, SWP_NOZORDER );
    m_cancel.SetWindowPos( NULL, 204, 39, 70, 25, SWP_NOZORDER );

    return TRUE;  // return TRUE unless you set the focus to a control
}

void CSkinDlg::OnCancel()
{
    CDialog::OnCancel();
}

void CSkinDlg::OnOK()
{
    int i = m_skinList.GetCurSel();
    if ( i != LB_ERR )
        m_skinList.GetText( i, m_skin );

    CDialog::OnOK();
}

const CString & CSkinDlg::GetSelectedSkin()
{
    return m_skin;
}

void CSkinDlg::OnSelchangeSkinList()
{
    int i = m_skinList.GetCurSel();
    if ( i != LB_ERR )
    {
        CString buff;
        m_skinList.GetText( i, buff );
        m_skinCtrl.SetBmp( buff );
    }
}
