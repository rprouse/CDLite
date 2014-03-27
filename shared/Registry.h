// Registry.h
//
//////////////////////////////////////////////////////////////////////
#ifndef ALTERIDEM_REGISTRY_H
#define ALTERIDEM_REGISTRY_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// Including this allows us to get the library version
// and forces the including project to link to the
// library
#ifndef BUILDING_LIBRARY
#include <Library.h>
#endif

/**
 \note Internet Explorer 4.0+ is required and you must link to shlwapi.lib to use this class
 **/
class CRegistry
{
private:
    HKEY m_hkey;

public:
    CRegistry();
    CRegistry( HKEY rootkey, LPCWSTR keyname );
    ~CRegistry();

    bool CreateKey( HKEY rootkey, LPCWSTR key );
    bool DeleteKey( HKEY rootkey, LPCWSTR keyname );
    bool OpenKey( HKEY rootkey, LPCWSTR key );
    bool CloseKey();

    /// See if a key exists
    static bool Exists( HKEY rootkey, LPCWSTR keyname );

    /// See if the subkey of an already open subkey exists
    bool Exists( LPCWSTR keyname );

    bool SetDWORD( LPCWSTR name, DWORD   value );
    bool SetDWORD64( LPCWSTR name, DWORD64 value );
    bool SetString( LPCWSTR name, LPCWSTR   value );
    bool SetString( LPCWSTR name, const CString & value );
    bool SetBinary( LPCWSTR name, BYTE *  value, DWORD len );

    bool SetValue( LPCWSTR name, DWORD64 value );
    bool SetValue( LPCWSTR name, DWORD   value );
    bool SetValue( LPCWSTR name, LPCWSTR   value );
    bool SetValue( LPCWSTR name, int     value );
    bool SetValue( LPCWSTR name, const CString &value );

    DWORD   GetDWORD( LPCWSTR name, DWORD   defVal = 0 );
    DWORD64 GetDWORD64( LPCWSTR name, DWORD64 defVal = 0 );
    CString GetString( LPCWSTR name );
    DWORD   GetString( LPCWSTR name, LPWSTR string, DWORD len );
    DWORD   GetBinary( LPCWSTR name, BYTE * value, DWORD len );

    bool GetValue( LPCWSTR name, CString &value );
    bool GetValue( LPCWSTR name, LPWSTR  string, int       len );
    bool GetValue( LPCWSTR name, DWORD   *dword, DWORD     defVal = 0 );
    bool GetValue( LPCWSTR name, DWORD64 *dword64, DWORD64 defVal = 0 );
    bool GetValue( LPCWSTR name, int     *dword, int       defVal = 0 );

    bool RemoveValue( LPCWSTR name );
};

#endif
