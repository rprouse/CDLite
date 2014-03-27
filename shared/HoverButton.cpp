// HoverButton.cpp : implementation file
//

#include "stdafx.h"         // MFC core and standard component
#include <string>
#include <mmsystem.h>

#include "HoverButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


// Static members
CPalette * CHoverButton::cPalette = NULL;
CString CHoverButton::clickSound;
CString CHoverButton::mouseOverSound;

// Constructor
CHoverButton::CHoverButton() :
textColour( RGB( 250, 250, 250 ) ),
textHighlightColour( RGB( 200, 200, 200 ) ),
textShadowColour( RGB( 98, 98, 98 ) ),
bmNormal(),
bmDepressed(),
bmHover(),
bmDisabled(),
bMouseOver( false ),
bDontPlay( false ),
bFirstThrough( true ),
offset( 0 ),
font( NULL ),
textFormat( DT_SINGLELINE | DT_LEFT | DT_VCENTER ) { }

CHoverButton::~CHoverButton() { }

BEGIN_MESSAGE_MAP( CHoverButton, CButton )
    //{{AFX_MSG_MAP(CHoverButton)
    ON_WM_ERASEBKGND()
    ON_WM_MOUSEMOVE()
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHoverButton message handlers

void CHoverButton::DrawItem( LPDRAWITEMSTRUCT lpDrawItemStruct )
{
    CDC *pDC = CDC::FromHandle( lpDrawItemStruct->hDC );

    bool clicked = false;
    if ( ( lpDrawItemStruct->itemState & ODS_SELECTED ) == ODS_SELECTED )
    {
        clicked = true;
        if ( !clickSound.IsEmpty() )
            PlaySound( clickSound, NULL, SND_RESOURCE | SND_NOWAIT );
    }
    else if ( ( lpDrawItemStruct->itemAction == 4 ) &&
        ( ( lpDrawItemStruct->itemState & ODS_FOCUS ) != ODS_FOCUS ) )  // Just trust me on this one
    {
        bMouseOver = false;
        bFirstThrough = true;
        bDontPlay = false;
        ReleaseCapture();
    }

    CRect rect, shadow;
    GetClientRect( &rect );
    pDC->SetBkMode( TRANSPARENT );
    CString text;
    GetWindowText( text );
    if ( font )
        pDC->SelectObject( font );
    rect.left += offset;
    rect.top += 3;        // Just because it doesn't look centered.

    BOOL enabled = IsWindowEnabled();
    //BOOL clicked = (GetState() & 0x0004 == 0x0004);

    // Draw the correct bitmap here, the calls to update parent are for 
    // cases where we have no bitmap that works, so we want the parent
    // to draw itself (maybe the parent has the bitmap buttons drawn on it.)
    if ( enabled )
    {
        if ( clicked )
        {
            if ( !bmDepressed.Draw( pDC->m_hDC ) && !bmNormal.Draw( pDC->m_hDC ) )
                UpdateParent();
        }
        else if ( bMouseOver )
        {
            if ( !bmHover.Draw( pDC->m_hDC ) && !bmNormal.Draw( pDC->m_hDC ) )
                UpdateParent();
        }
        else
        {
            if ( !bmNormal.Draw( pDC->m_hDC ) )
                UpdateParent();
        }
    }
    else
    {
        if ( !bmDisabled.Draw( pDC->m_hDC ) )
            UpdateParent();
    }

    // Draw a drop shadow
    shadow = rect;
    shadow.bottom += 2;
    shadow.top += 2;
    shadow.right += 2;
    shadow.left += 2;
    pDC->SetTextColor( textShadowColour );
    pDC->DrawText( text, &shadow, textFormat );

    if ( cPalette )
    {
        pDC->SelectPalette( cPalette, 1 );
        pDC->RealizePalette();
    }

    // Set the text colour here
    if ( enabled )
    {
        if ( bMouseOver || clicked )
            pDC->SetTextColor( textHighlightColour );
        else
            pDC->SetTextColor( textColour );
    }
    else
    {
        pDC->SetTextColor( textDisabledColour );
    }

    // Draw the text
    pDC->DrawText( text, &rect, textFormat );
    //AntiAliasedTextOut(pDC->m_hDC, rect.left, rect.top, text);

    if ( bMouseOver )
    {
        if ( !mouseOverSound.IsEmpty() && !bDontPlay )
            PlaySound( mouseOverSound, NULL, SND_RESOURCE | SND_NOWAIT );

        bDontPlay = false;
        bFirstThrough = false;
    }
}

