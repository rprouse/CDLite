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
    CRegistry(HKEY rootkey, LPCTSTR keyname);
    ~CRegistry();
    
    bool CreateKey(HKEY rootkey,LPCSTR key);
    bool DeleteKey(HKEY rootkey,LPCSTR keyname);
    bool OpenKey(HKEY rootkey,LPCSTR key);
    bool CloseKey();

    /// See if a key exists
    static bool Exists(HKEY rootkey, LPCSTR keyname);

    /// See if the subkey of an already open subkey exists
    bool Exists(LPCSTR keyname);

    bool SetDWORD(LPCSTR name,   DWORD   value);
    bool SetDWORD64(LPCSTR name, DWORD64 value);
    bool SetString(LPCSTR name,  LPSTR   value);
    bool SetString(LPCSTR name,  const CString & value);
    bool SetBinary(LPCSTR name,  BYTE *  value, DWORD len);

    bool SetValue(LPCSTR name, DWORD64 value);
    bool SetValue(LPCSTR name, DWORD   value);
    bool SetValue(LPCSTR name, LPSTR   value);
    bool SetValue(LPCSTR name, int     value);
    bool SetValue(LPCSTR name, const CString &value);

    DWORD   GetDWORD(  LPCSTR name, DWORD   defVal = 0);
    DWORD64 GetDWORD64(LPCSTR name, DWORD64 defVal = 0);
    CString GetString( LPCSTR name);
    DWORD   GetString( LPCSTR name, LPSTR string, DWORD len);
    DWORD   GetBinary( LPCSTR name, BYTE * value, DWORD len);

    bool GetValue(LPCSTR name, CString &value);
    bool GetValue(LPCSTR name, LPSTR    string,  int     len);
    bool GetValue(LPCSTR name, DWORD   *dword,   DWORD   defVal = 0);
    bool GetValue(LPCSTR name, DWORD64 *dword64, DWORD64 defVal = 0);
    bool GetValue(LPCSTR name, int     *dword,   int     defVal = 0);
    
    bool RemoveValue(LPCSTR name);
};

#endif
