# Microsoft Developer Studio Project File - Name="shared" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=shared - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "shared.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "shared.mak" CFG="shared - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "shared - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "shared - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "shared - Win32 Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 1
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "BUILDING_LIBRARY" /Yu"stdafx.h" /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"\lib\altwin.lib"

!ELSEIF  "$(CFG)" == "shared - Win32 Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 1
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "BUILDING_LIBRARY" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"\lib\altwin_d.lib"

!ENDIF 

# Begin Target

# Name "shared - Win32 Release"
# Name "shared - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\Bmp.cpp
# End Source File
# Begin Source File

SOURCE=.\BmpDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\CFileLog.cpp
# End Source File
# Begin Source File

SOURCE=.\CFuncLog.cpp
# End Source File
# Begin Source File

SOURCE=.\CLog.cpp
# End Source File
# Begin Source File

SOURCE=.\CWinLog.cpp
# End Source File
# Begin Source File

SOURCE=.\FileInfo.cpp
# End Source File
# Begin Source File

SOURCE=.\FileVersion.cpp
# End Source File
# Begin Source File

SOURCE=.\FolderDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\GridCtrl\GridCell.cpp
# End Source File
# Begin Source File

SOURCE=.\GridCtrl\GridCellBase.cpp
# End Source File
# Begin Source File

SOURCE=.\GridCtrl\GridCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\GridCtrl\GridDropTarget.cpp
# End Source File
# Begin Source File

SOURCE=.\HoverButton.cpp
# End Source File
# Begin Source File

SOURCE=.\HyperLink.cpp
# End Source File
# Begin Source File

SOURCE=.\GridCtrl\InPlaceEdit.cpp
# End Source File
# Begin Source File

SOURCE=.\Label.cpp
# End Source File
# Begin Source File

SOURCE=.\Library.cpp
# End Source File
# Begin Source File

SOURCE=.\Picture.cpp
# End Source File
# Begin Source File

SOURCE=.\ProgressWnd.cpp
# End Source File
# Begin Source File

SOURCE=.\Registry.cpp
# End Source File
# Begin Source File

SOURCE=.\ShadeDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\Subclass.cpp
# End Source File
# Begin Source File

SOURCE=.\System.cpp
# End Source File
# Begin Source File

SOURCE=.\GridCtrl\TitleTip.cpp
# End Source File
# Begin Source File

SOURCE=.\TransButton.cpp
# End Source File
# Begin Source File

SOURCE=.\TransDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\TransStatic.cpp
# End Source File
# Begin Source File

SOURCE=.\TrayIcon.cpp
# End Source File
# Begin Source File

SOURCE=.\Version.cpp
# End Source File
# Begin Source File

SOURCE=.\xShadeButton.cpp
# End Source File
# End Group
# Begin Group "Local Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AutoBuild.h
# End Source File
# Begin Source File

SOURCE=.\GridCtrl\GridDropTarget.h
# End Source File
# Begin Source File

SOURCE=.\GridCtrl\InPlaceEdit.h
# End Source File
# Begin Source File

SOURCE=.\GridCtrl\MemDC.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\GridCtrl\TitleTip.h
# End Source File
# End Group
# Begin Group "Library Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\Bmp.h

!IF  "$(CFG)" == "shared - Win32 Release"

# Begin Custom Build
InputPath=.\Bmp.h
InputName=Bmp

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ELSEIF  "$(CFG)" == "shared - Win32 Debug"

# Begin Custom Build
InputPath=.\Bmp.h
InputName=Bmp

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\BmpDlg.h

!IF  "$(CFG)" == "shared - Win32 Release"

# Begin Custom Build
InputPath=.\BmpDlg.h
InputName=BmpDlg

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ELSEIF  "$(CFG)" == "shared - Win32 Debug"

# Begin Custom Build
InputPath=.\BmpDlg.h
InputName=BmpDlg

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\GridCtrl\CellRange.h

!IF  "$(CFG)" == "shared - Win32 Release"

# Begin Custom Build
InputPath=.\GridCtrl\CellRange.h
InputName=CellRange

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ELSEIF  "$(CFG)" == "shared - Win32 Debug"

# Begin Custom Build
InputPath=.\GridCtrl\CellRange.h
InputName=CellRange

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\CFileLog.h

!IF  "$(CFG)" == "shared - Win32 Release"

# Begin Custom Build
InputPath=.\CFileLog.h
InputName=CFileLog

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ELSEIF  "$(CFG)" == "shared - Win32 Debug"

# Begin Custom Build
InputPath=.\CFileLog.h
InputName=CFileLog

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\CFuncLog.h

