// BmpDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ShadeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNAMIC(CShadeDlg, CDialog)

BEGIN_MESSAGE_MAP(CShadeDlg, CDialog)
//{{AFX_MSG_MAP(CShadeDlg)
ON_WM_LBUTTONDOWN()
ON_WM_ERASEBKGND()
ON_WM_PAINT()
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CShadeDlg::CShadeDlg() : 
    CDialog(), m_Border(1) { }

CShadeDlg::CShadeDlg(LPCTSTR lpszTemplateName, CWnd* pParentWnd) : 
    CDialog(lpszTemplateName, pParentWnd), m_Border(1) { }

CShadeDlg::CShadeDlg(UINT nIDTemplate, CWnd* pParentWnd) : 
    CDialog(nIDTemplate, pParentWnd), m_Border(1) { }

CShadeDlg::~CShadeDlg() { }

BOOL CShadeDlg::OnEraseBkgnd(CDC* pDC) 
{
    return 1;   // don't erase the dialog background
}

void CShadeDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
    // This simulates clicking on the titlebar so windows will 
    // handle moving of the dialog
    SendMessage(WM_SYSCOMMAND, SC_MOVE | 0x02, 0L);

    CDialog::OnLButtonDown(nFlags, point);
}

/////////////////////////////////////////////////////////////////////////////
void CShadeDlg::OnPaint()  
{
    CPaintDC dc(this); // device context for painting
    CRect r;
    GetWindowRect(&r);
    r.right  -= r.left;
    r.bottom -= r.top;
    r.left    = 0;
    r.top     = 0;
    
    if(!m_dActive.IsValid())
        // no skin selected for disabled state -> standard button
        dc.FillSolidRect(&r,GetSysColor(COLOR_BTNFACE));
    else // paint the skin
        m_dActive.Draw(dc.GetSafeHdc(),0,0);
    // if needed, draw the standard 3D rectangular border
    if (m_Border) dc.DrawEdge(&r,EDGE_RAISED,BF_RECT);
}

