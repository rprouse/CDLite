// Library.cpp: implementation of the CLibrary class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Library.h"
#include "AutoBuild.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

// Constructs it with the AutoBuild.h version numbers
CLibrary::CLibrary() : CVersion(FILEVER) { }
