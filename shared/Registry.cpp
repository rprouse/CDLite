#include "stdafx.h"
#include "Registry.h"
#include <stdexcept>

CRegistry::CRegistry() : m_hkey( NULL ) { }


CRegistry::CRegistry( HKEY rootkey, LPCWSTR keyname ) : m_hkey( NULL )
{
    if ( !OpenKey( rootkey, keyname ) && !CreateKey( rootkey, keyname ) )
        throw std::runtime_error( "Could not open or create registry key" );
}

CRegistry::~CRegistry()
{
    CloseKey();
}

bool CRegistry::CreateKey( HKEY rootkey, LPCWSTR keyname )
{
    //make sure no other key is open
    CloseKey();

    //open up the key for the email config info
    if ( RegCreateKey( rootkey, keyname, &m_hkey ) == ERROR_SUCCESS )
    {
        return true;
    }
    m_hkey = NULL;
    return false;
}

// Requires IE4 or later
bool CRegistry::DeleteKey( HKEY rootkey, LPCWSTR keyname )
{
    //make sure no other key is open
    CloseKey();

    //open up the key for the email config info
    return ( SHDeleteKey( rootkey, keyname ) == ERROR_SUCCESS );
}

bool CRegistry::OpenKey( HKEY rootkey, LPCWSTR keyname )
{
    //make sure no other key is open
    CloseKey();

    //open up the key for the email config info
    if ( RegOpenKey( rootkey, keyname, &m_hkey ) == ERROR_SUCCESS )
    {
        return true;
    }
    m_hkey = NULL;
    return false;
}

bool CRegistry::CloseKey()
{
    //close the key if it is open
    if ( m_hkey != NULL )
    {
        RegCloseKey( m_hkey );
        m_hkey = NULL;
    }
    return true;
}

bool CRegistry::Exists( HKEY rootkey, LPCWSTR keyname )
{
    HKEY temp;
    bool b = ( RegOpenKey( rootkey, keyname, &temp ) == ERROR_SUCCESS ) ? true : false;
    RegCloseKey( temp );
    return b;
}

bool CRegistry::Exists( LPCWSTR keyname )
{
    // Check that we have a key open
    if ( !m_hkey )
        return false;

    HKEY temp;
    bool b = ( RegOpenKey( m_hkey, keyname, &temp ) == ERROR_SUCCESS ) ? true : false;
    RegCloseKey( temp );
    return b;
}

bool CRegistry::SetValue( LPCWSTR name, DWORD value )
{
    return SetDWORD( name, value );
}

bool CRegistry::SetValue( LPCWSTR name, DWORD64 value )
{
    return SetDWORD64( name, value );
}

bool CRegistry::SetValue( LPCWSTR name, LPCWSTR value )
{
    return SetString( name, value );
}

bool CRegistry::SetValue( LPCWSTR name, int value )
{
    return SetDWORD( name, (DWORD)value );
}

bool CRegistry::SetValue( LPCWSTR name, const CString &value )
{
    return SetString( name, value );
}

bool CRegistry::GetValue( LPCWSTR name, CString &value )
{
    DWORD type;
    DWORD size = 0;

    //get the value
    if ( RegQueryValueEx( m_hkey, name, NULL, &type, NULL, &size ) != ERROR_SUCCESS || type != REG_SZ )
        return false;

    TCHAR *buff = new TCHAR[size/sizeof(TCHAR)];
    if ( !buff ) return false;

    if ( RegQueryValueEx( m_hkey, name, NULL, &type, (LPBYTE)buff, &size ) != ERROR_SUCCESS )
    {
        delete[] buff;
        return false;
    }

    value = buff;
    delete[] buff;
    return true;
}

bool CRegistry::GetValue( LPCWSTR name, LPWSTR string, int len )
{
    DWORD type;
    DWORD size = len;

    //get the value
    *string = '\0';
    return( RegQueryValueEx( m_hkey, name, NULL, &type, (LPBYTE)string, &size ) == ERROR_SUCCESS );
}

bool CRegistry::GetValue( LPCWSTR name, DWORD *dword, DWORD defVal )
{
    DWORD type;
    DWORD size = sizeof( DWORD );

    //get the value
    *dword = defVal;
    return( RegQueryValueEx( m_hkey, name, NULL, &type, (LPBYTE)dword, &size ) == ERROR_SUCCESS );
}

