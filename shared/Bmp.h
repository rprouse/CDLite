// Bmp.h: interface for the CBmp class.
//
//////////////////////////////////////////////////////////////////////

#ifndef ALTERIDEM_BMP_H
#define ALTERIDEM_BMP_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// Including this allows us to get the library version
// and forces the including project to link to the
// library
#ifndef BUILDING_LIBRARY
#include <win/Library.h>
#endif

class CBmp  
{
protected:
    HBITMAP m_hBitmap;	// Handle to the bitmap
    int *   m_pCount;	// Reference count, how many objects are pointing to this handle

public:
    /**
     * Constructs an empty bitmap, fill it with the Load member function
     **/
    CBmp();

    /**
     * Constructs a bitmap from a file or a resource
     * @param name the name of the file or resource
     * @param file true to load from a file, false to load from a resource
     **/
    CBmp(const char * name, bool file = false);

    /**
     * Construct from a bitmap handle
     * @warning This class will take responsibility for the bitmap and delete it
     *          when the class is destroyed and the reference count goes to 0
     * @param the bitmap handle to attach to
     **/
    CBmp(HBITMAP hBmp);

    /**
     * Copy constructor
     **/
    CBmp(const CBmp & rhs);

    /**
     * Destructor
     **/
    virtual ~CBmp();

    /**
     * Operator = CBmp
     **/
    CBmp & operator=(const CBmp & rhs);

    /**
     * Operator = HBITMAP
     * @warning This class will take responsibility for the bitmap and delete it
     *          when the class is destroyed and the reference count goes to 0
     **/
    CBmp & operator=(const HBITMAP & rhs);

    /**
     * Loads a bitmap from a file or a resource
     * @param name the name of the file or resource
     * @param file true to load from a file, false to load from a resource
     * @return the handle to the loaded bitmap, NULL on failure
     **/
    HBITMAP Load(const char * name, bool file = false);

    /**
     * Draws the bitmap to the screen
     * @param hDC The HDC to draw to
     * @param xOffset the X offset to draw the bitmap to on the screen
     * @param yOffset the Y offset to draw the bitmap to on the screen
     * @param width the width of the bitmap to draw, if 0, will draw full width
     * @param height the height of the bitmap to draw, if 0, will draw full height
     * @param xSrc Used for image strips, the x coordinate in the bitmap to draw from
     * @param ySrc Used for image strips, the y coordinate in the bitmap to draw from
     * @return true if drawn, false if failed (probably because bitmap is not loaded)
     **/
    bool Draw(HDC hDC, int xOffset = 0, int yOffset = 0, int width = 0, int height = 0, int xSrc = 0, int ySrc = 0);

    /**
     * Clears the bitmap from the object ready to load a new one
     **/
    void Clear();

    /**
     * @return the handle to the bitmap that the class contains
     */
    operator HBITMAP() { return m_hBitmap; }

    /**
     * @return true if the class holds a valid bitmap handle
     */
    operator bool() { return (m_hBitmap ? true : false); }
    
    /**
     * Attach to an HBITMAP
     * @warning This class will take responsibility for the bitmap and delete it
     *          when the class is destroyed and the reference count goes to 0
     **/
    void Attach(HBITMAP hBmp);
};

/// A class to bind the position within an image strip to the image when necessary
class CBmpStrip : public CBmp, public CRect
{
public:
    /// Constructor
    CBmpStrip();

    /**
     * Draws the bitmap to the screen using the x, y, w, h parameters.
     * @param hDC The HDC to draw to
     * @param xOffset the X offset to draw the bitmap to on the screen
     * @param yOffset the Y offset to draw the bitmap to on the screen
     * @return true if drawn, false if failed (probably because bitmap is not loaded)
     **/
    bool Draw(HDC hDC, int xOffset = 0, int yOffset = 0);

    /// Allow copying from the parent class
    CBmpStrip & operator=(const CBmp & rhs);

    /// Set the x, y, width, and height parameters.
    void SetPos(int x, int y, int w, int h);

    /// Attach to the specified bitmap
    void Attach(const CBmp & bmp, int x, int y, int w, int h);
private:

};
#endif