void CHoverButton::UpdateParent()
{
    static bool alreadyUpdating = false;

    // This prevents the parent from updating the control
    // which updates the parent in a circle.
    if ( !alreadyUpdating )
    {
        CRect pRect, updateRect;
        GetWindowRect( updateRect );
        GetParent()->GetWindowRect( &pRect );
        updateRect.top -= pRect.top;
        updateRect.bottom -= pRect.top;
        updateRect.right -= pRect.left;
        updateRect.left -= pRect.left;

        alreadyUpdating = true;
        GetParent()->RedrawWindow( &updateRect, NULL, RDW_INVALIDATE | RDW_UPDATENOW );
        alreadyUpdating = false;
    }
}

void CHoverButton::SetPalette( CPalette *palette )
{
    if ( palette ) cPalette = palette;
}

BOOL CHoverButton::OnEraseBkgnd( CDC* pDC )
{
    return 0;
}

bool CHoverButton::SetNormalBitmap( LPCWSTR name, bool file )
{
    bmNormal.Load( name, file );
    return bmNormal;
}

bool CHoverButton::SetDepressedBitmap( LPCWSTR name, bool file )
{
    bmDepressed.Load( name, file );
    return bmDepressed;
}

bool CHoverButton::SetHoverBitmap( LPCWSTR name, bool file )
{
    bmHover.Load( name, file );
    return bmHover;
}

bool CHoverButton::SetDisabledBitmap( LPCWSTR name, bool file )
{
    bmDisabled.Load( name, file );
    return bmDisabled;
}

bool CHoverButton::SetNormalBitmap( const CBmp & bmp, int x, int y, int w, int h )
{
    bmNormal.Attach( bmp, x, y, w, h );
    return bmNormal;
}

bool CHoverButton::SetDepressedBitmap( const CBmp & bmp, int x, int y, int w, int h )
{
    bmDepressed.Attach( bmp, x, y, w, h );
    return bmDepressed;
}

bool CHoverButton::SetHoverBitmap( const CBmp & bmp, int x, int y, int w, int h )
{
    bmHover.Attach( bmp, x, y, w, h );
    return bmHover;
}

bool CHoverButton::SetDisabledBitmap( const CBmp & bmp, int x, int y, int w, int h )
{
    bmDisabled.Attach( bmp, x, y, w, h );
    return bmDisabled;
}

bool CHoverButton::SetButtonStrip( const CBmp & bmp, int w )
{
    // It's okay, they are reference counted
    SetNormalBitmap( bmp, 0, 0, w, 0 );
    SetDepressedBitmap( bmp, w, 0, w, 0 );
    SetHoverBitmap( bmp, w * 2, 0, w );
    return SetDisabledBitmap( bmp, w * 3, 0, w ); // they're all the same
}

void CHoverButton::OnMouseMove( UINT nFlags, CPoint point )
{
    CRect rect;
    GetWindowRect( &rect );

    // If the mouse was not over, see if it is now.
    if ( !bMouseOver && point.x >= 0 && point.x <= rect.right - rect.left && point.y >= 0 && point.y <= rect.bottom - rect.top )
    {
        bFirstThrough = false;
        bMouseOver = true;
        SetFocus();
        SetCapture();        // Capture all mousemoves so we know when the mouse has left.
        RedrawWindow( NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW );
    }

    // If the mouse was over, see if it has left
    else if ( bMouseOver && ( point.x < 0 || point.x > rect.right - rect.left || point.y < 0 || point.y > rect.bottom - rect.top ) )
    {
        bMouseOver = false;
        bFirstThrough = true;
        ReleaseCapture();

        // Force a repaint of the parent to erase our graphic
        CRect pRect, updateRect;
        GetParent()->GetWindowRect( &pRect );
        updateRect.top = rect.top - pRect.top;
        updateRect.bottom = rect.bottom - pRect.top;
        updateRect.right = rect.right - pRect.left;
        updateRect.left = rect.left - pRect.left;

        GetParent()->RedrawWindow( &updateRect, NULL, RDW_INVALIDATE | RDW_UPDATENOW );
    }

    CButton::OnMouseMove( nFlags, point );
}

