// Picture.h: interface for the CPicture class.
//
//////////////////////////////////////////////////////////////////////

#ifndef ALTERIDEM_PICTURE_H
#define ALTERIDEM_PICTURE_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXDTCTL_H__
#pragma message("WARNING:  You must include afxdtctl.h before including picture.h, probably in your stdafx.h")
#endif

// Including this allows us to get the library version
// and forces the including project to link to the
// library
#ifndef BUILDING_LIBRARY
#include <Library.h>
#endif

class CPicture  
{
public:
    CPicture();
    virtual ~CPicture();
    
    bool  Load(CString sResourceType, CString sResource);
    bool  Load(CString sFileName);
    bool  Draw(CDC* pDC);
    bool  Draw(CDC* pDC, CPoint Pos);
    bool  Draw(CDC* pDC, CPoint Pos, CSize Size);
    bool  Draw(CDC* pDC, double nSizeRatio);
    bool  Draw(CDC* pDC, CPoint Pos, double nSizeRatio);
    CSize GetSize(CDC* pDC);
    void  UnLoad();

private:
    static bool GetResource(LPSTR lpName, LPSTR lpType, void* pResource, int& nBufSize);
    bool  LoadFromBuffer(BYTE* pBuff, int nSize);
    bool  Draw(CDC* pDC, int x, int y, int cx, int cy);
    IPicture * m_pPicture;
    enum
    {
	HIMETRIC_INCH	= 2540
    };
};

#endif // !defined(AFX_PICTURE_H__6098A4C3_D6D5_4711_BC7B_1595F459B480__INCLUDED_)
