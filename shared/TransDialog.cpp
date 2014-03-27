// CTransDialog.cpp: implementation of the CTransDialog class.
//
// A base class to be used to create a transparent dialog.
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TransDialog.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTransDialog::CTransDialog() : FirstRun(true), hBackground(NULL), hMask(NULL)
{    
    size.cx = size.cy = 0;    
}

//////////////////////////////////////////////////////////////////////
//  Setup the windows Region
//  The windows region controls what the OS will draw in reguards to the window
//  The loop below will search for the "magic color" and add it to a region
//  then Xor the region and assign it to the window and viola.
//////////////////////////////////////////////////////////////////////
void CTransDialog::SetupBk(HWND hWnd, HDC hdc)
{
    TransparentBlt(hdc , 0, 0, size.cx, size.cy, hMask, 0, 0, NULL);   
    
    //Only do this once because it takes some time.
    //maybe should pre-make a seperate file to hold region data?
    if (FirstRun){
	int Set = 0;
	//begin pixel by pixel scan for transparent color
	for(int X = 0; X <= size.cx; X++){
	    for(int Y = 0; Y <= size.cy; Y++){
		COLORREF C = GetPixel(hdc, X, Y);
		//Get the color
		if(C == 0x00FFFFFF){
		    if(Set == 0){
			//First, init the working region 
			//never delete Working, the OS does not store the value, only a pointer to it.
			Working = CreateRectRgn(X, Y, X+1, Y+1);
			Set = 1;
		    }
		    else{
			Temp = CreateRectRgn(X, Y, X+1, Y+1);
			//Add pixel to region
			CombineRgn(Working, Working, Temp, RGN_OR);
			DeleteObject(Temp);
		    }
		}
	    }
	}
	FirstRun = false;
	Temp = CreateRectRgn(0,0,1200,1200);
	//flip to get the non-transparent region
	CombineRgn(Working, Working, Temp, RGN_XOR);
	DeleteObject(Temp);
	if (Set) SetWindowRgn(hWnd, (HRGN)Working, TRUE);
	//redraw just in case.. trust me.. leave this here
	RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE);
    }
}

//////////////////////////////////////////////////////////////////////
// From Codeguru.. by Zafir Anjum, the transparency here is overkill, 
// SetupBk() will take care of the transparency that we are dealing with
// Converted from MFC to WIN32 SDK by Rob Prouse, 30 Sept 99
// Pass in a black and white mask bitmap with the white to be transparent.
//////////////////////////////////////////////////////////////////////
void CTransDialog::TransparentBlt( HDC dc, int nXDest, int nYDest, int nWidth, 
				 int nHeight, HBITMAP hMaskBitmap, int nXSrc, 
				 int nYSrc, HPALETTE hPal)
{
    HDC memDC, maskDC, tempDC;
    maskDC = CreateCompatibleDC(dc);
    HBITMAP maskBitmap;
    
    //add these to store return of SelectObject() calls
    HBITMAP hOldMemBmp  = NULL;
    HBITMAP hOldMaskBmp = NULL;
    HBITMAP hOldTempBmp = NULL;
    
    memDC  = CreateCompatibleDC(dc);
    tempDC = CreateCompatibleDC(dc);
    HBITMAP bmpImage;
    bmpImage = CreateCompatibleBitmap(dc, nWidth, nHeight);
    hOldMemBmp = (HBITMAP)SelectObject(memDC, (HGDIOBJ)bmpImage);
    
    // Select and realize the palette
    if( GetDeviceCaps(dc, RASTERCAPS) & RC_PALETTE && hPal )
    {
	SelectPalette(dc, hPal, FALSE);
	RealizePalette(dc);		
	SelectPalette(memDC, hPal, FALSE);
    }
    
    hOldTempBmp = (HBITMAP) SelectObject(tempDC, hMaskBitmap);
    
    BitBlt(memDC, 0, 0, nWidth, nHeight, tempDC, nXSrc, nYSrc, SRCCOPY);
    
    // Create monochrome bitmap for the mask
    maskBitmap = CreateBitmap(nWidth, nHeight, 1, 1, NULL);
    hOldMaskBmp = (HBITMAP)SelectObject(maskDC, maskBitmap);
    SetBkColor(memDC, RGB(0,0,0));
    
    // Create the mask from the memory DC
    BitBlt(maskDC, 0, 0, nWidth, nHeight, memDC, 0, 0, SRCCOPY);
    
    // Set the background in memDC to black. Using SRCPAINT with black 
    // and any other color results in the other color, thus making 
    // black the transparent color
    SetBkColor(memDC, RGB(0,0,0));
    SetTextColor(memDC, RGB(255,255,255));
    BitBlt(memDC, 0, 0, nWidth, nHeight, maskDC, 0, 0, SRCAND);
    
    // Set the foreground to black. See comment above.
    SetBkColor(dc, RGB(255,255,255));
    SetTextColor(dc, RGB(0,0,0));
    BitBlt(dc, nXDest, nYDest, nWidth, nHeight, maskDC, 0, 0, SRCAND);
    
    // Combine the foreground with the background
    BitBlt(dc, nXDest, nYDest, nWidth, nHeight, memDC, 0, 0, SRCPAINT);
    
    if (hOldTempBmp)
	SelectObject(tempDC, hOldTempBmp);
    if (hOldMaskBmp)
	SelectObject(maskDC, hOldMaskBmp);
    if (hOldMemBmp)
	SelectObject(memDC, hOldMemBmp );
    DeleteDC(maskDC);
    DeleteDC(tempDC);
    DeleteDC(memDC);
    DeleteObject(bmpImage);
    DeleteObject(maskBitmap);    
}