!IF  "$(CFG)" == "shared - Win32 Release"

# Begin Custom Build
InputPath=.\CFuncLog.h
InputName=CFuncLog

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ELSEIF  "$(CFG)" == "shared - Win32 Debug"

# Begin Custom Build
InputPath=.\CFuncLog.h
InputName=CFuncLog

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\CLog.h

!IF  "$(CFG)" == "shared - Win32 Release"

# Begin Custom Build
InputPath=.\CLog.h
InputName=CLog

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ELSEIF  "$(CFG)" == "shared - Win32 Debug"

# Begin Custom Build
InputPath=.\CLog.h
InputName=CLog

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\CStoreLog.h

!IF  "$(CFG)" == "shared - Win32 Release"

# Begin Custom Build
InputPath=.\CStoreLog.h
InputName=CStoreLog

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ELSEIF  "$(CFG)" == "shared - Win32 Debug"

# Begin Custom Build
InputPath=.\CStoreLog.h
InputName=CStoreLog

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\CWinLog.h

!IF  "$(CFG)" == "shared - Win32 Release"

# Begin Custom Build
InputPath=.\CWinLog.h
InputName=CWinLog

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ELSEIF  "$(CFG)" == "shared - Win32 Debug"

# Begin Custom Build
InputPath=.\CWinLog.h
InputName=CWinLog

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\FileInfo.h

!IF  "$(CFG)" == "shared - Win32 Release"

# Begin Custom Build
InputPath=.\FileInfo.h
InputName=FileInfo

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ELSEIF  "$(CFG)" == "shared - Win32 Debug"

# Begin Custom Build
InputPath=.\FileInfo.h
InputName=FileInfo

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\FileVersion.h

!IF  "$(CFG)" == "shared - Win32 Release"

# Begin Custom Build
InputPath=.\FileVersion.h
InputName=FileVersion

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ELSEIF  "$(CFG)" == "shared - Win32 Debug"

# Begin Custom Build
InputPath=.\FileVersion.h
InputName=FileVersion

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\FolderDialog.h

!IF  "$(CFG)" == "shared - Win32 Release"

# Begin Custom Build
InputPath=.\FolderDialog.h
InputName=FolderDialog

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ELSEIF  "$(CFG)" == "shared - Win32 Debug"

# Begin Custom Build
InputPath=.\FolderDialog.h
InputName=FolderDialog

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\GridCtrl\GridCell.h

!IF  "$(CFG)" == "shared - Win32 Release"

# Begin Custom Build
InputPath=.\GridCtrl\GridCell.h
InputName=GridCell

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ELSEIF  "$(CFG)" == "shared - Win32 Debug"

# Begin Custom Build
InputPath=.\GridCtrl\GridCell.h
InputName=GridCell

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\GridCtrl\GridCellBase.h

!IF  "$(CFG)" == "shared - Win32 Release"

# Begin Custom Build
InputPath=.\GridCtrl\GridCellBase.h
InputName=GridCellBase

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ELSEIF  "$(CFG)" == "shared - Win32 Debug"

# Begin Custom Build
InputPath=.\GridCtrl\GridCellBase.h
InputName=GridCellBase

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\GridCtrl\GridCtrl.h

!IF  "$(CFG)" == "shared - Win32 Release"

# Begin Custom Build
InputPath=.\GridCtrl\GridCtrl.h
InputName=GridCtrl

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ELSEIF  "$(CFG)" == "shared - Win32 Debug"

# Begin Custom Build
InputPath=.\GridCtrl\GridCtrl.h
InputName=GridCtrl

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\HoverButton.h

!IF  "$(CFG)" == "shared - Win32 Release"

# Begin Custom Build
InputPath=.\HoverButton.h
InputName=HoverButton

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ELSEIF  "$(CFG)" == "shared - Win32 Debug"

# Begin Custom Build
InputPath=.\HoverButton.h
InputName=HoverButton

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\hyperlink.h

!IF  "$(CFG)" == "shared - Win32 Release"

# Begin Custom Build
InputPath=.\hyperlink.h
InputName=hyperlink

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ELSEIF  "$(CFG)" == "shared - Win32 Debug"

# Begin Custom Build
InputPath=.\hyperlink.h
InputName=hyperlink

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Label.h

!IF  "$(CFG)" == "shared - Win32 Release"

# Begin Custom Build
InputPath=.\Label.h
InputName=Label

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ELSEIF  "$(CFG)" == "shared - Win32 Debug"

# Begin Custom Build
InputPath=.\Label.h
InputName=Label

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Library.h

!IF  "$(CFG)" == "shared - Win32 Release"

