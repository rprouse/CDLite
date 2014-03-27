////////////////////////////////////////////////////////////////////////////////
// TransStatic.cpp : implementation file
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "TransStatic.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTransStatic

CTransStatic::CTransStatic() { }

CTransStatic::~CTransStatic() { }

BEGIN_MESSAGE_MAP( CTransStatic, CStatic )
    //{{AFX_MSG_MAP(CTransStatic)
    ON_WM_CTLCOLOR_REFLECT()
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTransStatic message handlers
HBRUSH CTransStatic::CtlColor( CDC* pDC, UINT nCtlColor )
{
    pDC->SetBkMode( TRANSPARENT );
    return (HBRUSH)GetStockObject( NULL_BRUSH );
}

void CTransStatic::SetWindowText( LPCTSTR lpszString )
{
    CStatic::SetWindowText( lpszString );

    CRect rect;
    GetWindowRect( &rect );
    GetParent()->ScreenToClient( &rect );
    GetParent()->InvalidateRect( &rect, FALSE );
}
