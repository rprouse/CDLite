// System.h: interface for the CSystem class.
//
//////////////////////////////////////////////////////////////////////

#ifndef ALTERIDEM_SYSTEM_H
#define ALTERIDEM_SYSTEM_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// Including this allows us to get the library version
// and forces the including project to link to the
// library
#ifndef BUILDING_LIBRARY
#include <Library.h>
#endif

class CSystem  
{
public:
    /** 
     * Returns the location of the file that has called this function.
     * \param withFilename true to return the name of the application along with it location. 
     * Default is false, returning only its path.
     * \return Location of the application.
     */
    static CString ProgramPath(bool withFilename = false);

    /** 
     * Returns the windows directory on the local machine.
     * \return The location of the operating system on the local machine 
     * (for example "C:\Windows\")
     */
    static CString WindowsDirectory(void);

    /** 
     * Returns the current working directory.
     * \return The path of the current working directory
     */
    static CString CurrentDirectory(void);

    /** 
     * Returns the system directory on the local machine.
     * \return The directory of the system files (for example "C:\Windows\System\")
     */
    static CString SystemDirectory(void);

    /** 
     * Returns a unique file name with the temporary path prepended.
     * \param prefix A prefix for the filename.
     * \return The absolute location for a temporary file, including name.
     */
    static CString TemporaryFilename(const char * prefix);

    /** 
     * Returns the location of the temperory files path.
     * \return Local temporary directory, for example "C:\Windows\Temp\".
     */
    static CString TemporaryPath(void);

    /** 
     * Indicates if a file is locked for writing.
     * \param filename Name of the file to attempt opening.
     * \return true if the file is locked (or file is read only or not shared for write access).
     * If the file does not exist, this function will return false.
     */
    static bool IsFileLocked(const char * filename);

    /**
     *  Reboots the computer.
     *  This static member function works on all Windows OS's.
     *  \author Robert Prouse
     *  \warning Quietly ignores errors
     */
    static void Reboot(void);

    /**
     *  Launches a file based on extension, or a program.
     *  @param program Name of the program to launch.
     *  @param parameters Command line parametres to send the program.
     *  @param wait Wait until the program has exited before returning from the function.
     *  @param show Initial state of the launched program (ie. SW_SHOWDEFAULT, SW_MINIMIZED...)
     */
    static bool LaunchProgram(const char * program, const char * parameters = "", const bool wait = false, const int show = SW_SHOWDEFAULT);
    
    /**
     * LaunchProgram2(LPCSTR szCommandLine)
     *
     * Launches another program with standard options and waits to get it's return value
     * @param szCommandLine A null terminated string containing the program name and parameters.
     * @return The return value for the called program
     */
    static DWORD LaunchProgram2(LPCSTR szCommandLine);

    /**
     * Gets information about a dll
     * \param lpszDllName is the name of the dll you are inquiring about
     * \param lpszInfo can be one of 
     *    "Comments" 
     *    "CompanyName" 
     *    "FileDescritpion"
     *    "FileVersion"
     *    "InternalName"
     *    "LegalCopyright"
     *    "LegalTrademarks"
     *    "OriginalFileName"
     *    "ProductName"
     *    "ProductVersion"
     * \param primary_langid The language to get the information in if it is available
     * \return A string containing the information
     */
    static LPSTR GetDllInfo(LPTSTR lpszDllName, LPTSTR lpszInfo, WORD primary_langid = LANG_ENGLISH);

    /** 
     * Checks to see if a local path exists.
     * \param directory Directory to search for.
     * \return true if the directory was found
     */
    static bool DirectoryExists(const char * directory);

    /** 
     * Creates a directory in the current path.
     * \param directory Name of the directory to create. If the directory contains more that 
     * one level, all will be created.
     * \return true if the directory was created.
     */
    static bool CreateDirectory(const char * directory);
    
    /** 
     * Deletes a directory, and its contents.
     * \param directory Directory to delete.
     * \return true if successful
     */
    //static bool DeleteDirectory(const char * directory);

    /** 
     * Copies a directory to another location.
     * \param source Source directory for files.
     * \param dest Destination directory for files.
     * \param backup Backup directory for files being copied over. If blank, no backups are made. The default is blank.
     * \return true if successful.
     */
    //static bool CopyDirectory(const char * source, const char * dest, const char * backup = "");

    /** 
     * Moves a directory to another location,
     * \param source Source directory for files.
     * \param dest Destination directory for files.
     * \param backup Backup directory for files being copied over. If blank, no backups are made. The dedault is blank.
     * \return true if successful
     */
    //static bool MoveDirectory(const char * source, const char * dest, const char * backup = "");


private:
    CSystem() { } // Don't allow construction
    
};

#endif
