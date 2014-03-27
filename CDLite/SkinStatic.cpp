// SkinStatic.cpp : implementation file
//

#include "stdafx.h"
#include "cdlite.h"
#include "SkinStatic.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSkinStatic

CSkinStatic::CSkinStatic() { }

CSkinStatic::~CSkinStatic() { }

BEGIN_MESSAGE_MAP( CSkinStatic, CStatic )
    //{{AFX_MSG_MAP(CSkinStatic)
    ON_WM_CTLCOLOR_REFLECT()
    ON_WM_PAINT()
    ON_WM_CREATE()
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSkinStatic message handlers
HBRUSH CSkinStatic::CtlColor( CDC* pDC, UINT nCtlColor )
{
    pDC->SetBkMode( TRANSPARENT );
    return (HBRUSH)GetStockObject( NULL_BRUSH );
}

void CSkinStatic::OnPaint()
{
    CPaintDC dc( this ); // device context for painting
    m_skin.Draw( dc.m_hDC, 0, 0, 186, 12 );
}

int CSkinStatic::OnCreate( LPCREATESTRUCT lpCreateStruct )
{
    if ( CStatic::OnCreate( lpCreateStruct ) == -1 )
        return -1;

    lpCreateStruct->cx = 186;
    lpCreateStruct->cy = 12;

    return 0;
}

void CSkinStatic::SetBmp( LPCWSTR skinname )
{
    CString skin( "skins\\" );
    skin += skinname;
    skin += ".bmp";

    if ( !m_skin.Load( skin, true ) )
    {
        // Load default skin
        m_skin.Load( _T( "IDB_DEFAULT_SKIN" ), false );
    }
    Invalidate( FALSE );
    UpdateWindow();
}