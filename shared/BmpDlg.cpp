// BmpDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BmpDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNAMIC( CBmpDlg, CDialog )

BEGIN_MESSAGE_MAP( CBmpDlg, CDialog )
    //{{AFX_MSG_MAP(CBmpDlg)
    ON_WM_LBUTTONDOWN()
    ON_WM_LBUTTONUP()
    ON_WM_MOUSEMOVE()
    ON_WM_PAINT()
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

CBmpDlg::CBmpDlg() :
CDialog(), m_bMoving( false ), hBackground() { }

CBmpDlg::CBmpDlg( LPCWSTR lpszTemplateName, CWnd* pParentWnd ) :
CDialog( lpszTemplateName, pParentWnd ), m_bMoving( false ), hBackground() { }

CBmpDlg::CBmpDlg( UINT nIDTemplate, CWnd* pParentWnd ) :
CDialog( nIDTemplate, pParentWnd ), m_bMoving( false ), hBackground() { }

CBmpDlg::~CBmpDlg()
{
}

bool CBmpDlg::LoadBackground( LPCWSTR lpszName, bool bFromFile )
{
    hBackground.Load( lpszName, bFromFile );
    return hBackground;
}

bool CBmpDlg::SetBackground( const CBmp & bmp, int x, int y, int w, int h )
{
    hBackground.Attach( bmp, x, y, w, h );
    return hBackground;
}

void CBmpDlg::OnLButtonDown( UINT nFlags, CPoint point )
{
    m_MoveOffset = point;
    m_bMoving = true;
    SetCapture();
    CDialog::OnLButtonDown( nFlags, point );
}

void CBmpDlg::OnLButtonUp( UINT nFlags, CPoint point )
{
    m_bMoving = false;
    ReleaseCapture();
    Invalidate();
    UpdateWindow();
    CDialog::OnLButtonUp( nFlags, point );
}

void CBmpDlg::OnMouseMove( UINT nFlags, CPoint point )
{
    if ( m_bMoving )
    {
        CRect rect;
        GetWindowRect( &rect );
        point -= m_MoveOffset;
        rect += point;
        SetWindowPos( NULL, rect.left, rect.top, 0, 0, SWP_NOZORDER | SWP_NOSIZE );
    }
    CDialog::OnMouseMove( nFlags, point );
}

void CBmpDlg::OnPaint()
{
    CPaintDC dc( this ); // device context for painting

    // Draw the bitmap
    if ( hBackground )
    {
        BITMAP bmp;
        GetObject( (HBITMAP)hBackground, sizeof( bmp ), (LPVOID)&bmp );

        static bool sized = false;
        if ( !sized )
        {
            sized = true;
            if ( hBackground.Width() == 0 || hBackground.Height() == 0 )
                SetWindowPos( NULL, 0, 0, bmp.bmWidth, bmp.bmHeight, SWP_NOMOVE | SWP_NOZORDER );
            else
                SetWindowPos( NULL, 0, 0, hBackground.Width(), hBackground.Height(), SWP_NOMOVE | SWP_NOZORDER );
        }
        hBackground.Draw( dc );
    }
}