void CHoverButton::SetFont( CFont *fn )
{
    font = fn;
}

void CHoverButton::SetClickSound( LPCWSTR resource )
{
    clickSound = resource;
}

void CHoverButton::SetMouseOverSound( LPCWSTR resource )
{
    mouseOverSound = resource;
}

void CHoverButton::SetTextFormat( UINT format )
{
    textFormat = format;
}

void CHoverButton::SetTextOffset( UINT pixels )
{
    offset = pixels;
}

void CHoverButton::SetDisabledTextColor( COLORREF crColor )
{
    textDisabledColour = crColor;
}

void CHoverButton::SetTextColor( COLORREF crColor )
{
    textColour = crColor;
}

void CHoverButton::SetTextHighlightColor( COLORREF crColor )
{
    textHighlightColour = crColor;
}

void CHoverButton::SetTextShadowColor( COLORREF crColor )
{
    textShadowColour = crColor;
}

bool CHoverButton::AntiAliasedText( HDC hDC, const int& nXStart, const int& nYStart, LPCWSTR lpString )
{
    MAT2 m2 = { { 0, 1 }, { 0, 0 }, { 0, 0 }, { 0, 1 } };
    GLYPHMETRICS gm;

    int nLen = _tcslen( lpString );
    POINT pt1 = { nXStart, nYStart };

    COLORREF crText = ::GetTextColor( hDC );

    for ( int i = 0; i < nLen; i++ )
    {
        UINT u = (BYTE)lpString[i];
        DWORD cbBuf = ::GetGlyphOutline( hDC, u, GGO_GRAY8_BITMAP,
            &gm, 0, NULL, &m2 );

        if ( cbBuf == -1 )
            return false; // raster font?

        POINT pt2;
        pt2.x = pt1.x + gm.gmptGlyphOrigin.x;
        pt2.y = pt1.y - gm.gmptGlyphOrigin.y;

        pt1.x += gm.gmCellIncX;
        pt1.y += gm.gmCellIncY;

        if ( cbBuf == 0 )
            continue; // EMPTY GLYPH

        // this test should be useless
        if ( ( u == 0x20 ) || ( u == 0xA0 ) )
            continue; // put a breakpoint here; if reached, something is wrong

        BYTE* pBuf = new BYTE[cbBuf];
        if ( pBuf == NULL )
            return false; // not enough mem

        ::GetGlyphOutline( hDC, u, GGO_GRAY8_BITMAP,
            &gm, cbBuf, pBuf, &m2 );

        int nLineSize = ( ( gm.gmBlackBoxX + 3 ) >> 2 ) << 2;
        BYTE* pLine = pBuf;
        for ( int y = 0; y < (int)gm.gmBlackBoxY; y++ )
        {
            for ( int x = 0; x < (int)gm.gmBlackBoxX; x++ )
            {
                BYTE bVal = pLine[x];
                if ( bVal == 0 )
                    continue;

                if ( bVal == 64 )
                {
                    ::SetPixel( hDC, pt2.x + x, pt2.y + y, crText );
                    continue;
                }

                // alpha blend
                COLORREF crOld = ::GetPixel( hDC, pt2.x + x, pt2.y + y );

                BYTE bR = ( GetRValue( crOld ) * ( 64 - bVal ) +
                    GetRValue( crText ) * bVal ) >> 6;
                BYTE bG = ( GetGValue( crOld ) * ( 64 - bVal ) +
                    GetGValue( crText ) * bVal ) >> 6;
                BYTE bB = ( GetBValue( crOld ) * ( 64 - bVal ) +
                    GetBValue( crText ) * bVal ) >> 6;

                ::SetPixel( hDC, pt2.x + x, pt2.y + y, RGB( bR, bG, bB ) );
            }
            pLine += nLineSize;
        }
        delete[] pBuf;
    }
    return true;
}