//////////////////////////////////////////////////////////////////////////////////////////////////
// Much of this code is modified from Davide Pizzolato's CxShadeButton class
// since this class is designed to mimic it's look and behaviour.  CxShadeButton
// is available on CodeProject at http://www.codeproject.com/buttonctrl/cxshadebutton.asp
/////////////////////////////////////////////////////////////////////////////////////////////////
void CShadeDlg::SetShade(UINT shadeID,BYTE granularity,BYTE highlight,BYTE coloring,COLORREF color)
{
    long        sXSize,sYSize,bytes,j,i,k,h;
    BYTE        *iDst ,*posDst;
    
    RECT rect;
    GetWindowRect(&rect);
    sYSize=rect.bottom-rect.top;
    sXSize=rect.right-rect.left ;
        
    m_dActive.Create(sXSize, sYSize, 8);        //create the Active bitmap
    
    COLORREF hicr=GetSysColor(COLOR_BTNHIGHLIGHT);      //get the button base colors
    COLORREF midcr=GetSysColor(COLOR_BTNFACE);
    COLORREF locr=GetSysColor(COLOR_BTNSHADOW);
    long r,g,b;                                                                                 //build the shaded palette
    for(i=0;i<129;i++)
    {
        r = ((128 - i) * GetRValue(locr) + i * GetRValue(midcr)) / 128;
        g = ((128 - i) * GetGValue(locr) + i * GetGValue(midcr)) / 128;
        b = ((128 - i) * GetBValue(locr) + i * GetBValue(midcr)) / 128;
        m_dActive.SetPaletteIndex((BYTE)i,(BYTE)r,(BYTE)g,(BYTE)b);
    }
    for(i=1;i<129;i++){
        r=((128 - i) * GetRValue(midcr) + i * GetRValue(hicr)) / 128;
        g=((128 - i) * GetGValue(midcr) + i * GetGValue(hicr)) / 128;
        b=((128 - i) * GetBValue(midcr) + i * GetBValue(hicr)) / 128;
        m_dActive.SetPaletteIndex((BYTE)(i+127),(BYTE)r,(BYTE)g,(BYTE)b);
    }
    
    m_dActive.BlendPalette(color,coloring);     //color the palette
    
    bytes  = m_dActive.GetLineWidth();
    iDst   = m_dActive.GetBits();
    posDst = iDst;
    long a, x, y, d, xs, idxmax, idxmin;
    
    int grainx2 = RAND_MAX / (max(1, 2 * granularity));
    idxmax      = 255-granularity;
    idxmin      = granularity;
    
    switch(shadeID)
    {
        //----------------------------------------------------
    case SHS_METAL:
        m_dActive.Clear();
        // create the strokes
        k = 40; //stroke granularity
        for(a = 0; a < 200; ++a)
        {
            x  = rand() / (RAND_MAX / sXSize);                      //stroke postion
            y  = rand() / (RAND_MAX / sYSize);                      //stroke position
            xs = rand() / (RAND_MAX / min(sXSize, sYSize)) / 2;     //stroke lenght
            d  = rand() / (RAND_MAX / k);                           //stroke color
            for(i=0;i<xs;i++)
            {
                if (((x - i) > 0) && ((y + i) < sYSize))
                    m_dActive.SetPixelIndex(x - i,y + i,(BYTE)d);
                if (((x + i) < sXSize) && ((y - i) > 0))
                    m_dActive.SetPixelIndex(sXSize - x + i, y - i,(BYTE)d);
            }
        }
        //blend strokes with SHS_DIAGONAL
        posDst = iDst;
        a = (idxmax - idxmin - k) / 2;
        for(i = 0; i < sYSize; ++i) 
        {
            for(j = 0; j < sXSize; ++j) 
            {
                d = posDst[j] + ((a * i) / sYSize + (a * (sXSize - j)) / sXSize);
                posDst[j]  = (BYTE)d;
                posDst[j] += rand() / grainx2;
            }
            posDst += bytes;
        }       
        break;
        //----------------------------------------------------
    case SHS_HARDBUMP:
        //set horizontal bump
        for(i = 0; i < sYSize; ++i) 
        {
            k = (255 * i / sYSize) - 127;
            k = (k * (k * k) / 128) / 128;
            k = (k * (128 - granularity)) / 128 + 128;
            for(j = 0; j < sXSize; ++j) 
            {
                posDst[j]  = (BYTE)k;
                posDst[j] += rand() / grainx2 - granularity;
            }
            posDst+=bytes;
        }
        //set vertical bump
        d = min(16, sXSize / 6);        //max edge=16
        a = sYSize * sYSize / 4;
        posDst = iDst;
        for(i = 0; i < sYSize; ++i) 
        {
            y=i-sYSize/2;
            for(j = 0; j < sXSize; ++j) 
            {
                x  = j - sXSize / 2;
                xs = sXSize / 2 - d + (y * y * d) / a;
                if (x > xs) 
                    posDst[j] = idxmin + (BYTE)(((sXSize - j) * 128) / d);
                if ((x + xs) < 0) 
                    posDst[j] = idxmax - (BYTE)((j * 128) / d);
                posDst[j] += rand() / grainx2 - granularity;
            }
            posDst += bytes;
        }
        break;
        //----------------------------------------------------
    case SHS_SOFTBUMP:
        for(i = 0; i < sYSize; ++i) 
        {
            h = (255 * i / sYSize) - 127;
            for(j = 0; j < sXSize; ++j) 
            {
                k = (255 * (sXSize - j) / sXSize) - 127;
                k = (h * (h * h) / 128) / 128 + (k * (k * k) / 128) / 128;
                k = k * (128 - granularity) / 128 + 128;
                if (k < idxmin) k = idxmin;
                if (k > idxmax) k = idxmax;
                posDst[j]  = (BYTE)k;
                posDst[j] += rand() / grainx2 - granularity;
            }
            posDst += bytes;
        }
        break;
        //----------------------------------------------------
    case SHS_VBUMP:
        for(j = 0; j < sXSize; ++j) 
        {
            k = (255 * (sXSize - j) / sXSize) - 127;
            k = (k * (k * k) / 128) / 128;
            k = (k * (128 - granularity)) / 128 + 128;
            for(i = 0; i < sYSize; ++i)  
            {
                posDst[j + i * bytes]  = (BYTE)k;
                posDst[j + i * bytes] += rand() / grainx2 - granularity;
            }
        }
        break;
        //----------------------------------------------------
    case SHS_HBUMP:
        for(i = 0; i < sYSize; ++i) 
        {
            k = (255 * i / sYSize) - 127;
            k = (k * (k * k) / 128) / 128;
            k = (k * (128 - granularity)) / 128 + 128;
            for(j = 0; j < sXSize; ++j) 
            {
                posDst[j]  = (BYTE)k;
                posDst[j] += rand() / grainx2 - granularity;
            }
            posDst += bytes;
        }
        break;
        //----------------------------------------------------
    case SHS_DIAGSHADE:
        a=(idxmax-idxmin)/2;
        for(i = 0; i < sYSize; ++i) 
        {
            for(j = 0; j < sXSize; ++j) 
            {
                posDst[j]  = (BYTE)(idxmin + a * i / sYSize + a * (sXSize - j) / sXSize);
                posDst[j] += rand() / grainx2 - granularity;
            }
            posDst+=bytes;
        }
        break;
        //----------------------------------------------------
    case SHS_HSHADE:
        a = idxmax - idxmin;
        for(i = 0; i < sYSize; ++i) 
        {
            k = a * i / sYSize + idxmin;
            for(j = 0; j < sXSize; j++) 
            {
                posDst[j]  = (BYTE)k;
                posDst[j] += rand() / grainx2 - granularity;
            }
            posDst += bytes;
        }
        break;
        //----------------------------------------------------
    case SHS_VSHADE:
        a = idxmax - idxmin;
        for(j = 0; j < sXSize; ++j) 
        {
            k = a * (sXSize - j) / sXSize + idxmin;
            for(i = 0; i < sYSize; ++i) 
            {
                posDst[j + i * bytes]  = (BYTE)k;
                posDst[j + i * bytes] += rand() / grainx2 - granularity;
            }
        }
        break;
        //----------------------------------------------------
    case SHS_NOISE:
    default:
        for(i = 0; i < sYSize; ++i) 
        {
            for(j = 0; j < sXSize; ++j) 
            {
                posDst[j] = 128 + rand() / grainx2 - granularity;
            }
            posDst += bytes;
        }
    }
}
