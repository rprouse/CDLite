// Version.h
//
//////////////////////////////////////////////////////////////////////
#ifndef ALTERIDEM_VERSION_H
#define ALTERIDEM_VERSION_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// Including this allows us to get the library version
// and forces the including project to link to the
// library
#ifndef BUILDING_LIBRARY
#include <Library.h>
#endif


class CVersion  
{    
public:
    CVersion(WORD major = 1, WORD minor = 0, WORD increment = 0, WORD build = 0);
    CVersion(const CString&);
    CVersion(const CVersion & rhs);
    virtual ~CVersion();
    
    operator CString() const;
    
    CVersion& operator=(const CString  & rhs);
    CVersion& operator=(const CVersion & rhs);

    bool operator>(const CVersion& rhs) const;
    
    WORD Major(void) const;
    WORD Minor(void) const;
    WORD Increment(void) const;
    WORD Build(void) const;

    CString StringValue() const;
    CString ShortStringValue() const;   

    int Convert(const CString&);

protected:
    WORD nMajor, nMinor, nIncrement, nBuild; 
};

#endif 
