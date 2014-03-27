/////////////////////////////////////////////////////////////////////////////
// CBmpDlg dialog
//
//////////////////////////////////////////////////////////////////////
#ifndef ALTERIDEM_BMPDLG_H
#define ALTERIDEM_BMPDLG_H

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

class CBmpDlg : public CDialog
{
public:
    CBmpDlg();
    CBmpDlg(LPCTSTR lpszTemplateName, CWnd* pParentWnd = NULL );
    CBmpDlg(UINT nIDTemplate, CWnd* pParentWnd = NULL );
    virtual ~CBmpDlg();
    
    /**
     * Loads a background bitmap from a file or a resource
     * @param name the name of the file or resource
     * @param file true to load from a file, false to load from a resource
     * @return true if successful
     **/
    bool LoadBackground(LPCTSTR lpszName, bool bFromFile = false);

    /**
     * Sets the background to a CBmp object  
     * @param bmp The bitmap which may be a larger skin bitmap or bitmap strip.  If
     *            you use the defaults for the remaining arguments, it is assumed to
     * 	       be the full bitmap for the button.
     * @param x The x coordinate within the bitmap where the button image starts
     * @param y The y coordinate within the bitmap where the button image starts
     * @param w The width of the button bitmap within the whole bitmap, 0 indicates the
     *          whole bitmap.
     * @param h The height of the button bitmap within the whole bitmap, 0 indicates the
     *          whole bitmap.
     * @return true if the bitmap passed in is valid 
     **/
    bool SetBackground(const CBmp & bmp, int x = 0, int y = 0, int w = 0, int h = 0);

    DECLARE_DYNAMIC(CBmpDlg)
protected:
    //{{AFX_MSG(CBmpDlg)
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
    afx_msg void OnPaint();
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()

    bool	m_bMoving;
    CPoint	m_MoveOffset;
    CBmpStrip	hBackground;
};

#endif