//====================================================================
// Bmp.cpp: implementation of the CBmp class.
//
// $Log: Bmp.cpp,v $
// Revision 1.7  2003/02/07 15:35:41  commando
// More correct C++
//
// Revision 1.6  2001/09/18 00:36:44  vertigo
// Converted the CBmpStrip to derive from a CRect
//
// Revision 1.5  2001/09/14 21:11:43  vertigo
// Added methods to make using the classes easier and to simplify code
//
// Revision 1.4  2001/09/14 20:22:11  vertigo
// Added methods to load button images from various types of image strips
//
// Revision 1.3  2001/09/14 19:28:37  vertigo
// no message
//
// Revision 1.2  2001/09/14 19:27:29  vertigo
// Made the CBmp class reference counted so that we can do things 
// like copying and still delete the handle to the bitmap when we 
// are done with it.
//
//====================================================================

#include "stdafx.h"
#include "Bmp.h"

//====================================================================
// Construction/Destruction
//====================================================================

//====================================================================
//  CBmp()
//====================================================================
CBmp::CBmp() : m_hBitmap( NULL ), m_pCount( NULL ) { }

//====================================================================
//  CBmp(const char *, bool)
//====================================================================
CBmp::CBmp( const char * name, bool file ) : m_hBitmap( NULL ), m_pCount( NULL )
{
    Load( name, file );
}

//====================================================================
//  CBmp(HBITMAP)
//====================================================================
CBmp::CBmp( HBITMAP hBmp ) : m_hBitmap( hBmp ), m_pCount( new int( 1 ) ) { }

//====================================================================
//  CBmp(const CBmp &)
//====================================================================
CBmp::CBmp( const CBmp & rhs ) : m_hBitmap( rhs.m_hBitmap ), m_pCount( rhs.m_pCount )
{
    if ( m_pCount )
    {
        ( *m_pCount )++;
    }
}

//====================================================================
//  ~CBmp()
//====================================================================
CBmp::~CBmp()
{
    Clear();
}

//====================================================================
// Operator Overloads
//====================================================================

//====================================================================
//  operator=(const CBmp &)
//====================================================================
CBmp & CBmp::operator=( const CBmp & rhs )
{
    if ( m_hBitmap == rhs.m_hBitmap )  return *this;
    Clear();
    m_hBitmap = rhs.m_hBitmap;
    m_pCount = rhs.m_pCount;
    ( *m_pCount )++;
    return *this;
}


//====================================================================
//  operator=(const HBITMAP &)
//====================================================================
CBmp & CBmp::operator=( const HBITMAP & rhs )
{
    if ( m_hBitmap == rhs ) return *this;
    Clear();
    m_hBitmap = rhs;
    m_pCount = new int( 1 );
    return *this;
}

//====================================================================
// Public Methods
//====================================================================

//====================================================================
//  Clear()
//====================================================================
void CBmp::Clear()
{
    // If there is a reference counter and it goes to zero,
    // delete the reference counter and the bitmap handle
    if ( m_pCount && ( --( *m_pCount ) == 0 ) )
    {
        delete m_pCount;
        if ( m_hBitmap )
            DeleteObject( m_hBitmap );
    }
    // Clear all references to the count and the bitmap handle
    m_pCount = NULL;
    m_hBitmap = NULL;
}


//====================================================================
//  Load(const char *, bool) 
//====================================================================
HBITMAP CBmp::Load( const char * name, bool file )
{
    Clear();

    if ( !name )
        return NULL;

    UINT flags = LR_CREATEDIBSECTION;
    if ( file )
        flags |= LR_LOADFROMFILE;
    m_hBitmap = ( HBITMAP )::LoadImage( AfxGetInstanceHandle(), name, IMAGE_BITMAP, 0, 0, flags );

    if ( m_hBitmap )
    {
        // Set the reference count to 1
        m_pCount = new int( 1 );
    }

    return m_hBitmap;
}

//====================================================================
//  Draw(HDC, int, int, int, int, int, int)
//====================================================================
bool CBmp::Draw( HDC hDC, int xOffset, int yOffset, int width, int height, int xSrc, int ySrc )
{
    if ( !m_hBitmap )
        return false;

    HDC memDC;
    BITMAP bmp;
    memDC = CreateCompatibleDC( hDC );
    SelectObject( memDC, m_hBitmap );
    GetObject( m_hBitmap, sizeof( bmp ), (LPSTR)&bmp );
    if ( width == 0 )
        width = bmp.bmWidth;
    if ( height == 0 )
        height = bmp.bmHeight;
    BitBlt( hDC, xOffset, yOffset, width, height, memDC, xSrc, ySrc, SRCCOPY );
    DeleteDC( memDC );

    return true;
}

//====================================================================
//  Attach(HBITMAP)
//====================================================================
void CBmp::Attach( HBITMAP hBmp )
{
    *this = hBmp;
}


//====================================================================
//  CBtnImage()
//====================================================================
CBmpStrip::CBmpStrip() : CBmp(), CRect() { }

//====================================================================
//  Draw(HDC hDC)
//====================================================================
bool CBmpStrip::Draw( HDC hDC, int xOffset, int yOffset )
{
    return CBmp::Draw( hDC, xOffset, yOffset, Width(), Height(), left, top );
}

//====================================================================
//  operator=(const CBmp & rhs)
//====================================================================
CBmpStrip & CBmpStrip::operator=( const CBmp & rhs )
{
    CBmp::operator =( rhs );
    SetPos( 0, 0, 0, 0 );
    return *this;
}

//====================================================================
//  SetPos(int x, int y, int w, int h)
//====================================================================
void CBmpStrip::SetPos( int x, int y, int w, int h )
{
    left = x;
    top = y;
    bottom = y + h;
    right = x + w;
}

//====================================================================
//  Attach(const CBmp & bmp, int x, int y, int w, int h)
//====================================================================
void CBmpStrip::Attach( const CBmp & bmp, int x, int y, int w, int h )
{
    *this = bmp;
    SetPos( x, y, w, h );
}