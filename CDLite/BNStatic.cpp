// BNStatic.cpp : implementation file
//

#include "stdafx.h"
#include "cdlite.h"
#include "BNStatic.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBmpNumberStatic

CBmpNumberStatic::CBmpNumberStatic() : CStatic() { }

CBmpNumberStatic::~CBmpNumberStatic() { }


BEGIN_MESSAGE_MAP( CBmpNumberStatic, CStatic )
    //{{AFX_MSG_MAP(CBmpNumberStatic)
    ON_WM_CTLCOLOR_REFLECT()
    ON_WM_PAINT()
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBmpNumberStatic message handlers

HBRUSH CBmpNumberStatic::CtlColor( CDC* pDC, UINT nCtlColor )
{
    pDC->SetBkMode( TRANSPARENT );
    return (HBRUSH)GetStockObject( NULL_BRUSH );
}

void CBmpNumberStatic::SetWindowText( LPCTSTR lpszString )
{
    CStatic::SetWindowText( lpszString );

    CRect rect;
    GetWindowRect( &rect );
    GetParent()->ScreenToClient( &rect );
    GetParent()->InvalidateRect( &rect, FALSE );
}

bool CBmpNumberStatic::SetBmp( const CBmp & bmp )
{
    // These are the positions within the number strip
    // of each of the digits, 0-9 then : -
    for ( int i = 0; i < 10; i++ )
    {
        m_digits[i].Attach( bmp, i * 5, 14, 5, 7 );
    }
    m_digits[10].Attach( bmp, 50, 14, 2, 7 );
    m_digits[11].Attach( bmp, 52, 14, 4, 7 );

    return m_digits[0];  // OK, cause they are all the same bitmap
}

void CBmpNumberStatic::OnPaint()
{
    CPaintDC dc( this ); // device context for painting

    CString text;
    GetWindowText( text );

    int xPos = 0;
    int len = text.GetLength();
    for ( int i = 0; i < len; i++ )
    {
        TCHAR c = text[i];
        switch ( c )
        {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            m_digits[c - '0'].Draw( dc.m_hDC, xPos, 0 );
            xPos += 5;
            break;
        case ':':
            m_digits[10].Draw( dc.m_hDC, xPos, 0 );
            xPos += 2;
            break;
        case '-':
            m_digits[11].Draw( dc.m_hDC, xPos, 0 );
        case ' ':
            xPos += 4;
            break;
        default:    // Do nothing
            break;
        }
    }
}
