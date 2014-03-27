// FileVersion.h: interface for the CFileVersion class.
// by Manuel Laflamme
//////////////////////////////////////////////////////////////////////

#ifndef ALTERIDEM_FILEVERSION_H
#define ALTERIDEM_FILEVERSION_H

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

// Including this allows us to get the library version
// and forces the including project to link to the
// library
#ifndef BUILDING_LIBRARY
#include <Library.h>
#endif

class CFileVersion
{
    // Construction
public:
    CFileVersion();

    // Operations    
public:
    BOOL    Open( LPCTSTR lpszModuleName );
    void    Close();

    CString QueryValue( LPCTSTR lpszValueName, DWORD dwLangCharset = 0 );
    CString GetFileDescription()  { return QueryValue( _T( "FileDescription" ) ); };
    CString GetFileVersion()      { return QueryValue( _T( "FileVersion" ) ); };
    CString GetInternalName()     { return QueryValue( _T( "InternalName" ) ); };
    CString GetCompanyName()      { return QueryValue( _T( "CompanyName" ) ); };
    CString GetLegalCopyright()   { return QueryValue( _T( "LegalCopyright" ) ); };
    CString GetOriginalFilename() { return QueryValue( _T( "OriginalFilename" ) ); };
    CString GetProductName()      { return QueryValue( _T( "ProductName" ) ); };
    CString GetProductVersion()   { return QueryValue( _T( "ProductVersion" ) ); };

    BOOL    GetFixedInfo( VS_FIXEDFILEINFO& vsffi );
    CString GetFixedFileVersion();
    CString GetFixedProductVersion();

    // Attributes
protected:
    LPBYTE  m_lpVersionData;
    DWORD   m_dwLangCharset;

    // Implementation
public:
    ~CFileVersion();
};

#endif  