// HoverButton.h : header file
//
//////////////////////////////////////////////////////////////////////
#ifndef ALTERIDEM_HOVERBUTTON_H
#define ALTERIDEM_HOVERBUTTON_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// Including this allows us to get the library version
// and forces the including project to link to the
// library
#ifndef BUILDING_LIBRARY
#include <Library.h>
#endif

#ifdef BUILDING_LIBRARY
#include "Bmp.h"
#else
#include <Bmp.h>
#endif

///
class CHoverButton : public CButton
{    
public:
    /// Constructor
    CHoverButton();
    /// Destructor
    virtual ~CHoverButton();

    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CHoverButton)

    virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
    //}}AFX_VIRTUAL
    
    /** Sets the offset of this buttons text.
    @param pixels Offset of the text from the left of the buttons edge. */    
    void SetTextOffset(UINT pixels);
    
    /** Sets the format of this buttons text.    
    @param format Format of the text. See CDC::DrawText for specifications. */
    void SetTextFormat(UINT format);
    
    /** Sets the font of this button.    
    @param fn Pointer to the CFont object to use */
    void SetFont(CFont * fn);
    
    /** Sets this button's bitmap when the mouse is not over it.    
    @param resource Resource name of the active bitmap
    @param file Set to true to load from a file, false to load from a resource
    @return true if loaded successfully */
    bool SetNormalBitmap(const char * name, bool file = false);
    
    /** Sets this button's bitmap when the mouse clicks on it.    
    @param resource Resource name of the active bitmap 
    @param file Set to true to load from a file, false to load from a resource
    @return true if loaded successfully */
    bool SetDepressedBitmap(const char * name, bool file = false);
    
    /** Sets this button's bitmap when the mouse is over it.    
    @param resource Resource name of the active bitmap 
    @param file Set to true to load from a file, false to load from a resource
    @return true if loaded successfully */
    bool SetHoverBitmap(const char * name, bool file = false);
    
    /** Sets this button's bitmap when the button is disabled.    
    @param resource Resource name of the active bitmap 
    @param file Set to true to load from a file, false to load from a resource
    @return true if loaded successfully */
    bool SetDisabledBitmap(const char * name, bool file = false);
    
    /** Sets this button's bitmap when the mouse is not over it.   
    @param bmp The bitmap which may be a larger skin bitmap or bitmap strip.  If
               you use the defaults for the remaining arguments, it is assumed to
	       be the full bitmap for the button.
    @param x The x coordinate within the bitmap where the button image starts
    @param y The y coordinate within the bitmap where the button image starts
    @param w The width of the button bitmap within the whole bitmap, 0 indicates the
             whole bitmap.
    @param h The height of the button bitmap within the whole bitmap, 0 indicates the
             whole bitmap.
    @return true if the bitmap passed in is valid */
    bool SetNormalBitmap(const CBmp & bmp, int x = 0, int y = 0, int w = 0, int h = 0);
    
    /** Sets this button's bitmap when the mouse clicks on it.  
    @param bmp The bitmap which may be a larger skin bitmap or bitmap strip.  If
               you use the defaults for the remaining arguments, it is assumed to
	       be the full bitmap for the button.
    @param x The x coordinate within the bitmap where the button image starts
    @param y The y coordinate within the bitmap where the button image starts
    @param w The width of the button bitmap within the whole bitmap, 0 indicates the
             whole bitmap.
    @param h The height of the button bitmap within the whole bitmap, 0 indicates the
             whole bitmap.
    @return true if the bitmap passed in is valid */
    bool SetDepressedBitmap(const CBmp & bmp, int x = 0, int y = 0, int w = 0, int h = 0);
    
    /** Sets this button's bitmap when the mouse is over it.   
    @param bmp The bitmap which may be a larger skin bitmap or bitmap strip.  If
               you use the defaults for the remaining arguments, it is assumed to
	       be the full bitmap for the button.
    @param x The x coordinate within the bitmap where the button image starts
    @param y The y coordinate within the bitmap where the button image starts
    @param w The width of the button bitmap within the whole bitmap, 0 indicates the
             whole bitmap.
    @param h The height of the button bitmap within the whole bitmap, 0 indicates the
             whole bitmap.
    @return true if the bitmap passed in is valid */
    bool SetHoverBitmap(const CBmp & bmp, int x = 0, int y = 0, int w = 0, int h = 0);
    
    /** Sets this button's bitmap when the button is disabled.  
    @param bmp The bitmap which may be a larger skin bitmap or bitmap strip.  If
               you use the defaults for the remaining arguments, it is assumed to
	       be the full bitmap for the button.
    @param x The x coordinate within the bitmap where the button image starts
    @param y The y coordinate within the bitmap where the button image starts
    @param w The width of the button bitmap within the whole bitmap, 0 indicates the
             whole bitmap.
    @param h The height of the button bitmap within the whole bitmap, 0 indicates the
             whole bitmap.
    @return true if the bitmap passed in is valid */
    bool SetDisabledBitmap(const CBmp & bmp, int x = 0, int y = 0, int w = 0, int h = 0);

    /** Sets all the button's state bitmaps from one bitmap strip
    @param bmp The bitmap strip with the normal, depressed, hover 
               and disabled buttons in a strip from left to right
    @param w   The width of each button, height is taken to be the 
               height of the bitmap
    @return true if the bitmap passed in is valid */
    bool SetButtonStrip(const CBmp & bmp, int w);

    /** Sets the palette of all buttons.    
    @param palette Pointer to a CPalette to use */
    static void SetPalette(CPalette * palette);
    
    /** Sets the resource name of the mouse over sound.    
    @param resource Resource name of the sound*/
    static void SetMouseOverSound(const char * resource);
    
    /** Sets the resource name of the click sound.    
    @param resource Name of the sound resource */
    static void SetClickSound(const char * resource);
    
    /** Sets the colour of the text shadow.    
    @param crColor COLORREF structure of the text shadow. */
    void SetTextShadowColor( COLORREF crColor );
    
    /** Sets the colour of the highlighted text.    
    @param crColor COLORREF structure of the text highlight */
    void SetTextHighlightColor( COLORREF crColor );
    
    /** Sets the colour of the text.    
    @param crColor COLORREF structure of the standard text */
    void SetTextColor( COLORREF crColor );
    
    /** Sets the colour of the disabled text.    
    @param crColor COLORREF structure of the standard text */
    void SetDisabledTextColor( COLORREF crColor );
    
    // Generated message map functions
protected:
    CHoverButton(CHoverButton &dontCopy){}    // Protected to prevent use

    static bool AntiAliasedText(HDC hDC, const int& nXStart, const int& nYStart, const char * lpString);

    void UpdateParent();

    bool    bFirstThrough;
    bool    bMouseOver;
    UINT    textFormat;
    UINT    offset;
    CFont * font;

    CBmpStrip bmNormal;
    CBmpStrip bmDepressed;
    CBmpStrip bmHover;
    CBmpStrip bmDisabled;

    static CPalette *cPalette;
    static CString   clickSound;
    static CString   mouseOverSound;

    COLORREF textColour;
    COLORREF textHighlightColour;
    COLORREF textShadowColour;
    COLORREF textDisabledColour;

    //{{AFX_MSG(CHoverButton)
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
    //}}AFX_MSG
    
    DECLARE_MESSAGE_MAP()
private:
    bool bDontPlay;   // This is just used to prevent the mouseover sound from playing on a mouse click
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif 
