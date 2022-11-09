# Microsoft Developer Studio Project File - Name="krnln" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=krnln - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "krnln_VC6.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "krnln_VC6.mak" CFG="krnln - Win32 Debug"
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
# PROP BASE Output_Dir "..\Release"
# PROP BASE Intermediate_Dir ".\Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\Release"
# PROP Intermediate_Dir ".\Release"
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
# ADD LIB32 /nologo /out:"..\Release\krnln.lib"

!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\Debug"
# PROP BASE Intermediate_Dir ".\Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\Debug"
# PROP Intermediate_Dir ".\Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG"
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

SOURCE="..\krnln\BlackMoonCallPropertyVaule.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\BlackMoonCallUserDll.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\BlackMoonLibNotifySys.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\CloneBinData.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\CloneTextData.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\DateTimeFormat.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\DllEntryFunc.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\eHelpFunc.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\FileManager.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\FreeAryElement.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\GetAryElementInf.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\GetDataTypeType.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\GetDatePart.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\GetDaysOfSpecMonth.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\GetRegRootVal.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\GetSpecTime.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\GetSysDataTypeDataSize.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\GetTimePart.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\GetWeekDay.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\HelpFunc12.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\IsInFileMangerList.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_abs.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_asc.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_atn.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_band.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_beep.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_bin.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_BinLeft.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_BinLen.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_BinMid.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_BinRight.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_BJCase.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_bnot.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_bor.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_bxor.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_ChDir.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_ChDrive.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_chr.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_ClearClipBoard.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_close.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_cos.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_create.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_CryptOpen.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_CurDir.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_day.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_DeleteRegItem.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_Dispatch.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_DoEvents.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_exp.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_feof.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_fgets.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_FileCopy.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_FileDateTime.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_FileLen.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_FileMove.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_fix.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_fputs.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_FSeek.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_GetAllPY.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_GetAttr.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_GetBackColor.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_GetBinElement.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_GetBinRegItem.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_GetClipBoardText.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_GetCmdLine.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_GetColorCount.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_GetCursorHorzPos.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_GetCursorVertPos.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_GetDataTypeSize.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_GetDatePart.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_GetDaysOfSpecMonth.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_GetDiskFreeSpace.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_GetDiskLabel.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_GetDiskTotalSpace.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_GetEnv.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_GetHDiskCode.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_GetHostName.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_GetIntInsideBin.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_GetKeyText.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_GetLastError.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_GetNumRegItem.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_GetRunFileName.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_GetRunPath.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_GetRuntimeDataType.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_GetScreenHeight.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_GetScreenWidth.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_GetSectionNames.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_GetSpecTime.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_GetSysVer.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_GetTempFileName.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_GetTextRegItem.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_GetTickCount.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_GetTimePart.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_GetWinPic.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_hex.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_HostNameToIP.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_hour.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_IDiv.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_InBin.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_InBinRev.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_InputBox.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_InsBin.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_InsLine.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_InsText.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_InStr.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_InStrRev.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_int.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_IPToHostName.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_IsCalcOK.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_IsFileExist.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_IsHaveTextInClip.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_IsRegItemExist.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_kill.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_LCase.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_left.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_len.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_like.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_loc.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_lock.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_lof.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_log.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_LTrim.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_MakeLong.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_MakeWord.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_mid.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_minute.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_MkDir.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_mod.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_month.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_MsgBox.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_name.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_now.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_NumToRMB.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_NumToText.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_oct.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_open.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_OpenManyFileDialog.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_OpenMemFile.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_p2double.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_p2float.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_p2int.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_pbin.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_ping.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_PlayMID.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_PlayMusic.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_PlayStop.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_pow.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_pstr.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_PutEnv.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_QJCase.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_randomize.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_read.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_ReadBin.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_ReadFile.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_ReadLine.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_ReadText.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_RemoveData.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_ReplaceText.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_reset.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_RestroeCursor.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_ReverseIntBytes.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_rgb.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_right.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_RmDir.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_rnd.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_round.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_RpBin.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_RpSubBin.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_RpSubText.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_RTrim.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_run.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_RunConsoleApp.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_SaveRegItem.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_second.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_SeekToBegin.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_SeekToEnd.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_SetAttr.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_SetClipBoardText.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_SetDiskLabel.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_SetIntInsideBin.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_SetKeyText.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_SetSysTime.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_SetWaitCursor.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_sgn.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_shl.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_shr.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_sin.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_sleep.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_SortAry.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_space.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_SpaceBin.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_split.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_SplitBin.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_sqr.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_str.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_StrComp.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_string.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_StrToUTF8.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_tan.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_TimeChg.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_TimeDiff.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_TimePart.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_TimeToText.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_ToBin.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_ToByte.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_ToFloat.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_ToInt.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_ToLong.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_ToShort.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_ToTime.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_trim.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_TrimAll.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_UCase.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_Unlock.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_UNum.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_UTF8ToStr.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_val.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_Variant.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_WeekDay.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_write.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_WriteBin.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_WriteFile.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_WriteLine.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_WriteMem.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_WriteText.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_year.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\krnln_ZeroAry.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\LTrimZeroChr.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\md5t.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\mem.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\midi.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\Myfunctions.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\MyMemFile.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\NumToChinese.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\replaceText.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\SDataToStr.cpp"
# End Source File
# Begin Source File

SOURCE="..\krnln\StdAfx.cpp"
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE="..\krnln\lib2.h"
# End Source File
# Begin Source File

SOURCE="..\krnln\LTrimZeroChr.h"
# End Source File
# Begin Source File

SOURCE="..\krnln\md5t.h"
# End Source File
# Begin Source File

SOURCE="..\krnln\mem.h"
# End Source File
# Begin Source File

SOURCE="..\krnln\midi.h"
# End Source File
# Begin Source File

SOURCE="..\krnln\Myfunctions.h"
# End Source File
# Begin Source File

SOURCE="..\krnln\MyMemFile.h"
# End Source File
# Begin Source File

SOURCE="..\krnln\StdAfx.h"
# End Source File
# End Group
# Begin Source File

SOURCE="..\Readme.txt"
# End Source File
# Begin Source File

SOURCE="..\krnln\Diskid32.obj"
# End Source File
# Begin Source File

SOURCE="..\krnln\PY.OBJ"
# End Source File
# End Target
# End Project