bool CRegistry::GetValue( LPCWSTR name, DWORD64 *dword64, DWORD64 defVal )
{
    DWORD type;
    DWORD size = sizeof( DWORD64 );

    //get the value
    *dword64 = defVal;
    return( RegQueryValueEx( m_hkey, name, NULL, &type, (LPBYTE)dword64, &size ) == ERROR_SUCCESS );
}

bool CRegistry::GetValue( LPCWSTR name, int *dword, int defVal )
{
    return GetValue( name, (DWORD *)dword, defVal );
}

bool CRegistry::RemoveValue( LPCWSTR name )
{
    return( RegDeleteValue( m_hkey, name ) == ERROR_SUCCESS );
}

bool CRegistry::SetDWORD( LPCWSTR name, DWORD value )
{
    return( RegSetValueEx( m_hkey, name, 0, REG_DWORD, (LPBYTE)&value, sizeof( DWORD ) ) == ERROR_SUCCESS );
}

bool CRegistry::SetDWORD64( LPCWSTR name, DWORD64 value )
{
    return( RegSetValueEx( m_hkey, name, 0, REG_BINARY, (LPBYTE)&value, sizeof( DWORD64 ) ) == ERROR_SUCCESS );
}

bool CRegistry::SetString( LPCWSTR name, LPCWSTR value )
{
    return( RegSetValueEx( m_hkey, name, 0, REG_SZ, (LPBYTE)value, ( lstrlen( value ) + 1 ) * sizeof( TCHAR ) ) == ERROR_SUCCESS );
}

bool CRegistry::SetString( LPCWSTR name, const CString & value )
{
    return( RegSetValueEx( m_hkey, name, 0, REG_SZ, (BYTE*)(LPCWSTR)value, ( value.GetLength() + 1 ) * sizeof( TCHAR ) ) == ERROR_SUCCESS );
}

bool CRegistry::SetBinary( LPCWSTR name, BYTE * value, DWORD len )
{
    return( RegSetValueEx( m_hkey, name, 0, REG_BINARY, value, len ) == ERROR_SUCCESS );
}

DWORD CRegistry::GetDWORD( LPCWSTR name, DWORD defVal )
{
    DWORD type;
    DWORD size = sizeof( DWORD64 );

    //get the value
    DWORD64 dword = defVal;
    if ( ( RegQueryValueEx( m_hkey, name, NULL, &type, (LPBYTE)&dword, &size ) != ERROR_SUCCESS ) || ( type != REG_DWORD ) )
        return defVal;
    return dword;
}

DWORD64 CRegistry::GetDWORD64( LPCWSTR name, DWORD64 defVal )
{
    DWORD type;
    DWORD size = sizeof( DWORD64 );

    //get the value
    DWORD64 dword64 = defVal;
    if ( ( RegQueryValueEx( m_hkey, name, NULL, &type, (LPBYTE)&dword64, &size ) != ERROR_SUCCESS ) || ( type != REG_BINARY ) )
        return defVal;
    return dword64;
}

DWORD CRegistry::GetString( LPCWSTR name, LPWSTR string, DWORD len )
{
    DWORD type;
    DWORD size = len;

    //get the value
    *string = '\0';
    if ( RegQueryValueEx( m_hkey, name, NULL, &type, (LPBYTE)string, &size ) != ERROR_SUCCESS )
        size = 0;

    return size;
}

CString CRegistry::GetString( LPCWSTR name )
{
    DWORD type;
    DWORD size = 0;
    CString temp;

    //get the value
    if ( RegQueryValueEx( m_hkey, name, NULL, &type, NULL, &size ) != ERROR_SUCCESS || type != REG_SZ )
        return temp;

    char *buff = new char[size];
    if ( !buff ) return temp;

    if ( RegQueryValueEx( m_hkey, name, NULL, NULL, (LPBYTE)buff, &size ) != ERROR_SUCCESS )
    {
        delete[] buff;
        return temp;
    }

    temp = buff;
    delete[] buff;
    return temp;
}

DWORD CRegistry::GetBinary( LPCWSTR name, BYTE * value, DWORD len )
{
    DWORD type;
    DWORD size = len;

    if ( RegQueryValueEx( m_hkey, name, NULL, &type, value, &size ) != ERROR_SUCCESS )
        size = 0;

    return size;
}