# Begin Custom Build
InputPath=.\Library.h
InputName=Library

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ELSEIF  "$(CFG)" == "shared - Win32 Debug"

# Begin Custom Build
InputPath=.\Library.h
InputName=Library

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\logsync.h

!IF  "$(CFG)" == "shared - Win32 Release"

# Begin Custom Build
InputPath=.\logsync.h
InputName=logsync

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ELSEIF  "$(CFG)" == "shared - Win32 Debug"

# Begin Custom Build
InputPath=.\logsync.h
InputName=logsync

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Picture.h

!IF  "$(CFG)" == "shared - Win32 Release"

# Begin Custom Build
InputPath=.\Picture.h
InputName=Picture

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ELSEIF  "$(CFG)" == "shared - Win32 Debug"

# Begin Custom Build
InputPath=.\Picture.h
InputName=Picture

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ProgressWnd.h

!IF  "$(CFG)" == "shared - Win32 Release"

# Begin Custom Build
InputPath=.\ProgressWnd.h
InputName=ProgressWnd

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ELSEIF  "$(CFG)" == "shared - Win32 Debug"

# Begin Custom Build
InputPath=.\ProgressWnd.h
InputName=ProgressWnd

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Registry.h

!IF  "$(CFG)" == "shared - Win32 Release"

# Begin Custom Build
InputPath=.\Registry.h
InputName=Registry

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ELSEIF  "$(CFG)" == "shared - Win32 Debug"

# Begin Custom Build
InputPath=.\Registry.h
InputName=Registry

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ShadeDlg.h

!IF  "$(CFG)" == "shared - Win32 Release"

# Begin Custom Build
InputPath=.\ShadeDlg.h
InputName=ShadeDlg

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ELSEIF  "$(CFG)" == "shared - Win32 Debug"

# Begin Custom Build
InputPath=.\ShadeDlg.h
InputName=ShadeDlg

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Subclass.h

!IF  "$(CFG)" == "shared - Win32 Release"

# Begin Custom Build
InputPath=.\Subclass.h
InputName=Subclass

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ELSEIF  "$(CFG)" == "shared - Win32 Debug"

# Begin Custom Build
InputPath=.\Subclass.h
InputName=Subclass

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\System.h

!IF  "$(CFG)" == "shared - Win32 Release"

# Begin Custom Build
InputPath=.\System.h
InputName=System

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ELSEIF  "$(CFG)" == "shared - Win32 Debug"

# Begin Custom Build
InputPath=.\System.h
InputName=System

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\TransButton.h

!IF  "$(CFG)" == "shared - Win32 Release"

# Begin Custom Build
InputPath=.\TransButton.h
InputName=TransButton

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ELSEIF  "$(CFG)" == "shared - Win32 Debug"

# Begin Custom Build
InputPath=.\TransButton.h
InputName=TransButton

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\TransDialog.h

!IF  "$(CFG)" == "shared - Win32 Release"

# Begin Custom Build
InputPath=.\TransDialog.h
InputName=TransDialog

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ELSEIF  "$(CFG)" == "shared - Win32 Debug"

# Begin Custom Build
InputPath=.\TransDialog.h
InputName=TransDialog

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\TransStatic.h

!IF  "$(CFG)" == "shared - Win32 Release"

# Begin Custom Build
InputPath=.\TransStatic.h
InputName=TransStatic

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ELSEIF  "$(CFG)" == "shared - Win32 Debug"

# Begin Custom Build
InputPath=.\TransStatic.h
InputName=TransStatic

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\TrayIcon.h

!IF  "$(CFG)" == "shared - Win32 Release"

# Begin Custom Build
InputPath=.\TrayIcon.h
InputName=TrayIcon

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ELSEIF  "$(CFG)" == "shared - Win32 Debug"

# Begin Custom Build
InputPath=.\TrayIcon.h
InputName=TrayIcon

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Version.h

!IF  "$(CFG)" == "shared - Win32 Release"

# Begin Custom Build
InputPath=.\Version.h
InputName=Version

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ELSEIF  "$(CFG)" == "shared - Win32 Debug"

# Begin Custom Build
InputPath=.\Version.h
InputName=Version

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\xShadeButton.h

!IF  "$(CFG)" == "shared - Win32 Release"

# Begin Custom Build
InputPath=.\xShadeButton.h
InputName=xShadeButton

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ELSEIF  "$(CFG)" == "shared - Win32 Debug"

# Begin Custom Build
InputPath=.\xShadeButton.h
InputName=xShadeButton

"\include\win\$(InputName).h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) \include\win\$(InputName).h

# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Source File

SOURCE=.\sources.txt
# End Source File
# End Target
# End Project
