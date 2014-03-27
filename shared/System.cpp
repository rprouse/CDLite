// System.cpp: implementation of the CSystem class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "System.h"

#include <io.h>
#include <direct.h>

CString CSystem::ProgramPath( bool withFilename )
{
    char root[MAX_PATH];
    if ( GetModuleFileName( NULL, root, MAX_PATH ) != 0 && !withFilename )
        *( strrchr( root, '\\' ) + 1 ) = '\0';

    return root;
}

CString CSystem::WindowsDirectory( void )
{
    char dir[MAX_PATH];
    GetWindowsDirectory( dir, MAX_PATH );
    return CString( dir ) + "\\";
}

CString CSystem::CurrentDirectory( void )
{
    char dir[MAX_PATH];
    GetCurrentDirectory( MAX_PATH, dir );
    return CString( dir ) + "\\";
}

CString CSystem::SystemDirectory( void )
{
    char dir[MAX_PATH];
    GetSystemDirectory( dir, MAX_PATH );
    return CString( dir ) + "\\";
}

CString CSystem::TemporaryFilename( const char * prefix )
{
    char filename[MAX_PATH];
    GetTempFileName( TemporaryPath(), prefix, 0, filename );
    return filename;
}

CString CSystem::TemporaryPath( void )
{
    char path[MAX_PATH];
    GetTempPath( MAX_PATH, path );
    return path;
}

bool CSystem::IsFileLocked( const char * filename )
{
    // Does the file exist
    HANDLE handle = CreateFile( filename, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL );
    if ( handle != INVALID_HANDLE_VALUE || GetLastError() != ERROR_FILE_NOT_FOUND )
    {
        CloseHandle( handle );

        // Check for write access
        handle = CreateFile( filename, GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL );
        if ( handle == INVALID_HANDLE_VALUE )
            return true;    // We did not get the handle, so file is locked

        CloseHandle( handle );
    }
    return false;
}

void CSystem::Reboot( void )
{
    HANDLE hToken;

    // Get a token for this process.     
    if ( OpenProcessToken( GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken ) )
    {
        TOKEN_PRIVILEGES tkp;

        // Get the LUID for the shutdown privilege. 
        LookupPrivilegeValue( NULL, SE_SHUTDOWN_NAME, &tkp.Privileges[0].Luid );

        tkp.PrivilegeCount = 1; // one privilege to set 
        tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

        // Get the shutdown privilege for this process.     
        AdjustTokenPrivileges( hToken, FALSE, &tkp, 0, NULL, 0 );

        CloseHandle( hToken );
    }

    // Shut down the system and force all applications to close. 
    ExitWindowsEx( EWX_REBOOT, 0 );
}

bool CSystem::LaunchProgram( const char * program, const char * parameters, const bool wait, const int show )
{
    SHELLEXECUTEINFO execInfo;
    memset( &execInfo, 0, sizeof( execInfo ) );

    execInfo.cbSize = sizeof( execInfo );
    execInfo.lpVerb = "open";
    execInfo.lpFile = program;
    execInfo.lpParameters = parameters;
    execInfo.fMask = SEE_MASK_NOCLOSEPROCESS | SEE_MASK_FLAG_NO_UI;     // don't close this program or show error messages
    execInfo.nShow = show;

    // Launch the program
    if ( !ShellExecuteEx( &execInfo ) )
        return false;

    if ( wait )
        WaitForSingleObject( execInfo.hProcess, INFINITE );

    return true;
}

bool CSystem::DirectoryExists( const char * directory )
{
    _finddata_t files;
    int handle = _findfirst( directory, &files );

    if ( handle == -1 )
        return false;

    _findclose( handle );

    return ( files.attrib & _A_SUBDIR ) != 0;
}

bool CSystem::CreateDirectory( const char * directory )
{
    if ( CSystem::DirectoryExists( directory ) )
        return true;

    // Try and create the directory
    if ( _mkdir( directory ) == -1 )
    {
        // Failed, better create the parent first
        CString dir( directory );
        int slash = dir.ReverseFind( '\\' );
        if ( slash > 0 )
        {
            // Create the parent directory
            if ( CSystem::CreateDirectory( dir.Left( slash ) ) )
                return ( _mkdir( directory ) != -1 );
        }
        return false;
    }
    return true;
}

