// Library.h: interface for the CLibrary class.
//
//////////////////////////////////////////////////////////////////////

#ifndef ALTERIDEM_LIBRARY_H
#define ALTERIDEM_LIBRARY_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// Force the inclusion of this library (and the required
// shlwapi library)
#ifndef BUILDING_LIBRARY
#  pragma comment(lib, "shlwapi.lib")
#  pragma comment(lib, "version.lib")
#  ifdef _DEBUG
#    pragma comment(lib, "altwin_d.lib")
#  else
#    pragma comment(lib, "altwin.lib")
#  endif
#endif

#ifdef BUILDING_LIBRARY
#include "Version.h"
#else
#include <win/Version.h>
#endif

class CLibrary : public CVersion  
{
public:
    CLibrary();
};

#endif // !defined(ALTERIDEM_LIBRARY_H__)
