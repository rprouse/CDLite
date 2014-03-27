// TransDialog.h
//
//////////////////////////////////////////////////////////////////////
#ifndef ALTERIDEM_TRANSDIALOG_H
#define ALTERIDEM_TRANSDIALOG_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// Including this allows us to get the library version
// and forces the including project to link to the
// library
#ifndef BUILDING_LIBRARY
#include <Library.h>
#endif

/** Creates a transparent dialog from a bitmap

    18 Oct 99 - Robert Prouse
  
    New base class for creating a transparent dialog.  Just derive your
    dialog class from this, set the size, background and black&white mask
    and you're set.  All you have to do then is call the SetupBk method in
    your paint method.  Don't forget to draw the background though!
    To do this, use code similar to the following;
    
	void MainWindow::Paint() 
	{
	    PAINTSTRUCT ps;
	    HDC hDC = BeginPaint(hWnd, &ps);
	    SetupBk(hWnd, hDC);
	    if (!bMinimized) 
	    {
		SelectPalette(hDC, hPalette, 0);
		RealizePalette(hDC);
		XSDraw::Bitmap(hDC, hBackground, 0, 0);
	    }
	    EndPaint(hWnd, &ps);
	}
*/
class CTransDialog  
{
public:
	/// Sets the mask of the bitmap
	void SetMask(HBITMAP hMsk) { hMask = hMsk; FirstRun = true; }
	/// Sets the background image to use
	void SetBackground(HBITMAP hBack) { hBackground = hBack; }
	/// Sets the size of the bitmap
	void SetSize(SIZE & s) { size.cx = s.cx; size.cy = s.cy; }
	/// Sets the size of the bitmap
	void SetSize(int x, int y) { size.cx = x; size.cy = y; }
	/// Constructor
	CTransDialog();
	
	/// Creates the region
	virtual void SetupBk(HWND hWnd, HDC hdc); 
	/// Commits a transparent bit using the mask
	void TransparentBlt( HDC dc, int nXDest, int nYDest, int nWidth, 
		int nHeight, HBITMAP hMaskBitmap, int nXSrc, int nYSrc, HPALETTE hPal );
	
	/// Indicated this instances first run
	bool FirstRun;
	
	/// Size of the image
	SIZE size;
	
	/// Background image
	HBITMAP hBackground;
	
	/// Mask for the background
	HBITMAP hMask;
private:
	
	/// A working region of the transparency
	HRGN Working;
	
	/// Storeage to work with
	HRGN Temp;
};

#endif 