/*
bool CSystem::DeleteDirectory(const char * directory)
{
_finddata_t files;
int handle = _findfirst((directory + (directory.Ends("\\") ? "" : "\\") + "*.*").c_str(), &files);

if(handle != -1)
{
do
{
if(strcmp(files.name, "..") == 0 || strcmp(files.name, ".") == 0)
continue;
if(files.attrib & _A_SUBDIR)
{
if(!CSystem::DeleteDirectory(directory + (directory.Ends("\\") ? "" : "\\") + files.name))
return false;
}
else
XSFile::DeleteDirectory(directory + (directory.Ends("\\") ? "" : "\\") + files.name);

}
while(_findnext(handle, &files) != -1);

_findclose(handle);
}

return (_rmdir(directory.c_str()) == -1 ? false : true);
}

bool CSystem::CopyDirectory(const char * source, const char * destination, const char * backup)
{
_finddata_t files;
int handle = _findfirst((source + (source.Ends("\\") ? "" : "\\") + "*.*").c_str(), &files);

if(handle != -1)
{
CSystem::Create(destination);
do
{
if(strcmp(files.name, "..") == 0 || strcmp(files.name, ".") == 0)
continue;
if(files.attrib & _A_SUBDIR)
{
if(!CSystem::Copy(source + (source.Ends("\\") ? "" : "\\") + files.name, destination + (destination.Ends("\\") ? "" : "\\") + files.name, backup.Size() ? backup + (backup.Ends("\\") ? "" : "\\") + files.name : ""))
return false;
}
else
{
if(!CopyFile(
(source + (source.Ends("\\") ? "" : "\\") + files.name).c_str(),
(destination + (destination.Ends("\\") ? "" : "\\") + files.name).c_str(),
backup.Size() ? true : false))
{
CSystem::Create(backup);
CopyFile(
(source + (source.Ends("\\") ? "" : "\\") + files.name).c_str(),
(backup + (backup.Ends("\\") ? "" : "\\") + files.name).c_str(), false);
if(!CopyFile(
(source + (source.Ends("\\") ? "" : "\\") + files.name).c_str(),
(destination + (destination.Ends("\\") ? "" : "\\") + files.name).c_str(), false))
return false;
}
}
}
while(_findnext(handle, &files) != -1);

_findclose(handle);
}

return true;
}
*/

/**
 * LaunchProgram2(LPCSTR szCommandLine)
 *
 * Launches another program with standard options and waits to get it's return value
 * @param szCommandLine A null terminated string containing the program name and parameters.
 * @return The return value for the called program
 */
DWORD CSystem::LaunchProgram2( LPCSTR szCommandLine )
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    memset( &si, 0, sizeof( si ) );
    memset( &pi, 0, sizeof( pi ) );

    si.cb = sizeof( si );

    // CreateProcess modifies it's second parameter
    int len = strlen( szCommandLine );
    char * commandLine = new char[len + 1];
    strcpy( commandLine, szCommandLine );

    BOOL result = CreateProcess( NULL, commandLine, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi );
    delete commandLine;
    if ( !result )
        return 0;

    WaitForSingleObject( pi.hProcess, INFINITE );

    DWORD ret;
    GetExitCodeProcess( pi.hProcess, &ret );

    return ret;
}

LPSTR CSystem::GetDllInfo( LPTSTR lpszDllName, LPTSTR lpszInfo, WORD primary_langid )
{
    LPSTR pzStr;
    pzStr = "";
    DWORD dwVerInfoSize = 0;
    DWORD dwVerHnd = 0;
    LPSTR lpstrVffInfo;
    UINT* pVersionLen = new UINT;
    HANDLE hMem;

    struct LANGANDCODEPAGE {
        WORD wLanguage;
        WORD wCodePage;
    } *lpvi;

    //extracting the version info structure size 
    if ( ( dwVerInfoSize = GetFileVersionInfoSize( lpszDllName, &dwVerHnd ) ) > 0 )
    {
        UINT iLen;
        hMem = GlobalAlloc( GMEM_MOVEABLE, dwVerInfoSize );
        lpstrVffInfo = (char *)GlobalLock( hMem );
        int iSizeOfStruct( sizeof( struct LANGANDCODEPAGE ) );

        GetFileVersionInfo( lpszDllName, dwVerHnd, dwVerInfoSize, lpstrVffInfo );
        //extracting the language/character value from the file. 
        if ( ( VerQueryValue(
            (LPVOID)lpstrVffInfo,
            TEXT( "\\VarFileInfo\\Translation" ),
            (LPVOID*)&lpvi,
            &iLen ) ) > 0 )
        {
            for ( unsigned int j = 0; j < ( iLen / iSizeOfStruct ); j++ )
            {
                // The language you are looking for.
                if ( PRIMARYLANGID( lpvi[j].wLanguage ) == primary_langid )
                {
                    pzStr = "";
                    char strVerCar[_MAX_PATH] = "\0";
                    sprintf(
                        strVerCar, "\\StringFileInfo\\%04x%04x\\%s",
                        lpvi[j].wLanguage,
                        lpvi[j].wCodePage,
                        lpszInfo );
                    //querying the file with the correct language/character value. 
                    VerQueryValue(
                        (LPVOID)lpstrVffInfo,
                        (LPTSTR)(LPCTSTR)strVerCar,
                        (LPVOID *)&pzStr,
                        pVersionLen );
                }
            }
        }
    }
    return pzStr;
}