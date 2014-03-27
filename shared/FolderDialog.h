// FolderDialog.h: interface for the CFolderDialog class.
//    $Copyright �  1998 Kenneth M. Reed, ALL RIGHTS RESERVED. $
//
//////////////////////////////////////////////////////////////////////

#ifndef ALTERIDEM_FOLDER_DIALOG_H
#define ALTERIDEM_FOLDER_DIALOG_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// Including this allows us to get the library version
// and forces the including project to link to the
// library
#ifndef BUILDING_LIBRARY
#include <Library.h>
#endif

#include <shlobj.h>

class CFolderDialog
{
    friend static int CALLBACK BrowseDirectoryCallback( HWND hWnd, UINT uMsg, LPARAM lParam, LPARAM lpData );

public:
    CFolderDialog( LPCTSTR lpszFolderName = NULL, DWORD dwFlags = NULL, CWnd* pParentWnd = NULL );
    virtual ~CFolderDialog();
    virtual int DoModal();
    CString GetPathName() const;

protected:
    virtual void OnInitDialog();
    virtual void OnSelChanged( ITEMIDLIST* pIdl );
    virtual void CallbackFunction( HWND hWnd, UINT uMsg, LPARAM lParam );

    void EnableOK( BOOL bEnable = TRUE );
    void SetSelection( LPCTSTR pszSelection );
    void SetSelection( ITEMIDLIST* pIdl );
    void SetStatusText( LPCTSTR pszStatusText );
    CString ShortName( const CString& strName );

public:
    BROWSEINFO m_bi;

protected:
    CString m_strInitialFolderName;
    CString m_strFinalFolderName;

    TCHAR m_szDisplayName[MAX_PATH];
    TCHAR m_szPath[MAX_PATH];

    HWND m_hDialogBox;
};

#endif 