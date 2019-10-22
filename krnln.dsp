# Microsoft Developer Studio Project File - Name="krnln" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=krnln - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "krnln.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "krnln.mak" CFG="krnln - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "krnln - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "krnln - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "krnln - Win32 Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /FR /Yu"stdafx.h" /FD /c
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:".\Release\krnln.lib"

!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ENDIF 

# Begin Target

# Name "krnln - Win32 Release"
# Name "krnln - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\BlackMoonCallPropertyVaule.cpp
# End Source File
# Begin Source File

SOURCE=.\BlackMoonCallUserDll.cpp
# End Source File
# Begin Source File

SOURCE=.\BlackMoonLibNotifySys.cpp
# End Source File
# Begin Source File

SOURCE=.\CloneBinData.cpp
# End Source File
# Begin Source File

SOURCE=.\CloneTextData.cpp
# End Source File
# Begin Source File

SOURCE=.\DateTimeFormat.cpp
# End Source File
# Begin Source File

SOURCE=.\DllEntryFunc.cpp
# End Source File
# Begin Source File

SOURCE=.\eHelpFunc.cpp
# End Source File
# Begin Source File

SOURCE=.\FileManager.cpp
# End Source File
# Begin Source File

SOURCE=.\FreeAryElement.cpp
# End Source File
# Begin Source File

SOURCE=.\GetAryElementInf.cpp
# End Source File
# Begin Source File

SOURCE=.\GetDataTypeType.cpp
# End Source File
# Begin Source File

SOURCE=.\GetDatePart.cpp
# End Source File
# Begin Source File

SOURCE=.\GetDaysOfSpecMonth.cpp
# End Source File
# Begin Source File

SOURCE=.\GetRegRootVal.cpp
# End Source File
# Begin Source File

SOURCE=.\GetSpecTime.cpp
# End Source File
# Begin Source File

SOURCE=.\GetSysDataTypeDataSize.cpp
# End Source File
# Begin Source File

SOURCE=.\GetTimePart.cpp
# End Source File
# Begin Source File

SOURCE=.\GetWeekDay.cpp
# End Source File
# Begin Source File

SOURCE=.\HelpFunc12.cpp
# End Source File
# Begin Source File

SOURCE=.\IsInFileMangerList.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_abs.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_asc.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_atn.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_band.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_beep.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_bin.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_BinLeft.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_BinLen.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_BinMid.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_BinRight.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_BJCase.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_bnot.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_bor.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_bxor.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_ChDir.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_ChDrive.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_chr.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_ClearClipBoard.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_close.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_cos.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_CryptOpen.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_CurDir.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_day.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_DeleteRegItem.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_Dispatch.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_DoEvents.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_exp.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_feof.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_fgets.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_FileCopy.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_FileDateTime.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_FileLen.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_FileMove.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_fix.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_fputs.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_FSeek.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_GetAllPY.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_GetAttr.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_GetBackColor.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_GetBinElement.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_GetBinRegItem.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_GetClipBoardText.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_GetCmdLine.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_GetColorCount.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_GetCursorHorzPos.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_GetCursorVertPos.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_GetDataTypeSize.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_GetDatePart.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_GetDaysOfSpecMonth.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_GetDiskFreeSpace.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_GetDiskLabel.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_GetDiskTotalSpace.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_GetEnv.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_GetHDiskCode.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_GetHostName.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_GetIntInsideBin.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_GetKeyText.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_GetLastError.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_GetNumRegItem.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_GetRunFileName.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_GetRunPath.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_GetRuntimeDataType.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_GetScreenHeight.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_GetScreenWidth.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_GetSectionNames.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_GetSpecTime.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_GetSysVer.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_GetTempFileName.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_GetTextRegItem.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_GetTickCount.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_GetTimePart.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_GetWinPic.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_hex.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_HostNameToIP.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_hour.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_IDiv.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_InBin.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_InBinRev.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_InputBox.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_InsBin.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_InsLine.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_InsText.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_InStr.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_InStrRev.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_int.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_IPToHostName.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_IsCalcOK.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_IsFileExist.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_IsHaveTextInClip.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_IsRegItemExist.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_kill.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_LCase.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_left.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_len.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_like.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_loc.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_lock.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_lof.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_log.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_LTrim.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_MakeLong.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_MakeWord.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_mid.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_minute.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_MkDir.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_mod.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_month.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_MsgBox.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_name.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_now.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_NumToRMB.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_NumToText.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_oct.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_open.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_OpenManyFileDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_OpenMemFile.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_p2double.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_p2float.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_p2int.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_pbin.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_ping.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_PlayMID.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_PlayMusic.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_PlayStop.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_pow.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_pstr.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_PutEnv.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_QJCase.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_randomize.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_read.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_ReadBin.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_ReadFile.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_ReadLine.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_ReadText.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_RemoveData.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_ReplaceText.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_reset.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_RestroeCursor.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_ReverseIntBytes.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_rgb.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_right.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_RmDir.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_rnd.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_round.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_RpBin.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_RpSubBin.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_RpSubText.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_RTrim.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_run.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_RunConsoleApp.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_SaveRegItem.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_second.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_SeekToBegin.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_SeekToEnd.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_SetAttr.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_SetClipBoardText.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_SetDiskLabel.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_SetIntInsideBin.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_SetKeyText.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_SetSysTime.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_SetWaitCursor.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_sgn.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_shl.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_shr.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_sin.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_sleep.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_SortAry.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_space.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_SpaceBin.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_split.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_SplitBin.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_sqr.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_str.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_StrComp.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_string.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_StrToUTF8.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_tan.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_TimeChg.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_TimeDiff.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_TimePart.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_TimeToText.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_ToBin.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_ToByte.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_ToFloat.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_ToInt.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_ToLong.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_ToShort.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_ToTime.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_trim.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_TrimAll.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_UCase.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_Unlock.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_UNum.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_UTF8ToStr.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_val.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_Variant.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_WeekDay.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_write.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_WriteBin.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_WriteFile.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_WriteLine.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_WriteMem.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_WriteText.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_year.cpp
# End Source File
# Begin Source File

SOURCE=.\krnln_ZeroAry.cpp
# End Source File
# Begin Source File

SOURCE=.\LTrimZeroChr.cpp
# End Source File
# Begin Source File

SOURCE=.\md5t.cpp
# End Source File
# Begin Source File

SOURCE=.\mem.cpp
# End Source File
# Begin Source File

SOURCE=.\midi.cpp
# End Source File
# Begin Source File

SOURCE=.\Myfunctions.cpp
# End Source File
# Begin Source File

SOURCE=.\MyMemFile.cpp
# End Source File
# Begin Source File

SOURCE=.\NumToChinese.cpp
# End Source File
# Begin Source File

SOURCE=.\replaceText.cpp
# End Source File
# Begin Source File

SOURCE=.\SDataToStr.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\lib2.h
# End Source File
# Begin Source File

SOURCE=.\LTrimZeroChr.h
# End Source File
# Begin Source File

SOURCE=.\md5t.h
# End Source File
# Begin Source File

SOURCE=.\mem.h
# End Source File
# Begin Source File

SOURCE=.\midi.h
# End Source File
# Begin Source File

SOURCE=.\Myfunctions.h
# End Source File
# Begin Source File

SOURCE=.\MyMemFile.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\Readme.txt
# End Source File
# Begin Source File

SOURCE=.\Diskid32.obj
# End Source File
# Begin Source File

SOURCE=.\PY.OBJ
# End Source File
# End Target
# End Project
