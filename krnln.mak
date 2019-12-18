# Microsoft Developer Studio Generated NMAKE File, Based on krnln.dsp
	!IF "$(CFG)" == ""
		CFG=krnln - Win32 Debug
!MESSAGE No configuration specified. Defaulting to krnln - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "krnln - Win32 Release" && "$(CFG)" != "krnln - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
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
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "krnln - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\krnln.lib" "$(OUTDIR)\krnln.bsc"


CLEAN :
	-@erase "$(INTDIR)\BlackMoonCallPropertyVaule.obj"
	-@erase "$(INTDIR)\BlackMoonCallPropertyVaule.sbr"
	-@erase "$(INTDIR)\BlackMoonCallUserDll.obj"
	-@erase "$(INTDIR)\BlackMoonCallUserDll.sbr"
	-@erase "$(INTDIR)\BlackMoonLibNotifySys.obj"
	-@erase "$(INTDIR)\BlackMoonLibNotifySys.sbr"
	-@erase "$(INTDIR)\CloneBinData.obj"
	-@erase "$(INTDIR)\CloneBinData.sbr"
	-@erase "$(INTDIR)\CloneTextData.obj"
	-@erase "$(INTDIR)\CloneTextData.sbr"
	-@erase "$(INTDIR)\DateTimeFormat.obj"
	-@erase "$(INTDIR)\DateTimeFormat.sbr"
	-@erase "$(INTDIR)\DllEntryFunc.obj"
	-@erase "$(INTDIR)\DllEntryFunc.sbr"
	-@erase "$(INTDIR)\eHelpFunc.obj"
	-@erase "$(INTDIR)\eHelpFunc.sbr"
	-@erase "$(INTDIR)\FileManager.obj"
	-@erase "$(INTDIR)\FileManager.sbr"
	-@erase "$(INTDIR)\FreeAryElement.obj"
	-@erase "$(INTDIR)\FreeAryElement.sbr"
	-@erase "$(INTDIR)\GetAryElementInf.obj"
	-@erase "$(INTDIR)\GetAryElementInf.sbr"
	-@erase "$(INTDIR)\GetDataTypeType.obj"
	-@erase "$(INTDIR)\GetDataTypeType.sbr"
	-@erase "$(INTDIR)\GetDatePart.obj"
	-@erase "$(INTDIR)\GetDatePart.sbr"
	-@erase "$(INTDIR)\GetDaysOfSpecMonth.obj"
	-@erase "$(INTDIR)\GetDaysOfSpecMonth.sbr"
	-@erase "$(INTDIR)\GetRegRootVal.obj"
	-@erase "$(INTDIR)\GetRegRootVal.sbr"
	-@erase "$(INTDIR)\GetSpecTime.obj"
	-@erase "$(INTDIR)\GetSpecTime.sbr"
	-@erase "$(INTDIR)\GetSysDataTypeDataSize.obj"
	-@erase "$(INTDIR)\GetSysDataTypeDataSize.sbr"
	-@erase "$(INTDIR)\GetTimePart.obj"
	-@erase "$(INTDIR)\GetTimePart.sbr"
	-@erase "$(INTDIR)\GetWeekDay.obj"
	-@erase "$(INTDIR)\GetWeekDay.sbr"
	-@erase "$(INTDIR)\HelpFunc12.obj"
	-@erase "$(INTDIR)\HelpFunc12.sbr"
	-@erase "$(INTDIR)\IsInFileMangerList.obj"
	-@erase "$(INTDIR)\IsInFileMangerList.sbr"
	-@erase "$(INTDIR)\krnln.pch"
	-@erase "$(INTDIR)\krnln_abs.obj"
	-@erase "$(INTDIR)\krnln_abs.sbr"
	-@erase "$(INTDIR)\krnln_asc.obj"
	-@erase "$(INTDIR)\krnln_asc.sbr"
	-@erase "$(INTDIR)\krnln_atn.obj"
	-@erase "$(INTDIR)\krnln_atn.sbr"
	-@erase "$(INTDIR)\krnln_band.obj"
	-@erase "$(INTDIR)\krnln_band.sbr"
	-@erase "$(INTDIR)\krnln_beep.obj"
	-@erase "$(INTDIR)\krnln_beep.sbr"
	-@erase "$(INTDIR)\krnln_bin.obj"
	-@erase "$(INTDIR)\krnln_bin.sbr"
	-@erase "$(INTDIR)\krnln_BinLeft.obj"
	-@erase "$(INTDIR)\krnln_BinLeft.sbr"
	-@erase "$(INTDIR)\krnln_BinLen.obj"
	-@erase "$(INTDIR)\krnln_BinLen.sbr"
	-@erase "$(INTDIR)\krnln_BinMid.obj"
	-@erase "$(INTDIR)\krnln_BinMid.sbr"
	-@erase "$(INTDIR)\krnln_BinRight.obj"
	-@erase "$(INTDIR)\krnln_BinRight.sbr"
	-@erase "$(INTDIR)\krnln_BJCase.obj"
	-@erase "$(INTDIR)\krnln_BJCase.sbr"
	-@erase "$(INTDIR)\krnln_bnot.obj"
	-@erase "$(INTDIR)\krnln_bnot.sbr"
	-@erase "$(INTDIR)\krnln_bor.obj"
	-@erase "$(INTDIR)\krnln_bor.sbr"
	-@erase "$(INTDIR)\krnln_bxor.obj"
	-@erase "$(INTDIR)\krnln_bxor.sbr"
	-@erase "$(INTDIR)\krnln_ChDir.obj"
	-@erase "$(INTDIR)\krnln_ChDir.sbr"
	-@erase "$(INTDIR)\krnln_ChDrive.obj"
	-@erase "$(INTDIR)\krnln_ChDrive.sbr"
	-@erase "$(INTDIR)\krnln_chr.obj"
	-@erase "$(INTDIR)\krnln_chr.sbr"
	-@erase "$(INTDIR)\krnln_ClearClipBoard.obj"
	-@erase "$(INTDIR)\krnln_ClearClipBoard.sbr"
	-@erase "$(INTDIR)\krnln_close.obj"
	-@erase "$(INTDIR)\krnln_close.sbr"
	-@erase "$(INTDIR)\krnln_cos.obj"
	-@erase "$(INTDIR)\krnln_cos.sbr"
	-@erase "$(INTDIR)\krnln_CryptOpen.obj"
	-@erase "$(INTDIR)\krnln_CryptOpen.sbr"
	-@erase "$(INTDIR)\krnln_CurDir.obj"
	-@erase "$(INTDIR)\krnln_CurDir.sbr"
	-@erase "$(INTDIR)\krnln_day.obj"
	-@erase "$(INTDIR)\krnln_day.sbr"
	-@erase "$(INTDIR)\krnln_DeleteRegItem.obj"
	-@erase "$(INTDIR)\krnln_DeleteRegItem.sbr"
	-@erase "$(INTDIR)\krnln_Dispatch.obj"
	-@erase "$(INTDIR)\krnln_Dispatch.sbr"
	-@erase "$(INTDIR)\krnln_DoEvents.obj"
	-@erase "$(INTDIR)\krnln_DoEvents.sbr"
	-@erase "$(INTDIR)\krnln_exp.obj"
	-@erase "$(INTDIR)\krnln_exp.sbr"
	-@erase "$(INTDIR)\krnln_feof.obj"
	-@erase "$(INTDIR)\krnln_feof.sbr"
	-@erase "$(INTDIR)\krnln_fgets.obj"
	-@erase "$(INTDIR)\krnln_fgets.sbr"
	-@erase "$(INTDIR)\krnln_FileCopy.obj"
	-@erase "$(INTDIR)\krnln_FileCopy.sbr"
	-@erase "$(INTDIR)\krnln_FileDateTime.obj"
	-@erase "$(INTDIR)\krnln_FileDateTime.sbr"
	-@erase "$(INTDIR)\krnln_FileLen.obj"
	-@erase "$(INTDIR)\krnln_FileLen.sbr"
	-@erase "$(INTDIR)\krnln_FileMove.obj"
	-@erase "$(INTDIR)\krnln_FileMove.sbr"
	-@erase "$(INTDIR)\krnln_fix.obj"
	-@erase "$(INTDIR)\krnln_fix.sbr"
	-@erase "$(INTDIR)\krnln_fputs.obj"
	-@erase "$(INTDIR)\krnln_fputs.sbr"
	-@erase "$(INTDIR)\krnln_FSeek.obj"
	-@erase "$(INTDIR)\krnln_FSeek.sbr"
	-@erase "$(INTDIR)\krnln_GetAllPY.obj"
	-@erase "$(INTDIR)\krnln_GetAllPY.sbr"
	-@erase "$(INTDIR)\krnln_GetAttr.obj"
	-@erase "$(INTDIR)\krnln_GetAttr.sbr"
	-@erase "$(INTDIR)\krnln_GetBackColor.obj"
	-@erase "$(INTDIR)\krnln_GetBackColor.sbr"
	-@erase "$(INTDIR)\krnln_GetBinElement.obj"
	-@erase "$(INTDIR)\krnln_GetBinElement.sbr"
	-@erase "$(INTDIR)\krnln_GetBinRegItem.obj"
	-@erase "$(INTDIR)\krnln_GetBinRegItem.sbr"
	-@erase "$(INTDIR)\krnln_GetClipBoardText.obj"
	-@erase "$(INTDIR)\krnln_GetClipBoardText.sbr"
	-@erase "$(INTDIR)\krnln_GetCmdLine.obj"
	-@erase "$(INTDIR)\krnln_GetCmdLine.sbr"
	-@erase "$(INTDIR)\krnln_GetColorCount.obj"
	-@erase "$(INTDIR)\krnln_GetColorCount.sbr"
	-@erase "$(INTDIR)\krnln_GetCursorHorzPos.obj"
	-@erase "$(INTDIR)\krnln_GetCursorHorzPos.sbr"
	-@erase "$(INTDIR)\krnln_GetCursorVertPos.obj"
	-@erase "$(INTDIR)\krnln_GetCursorVertPos.sbr"
	-@erase "$(INTDIR)\krnln_GetDataTypeSize.obj"
	-@erase "$(INTDIR)\krnln_GetDataTypeSize.sbr"
	-@erase "$(INTDIR)\krnln_GetDatePart.obj"
	-@erase "$(INTDIR)\krnln_GetDatePart.sbr"
	-@erase "$(INTDIR)\krnln_GetDaysOfSpecMonth.obj"
	-@erase "$(INTDIR)\krnln_GetDaysOfSpecMonth.sbr"
	-@erase "$(INTDIR)\krnln_GetDiskFreeSpace.obj"
	-@erase "$(INTDIR)\krnln_GetDiskFreeSpace.sbr"
	-@erase "$(INTDIR)\krnln_GetDiskLabel.obj"
	-@erase "$(INTDIR)\krnln_GetDiskLabel.sbr"
	-@erase "$(INTDIR)\krnln_GetDiskTotalSpace.obj"
	-@erase "$(INTDIR)\krnln_GetDiskTotalSpace.sbr"
	-@erase "$(INTDIR)\krnln_GetEnv.obj"
	-@erase "$(INTDIR)\krnln_GetEnv.sbr"
	-@erase "$(INTDIR)\krnln_GetHDiskCode.obj"
	-@erase "$(INTDIR)\krnln_GetHDiskCode.sbr"
	-@erase "$(INTDIR)\krnln_GetHostName.obj"
	-@erase "$(INTDIR)\krnln_GetHostName.sbr"
	-@erase "$(INTDIR)\krnln_GetIntInsideBin.obj"
	-@erase "$(INTDIR)\krnln_GetIntInsideBin.sbr"
	-@erase "$(INTDIR)\krnln_GetKeyText.obj"
	-@erase "$(INTDIR)\krnln_GetKeyText.sbr"
	-@erase "$(INTDIR)\krnln_GetLastError.obj"
	-@erase "$(INTDIR)\krnln_GetLastError.sbr"
	-@erase "$(INTDIR)\krnln_GetNumRegItem.obj"
	-@erase "$(INTDIR)\krnln_GetNumRegItem.sbr"
	-@erase "$(INTDIR)\krnln_GetRunFileName.obj"
	-@erase "$(INTDIR)\krnln_GetRunFileName.sbr"
	-@erase "$(INTDIR)\krnln_GetRunPath.obj"
	-@erase "$(INTDIR)\krnln_GetRunPath.sbr"
	-@erase "$(INTDIR)\krnln_GetRuntimeDataType.obj"
	-@erase "$(INTDIR)\krnln_GetRuntimeDataType.sbr"
	-@erase "$(INTDIR)\krnln_GetScreenHeight.obj"
	-@erase "$(INTDIR)\krnln_GetScreenHeight.sbr"
	-@erase "$(INTDIR)\krnln_GetScreenWidth.obj"
	-@erase "$(INTDIR)\krnln_GetScreenWidth.sbr"
	-@erase "$(INTDIR)\krnln_GetSectionNames.obj"
	-@erase "$(INTDIR)\krnln_GetSectionNames.sbr"
	-@erase "$(INTDIR)\krnln_GetSpecTime.obj"
	-@erase "$(INTDIR)\krnln_GetSpecTime.sbr"
	-@erase "$(INTDIR)\krnln_GetSysVer.obj"
	-@erase "$(INTDIR)\krnln_GetSysVer.sbr"
	-@erase "$(INTDIR)\krnln_GetTempFileName.obj"
	-@erase "$(INTDIR)\krnln_GetTempFileName.sbr"
	-@erase "$(INTDIR)\krnln_GetTextRegItem.obj"
	-@erase "$(INTDIR)\krnln_GetTextRegItem.sbr"
	-@erase "$(INTDIR)\krnln_GetTickCount.obj"
	-@erase "$(INTDIR)\krnln_GetTickCount.sbr"
	-@erase "$(INTDIR)\krnln_GetTimePart.obj"
	-@erase "$(INTDIR)\krnln_GetTimePart.sbr"
	-@erase "$(INTDIR)\krnln_GetWinPic.obj"
	-@erase "$(INTDIR)\krnln_GetWinPic.sbr"
	-@erase "$(INTDIR)\krnln_hex.obj"
	-@erase "$(INTDIR)\krnln_hex.sbr"
	-@erase "$(INTDIR)\krnln_HostNameToIP.obj"
	-@erase "$(INTDIR)\krnln_HostNameToIP.sbr"
	-@erase "$(INTDIR)\krnln_hour.obj"
	-@erase "$(INTDIR)\krnln_hour.sbr"
	-@erase "$(INTDIR)\krnln_IDiv.obj"
	-@erase "$(INTDIR)\krnln_IDiv.sbr"
	-@erase "$(INTDIR)\krnln_InBin.obj"
	-@erase "$(INTDIR)\krnln_InBin.sbr"
	-@erase "$(INTDIR)\krnln_InBinRev.obj"
	-@erase "$(INTDIR)\krnln_InBinRev.sbr"
	-@erase "$(INTDIR)\krnln_InputBox.obj"
	-@erase "$(INTDIR)\krnln_InputBox.sbr"
	-@erase "$(INTDIR)\krnln_InsBin.obj"
	-@erase "$(INTDIR)\krnln_InsBin.sbr"
	-@erase "$(INTDIR)\krnln_InsLine.obj"
	-@erase "$(INTDIR)\krnln_InsLine.sbr"
	-@erase "$(INTDIR)\krnln_InsText.obj"
	-@erase "$(INTDIR)\krnln_InsText.sbr"
	-@erase "$(INTDIR)\krnln_InStr.obj"
	-@erase "$(INTDIR)\krnln_InStr.sbr"
	-@erase "$(INTDIR)\krnln_InStrRev.obj"
	-@erase "$(INTDIR)\krnln_InStrRev.sbr"
	-@erase "$(INTDIR)\krnln_int.obj"
	-@erase "$(INTDIR)\krnln_int.sbr"
	-@erase "$(INTDIR)\krnln_IPToHostName.obj"
	-@erase "$(INTDIR)\krnln_IPToHostName.sbr"
	-@erase "$(INTDIR)\krnln_IsCalcOK.obj"
	-@erase "$(INTDIR)\krnln_IsCalcOK.sbr"
	-@erase "$(INTDIR)\krnln_IsFileExist.obj"
	-@erase "$(INTDIR)\krnln_IsFileExist.sbr"
	-@erase "$(INTDIR)\krnln_IsHaveTextInClip.obj"
	-@erase "$(INTDIR)\krnln_IsHaveTextInClip.sbr"
	-@erase "$(INTDIR)\krnln_IsRegItemExist.obj"
	-@erase "$(INTDIR)\krnln_IsRegItemExist.sbr"
	-@erase "$(INTDIR)\krnln_kill.obj"
	-@erase "$(INTDIR)\krnln_kill.sbr"
	-@erase "$(INTDIR)\krnln_LCase.obj"
	-@erase "$(INTDIR)\krnln_LCase.sbr"
	-@erase "$(INTDIR)\krnln_left.obj"
	-@erase "$(INTDIR)\krnln_left.sbr"
	-@erase "$(INTDIR)\krnln_len.obj"
	-@erase "$(INTDIR)\krnln_len.sbr"
	-@erase "$(INTDIR)\krnln_like.obj"
	-@erase "$(INTDIR)\krnln_like.sbr"
	-@erase "$(INTDIR)\krnln_loc.obj"
	-@erase "$(INTDIR)\krnln_loc.sbr"
	-@erase "$(INTDIR)\krnln_lock.obj"
	-@erase "$(INTDIR)\krnln_lock.sbr"
	-@erase "$(INTDIR)\krnln_lof.obj"
	-@erase "$(INTDIR)\krnln_lof.sbr"
	-@erase "$(INTDIR)\krnln_log.obj"
	-@erase "$(INTDIR)\krnln_log.sbr"
	-@erase "$(INTDIR)\krnln_LTrim.obj"
	-@erase "$(INTDIR)\krnln_LTrim.sbr"
	-@erase "$(INTDIR)\krnln_MakeLong.obj"
	-@erase "$(INTDIR)\krnln_MakeLong.sbr"
	-@erase "$(INTDIR)\krnln_MakeWord.obj"
	-@erase "$(INTDIR)\krnln_MakeWord.sbr"
	-@erase "$(INTDIR)\krnln_mid.obj"
	-@erase "$(INTDIR)\krnln_mid.sbr"
	-@erase "$(INTDIR)\krnln_minute.obj"
	-@erase "$(INTDIR)\krnln_minute.sbr"
	-@erase "$(INTDIR)\krnln_MkDir.obj"
	-@erase "$(INTDIR)\krnln_MkDir.sbr"
	-@erase "$(INTDIR)\krnln_mod.obj"
	-@erase "$(INTDIR)\krnln_mod.sbr"
	-@erase "$(INTDIR)\krnln_month.obj"
	-@erase "$(INTDIR)\krnln_month.sbr"
	-@erase "$(INTDIR)\krnln_MsgBox.obj"
	-@erase "$(INTDIR)\krnln_MsgBox.sbr"
	-@erase "$(INTDIR)\krnln_name.obj"
	-@erase "$(INTDIR)\krnln_name.sbr"
	-@erase "$(INTDIR)\krnln_now.obj"
	-@erase "$(INTDIR)\krnln_now.sbr"
	-@erase "$(INTDIR)\krnln_NumToRMB.obj"
	-@erase "$(INTDIR)\krnln_NumToRMB.sbr"
	-@erase "$(INTDIR)\krnln_NumToText.obj"
	-@erase "$(INTDIR)\krnln_NumToText.sbr"
	-@erase "$(INTDIR)\krnln_oct.obj"
	-@erase "$(INTDIR)\krnln_oct.sbr"
	-@erase "$(INTDIR)\krnln_open.obj"
	-@erase "$(INTDIR)\krnln_open.sbr"
	-@erase "$(INTDIR)\krnln_OpenManyFileDialog.obj"
	-@erase "$(INTDIR)\krnln_OpenManyFileDialog.sbr"
	-@erase "$(INTDIR)\krnln_OpenMemFile.obj"
	-@erase "$(INTDIR)\krnln_OpenMemFile.sbr"
	-@erase "$(INTDIR)\krnln_p2double.obj"
	-@erase "$(INTDIR)\krnln_p2double.sbr"
	-@erase "$(INTDIR)\krnln_p2float.obj"
	-@erase "$(INTDIR)\krnln_p2float.sbr"
	-@erase "$(INTDIR)\krnln_p2int.obj"
	-@erase "$(INTDIR)\krnln_p2int.sbr"
	-@erase "$(INTDIR)\krnln_pbin.obj"
	-@erase "$(INTDIR)\krnln_pbin.sbr"
	-@erase "$(INTDIR)\krnln_ping.obj"
	-@erase "$(INTDIR)\krnln_ping.sbr"
	-@erase "$(INTDIR)\krnln_PlayMID.obj"
	-@erase "$(INTDIR)\krnln_PlayMID.sbr"
	-@erase "$(INTDIR)\krnln_PlayMusic.obj"
	-@erase "$(INTDIR)\krnln_PlayMusic.sbr"
	-@erase "$(INTDIR)\krnln_PlayStop.obj"
	-@erase "$(INTDIR)\krnln_PlayStop.sbr"
	-@erase "$(INTDIR)\krnln_pow.obj"
	-@erase "$(INTDIR)\krnln_pow.sbr"
	-@erase "$(INTDIR)\krnln_pstr.obj"
	-@erase "$(INTDIR)\krnln_pstr.sbr"
	-@erase "$(INTDIR)\krnln_PutEnv.obj"
	-@erase "$(INTDIR)\krnln_PutEnv.sbr"
	-@erase "$(INTDIR)\krnln_QJCase.obj"
	-@erase "$(INTDIR)\krnln_QJCase.sbr"
	-@erase "$(INTDIR)\krnln_randomize.obj"
	-@erase "$(INTDIR)\krnln_randomize.sbr"
	-@erase "$(INTDIR)\krnln_read.obj"
	-@erase "$(INTDIR)\krnln_read.sbr"
	-@erase "$(INTDIR)\krnln_ReadBin.obj"
	-@erase "$(INTDIR)\krnln_ReadBin.sbr"
	-@erase "$(INTDIR)\krnln_ReadFile.obj"
	-@erase "$(INTDIR)\krnln_ReadFile.sbr"
	-@erase "$(INTDIR)\krnln_ReadLine.obj"
	-@erase "$(INTDIR)\krnln_ReadLine.sbr"
	-@erase "$(INTDIR)\krnln_ReadText.obj"
	-@erase "$(INTDIR)\krnln_ReadText.sbr"
	-@erase "$(INTDIR)\krnln_RemoveData.obj"
	-@erase "$(INTDIR)\krnln_RemoveData.sbr"
	-@erase "$(INTDIR)\krnln_ReplaceText.obj"
	-@erase "$(INTDIR)\krnln_ReplaceText.sbr"
	-@erase "$(INTDIR)\krnln_reset.obj"
	-@erase "$(INTDIR)\krnln_reset.sbr"
	-@erase "$(INTDIR)\krnln_RestroeCursor.obj"
	-@erase "$(INTDIR)\krnln_RestroeCursor.sbr"
	-@erase "$(INTDIR)\krnln_ReverseIntBytes.obj"
	-@erase "$(INTDIR)\krnln_ReverseIntBytes.sbr"
	-@erase "$(INTDIR)\krnln_rgb.obj"
	-@erase "$(INTDIR)\krnln_rgb.sbr"
	-@erase "$(INTDIR)\krnln_right.obj"
	-@erase "$(INTDIR)\krnln_right.sbr"
	-@erase "$(INTDIR)\krnln_RmDir.obj"
	-@erase "$(INTDIR)\krnln_RmDir.sbr"
	-@erase "$(INTDIR)\krnln_rnd.obj"
	-@erase "$(INTDIR)\krnln_rnd.sbr"
	-@erase "$(INTDIR)\krnln_round.obj"
	-@erase "$(INTDIR)\krnln_round.sbr"
	-@erase "$(INTDIR)\krnln_RpBin.obj"
	-@erase "$(INTDIR)\krnln_RpBin.sbr"
	-@erase "$(INTDIR)\krnln_RpSubBin.obj"
	-@erase "$(INTDIR)\krnln_RpSubBin.sbr"
	-@erase "$(INTDIR)\krnln_RpSubText.obj"
	-@erase "$(INTDIR)\krnln_RpSubText.sbr"
	-@erase "$(INTDIR)\krnln_RTrim.obj"
	-@erase "$(INTDIR)\krnln_RTrim.sbr"
	-@erase "$(INTDIR)\krnln_run.obj"
	-@erase "$(INTDIR)\krnln_run.sbr"
	-@erase "$(INTDIR)\krnln_RunConsoleApp.obj"
	-@erase "$(INTDIR)\krnln_RunConsoleApp.sbr"
	-@erase "$(INTDIR)\krnln_SaveRegItem.obj"
	-@erase "$(INTDIR)\krnln_SaveRegItem.sbr"
	-@erase "$(INTDIR)\krnln_second.obj"
	-@erase "$(INTDIR)\krnln_second.sbr"
	-@erase "$(INTDIR)\krnln_SeekToBegin.obj"
	-@erase "$(INTDIR)\krnln_SeekToBegin.sbr"
	-@erase "$(INTDIR)\krnln_SeekToEnd.obj"
	-@erase "$(INTDIR)\krnln_SeekToEnd.sbr"
	-@erase "$(INTDIR)\krnln_SetAttr.obj"
	-@erase "$(INTDIR)\krnln_SetAttr.sbr"
	-@erase "$(INTDIR)\krnln_SetClipBoardText.obj"
	-@erase "$(INTDIR)\krnln_SetClipBoardText.sbr"
	-@erase "$(INTDIR)\krnln_SetDiskLabel.obj"
	-@erase "$(INTDIR)\krnln_SetDiskLabel.sbr"
	-@erase "$(INTDIR)\krnln_SetIntInsideBin.obj"
	-@erase "$(INTDIR)\krnln_SetIntInsideBin.sbr"
	-@erase "$(INTDIR)\krnln_SetKeyText.obj"
	-@erase "$(INTDIR)\krnln_SetKeyText.sbr"
	-@erase "$(INTDIR)\krnln_SetSysTime.obj"
	-@erase "$(INTDIR)\krnln_SetSysTime.sbr"
	-@erase "$(INTDIR)\krnln_SetWaitCursor.obj"
	-@erase "$(INTDIR)\krnln_SetWaitCursor.sbr"
	-@erase "$(INTDIR)\krnln_sgn.obj"
	-@erase "$(INTDIR)\krnln_sgn.sbr"
	-@erase "$(INTDIR)\krnln_shl.obj"
	-@erase "$(INTDIR)\krnln_shl.sbr"
	-@erase "$(INTDIR)\krnln_shr.obj"
	-@erase "$(INTDIR)\krnln_shr.sbr"
	-@erase "$(INTDIR)\krnln_sin.obj"
	-@erase "$(INTDIR)\krnln_sin.sbr"
	-@erase "$(INTDIR)\krnln_sleep.obj"
	-@erase "$(INTDIR)\krnln_sleep.sbr"
	-@erase "$(INTDIR)\krnln_SortAry.obj"
	-@erase "$(INTDIR)\krnln_SortAry.sbr"
	-@erase "$(INTDIR)\krnln_space.obj"
	-@erase "$(INTDIR)\krnln_space.sbr"
	-@erase "$(INTDIR)\krnln_SpaceBin.obj"
	-@erase "$(INTDIR)\krnln_SpaceBin.sbr"
	-@erase "$(INTDIR)\krnln_split.obj"
	-@erase "$(INTDIR)\krnln_split.sbr"
	-@erase "$(INTDIR)\krnln_SplitBin.obj"
	-@erase "$(INTDIR)\krnln_SplitBin.sbr"
	-@erase "$(INTDIR)\krnln_sqr.obj"
	-@erase "$(INTDIR)\krnln_sqr.sbr"
	-@erase "$(INTDIR)\krnln_str.obj"
	-@erase "$(INTDIR)\krnln_str.sbr"
	-@erase "$(INTDIR)\krnln_StrComp.obj"
	-@erase "$(INTDIR)\krnln_StrComp.sbr"
	-@erase "$(INTDIR)\krnln_string.obj"
	-@erase "$(INTDIR)\krnln_string.sbr"
	-@erase "$(INTDIR)\krnln_StrToUTF8.obj"
	-@erase "$(INTDIR)\krnln_StrToUTF8.sbr"
	-@erase "$(INTDIR)\krnln_tan.obj"
	-@erase "$(INTDIR)\krnln_tan.sbr"
	-@erase "$(INTDIR)\krnln_TimeChg.obj"
	-@erase "$(INTDIR)\krnln_TimeChg.sbr"
	-@erase "$(INTDIR)\krnln_TimeDiff.obj"
	-@erase "$(INTDIR)\krnln_TimeDiff.sbr"
	-@erase "$(INTDIR)\krnln_TimePart.obj"
	-@erase "$(INTDIR)\krnln_TimePart.sbr"
	-@erase "$(INTDIR)\krnln_TimeToText.obj"
	-@erase "$(INTDIR)\krnln_TimeToText.sbr"
	-@erase "$(INTDIR)\krnln_ToBin.obj"
	-@erase "$(INTDIR)\krnln_ToBin.sbr"
	-@erase "$(INTDIR)\krnln_ToByte.obj"
	-@erase "$(INTDIR)\krnln_ToByte.sbr"
	-@erase "$(INTDIR)\krnln_ToFloat.obj"
	-@erase "$(INTDIR)\krnln_ToFloat.sbr"
	-@erase "$(INTDIR)\krnln_ToInt.obj"
	-@erase "$(INTDIR)\krnln_ToInt.sbr"
	-@erase "$(INTDIR)\krnln_ToLong.obj"
	-@erase "$(INTDIR)\krnln_ToLong.sbr"
	-@erase "$(INTDIR)\krnln_ToShort.obj"
	-@erase "$(INTDIR)\krnln_ToShort.sbr"
	-@erase "$(INTDIR)\krnln_ToTime.obj"
	-@erase "$(INTDIR)\krnln_ToTime.sbr"
	-@erase "$(INTDIR)\krnln_trim.obj"
	-@erase "$(INTDIR)\krnln_trim.sbr"
	-@erase "$(INTDIR)\krnln_TrimAll.obj"
	-@erase "$(INTDIR)\krnln_TrimAll.sbr"
	-@erase "$(INTDIR)\krnln_UCase.obj"
	-@erase "$(INTDIR)\krnln_UCase.sbr"
	-@erase "$(INTDIR)\krnln_Unlock.obj"
	-@erase "$(INTDIR)\krnln_Unlock.sbr"
	-@erase "$(INTDIR)\krnln_UNum.obj"
	-@erase "$(INTDIR)\krnln_UNum.sbr"
	-@erase "$(INTDIR)\krnln_UTF8ToStr.obj"
	-@erase "$(INTDIR)\krnln_UTF8ToStr.sbr"
	-@erase "$(INTDIR)\krnln_val.obj"
	-@erase "$(INTDIR)\krnln_val.sbr"
	-@erase "$(INTDIR)\krnln_Variant.obj"
	-@erase "$(INTDIR)\krnln_Variant.sbr"
	-@erase "$(INTDIR)\krnln_WeekDay.obj"
	-@erase "$(INTDIR)\krnln_WeekDay.sbr"
	-@erase "$(INTDIR)\krnln_write.obj"
	-@erase "$(INTDIR)\krnln_write.sbr"
	-@erase "$(INTDIR)\krnln_WriteBin.obj"
	-@erase "$(INTDIR)\krnln_WriteBin.sbr"
	-@erase "$(INTDIR)\krnln_WriteFile.obj"
	-@erase "$(INTDIR)\krnln_WriteFile.sbr"
	-@erase "$(INTDIR)\krnln_WriteLine.obj"
	-@erase "$(INTDIR)\krnln_WriteLine.sbr"
	-@erase "$(INTDIR)\krnln_WriteMem.obj"
	-@erase "$(INTDIR)\krnln_WriteMem.sbr"
	-@erase "$(INTDIR)\krnln_WriteText.obj"
	-@erase "$(INTDIR)\krnln_WriteText.sbr"
	-@erase "$(INTDIR)\krnln_year.obj"
	-@erase "$(INTDIR)\krnln_year.sbr"
	-@erase "$(INTDIR)\krnln_ZeroAry.obj"
	-@erase "$(INTDIR)\krnln_ZeroAry.sbr"
	-@erase "$(INTDIR)\LTrimZeroChr.obj"
	-@erase "$(INTDIR)\LTrimZeroChr.sbr"
	-@erase "$(INTDIR)\md5t.obj"
	-@erase "$(INTDIR)\md5t.sbr"
	-@erase "$(INTDIR)\mem.obj"
	-@erase "$(INTDIR)\mem.sbr"
	-@erase "$(INTDIR)\midi.obj"
	-@erase "$(INTDIR)\midi.sbr"
	-@erase "$(INTDIR)\Myfunctions.obj"
	-@erase "$(INTDIR)\Myfunctions.sbr"
	-@erase "$(INTDIR)\MyMemFile.obj"
	-@erase "$(INTDIR)\MyMemFile.sbr"
	-@erase "$(INTDIR)\NumToChinese.obj"
	-@erase "$(INTDIR)\NumToChinese.sbr"
	-@erase "$(INTDIR)\replaceText.obj"
	-@erase "$(INTDIR)\replaceText.sbr"
	-@erase "$(INTDIR)\SDataToStr.obj"
	-@erase "$(INTDIR)\SDataToStr.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\krnln.bsc"
	-@erase "$(OUTDIR)\krnln.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\krnln.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

RSC=rc.exe
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\krnln.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\BlackMoonCallPropertyVaule.sbr" \
	"$(INTDIR)\BlackMoonCallUserDll.sbr" \
	"$(INTDIR)\BlackMoonLibNotifySys.sbr" \
	"$(INTDIR)\CloneBinData.sbr" \
	"$(INTDIR)\CloneTextData.sbr" \
	"$(INTDIR)\DateTimeFormat.sbr" \
	"$(INTDIR)\DllEntryFunc.sbr" \
	"$(INTDIR)\eHelpFunc.sbr" \
	"$(INTDIR)\FileManager.sbr" \
	"$(INTDIR)\FreeAryElement.sbr" \
	"$(INTDIR)\GetAryElementInf.sbr" \
	"$(INTDIR)\GetDataTypeType.sbr" \
	"$(INTDIR)\GetDatePart.sbr" \
	"$(INTDIR)\GetDaysOfSpecMonth.sbr" \
	"$(INTDIR)\GetRegRootVal.sbr" \
	"$(INTDIR)\GetSpecTime.sbr" \
	"$(INTDIR)\GetSysDataTypeDataSize.sbr" \
	"$(INTDIR)\GetTimePart.sbr" \
	"$(INTDIR)\GetWeekDay.sbr" \
	"$(INTDIR)\HelpFunc12.sbr" \
	"$(INTDIR)\IsInFileMangerList.sbr" \
	"$(INTDIR)\krnln_abs.sbr" \
	"$(INTDIR)\krnln_asc.sbr" \
	"$(INTDIR)\krnln_atn.sbr" \
	"$(INTDIR)\krnln_band.sbr" \
	"$(INTDIR)\krnln_beep.sbr" \
	"$(INTDIR)\krnln_bin.sbr" \
	"$(INTDIR)\krnln_BinLeft.sbr" \
	"$(INTDIR)\krnln_BinLen.sbr" \
	"$(INTDIR)\krnln_BinMid.sbr" \
	"$(INTDIR)\krnln_BinRight.sbr" \
	"$(INTDIR)\krnln_BJCase.sbr" \
	"$(INTDIR)\krnln_bnot.sbr" \
	"$(INTDIR)\krnln_bor.sbr" \
	"$(INTDIR)\krnln_bxor.sbr" \
	"$(INTDIR)\krnln_ChDir.sbr" \
	"$(INTDIR)\krnln_ChDrive.sbr" \
	"$(INTDIR)\krnln_chr.sbr" \
	"$(INTDIR)\krnln_ClearClipBoard.sbr" \
	"$(INTDIR)\krnln_close.sbr" \
	"$(INTDIR)\krnln_cos.sbr" \
	"$(INTDIR)\krnln_CryptOpen.sbr" \
	"$(INTDIR)\krnln_CurDir.sbr" \
	"$(INTDIR)\krnln_day.sbr" \
	"$(INTDIR)\krnln_DeleteRegItem.sbr" \
	"$(INTDIR)\krnln_Dispatch.sbr" \
	"$(INTDIR)\krnln_DoEvents.sbr" \
	"$(INTDIR)\krnln_exp.sbr" \
	"$(INTDIR)\krnln_feof.sbr" \
	"$(INTDIR)\krnln_fgets.sbr" \
	"$(INTDIR)\krnln_FileCopy.sbr" \
	"$(INTDIR)\krnln_FileDateTime.sbr" \
	"$(INTDIR)\krnln_FileLen.sbr" \
	"$(INTDIR)\krnln_FileMove.sbr" \
	"$(INTDIR)\krnln_fix.sbr" \
	"$(INTDIR)\krnln_fputs.sbr" \
	"$(INTDIR)\krnln_FSeek.sbr" \
	"$(INTDIR)\krnln_GetAllPY.sbr" \
	"$(INTDIR)\krnln_GetAttr.sbr" \
	"$(INTDIR)\krnln_GetBackColor.sbr" \
	"$(INTDIR)\krnln_GetBinElement.sbr" \
	"$(INTDIR)\krnln_GetBinRegItem.sbr" \
	"$(INTDIR)\krnln_GetClipBoardText.sbr" \
	"$(INTDIR)\krnln_GetCmdLine.sbr" \
	"$(INTDIR)\krnln_GetColorCount.sbr" \
	"$(INTDIR)\krnln_GetCursorHorzPos.sbr" \
	"$(INTDIR)\krnln_GetCursorVertPos.sbr" \
	"$(INTDIR)\krnln_GetDataTypeSize.sbr" \
	"$(INTDIR)\krnln_GetDatePart.sbr" \
	"$(INTDIR)\krnln_GetDaysOfSpecMonth.sbr" \
	"$(INTDIR)\krnln_GetDiskFreeSpace.sbr" \
	"$(INTDIR)\krnln_GetDiskLabel.sbr" \
	"$(INTDIR)\krnln_GetDiskTotalSpace.sbr" \
	"$(INTDIR)\krnln_GetEnv.sbr" \
	"$(INTDIR)\krnln_GetHDiskCode.sbr" \
	"$(INTDIR)\krnln_GetHostName.sbr" \
	"$(INTDIR)\krnln_GetIntInsideBin.sbr" \
	"$(INTDIR)\krnln_GetKeyText.sbr" \
	"$(INTDIR)\krnln_GetLastError.sbr" \
	"$(INTDIR)\krnln_GetNumRegItem.sbr" \
	"$(INTDIR)\krnln_GetRunFileName.sbr" \
	"$(INTDIR)\krnln_GetRunPath.sbr" \
	"$(INTDIR)\krnln_GetRuntimeDataType.sbr" \
	"$(INTDIR)\krnln_GetScreenHeight.sbr" \
	"$(INTDIR)\krnln_GetScreenWidth.sbr" \
	"$(INTDIR)\krnln_GetSectionNames.sbr" \
	"$(INTDIR)\krnln_GetSpecTime.sbr" \
	"$(INTDIR)\krnln_GetSysVer.sbr" \
	"$(INTDIR)\krnln_GetTempFileName.sbr" \
	"$(INTDIR)\krnln_GetTextRegItem.sbr" \
	"$(INTDIR)\krnln_GetTickCount.sbr" \
	"$(INTDIR)\krnln_GetTimePart.sbr" \
	"$(INTDIR)\krnln_GetWinPic.sbr" \
	"$(INTDIR)\krnln_hex.sbr" \
	"$(INTDIR)\krnln_HostNameToIP.sbr" \
	"$(INTDIR)\krnln_hour.sbr" \
	"$(INTDIR)\krnln_IDiv.sbr" \
	"$(INTDIR)\krnln_InBin.sbr" \
	"$(INTDIR)\krnln_InBinRev.sbr" \
	"$(INTDIR)\krnln_InputBox.sbr" \
	"$(INTDIR)\krnln_InsBin.sbr" \
	"$(INTDIR)\krnln_InsLine.sbr" \
	"$(INTDIR)\krnln_InsText.sbr" \
	"$(INTDIR)\krnln_InStr.sbr" \
	"$(INTDIR)\krnln_InStrRev.sbr" \
	"$(INTDIR)\krnln_int.sbr" \
	"$(INTDIR)\krnln_IPToHostName.sbr" \
	"$(INTDIR)\krnln_IsCalcOK.sbr" \
	"$(INTDIR)\krnln_IsFileExist.sbr" \
	"$(INTDIR)\krnln_IsHaveTextInClip.sbr" \
	"$(INTDIR)\krnln_IsRegItemExist.sbr" \
	"$(INTDIR)\krnln_kill.sbr" \
	"$(INTDIR)\krnln_LCase.sbr" \
	"$(INTDIR)\krnln_left.sbr" \
	"$(INTDIR)\krnln_len.sbr" \
	"$(INTDIR)\krnln_like.sbr" \
	"$(INTDIR)\krnln_loc.sbr" \
	"$(INTDIR)\krnln_lock.sbr" \
	"$(INTDIR)\krnln_lof.sbr" \
	"$(INTDIR)\krnln_log.sbr" \
	"$(INTDIR)\krnln_LTrim.sbr" \
	"$(INTDIR)\krnln_MakeLong.sbr" \
	"$(INTDIR)\krnln_MakeWord.sbr" \
	"$(INTDIR)\krnln_mid.sbr" \
	"$(INTDIR)\krnln_minute.sbr" \
	"$(INTDIR)\krnln_MkDir.sbr" \
	"$(INTDIR)\krnln_mod.sbr" \
	"$(INTDIR)\krnln_month.sbr" \
	"$(INTDIR)\krnln_MsgBox.sbr" \
	"$(INTDIR)\krnln_name.sbr" \
	"$(INTDIR)\krnln_now.sbr" \
	"$(INTDIR)\krnln_NumToRMB.sbr" \
	"$(INTDIR)\krnln_NumToText.sbr" \
	"$(INTDIR)\krnln_oct.sbr" \
	"$(INTDIR)\krnln_open.sbr" \
	"$(INTDIR)\krnln_OpenManyFileDialog.sbr" \
	"$(INTDIR)\krnln_OpenMemFile.sbr" \
	"$(INTDIR)\krnln_p2double.sbr" \
	"$(INTDIR)\krnln_p2float.sbr" \
	"$(INTDIR)\krnln_p2int.sbr" \
	"$(INTDIR)\krnln_pbin.sbr" \
	"$(INTDIR)\krnln_ping.sbr" \
	"$(INTDIR)\krnln_PlayMID.sbr" \
	"$(INTDIR)\krnln_PlayMusic.sbr" \
	"$(INTDIR)\krnln_PlayStop.sbr" \
	"$(INTDIR)\krnln_pow.sbr" \
	"$(INTDIR)\krnln_pstr.sbr" \
	"$(INTDIR)\krnln_PutEnv.sbr" \
	"$(INTDIR)\krnln_QJCase.sbr" \
	"$(INTDIR)\krnln_randomize.sbr" \
	"$(INTDIR)\krnln_read.sbr" \
	"$(INTDIR)\krnln_ReadBin.sbr" \
	"$(INTDIR)\krnln_ReadFile.sbr" \
	"$(INTDIR)\krnln_ReadLine.sbr" \
	"$(INTDIR)\krnln_ReadText.sbr" \
	"$(INTDIR)\krnln_RemoveData.sbr" \
	"$(INTDIR)\krnln_ReplaceText.sbr" \
	"$(INTDIR)\krnln_reset.sbr" \
	"$(INTDIR)\krnln_RestroeCursor.sbr" \
	"$(INTDIR)\krnln_ReverseIntBytes.sbr" \
	"$(INTDIR)\krnln_rgb.sbr" \
	"$(INTDIR)\krnln_right.sbr" \
	"$(INTDIR)\krnln_RmDir.sbr" \
	"$(INTDIR)\krnln_rnd.sbr" \
	"$(INTDIR)\krnln_round.sbr" \
	"$(INTDIR)\krnln_RpBin.sbr" \
	"$(INTDIR)\krnln_RpSubBin.sbr" \
	"$(INTDIR)\krnln_RpSubText.sbr" \
	"$(INTDIR)\krnln_RTrim.sbr" \
	"$(INTDIR)\krnln_run.sbr" \
	"$(INTDIR)\krnln_RunConsoleApp.sbr" \
	"$(INTDIR)\krnln_SaveRegItem.sbr" \
	"$(INTDIR)\krnln_second.sbr" \
	"$(INTDIR)\krnln_SeekToBegin.sbr" \
	"$(INTDIR)\krnln_SeekToEnd.sbr" \
	"$(INTDIR)\krnln_SetAttr.sbr" \
	"$(INTDIR)\krnln_SetClipBoardText.sbr" \
	"$(INTDIR)\krnln_SetDiskLabel.sbr" \
	"$(INTDIR)\krnln_SetIntInsideBin.sbr" \
	"$(INTDIR)\krnln_SetKeyText.sbr" \
	"$(INTDIR)\krnln_SetSysTime.sbr" \
	"$(INTDIR)\krnln_SetWaitCursor.sbr" \
	"$(INTDIR)\krnln_sgn.sbr" \
	"$(INTDIR)\krnln_shl.sbr" \
	"$(INTDIR)\krnln_shr.sbr" \
	"$(INTDIR)\krnln_sin.sbr" \
	"$(INTDIR)\krnln_sleep.sbr" \
	"$(INTDIR)\krnln_SortAry.sbr" \
	"$(INTDIR)\krnln_space.sbr" \
	"$(INTDIR)\krnln_SpaceBin.sbr" \
	"$(INTDIR)\krnln_split.sbr" \
	"$(INTDIR)\krnln_SplitBin.sbr" \
	"$(INTDIR)\krnln_sqr.sbr" \
	"$(INTDIR)\krnln_str.sbr" \
	"$(INTDIR)\krnln_StrComp.sbr" \
	"$(INTDIR)\krnln_string.sbr" \
	"$(INTDIR)\krnln_StrToUTF8.sbr" \
	"$(INTDIR)\krnln_tan.sbr" \
	"$(INTDIR)\krnln_TimeChg.sbr" \
	"$(INTDIR)\krnln_TimeDiff.sbr" \
	"$(INTDIR)\krnln_TimePart.sbr" \
	"$(INTDIR)\krnln_TimeToText.sbr" \
	"$(INTDIR)\krnln_ToBin.sbr" \
	"$(INTDIR)\krnln_ToByte.sbr" \
	"$(INTDIR)\krnln_ToFloat.sbr" \
	"$(INTDIR)\krnln_ToInt.sbr" \
	"$(INTDIR)\krnln_ToLong.sbr" \
	"$(INTDIR)\krnln_ToShort.sbr" \
	"$(INTDIR)\krnln_ToTime.sbr" \
	"$(INTDIR)\krnln_trim.sbr" \
	"$(INTDIR)\krnln_TrimAll.sbr" \
	"$(INTDIR)\krnln_UCase.sbr" \
	"$(INTDIR)\krnln_Unlock.sbr" \
	"$(INTDIR)\krnln_UNum.sbr" \
	"$(INTDIR)\krnln_UTF8ToStr.sbr" \
	"$(INTDIR)\krnln_val.sbr" \
	"$(INTDIR)\krnln_Variant.sbr" \
	"$(INTDIR)\krnln_WeekDay.sbr" \
	"$(INTDIR)\krnln_write.sbr" \
	"$(INTDIR)\krnln_WriteBin.sbr" \
	"$(INTDIR)\krnln_WriteFile.sbr" \
	"$(INTDIR)\krnln_WriteLine.sbr" \
	"$(INTDIR)\krnln_WriteMem.sbr" \
	"$(INTDIR)\krnln_WriteText.sbr" \
	"$(INTDIR)\krnln_year.sbr" \
	"$(INTDIR)\krnln_ZeroAry.sbr" \
	"$(INTDIR)\LTrimZeroChr.sbr" \
	"$(INTDIR)\md5t.sbr" \
	"$(INTDIR)\mem.sbr" \
	"$(INTDIR)\midi.sbr" \
	"$(INTDIR)\Myfunctions.sbr" \
	"$(INTDIR)\MyMemFile.sbr" \
	"$(INTDIR)\NumToChinese.sbr" \
	"$(INTDIR)\replaceText.sbr" \
	"$(INTDIR)\SDataToStr.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\krnln.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LIB32=link.exe -lib
LIB32_FLAGS=/nologo /out:"$(OUTDIR)\krnln.lib" 
LIB32_OBJS= \
	"$(INTDIR)\BlackMoonCallPropertyVaule.obj" \
	"$(INTDIR)\BlackMoonCallUserDll.obj" \
	"$(INTDIR)\BlackMoonLibNotifySys.obj" \
	"$(INTDIR)\CloneBinData.obj" \
	"$(INTDIR)\CloneTextData.obj" \
	"$(INTDIR)\DateTimeFormat.obj" \
	"$(INTDIR)\DllEntryFunc.obj" \
	"$(INTDIR)\eHelpFunc.obj" \
	"$(INTDIR)\FileManager.obj" \
	"$(INTDIR)\FreeAryElement.obj" \
	"$(INTDIR)\GetAryElementInf.obj" \
	"$(INTDIR)\GetDataTypeType.obj" \
	"$(INTDIR)\GetDatePart.obj" \
	"$(INTDIR)\GetDaysOfSpecMonth.obj" \
	"$(INTDIR)\GetRegRootVal.obj" \
	"$(INTDIR)\GetSpecTime.obj" \
	"$(INTDIR)\GetSysDataTypeDataSize.obj" \
	"$(INTDIR)\GetTimePart.obj" \
	"$(INTDIR)\GetWeekDay.obj" \
	"$(INTDIR)\HelpFunc12.obj" \
	"$(INTDIR)\IsInFileMangerList.obj" \
	"$(INTDIR)\krnln_abs.obj" \
	"$(INTDIR)\krnln_asc.obj" \
	"$(INTDIR)\krnln_atn.obj" \
	"$(INTDIR)\krnln_band.obj" \
	"$(INTDIR)\krnln_beep.obj" \
	"$(INTDIR)\krnln_bin.obj" \
	"$(INTDIR)\krnln_BinLeft.obj" \
	"$(INTDIR)\krnln_BinLen.obj" \
	"$(INTDIR)\krnln_BinMid.obj" \
	"$(INTDIR)\krnln_BinRight.obj" \
	"$(INTDIR)\krnln_BJCase.obj" \
	"$(INTDIR)\krnln_bnot.obj" \
	"$(INTDIR)\krnln_bor.obj" \
	"$(INTDIR)\krnln_bxor.obj" \
	"$(INTDIR)\krnln_ChDir.obj" \
	"$(INTDIR)\krnln_ChDrive.obj" \
	"$(INTDIR)\krnln_chr.obj" \
	"$(INTDIR)\krnln_ClearClipBoard.obj" \
	"$(INTDIR)\krnln_close.obj" \
	"$(INTDIR)\krnln_cos.obj" \
	"$(INTDIR)\krnln_CryptOpen.obj" \
	"$(INTDIR)\krnln_CurDir.obj" \
	"$(INTDIR)\krnln_day.obj" \
	"$(INTDIR)\krnln_DeleteRegItem.obj" \
	"$(INTDIR)\krnln_Dispatch.obj" \
	"$(INTDIR)\krnln_DoEvents.obj" \
	"$(INTDIR)\krnln_exp.obj" \
	"$(INTDIR)\krnln_feof.obj" \
	"$(INTDIR)\krnln_fgets.obj" \
	"$(INTDIR)\krnln_FileCopy.obj" \
	"$(INTDIR)\krnln_FileDateTime.obj" \
	"$(INTDIR)\krnln_FileLen.obj" \
	"$(INTDIR)\krnln_FileMove.obj" \
	"$(INTDIR)\krnln_fix.obj" \
	"$(INTDIR)\krnln_fputs.obj" \
	"$(INTDIR)\krnln_FSeek.obj" \
	"$(INTDIR)\krnln_GetAllPY.obj" \
	"$(INTDIR)\krnln_GetAttr.obj" \
	"$(INTDIR)\krnln_GetBackColor.obj" \
	"$(INTDIR)\krnln_GetBinElement.obj" \
	"$(INTDIR)\krnln_GetBinRegItem.obj" \
	"$(INTDIR)\krnln_GetClipBoardText.obj" \
	"$(INTDIR)\krnln_GetCmdLine.obj" \
	"$(INTDIR)\krnln_GetColorCount.obj" \
	"$(INTDIR)\krnln_GetCursorHorzPos.obj" \
	"$(INTDIR)\krnln_GetCursorVertPos.obj" \
	"$(INTDIR)\krnln_GetDataTypeSize.obj" \
	"$(INTDIR)\krnln_GetDatePart.obj" \
	"$(INTDIR)\krnln_GetDaysOfSpecMonth.obj" \
	"$(INTDIR)\krnln_GetDiskFreeSpace.obj" \
	"$(INTDIR)\krnln_GetDiskLabel.obj" \
	"$(INTDIR)\krnln_GetDiskTotalSpace.obj" \
	"$(INTDIR)\krnln_GetEnv.obj" \
	"$(INTDIR)\krnln_GetHDiskCode.obj" \
	"$(INTDIR)\krnln_GetHostName.obj" \
	"$(INTDIR)\krnln_GetIntInsideBin.obj" \
	"$(INTDIR)\krnln_GetKeyText.obj" \
	"$(INTDIR)\krnln_GetLastError.obj" \
	"$(INTDIR)\krnln_GetNumRegItem.obj" \
	"$(INTDIR)\krnln_GetRunFileName.obj" \
	"$(INTDIR)\krnln_GetRunPath.obj" \
	"$(INTDIR)\krnln_GetRuntimeDataType.obj" \
	"$(INTDIR)\krnln_GetScreenHeight.obj" \
	"$(INTDIR)\krnln_GetScreenWidth.obj" \
	"$(INTDIR)\krnln_GetSectionNames.obj" \
	"$(INTDIR)\krnln_GetSpecTime.obj" \
	"$(INTDIR)\krnln_GetSysVer.obj" \
	"$(INTDIR)\krnln_GetTempFileName.obj" \
	"$(INTDIR)\krnln_GetTextRegItem.obj" \
	"$(INTDIR)\krnln_GetTickCount.obj" \
	"$(INTDIR)\krnln_GetTimePart.obj" \
	"$(INTDIR)\krnln_GetWinPic.obj" \
	"$(INTDIR)\krnln_hex.obj" \
	"$(INTDIR)\krnln_HostNameToIP.obj" \
	"$(INTDIR)\krnln_hour.obj" \
	"$(INTDIR)\krnln_IDiv.obj" \
	"$(INTDIR)\krnln_InBin.obj" \
	"$(INTDIR)\krnln_InBinRev.obj" \
	"$(INTDIR)\krnln_InputBox.obj" \
	"$(INTDIR)\krnln_InsBin.obj" \
	"$(INTDIR)\krnln_InsLine.obj" \
	"$(INTDIR)\krnln_InsText.obj" \
	"$(INTDIR)\krnln_InStr.obj" \
	"$(INTDIR)\krnln_InStrRev.obj" \
	"$(INTDIR)\krnln_int.obj" \
	"$(INTDIR)\krnln_IPToHostName.obj" \
	"$(INTDIR)\krnln_IsCalcOK.obj" \
	"$(INTDIR)\krnln_IsFileExist.obj" \
	"$(INTDIR)\krnln_IsHaveTextInClip.obj" \
	"$(INTDIR)\krnln_IsRegItemExist.obj" \
	"$(INTDIR)\krnln_kill.obj" \
	"$(INTDIR)\krnln_LCase.obj" \
	"$(INTDIR)\krnln_left.obj" \
	"$(INTDIR)\krnln_len.obj" \
	"$(INTDIR)\krnln_like.obj" \
	"$(INTDIR)\krnln_loc.obj" \
	"$(INTDIR)\krnln_lock.obj" \
	"$(INTDIR)\krnln_lof.obj" \
	"$(INTDIR)\krnln_log.obj" \
	"$(INTDIR)\krnln_LTrim.obj" \
	"$(INTDIR)\krnln_MakeLong.obj" \
	"$(INTDIR)\krnln_MakeWord.obj" \
	"$(INTDIR)\krnln_mid.obj" \
	"$(INTDIR)\krnln_minute.obj" \
	"$(INTDIR)\krnln_MkDir.obj" \
	"$(INTDIR)\krnln_mod.obj" \
	"$(INTDIR)\krnln_month.obj" \
	"$(INTDIR)\krnln_MsgBox.obj" \
	"$(INTDIR)\krnln_name.obj" \
	"$(INTDIR)\krnln_now.obj" \
	"$(INTDIR)\krnln_NumToRMB.obj" \
	"$(INTDIR)\krnln_NumToText.obj" \
	"$(INTDIR)\krnln_oct.obj" \
	"$(INTDIR)\krnln_open.obj" \
	"$(INTDIR)\krnln_OpenManyFileDialog.obj" \
	"$(INTDIR)\krnln_OpenMemFile.obj" \
	"$(INTDIR)\krnln_p2double.obj" \
	"$(INTDIR)\krnln_p2float.obj" \
	"$(INTDIR)\krnln_p2int.obj" \
	"$(INTDIR)\krnln_pbin.obj" \
	"$(INTDIR)\krnln_ping.obj" \
	"$(INTDIR)\krnln_PlayMID.obj" \
	"$(INTDIR)\krnln_PlayMusic.obj" \
	"$(INTDIR)\krnln_PlayStop.obj" \
	"$(INTDIR)\krnln_pow.obj" \
	"$(INTDIR)\krnln_pstr.obj" \
	"$(INTDIR)\krnln_PutEnv.obj" \
	"$(INTDIR)\krnln_QJCase.obj" \
	"$(INTDIR)\krnln_randomize.obj" \
	"$(INTDIR)\krnln_read.obj" \
	"$(INTDIR)\krnln_ReadBin.obj" \
	"$(INTDIR)\krnln_ReadFile.obj" \
	"$(INTDIR)\krnln_ReadLine.obj" \
	"$(INTDIR)\krnln_ReadText.obj" \
	"$(INTDIR)\krnln_RemoveData.obj" \
	"$(INTDIR)\krnln_ReplaceText.obj" \
	"$(INTDIR)\krnln_reset.obj" \
	"$(INTDIR)\krnln_RestroeCursor.obj" \
	"$(INTDIR)\krnln_ReverseIntBytes.obj" \
	"$(INTDIR)\krnln_rgb.obj" \
	"$(INTDIR)\krnln_right.obj" \
	"$(INTDIR)\krnln_RmDir.obj" \
	"$(INTDIR)\krnln_rnd.obj" \
	"$(INTDIR)\krnln_round.obj" \
	"$(INTDIR)\krnln_RpBin.obj" \
	"$(INTDIR)\krnln_RpSubBin.obj" \
	"$(INTDIR)\krnln_RpSubText.obj" \
	"$(INTDIR)\krnln_RTrim.obj" \
	"$(INTDIR)\krnln_run.obj" \
	"$(INTDIR)\krnln_RunConsoleApp.obj" \
	"$(INTDIR)\krnln_SaveRegItem.obj" \
	"$(INTDIR)\krnln_second.obj" \
	"$(INTDIR)\krnln_SeekToBegin.obj" \
	"$(INTDIR)\krnln_SeekToEnd.obj" \
	"$(INTDIR)\krnln_SetAttr.obj" \
	"$(INTDIR)\krnln_SetClipBoardText.obj" \
	"$(INTDIR)\krnln_SetDiskLabel.obj" \
	"$(INTDIR)\krnln_SetIntInsideBin.obj" \
	"$(INTDIR)\krnln_SetKeyText.obj" \
	"$(INTDIR)\krnln_SetSysTime.obj" \
	"$(INTDIR)\krnln_SetWaitCursor.obj" \
	"$(INTDIR)\krnln_sgn.obj" \
	"$(INTDIR)\krnln_shl.obj" \
	"$(INTDIR)\krnln_shr.obj" \
	"$(INTDIR)\krnln_sin.obj" \
	"$(INTDIR)\krnln_sleep.obj" \
	"$(INTDIR)\krnln_SortAry.obj" \
	"$(INTDIR)\krnln_space.obj" \
	"$(INTDIR)\krnln_SpaceBin.obj" \
	"$(INTDIR)\krnln_split.obj" \
	"$(INTDIR)\krnln_SplitBin.obj" \
	"$(INTDIR)\krnln_sqr.obj" \
	"$(INTDIR)\krnln_str.obj" \
	"$(INTDIR)\krnln_StrComp.obj" \
	"$(INTDIR)\krnln_string.obj" \
	"$(INTDIR)\krnln_StrToUTF8.obj" \
	"$(INTDIR)\krnln_tan.obj" \
	"$(INTDIR)\krnln_TimeChg.obj" \
	"$(INTDIR)\krnln_TimeDiff.obj" \
	"$(INTDIR)\krnln_TimePart.obj" \
	"$(INTDIR)\krnln_TimeToText.obj" \
	"$(INTDIR)\krnln_ToBin.obj" \
	"$(INTDIR)\krnln_ToByte.obj" \
	"$(INTDIR)\krnln_ToFloat.obj" \
	"$(INTDIR)\krnln_ToInt.obj" \
	"$(INTDIR)\krnln_ToLong.obj" \
	"$(INTDIR)\krnln_ToShort.obj" \
	"$(INTDIR)\krnln_ToTime.obj" \
	"$(INTDIR)\krnln_trim.obj" \
	"$(INTDIR)\krnln_TrimAll.obj" \
	"$(INTDIR)\krnln_UCase.obj" \
	"$(INTDIR)\krnln_Unlock.obj" \
	"$(INTDIR)\krnln_UNum.obj" \
	"$(INTDIR)\krnln_UTF8ToStr.obj" \
	"$(INTDIR)\krnln_val.obj" \
	"$(INTDIR)\krnln_Variant.obj" \
	"$(INTDIR)\krnln_WeekDay.obj" \
	"$(INTDIR)\krnln_write.obj" \
	"$(INTDIR)\krnln_WriteBin.obj" \
	"$(INTDIR)\krnln_WriteFile.obj" \
	"$(INTDIR)\krnln_WriteLine.obj" \
	"$(INTDIR)\krnln_WriteMem.obj" \
	"$(INTDIR)\krnln_WriteText.obj" \
	"$(INTDIR)\krnln_year.obj" \
	"$(INTDIR)\krnln_ZeroAry.obj" \
	"$(INTDIR)\LTrimZeroChr.obj" \
	"$(INTDIR)\md5t.obj" \
	"$(INTDIR)\mem.obj" \
	"$(INTDIR)\midi.obj" \
	"$(INTDIR)\Myfunctions.obj" \
	"$(INTDIR)\MyMemFile.obj" \
	"$(INTDIR)\NumToChinese.obj" \
	"$(INTDIR)\replaceText.obj" \
	"$(INTDIR)\SDataToStr.obj" \
	"$(INTDIR)\StdAfx.obj" \
	".\krnln\Diskid32.obj" \
	".\krnln\PY.OBJ"

"$(OUTDIR)\krnln.lib" : "$(OUTDIR)" $(DEF_FILE) $(LIB32_OBJS)
    $(LIB32) @<<
  $(LIB32_FLAGS) $(DEF_FLAGS) $(LIB32_OBJS)
<<

!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\krnln.lib"


CLEAN :
	-@erase "$(INTDIR)\BlackMoonCallPropertyVaule.obj"
	-@erase "$(INTDIR)\BlackMoonCallUserDll.obj"
	-@erase "$(INTDIR)\BlackMoonLibNotifySys.obj"
	-@erase "$(INTDIR)\CloneBinData.obj"
	-@erase "$(INTDIR)\CloneTextData.obj"
	-@erase "$(INTDIR)\DateTimeFormat.obj"
	-@erase "$(INTDIR)\DllEntryFunc.obj"
	-@erase "$(INTDIR)\eHelpFunc.obj"
	-@erase "$(INTDIR)\FileManager.obj"
	-@erase "$(INTDIR)\FreeAryElement.obj"
	-@erase "$(INTDIR)\GetAryElementInf.obj"
	-@erase "$(INTDIR)\GetDataTypeType.obj"
	-@erase "$(INTDIR)\GetDatePart.obj"
	-@erase "$(INTDIR)\GetDaysOfSpecMonth.obj"
	-@erase "$(INTDIR)\GetRegRootVal.obj"
	-@erase "$(INTDIR)\GetSpecTime.obj"
	-@erase "$(INTDIR)\GetSysDataTypeDataSize.obj"
	-@erase "$(INTDIR)\GetTimePart.obj"
	-@erase "$(INTDIR)\GetWeekDay.obj"
	-@erase "$(INTDIR)\HelpFunc12.obj"
	-@erase "$(INTDIR)\IsInFileMangerList.obj"
	-@erase "$(INTDIR)\krnln.pch"
	-@erase "$(INTDIR)\krnln_abs.obj"
	-@erase "$(INTDIR)\krnln_asc.obj"
	-@erase "$(INTDIR)\krnln_atn.obj"
	-@erase "$(INTDIR)\krnln_band.obj"
	-@erase "$(INTDIR)\krnln_beep.obj"
	-@erase "$(INTDIR)\krnln_bin.obj"
	-@erase "$(INTDIR)\krnln_BinLeft.obj"
	-@erase "$(INTDIR)\krnln_BinLen.obj"
	-@erase "$(INTDIR)\krnln_BinMid.obj"
	-@erase "$(INTDIR)\krnln_BinRight.obj"
	-@erase "$(INTDIR)\krnln_BJCase.obj"
	-@erase "$(INTDIR)\krnln_bnot.obj"
	-@erase "$(INTDIR)\krnln_bor.obj"
	-@erase "$(INTDIR)\krnln_bxor.obj"
	-@erase "$(INTDIR)\krnln_ChDir.obj"
	-@erase "$(INTDIR)\krnln_ChDrive.obj"
	-@erase "$(INTDIR)\krnln_chr.obj"
	-@erase "$(INTDIR)\krnln_ClearClipBoard.obj"
	-@erase "$(INTDIR)\krnln_close.obj"
	-@erase "$(INTDIR)\krnln_cos.obj"
	-@erase "$(INTDIR)\krnln_CryptOpen.obj"
	-@erase "$(INTDIR)\krnln_CurDir.obj"
	-@erase "$(INTDIR)\krnln_day.obj"
	-@erase "$(INTDIR)\krnln_DeleteRegItem.obj"
	-@erase "$(INTDIR)\krnln_Dispatch.obj"
	-@erase "$(INTDIR)\krnln_DoEvents.obj"
	-@erase "$(INTDIR)\krnln_exp.obj"
	-@erase "$(INTDIR)\krnln_feof.obj"
	-@erase "$(INTDIR)\krnln_fgets.obj"
	-@erase "$(INTDIR)\krnln_FileCopy.obj"
	-@erase "$(INTDIR)\krnln_FileDateTime.obj"
	-@erase "$(INTDIR)\krnln_FileLen.obj"
	-@erase "$(INTDIR)\krnln_FileMove.obj"
	-@erase "$(INTDIR)\krnln_fix.obj"
	-@erase "$(INTDIR)\krnln_fputs.obj"
	-@erase "$(INTDIR)\krnln_FSeek.obj"
	-@erase "$(INTDIR)\krnln_GetAllPY.obj"
	-@erase "$(INTDIR)\krnln_GetAttr.obj"
	-@erase "$(INTDIR)\krnln_GetBackColor.obj"
	-@erase "$(INTDIR)\krnln_GetBinElement.obj"
	-@erase "$(INTDIR)\krnln_GetBinRegItem.obj"
	-@erase "$(INTDIR)\krnln_GetClipBoardText.obj"
	-@erase "$(INTDIR)\krnln_GetCmdLine.obj"
	-@erase "$(INTDIR)\krnln_GetColorCount.obj"
	-@erase "$(INTDIR)\krnln_GetCursorHorzPos.obj"
	-@erase "$(INTDIR)\krnln_GetCursorVertPos.obj"
	-@erase "$(INTDIR)\krnln_GetDataTypeSize.obj"
	-@erase "$(INTDIR)\krnln_GetDatePart.obj"
	-@erase "$(INTDIR)\krnln_GetDaysOfSpecMonth.obj"
	-@erase "$(INTDIR)\krnln_GetDiskFreeSpace.obj"
	-@erase "$(INTDIR)\krnln_GetDiskLabel.obj"
	-@erase "$(INTDIR)\krnln_GetDiskTotalSpace.obj"
	-@erase "$(INTDIR)\krnln_GetEnv.obj"
	-@erase "$(INTDIR)\krnln_GetHDiskCode.obj"
	-@erase "$(INTDIR)\krnln_GetHostName.obj"
	-@erase "$(INTDIR)\krnln_GetIntInsideBin.obj"
	-@erase "$(INTDIR)\krnln_GetKeyText.obj"
	-@erase "$(INTDIR)\krnln_GetLastError.obj"
	-@erase "$(INTDIR)\krnln_GetNumRegItem.obj"
	-@erase "$(INTDIR)\krnln_GetRunFileName.obj"
	-@erase "$(INTDIR)\krnln_GetRunPath.obj"
	-@erase "$(INTDIR)\krnln_GetRuntimeDataType.obj"
	-@erase "$(INTDIR)\krnln_GetScreenHeight.obj"
	-@erase "$(INTDIR)\krnln_GetScreenWidth.obj"
	-@erase "$(INTDIR)\krnln_GetSectionNames.obj"
	-@erase "$(INTDIR)\krnln_GetSpecTime.obj"
	-@erase "$(INTDIR)\krnln_GetSysVer.obj"
	-@erase "$(INTDIR)\krnln_GetTempFileName.obj"
	-@erase "$(INTDIR)\krnln_GetTextRegItem.obj"
	-@erase "$(INTDIR)\krnln_GetTickCount.obj"
	-@erase "$(INTDIR)\krnln_GetTimePart.obj"
	-@erase "$(INTDIR)\krnln_GetWinPic.obj"
	-@erase "$(INTDIR)\krnln_hex.obj"
	-@erase "$(INTDIR)\krnln_HostNameToIP.obj"
	-@erase "$(INTDIR)\krnln_hour.obj"
	-@erase "$(INTDIR)\krnln_IDiv.obj"
	-@erase "$(INTDIR)\krnln_InBin.obj"
	-@erase "$(INTDIR)\krnln_InBinRev.obj"
	-@erase "$(INTDIR)\krnln_InputBox.obj"
	-@erase "$(INTDIR)\krnln_InsBin.obj"
	-@erase "$(INTDIR)\krnln_InsLine.obj"
	-@erase "$(INTDIR)\krnln_InsText.obj"
	-@erase "$(INTDIR)\krnln_InStr.obj"
	-@erase "$(INTDIR)\krnln_InStrRev.obj"
	-@erase "$(INTDIR)\krnln_int.obj"
	-@erase "$(INTDIR)\krnln_IPToHostName.obj"
	-@erase "$(INTDIR)\krnln_IsCalcOK.obj"
	-@erase "$(INTDIR)\krnln_IsFileExist.obj"
	-@erase "$(INTDIR)\krnln_IsHaveTextInClip.obj"
	-@erase "$(INTDIR)\krnln_IsRegItemExist.obj"
	-@erase "$(INTDIR)\krnln_kill.obj"
	-@erase "$(INTDIR)\krnln_LCase.obj"
	-@erase "$(INTDIR)\krnln_left.obj"
	-@erase "$(INTDIR)\krnln_len.obj"
	-@erase "$(INTDIR)\krnln_like.obj"
	-@erase "$(INTDIR)\krnln_loc.obj"
	-@erase "$(INTDIR)\krnln_lock.obj"
	-@erase "$(INTDIR)\krnln_lof.obj"
	-@erase "$(INTDIR)\krnln_log.obj"
	-@erase "$(INTDIR)\krnln_LTrim.obj"
	-@erase "$(INTDIR)\krnln_MakeLong.obj"
	-@erase "$(INTDIR)\krnln_MakeWord.obj"
	-@erase "$(INTDIR)\krnln_mid.obj"
	-@erase "$(INTDIR)\krnln_minute.obj"
	-@erase "$(INTDIR)\krnln_MkDir.obj"
	-@erase "$(INTDIR)\krnln_mod.obj"
	-@erase "$(INTDIR)\krnln_month.obj"
	-@erase "$(INTDIR)\krnln_MsgBox.obj"
	-@erase "$(INTDIR)\krnln_name.obj"
	-@erase "$(INTDIR)\krnln_now.obj"
	-@erase "$(INTDIR)\krnln_NumToRMB.obj"
	-@erase "$(INTDIR)\krnln_NumToText.obj"
	-@erase "$(INTDIR)\krnln_oct.obj"
	-@erase "$(INTDIR)\krnln_open.obj"
	-@erase "$(INTDIR)\krnln_OpenManyFileDialog.obj"
	-@erase "$(INTDIR)\krnln_OpenMemFile.obj"
	-@erase "$(INTDIR)\krnln_p2double.obj"
	-@erase "$(INTDIR)\krnln_p2float.obj"
	-@erase "$(INTDIR)\krnln_p2int.obj"
	-@erase "$(INTDIR)\krnln_pbin.obj"
	-@erase "$(INTDIR)\krnln_ping.obj"
	-@erase "$(INTDIR)\krnln_PlayMID.obj"
	-@erase "$(INTDIR)\krnln_PlayMusic.obj"
	-@erase "$(INTDIR)\krnln_PlayStop.obj"
	-@erase "$(INTDIR)\krnln_pow.obj"
	-@erase "$(INTDIR)\krnln_pstr.obj"
	-@erase "$(INTDIR)\krnln_PutEnv.obj"
	-@erase "$(INTDIR)\krnln_QJCase.obj"
	-@erase "$(INTDIR)\krnln_randomize.obj"
	-@erase "$(INTDIR)\krnln_read.obj"
	-@erase "$(INTDIR)\krnln_ReadBin.obj"
	-@erase "$(INTDIR)\krnln_ReadFile.obj"
	-@erase "$(INTDIR)\krnln_ReadLine.obj"
	-@erase "$(INTDIR)\krnln_ReadText.obj"
	-@erase "$(INTDIR)\krnln_RemoveData.obj"
	-@erase "$(INTDIR)\krnln_ReplaceText.obj"
	-@erase "$(INTDIR)\krnln_reset.obj"
	-@erase "$(INTDIR)\krnln_RestroeCursor.obj"
	-@erase "$(INTDIR)\krnln_ReverseIntBytes.obj"
	-@erase "$(INTDIR)\krnln_rgb.obj"
	-@erase "$(INTDIR)\krnln_right.obj"
	-@erase "$(INTDIR)\krnln_RmDir.obj"
	-@erase "$(INTDIR)\krnln_rnd.obj"
	-@erase "$(INTDIR)\krnln_round.obj"
	-@erase "$(INTDIR)\krnln_RpBin.obj"
	-@erase "$(INTDIR)\krnln_RpSubBin.obj"
	-@erase "$(INTDIR)\krnln_RpSubText.obj"
	-@erase "$(INTDIR)\krnln_RTrim.obj"
	-@erase "$(INTDIR)\krnln_run.obj"
	-@erase "$(INTDIR)\krnln_RunConsoleApp.obj"
	-@erase "$(INTDIR)\krnln_SaveRegItem.obj"
	-@erase "$(INTDIR)\krnln_second.obj"
	-@erase "$(INTDIR)\krnln_SeekToBegin.obj"
	-@erase "$(INTDIR)\krnln_SeekToEnd.obj"
	-@erase "$(INTDIR)\krnln_SetAttr.obj"
	-@erase "$(INTDIR)\krnln_SetClipBoardText.obj"
	-@erase "$(INTDIR)\krnln_SetDiskLabel.obj"
	-@erase "$(INTDIR)\krnln_SetIntInsideBin.obj"
	-@erase "$(INTDIR)\krnln_SetKeyText.obj"
	-@erase "$(INTDIR)\krnln_SetSysTime.obj"
	-@erase "$(INTDIR)\krnln_SetWaitCursor.obj"
	-@erase "$(INTDIR)\krnln_sgn.obj"
	-@erase "$(INTDIR)\krnln_shl.obj"
	-@erase "$(INTDIR)\krnln_shr.obj"
	-@erase "$(INTDIR)\krnln_sin.obj"
	-@erase "$(INTDIR)\krnln_sleep.obj"
	-@erase "$(INTDIR)\krnln_SortAry.obj"
	-@erase "$(INTDIR)\krnln_space.obj"
	-@erase "$(INTDIR)\krnln_SpaceBin.obj"
	-@erase "$(INTDIR)\krnln_split.obj"
	-@erase "$(INTDIR)\krnln_SplitBin.obj"
	-@erase "$(INTDIR)\krnln_sqr.obj"
	-@erase "$(INTDIR)\krnln_str.obj"
	-@erase "$(INTDIR)\krnln_StrComp.obj"
	-@erase "$(INTDIR)\krnln_string.obj"
	-@erase "$(INTDIR)\krnln_StrToUTF8.obj"
	-@erase "$(INTDIR)\krnln_tan.obj"
	-@erase "$(INTDIR)\krnln_TimeChg.obj"
	-@erase "$(INTDIR)\krnln_TimeDiff.obj"
	-@erase "$(INTDIR)\krnln_TimePart.obj"
	-@erase "$(INTDIR)\krnln_TimeToText.obj"
	-@erase "$(INTDIR)\krnln_ToBin.obj"
	-@erase "$(INTDIR)\krnln_ToByte.obj"
	-@erase "$(INTDIR)\krnln_ToFloat.obj"
	-@erase "$(INTDIR)\krnln_ToInt.obj"
	-@erase "$(INTDIR)\krnln_ToLong.obj"
	-@erase "$(INTDIR)\krnln_ToShort.obj"
	-@erase "$(INTDIR)\krnln_ToTime.obj"
	-@erase "$(INTDIR)\krnln_trim.obj"
	-@erase "$(INTDIR)\krnln_TrimAll.obj"
	-@erase "$(INTDIR)\krnln_UCase.obj"
	-@erase "$(INTDIR)\krnln_Unlock.obj"
	-@erase "$(INTDIR)\krnln_UNum.obj"
	-@erase "$(INTDIR)\krnln_UTF8ToStr.obj"
	-@erase "$(INTDIR)\krnln_val.obj"
	-@erase "$(INTDIR)\krnln_Variant.obj"
	-@erase "$(INTDIR)\krnln_WeekDay.obj"
	-@erase "$(INTDIR)\krnln_write.obj"
	-@erase "$(INTDIR)\krnln_WriteBin.obj"
	-@erase "$(INTDIR)\krnln_WriteFile.obj"
	-@erase "$(INTDIR)\krnln_WriteLine.obj"
	-@erase "$(INTDIR)\krnln_WriteMem.obj"
	-@erase "$(INTDIR)\krnln_WriteText.obj"
	-@erase "$(INTDIR)\krnln_year.obj"
	-@erase "$(INTDIR)\krnln_ZeroAry.obj"
	-@erase "$(INTDIR)\LTrimZeroChr.obj"
	-@erase "$(INTDIR)\md5t.obj"
	-@erase "$(INTDIR)\mem.obj"
	-@erase "$(INTDIR)\midi.obj"
	-@erase "$(INTDIR)\Myfunctions.obj"
	-@erase "$(INTDIR)\MyMemFile.obj"
	-@erase "$(INTDIR)\NumToChinese.obj"
	-@erase "$(INTDIR)\replaceText.obj"
	-@erase "$(INTDIR)\SDataToStr.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\krnln.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\krnln.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

RSC=rc.exe
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\krnln.bsc" 
BSC32_SBRS= \
	
LIB32=link.exe -lib
LIB32_FLAGS=/nologo /out:"$(OUTDIR)\krnln.lib" 
LIB32_OBJS= \
	"$(INTDIR)\BlackMoonCallPropertyVaule.obj" \
	"$(INTDIR)\BlackMoonCallUserDll.obj" \
	"$(INTDIR)\BlackMoonLibNotifySys.obj" \
	"$(INTDIR)\CloneBinData.obj" \
	"$(INTDIR)\CloneTextData.obj" \
	"$(INTDIR)\DateTimeFormat.obj" \
	"$(INTDIR)\DllEntryFunc.obj" \
	"$(INTDIR)\eHelpFunc.obj" \
	"$(INTDIR)\FileManager.obj" \
	"$(INTDIR)\FreeAryElement.obj" \
	"$(INTDIR)\GetAryElementInf.obj" \
	"$(INTDIR)\GetDataTypeType.obj" \
	"$(INTDIR)\GetDatePart.obj" \
	"$(INTDIR)\GetDaysOfSpecMonth.obj" \
	"$(INTDIR)\GetRegRootVal.obj" \
	"$(INTDIR)\GetSpecTime.obj" \
	"$(INTDIR)\GetSysDataTypeDataSize.obj" \
	"$(INTDIR)\GetTimePart.obj" \
	"$(INTDIR)\GetWeekDay.obj" \
	"$(INTDIR)\HelpFunc12.obj" \
	"$(INTDIR)\IsInFileMangerList.obj" \
	"$(INTDIR)\krnln_abs.obj" \
	"$(INTDIR)\krnln_asc.obj" \
	"$(INTDIR)\krnln_atn.obj" \
	"$(INTDIR)\krnln_band.obj" \
	"$(INTDIR)\krnln_beep.obj" \
	"$(INTDIR)\krnln_bin.obj" \
	"$(INTDIR)\krnln_BinLeft.obj" \
	"$(INTDIR)\krnln_BinLen.obj" \
	"$(INTDIR)\krnln_BinMid.obj" \
	"$(INTDIR)\krnln_BinRight.obj" \
	"$(INTDIR)\krnln_BJCase.obj" \
	"$(INTDIR)\krnln_bnot.obj" \
	"$(INTDIR)\krnln_bor.obj" \
	"$(INTDIR)\krnln_bxor.obj" \
	"$(INTDIR)\krnln_ChDir.obj" \
	"$(INTDIR)\krnln_ChDrive.obj" \
	"$(INTDIR)\krnln_chr.obj" \
	"$(INTDIR)\krnln_ClearClipBoard.obj" \
	"$(INTDIR)\krnln_close.obj" \
	"$(INTDIR)\krnln_cos.obj" \
	"$(INTDIR)\krnln_CryptOpen.obj" \
	"$(INTDIR)\krnln_CurDir.obj" \
	"$(INTDIR)\krnln_day.obj" \
	"$(INTDIR)\krnln_DeleteRegItem.obj" \
	"$(INTDIR)\krnln_Dispatch.obj" \
	"$(INTDIR)\krnln_DoEvents.obj" \
	"$(INTDIR)\krnln_exp.obj" \
	"$(INTDIR)\krnln_feof.obj" \
	"$(INTDIR)\krnln_fgets.obj" \
	"$(INTDIR)\krnln_FileCopy.obj" \
	"$(INTDIR)\krnln_FileDateTime.obj" \
	"$(INTDIR)\krnln_FileLen.obj" \
	"$(INTDIR)\krnln_FileMove.obj" \
	"$(INTDIR)\krnln_fix.obj" \
	"$(INTDIR)\krnln_fputs.obj" \
	"$(INTDIR)\krnln_FSeek.obj" \
	"$(INTDIR)\krnln_GetAllPY.obj" \
	"$(INTDIR)\krnln_GetAttr.obj" \
	"$(INTDIR)\krnln_GetBackColor.obj" \
	"$(INTDIR)\krnln_GetBinElement.obj" \
	"$(INTDIR)\krnln_GetBinRegItem.obj" \
	"$(INTDIR)\krnln_GetClipBoardText.obj" \
	"$(INTDIR)\krnln_GetCmdLine.obj" \
	"$(INTDIR)\krnln_GetColorCount.obj" \
	"$(INTDIR)\krnln_GetCursorHorzPos.obj" \
	"$(INTDIR)\krnln_GetCursorVertPos.obj" \
	"$(INTDIR)\krnln_GetDataTypeSize.obj" \
	"$(INTDIR)\krnln_GetDatePart.obj" \
	"$(INTDIR)\krnln_GetDaysOfSpecMonth.obj" \
	"$(INTDIR)\krnln_GetDiskFreeSpace.obj" \
	"$(INTDIR)\krnln_GetDiskLabel.obj" \
	"$(INTDIR)\krnln_GetDiskTotalSpace.obj" \
	"$(INTDIR)\krnln_GetEnv.obj" \
	"$(INTDIR)\krnln_GetHDiskCode.obj" \
	"$(INTDIR)\krnln_GetHostName.obj" \
	"$(INTDIR)\krnln_GetIntInsideBin.obj" \
	"$(INTDIR)\krnln_GetKeyText.obj" \
	"$(INTDIR)\krnln_GetLastError.obj" \
	"$(INTDIR)\krnln_GetNumRegItem.obj" \
	"$(INTDIR)\krnln_GetRunFileName.obj" \
	"$(INTDIR)\krnln_GetRunPath.obj" \
	"$(INTDIR)\krnln_GetRuntimeDataType.obj" \
	"$(INTDIR)\krnln_GetScreenHeight.obj" \
	"$(INTDIR)\krnln_GetScreenWidth.obj" \
	"$(INTDIR)\krnln_GetSectionNames.obj" \
	"$(INTDIR)\krnln_GetSpecTime.obj" \
	"$(INTDIR)\krnln_GetSysVer.obj" \
	"$(INTDIR)\krnln_GetTempFileName.obj" \
	"$(INTDIR)\krnln_GetTextRegItem.obj" \
	"$(INTDIR)\krnln_GetTickCount.obj" \
	"$(INTDIR)\krnln_GetTimePart.obj" \
	"$(INTDIR)\krnln_GetWinPic.obj" \
	"$(INTDIR)\krnln_hex.obj" \
	"$(INTDIR)\krnln_HostNameToIP.obj" \
	"$(INTDIR)\krnln_hour.obj" \
	"$(INTDIR)\krnln_IDiv.obj" \
	"$(INTDIR)\krnln_InBin.obj" \
	"$(INTDIR)\krnln_InBinRev.obj" \
	"$(INTDIR)\krnln_InputBox.obj" \
	"$(INTDIR)\krnln_InsBin.obj" \
	"$(INTDIR)\krnln_InsLine.obj" \
	"$(INTDIR)\krnln_InsText.obj" \
	"$(INTDIR)\krnln_InStr.obj" \
	"$(INTDIR)\krnln_InStrRev.obj" \
	"$(INTDIR)\krnln_int.obj" \
	"$(INTDIR)\krnln_IPToHostName.obj" \
	"$(INTDIR)\krnln_IsCalcOK.obj" \
	"$(INTDIR)\krnln_IsFileExist.obj" \
	"$(INTDIR)\krnln_IsHaveTextInClip.obj" \
	"$(INTDIR)\krnln_IsRegItemExist.obj" \
	"$(INTDIR)\krnln_kill.obj" \
	"$(INTDIR)\krnln_LCase.obj" \
	"$(INTDIR)\krnln_left.obj" \
	"$(INTDIR)\krnln_len.obj" \
	"$(INTDIR)\krnln_like.obj" \
	"$(INTDIR)\krnln_loc.obj" \
	"$(INTDIR)\krnln_lock.obj" \
	"$(INTDIR)\krnln_lof.obj" \
	"$(INTDIR)\krnln_log.obj" \
	"$(INTDIR)\krnln_LTrim.obj" \
	"$(INTDIR)\krnln_MakeLong.obj" \
	"$(INTDIR)\krnln_MakeWord.obj" \
	"$(INTDIR)\krnln_mid.obj" \
	"$(INTDIR)\krnln_minute.obj" \
	"$(INTDIR)\krnln_MkDir.obj" \
	"$(INTDIR)\krnln_mod.obj" \
	"$(INTDIR)\krnln_month.obj" \
	"$(INTDIR)\krnln_MsgBox.obj" \
	"$(INTDIR)\krnln_name.obj" \
	"$(INTDIR)\krnln_now.obj" \
	"$(INTDIR)\krnln_NumToRMB.obj" \
	"$(INTDIR)\krnln_NumToText.obj" \
	"$(INTDIR)\krnln_oct.obj" \
	"$(INTDIR)\krnln_open.obj" \
	"$(INTDIR)\krnln_OpenManyFileDialog.obj" \
	"$(INTDIR)\krnln_OpenMemFile.obj" \
	"$(INTDIR)\krnln_p2double.obj" \
	"$(INTDIR)\krnln_p2float.obj" \
	"$(INTDIR)\krnln_p2int.obj" \
	"$(INTDIR)\krnln_pbin.obj" \
	"$(INTDIR)\krnln_ping.obj" \
	"$(INTDIR)\krnln_PlayMID.obj" \
	"$(INTDIR)\krnln_PlayMusic.obj" \
	"$(INTDIR)\krnln_PlayStop.obj" \
	"$(INTDIR)\krnln_pow.obj" \
	"$(INTDIR)\krnln_pstr.obj" \
	"$(INTDIR)\krnln_PutEnv.obj" \
	"$(INTDIR)\krnln_QJCase.obj" \
	"$(INTDIR)\krnln_randomize.obj" \
	"$(INTDIR)\krnln_read.obj" \
	"$(INTDIR)\krnln_ReadBin.obj" \
	"$(INTDIR)\krnln_ReadFile.obj" \
	"$(INTDIR)\krnln_ReadLine.obj" \
	"$(INTDIR)\krnln_ReadText.obj" \
	"$(INTDIR)\krnln_RemoveData.obj" \
	"$(INTDIR)\krnln_ReplaceText.obj" \
	"$(INTDIR)\krnln_reset.obj" \
	"$(INTDIR)\krnln_RestroeCursor.obj" \
	"$(INTDIR)\krnln_ReverseIntBytes.obj" \
	"$(INTDIR)\krnln_rgb.obj" \
	"$(INTDIR)\krnln_right.obj" \
	"$(INTDIR)\krnln_RmDir.obj" \
	"$(INTDIR)\krnln_rnd.obj" \
	"$(INTDIR)\krnln_round.obj" \
	"$(INTDIR)\krnln_RpBin.obj" \
	"$(INTDIR)\krnln_RpSubBin.obj" \
	"$(INTDIR)\krnln_RpSubText.obj" \
	"$(INTDIR)\krnln_RTrim.obj" \
	"$(INTDIR)\krnln_run.obj" \
	"$(INTDIR)\krnln_RunConsoleApp.obj" \
	"$(INTDIR)\krnln_SaveRegItem.obj" \
	"$(INTDIR)\krnln_second.obj" \
	"$(INTDIR)\krnln_SeekToBegin.obj" \
	"$(INTDIR)\krnln_SeekToEnd.obj" \
	"$(INTDIR)\krnln_SetAttr.obj" \
	"$(INTDIR)\krnln_SetClipBoardText.obj" \
	"$(INTDIR)\krnln_SetDiskLabel.obj" \
	"$(INTDIR)\krnln_SetIntInsideBin.obj" \
	"$(INTDIR)\krnln_SetKeyText.obj" \
	"$(INTDIR)\krnln_SetSysTime.obj" \
	"$(INTDIR)\krnln_SetWaitCursor.obj" \
	"$(INTDIR)\krnln_sgn.obj" \
	"$(INTDIR)\krnln_shl.obj" \
	"$(INTDIR)\krnln_shr.obj" \
	"$(INTDIR)\krnln_sin.obj" \
	"$(INTDIR)\krnln_sleep.obj" \
	"$(INTDIR)\krnln_SortAry.obj" \
	"$(INTDIR)\krnln_space.obj" \
	"$(INTDIR)\krnln_SpaceBin.obj" \
	"$(INTDIR)\krnln_split.obj" \
	"$(INTDIR)\krnln_SplitBin.obj" \
	"$(INTDIR)\krnln_sqr.obj" \
	"$(INTDIR)\krnln_str.obj" \
	"$(INTDIR)\krnln_StrComp.obj" \
	"$(INTDIR)\krnln_string.obj" \
	"$(INTDIR)\krnln_StrToUTF8.obj" \
	"$(INTDIR)\krnln_tan.obj" \
	"$(INTDIR)\krnln_TimeChg.obj" \
	"$(INTDIR)\krnln_TimeDiff.obj" \
	"$(INTDIR)\krnln_TimePart.obj" \
	"$(INTDIR)\krnln_TimeToText.obj" \
	"$(INTDIR)\krnln_ToBin.obj" \
	"$(INTDIR)\krnln_ToByte.obj" \
	"$(INTDIR)\krnln_ToFloat.obj" \
	"$(INTDIR)\krnln_ToInt.obj" \
	"$(INTDIR)\krnln_ToLong.obj" \
	"$(INTDIR)\krnln_ToShort.obj" \
	"$(INTDIR)\krnln_ToTime.obj" \
	"$(INTDIR)\krnln_trim.obj" \
	"$(INTDIR)\krnln_TrimAll.obj" \
	"$(INTDIR)\krnln_UCase.obj" \
	"$(INTDIR)\krnln_Unlock.obj" \
	"$(INTDIR)\krnln_UNum.obj" \
	"$(INTDIR)\krnln_UTF8ToStr.obj" \
	"$(INTDIR)\krnln_val.obj" \
	"$(INTDIR)\krnln_Variant.obj" \
	"$(INTDIR)\krnln_WeekDay.obj" \
	"$(INTDIR)\krnln_write.obj" \
	"$(INTDIR)\krnln_WriteBin.obj" \
	"$(INTDIR)\krnln_WriteFile.obj" \
	"$(INTDIR)\krnln_WriteLine.obj" \
	"$(INTDIR)\krnln_WriteMem.obj" \
	"$(INTDIR)\krnln_WriteText.obj" \
	"$(INTDIR)\krnln_year.obj" \
	"$(INTDIR)\krnln_ZeroAry.obj" \
	"$(INTDIR)\LTrimZeroChr.obj" \
	"$(INTDIR)\md5t.obj" \
	"$(INTDIR)\mem.obj" \
	"$(INTDIR)\midi.obj" \
	"$(INTDIR)\Myfunctions.obj" \
	"$(INTDIR)\MyMemFile.obj" \
	"$(INTDIR)\NumToChinese.obj" \
	"$(INTDIR)\replaceText.obj" \
	"$(INTDIR)\SDataToStr.obj" \
	"$(INTDIR)\StdAfx.obj" \
	".\krnln\Diskid32.obj" \
	".\krnln\PY.OBJ"

"$(OUTDIR)\krnln.lib" : "$(OUTDIR)" $(DEF_FILE) $(LIB32_OBJS)
    $(LIB32) @<<
  $(LIB32_FLAGS) $(DEF_FLAGS) $(LIB32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("krnln.dep")
!INCLUDE "krnln.dep"
!ELSE 
!MESSAGE Warning: cannot find "krnln.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "krnln - Win32 Release" || "$(CFG)" == "krnln - Win32 Debug"
SOURCE=".\krnln\BlackMoonCallPropertyVaule.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\BlackMoonCallPropertyVaule.obj"	"$(INTDIR)\BlackMoonCallPropertyVaule.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\BlackMoonCallPropertyVaule.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\BlackMoonCallUserDll.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\BlackMoonCallUserDll.obj"	"$(INTDIR)\BlackMoonCallUserDll.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\BlackMoonCallUserDll.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\BlackMoonLibNotifySys.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\BlackMoonLibNotifySys.obj"	"$(INTDIR)\BlackMoonLibNotifySys.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\BlackMoonLibNotifySys.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\CloneBinData.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\CloneBinData.obj"	"$(INTDIR)\CloneBinData.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\CloneBinData.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\CloneTextData.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\CloneTextData.obj"	"$(INTDIR)\CloneTextData.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\CloneTextData.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\DateTimeFormat.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\DateTimeFormat.obj"	"$(INTDIR)\DateTimeFormat.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\DateTimeFormat.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\DllEntryFunc.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\DllEntryFunc.obj"	"$(INTDIR)\DllEntryFunc.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\DllEntryFunc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\eHelpFunc.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\eHelpFunc.obj"	"$(INTDIR)\eHelpFunc.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\eHelpFunc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\FileManager.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\FileManager.obj"	"$(INTDIR)\FileManager.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\FileManager.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\FreeAryElement.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\FreeAryElement.obj"	"$(INTDIR)\FreeAryElement.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\FreeAryElement.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\GetAryElementInf.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\GetAryElementInf.obj"	"$(INTDIR)\GetAryElementInf.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\GetAryElementInf.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\GetDataTypeType.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\GetDataTypeType.obj"	"$(INTDIR)\GetDataTypeType.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\GetDataTypeType.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\GetDatePart.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\GetDatePart.obj"	"$(INTDIR)\GetDatePart.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\GetDatePart.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\GetDaysOfSpecMonth.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\GetDaysOfSpecMonth.obj"	"$(INTDIR)\GetDaysOfSpecMonth.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\GetDaysOfSpecMonth.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\GetRegRootVal.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\GetRegRootVal.obj"	"$(INTDIR)\GetRegRootVal.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\GetRegRootVal.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\GetSpecTime.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\GetSpecTime.obj"	"$(INTDIR)\GetSpecTime.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\GetSpecTime.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\GetSysDataTypeDataSize.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\GetSysDataTypeDataSize.obj"	"$(INTDIR)\GetSysDataTypeDataSize.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\GetSysDataTypeDataSize.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\GetTimePart.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\GetTimePart.obj"	"$(INTDIR)\GetTimePart.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\GetTimePart.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\GetWeekDay.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\GetWeekDay.obj"	"$(INTDIR)\GetWeekDay.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\GetWeekDay.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\HelpFunc12.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\HelpFunc12.obj"	"$(INTDIR)\HelpFunc12.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\HelpFunc12.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\IsInFileMangerList.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\IsInFileMangerList.obj"	"$(INTDIR)\IsInFileMangerList.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\IsInFileMangerList.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_abs.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_abs.obj"	"$(INTDIR)\krnln_abs.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_abs.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_asc.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_asc.obj"	"$(INTDIR)\krnln_asc.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_asc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_atn.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_atn.obj"	"$(INTDIR)\krnln_atn.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_atn.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_band.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_band.obj"	"$(INTDIR)\krnln_band.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_band.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_beep.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_beep.obj"	"$(INTDIR)\krnln_beep.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_beep.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_bin.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_bin.obj"	"$(INTDIR)\krnln_bin.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_bin.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_BinLeft.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_BinLeft.obj"	"$(INTDIR)\krnln_BinLeft.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_BinLeft.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_BinLen.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_BinLen.obj"	"$(INTDIR)\krnln_BinLen.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_BinLen.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_BinMid.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_BinMid.obj"	"$(INTDIR)\krnln_BinMid.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_BinMid.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_BinRight.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_BinRight.obj"	"$(INTDIR)\krnln_BinRight.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_BinRight.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_BJCase.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_BJCase.obj"	"$(INTDIR)\krnln_BJCase.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_BJCase.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_bnot.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_bnot.obj"	"$(INTDIR)\krnln_bnot.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_bnot.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_bor.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_bor.obj"	"$(INTDIR)\krnln_bor.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_bor.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_bxor.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_bxor.obj"	"$(INTDIR)\krnln_bxor.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_bxor.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_ChDir.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_ChDir.obj"	"$(INTDIR)\krnln_ChDir.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_ChDir.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_ChDrive.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_ChDrive.obj"	"$(INTDIR)\krnln_ChDrive.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_ChDrive.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_chr.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_chr.obj"	"$(INTDIR)\krnln_chr.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_chr.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_ClearClipBoard.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_ClearClipBoard.obj"	"$(INTDIR)\krnln_ClearClipBoard.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_ClearClipBoard.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_close.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_close.obj"	"$(INTDIR)\krnln_close.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_close.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_cos.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_cos.obj"	"$(INTDIR)\krnln_cos.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_cos.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_CryptOpen.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_CryptOpen.obj"	"$(INTDIR)\krnln_CryptOpen.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_CryptOpen.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_CurDir.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_CurDir.obj"	"$(INTDIR)\krnln_CurDir.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_CurDir.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_day.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_day.obj"	"$(INTDIR)\krnln_day.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_day.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_DeleteRegItem.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_DeleteRegItem.obj"	"$(INTDIR)\krnln_DeleteRegItem.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_DeleteRegItem.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_Dispatch.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_Dispatch.obj"	"$(INTDIR)\krnln_Dispatch.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_Dispatch.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_DoEvents.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_DoEvents.obj"	"$(INTDIR)\krnln_DoEvents.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_DoEvents.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_exp.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_exp.obj"	"$(INTDIR)\krnln_exp.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_exp.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_feof.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_feof.obj"	"$(INTDIR)\krnln_feof.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_feof.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_fgets.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_fgets.obj"	"$(INTDIR)\krnln_fgets.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_fgets.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_FileCopy.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_FileCopy.obj"	"$(INTDIR)\krnln_FileCopy.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_FileCopy.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_FileDateTime.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_FileDateTime.obj"	"$(INTDIR)\krnln_FileDateTime.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_FileDateTime.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_FileLen.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_FileLen.obj"	"$(INTDIR)\krnln_FileLen.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_FileLen.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_FileMove.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_FileMove.obj"	"$(INTDIR)\krnln_FileMove.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_FileMove.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_fix.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_fix.obj"	"$(INTDIR)\krnln_fix.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_fix.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_fputs.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_fputs.obj"	"$(INTDIR)\krnln_fputs.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_fputs.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_FSeek.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_FSeek.obj"	"$(INTDIR)\krnln_FSeek.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_FSeek.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_GetAllPY.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_GetAllPY.obj"	"$(INTDIR)\krnln_GetAllPY.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_GetAllPY.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_GetAttr.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_GetAttr.obj"	"$(INTDIR)\krnln_GetAttr.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_GetAttr.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_GetBackColor.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_GetBackColor.obj"	"$(INTDIR)\krnln_GetBackColor.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_GetBackColor.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_GetBinElement.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_GetBinElement.obj"	"$(INTDIR)\krnln_GetBinElement.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_GetBinElement.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_GetBinRegItem.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_GetBinRegItem.obj"	"$(INTDIR)\krnln_GetBinRegItem.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_GetBinRegItem.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_GetClipBoardText.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_GetClipBoardText.obj"	"$(INTDIR)\krnln_GetClipBoardText.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_GetClipBoardText.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_GetCmdLine.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_GetCmdLine.obj"	"$(INTDIR)\krnln_GetCmdLine.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_GetCmdLine.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_GetColorCount.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_GetColorCount.obj"	"$(INTDIR)\krnln_GetColorCount.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_GetColorCount.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_GetCursorHorzPos.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_GetCursorHorzPos.obj"	"$(INTDIR)\krnln_GetCursorHorzPos.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_GetCursorHorzPos.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_GetCursorVertPos.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_GetCursorVertPos.obj"	"$(INTDIR)\krnln_GetCursorVertPos.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_GetCursorVertPos.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_GetDataTypeSize.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_GetDataTypeSize.obj"	"$(INTDIR)\krnln_GetDataTypeSize.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_GetDataTypeSize.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_GetDatePart.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_GetDatePart.obj"	"$(INTDIR)\krnln_GetDatePart.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_GetDatePart.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_GetDaysOfSpecMonth.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_GetDaysOfSpecMonth.obj"	"$(INTDIR)\krnln_GetDaysOfSpecMonth.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_GetDaysOfSpecMonth.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_GetDiskFreeSpace.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_GetDiskFreeSpace.obj"	"$(INTDIR)\krnln_GetDiskFreeSpace.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_GetDiskFreeSpace.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_GetDiskLabel.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_GetDiskLabel.obj"	"$(INTDIR)\krnln_GetDiskLabel.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_GetDiskLabel.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_GetDiskTotalSpace.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_GetDiskTotalSpace.obj"	"$(INTDIR)\krnln_GetDiskTotalSpace.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_GetDiskTotalSpace.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_GetEnv.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_GetEnv.obj"	"$(INTDIR)\krnln_GetEnv.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_GetEnv.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_GetHDiskCode.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_GetHDiskCode.obj"	"$(INTDIR)\krnln_GetHDiskCode.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_GetHDiskCode.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_GetHostName.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_GetHostName.obj"	"$(INTDIR)\krnln_GetHostName.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_GetHostName.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_GetIntInsideBin.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_GetIntInsideBin.obj"	"$(INTDIR)\krnln_GetIntInsideBin.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_GetIntInsideBin.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_GetKeyText.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_GetKeyText.obj"	"$(INTDIR)\krnln_GetKeyText.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_GetKeyText.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_GetLastError.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_GetLastError.obj"	"$(INTDIR)\krnln_GetLastError.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_GetLastError.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_GetNumRegItem.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_GetNumRegItem.obj"	"$(INTDIR)\krnln_GetNumRegItem.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_GetNumRegItem.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_GetRunFileName.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_GetRunFileName.obj"	"$(INTDIR)\krnln_GetRunFileName.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_GetRunFileName.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_GetRunPath.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_GetRunPath.obj"	"$(INTDIR)\krnln_GetRunPath.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_GetRunPath.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_GetRuntimeDataType.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_GetRuntimeDataType.obj"	"$(INTDIR)\krnln_GetRuntimeDataType.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_GetRuntimeDataType.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_GetScreenHeight.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_GetScreenHeight.obj"	"$(INTDIR)\krnln_GetScreenHeight.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_GetScreenHeight.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_GetScreenWidth.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_GetScreenWidth.obj"	"$(INTDIR)\krnln_GetScreenWidth.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_GetScreenWidth.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_GetSectionNames.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_GetSectionNames.obj"	"$(INTDIR)\krnln_GetSectionNames.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_GetSectionNames.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_GetSpecTime.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_GetSpecTime.obj"	"$(INTDIR)\krnln_GetSpecTime.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_GetSpecTime.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_GetSysVer.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_GetSysVer.obj"	"$(INTDIR)\krnln_GetSysVer.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_GetSysVer.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_GetTempFileName.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_GetTempFileName.obj"	"$(INTDIR)\krnln_GetTempFileName.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_GetTempFileName.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_GetTextRegItem.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_GetTextRegItem.obj"	"$(INTDIR)\krnln_GetTextRegItem.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_GetTextRegItem.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_GetTickCount.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_GetTickCount.obj"	"$(INTDIR)\krnln_GetTickCount.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_GetTickCount.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_GetTimePart.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_GetTimePart.obj"	"$(INTDIR)\krnln_GetTimePart.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_GetTimePart.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_GetWinPic.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_GetWinPic.obj"	"$(INTDIR)\krnln_GetWinPic.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_GetWinPic.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_hex.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_hex.obj"	"$(INTDIR)\krnln_hex.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_hex.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_HostNameToIP.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_HostNameToIP.obj"	"$(INTDIR)\krnln_HostNameToIP.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_HostNameToIP.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_hour.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_hour.obj"	"$(INTDIR)\krnln_hour.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_hour.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_IDiv.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_IDiv.obj"	"$(INTDIR)\krnln_IDiv.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_IDiv.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_InBin.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_InBin.obj"	"$(INTDIR)\krnln_InBin.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_InBin.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_InBinRev.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_InBinRev.obj"	"$(INTDIR)\krnln_InBinRev.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_InBinRev.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_InputBox.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_InputBox.obj"	"$(INTDIR)\krnln_InputBox.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_InputBox.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_InsBin.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_InsBin.obj"	"$(INTDIR)\krnln_InsBin.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_InsBin.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_InsLine.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_InsLine.obj"	"$(INTDIR)\krnln_InsLine.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_InsLine.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_InsText.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_InsText.obj"	"$(INTDIR)\krnln_InsText.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_InsText.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_InStr.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_InStr.obj"	"$(INTDIR)\krnln_InStr.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_InStr.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_InStrRev.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_InStrRev.obj"	"$(INTDIR)\krnln_InStrRev.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_InStrRev.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_int.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_int.obj"	"$(INTDIR)\krnln_int.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_int.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_IPToHostName.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_IPToHostName.obj"	"$(INTDIR)\krnln_IPToHostName.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_IPToHostName.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_IsCalcOK.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_IsCalcOK.obj"	"$(INTDIR)\krnln_IsCalcOK.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_IsCalcOK.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_IsFileExist.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_IsFileExist.obj"	"$(INTDIR)\krnln_IsFileExist.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_IsFileExist.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_IsHaveTextInClip.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_IsHaveTextInClip.obj"	"$(INTDIR)\krnln_IsHaveTextInClip.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_IsHaveTextInClip.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_IsRegItemExist.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_IsRegItemExist.obj"	"$(INTDIR)\krnln_IsRegItemExist.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_IsRegItemExist.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_kill.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_kill.obj"	"$(INTDIR)\krnln_kill.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_kill.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_LCase.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_LCase.obj"	"$(INTDIR)\krnln_LCase.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_LCase.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_left.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_left.obj"	"$(INTDIR)\krnln_left.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_left.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_len.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_len.obj"	"$(INTDIR)\krnln_len.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_len.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_like.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_like.obj"	"$(INTDIR)\krnln_like.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_like.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_loc.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_loc.obj"	"$(INTDIR)\krnln_loc.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_loc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_lock.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_lock.obj"	"$(INTDIR)\krnln_lock.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_lock.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_lof.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_lof.obj"	"$(INTDIR)\krnln_lof.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_lof.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_log.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_log.obj"	"$(INTDIR)\krnln_log.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_log.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_LTrim.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_LTrim.obj"	"$(INTDIR)\krnln_LTrim.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_LTrim.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_MakeLong.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_MakeLong.obj"	"$(INTDIR)\krnln_MakeLong.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_MakeLong.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_MakeWord.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_MakeWord.obj"	"$(INTDIR)\krnln_MakeWord.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_MakeWord.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_mid.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_mid.obj"	"$(INTDIR)\krnln_mid.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_mid.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_minute.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_minute.obj"	"$(INTDIR)\krnln_minute.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_minute.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_MkDir.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_MkDir.obj"	"$(INTDIR)\krnln_MkDir.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_MkDir.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_mod.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_mod.obj"	"$(INTDIR)\krnln_mod.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_mod.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_month.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_month.obj"	"$(INTDIR)\krnln_month.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_month.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_MsgBox.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_MsgBox.obj"	"$(INTDIR)\krnln_MsgBox.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_MsgBox.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_name.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_name.obj"	"$(INTDIR)\krnln_name.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_name.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_now.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_now.obj"	"$(INTDIR)\krnln_now.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_now.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_NumToRMB.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_NumToRMB.obj"	"$(INTDIR)\krnln_NumToRMB.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_NumToRMB.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_NumToText.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_NumToText.obj"	"$(INTDIR)\krnln_NumToText.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_NumToText.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_oct.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_oct.obj"	"$(INTDIR)\krnln_oct.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_oct.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_open.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_open.obj"	"$(INTDIR)\krnln_open.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_open.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_OpenManyFileDialog.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_OpenManyFileDialog.obj"	"$(INTDIR)\krnln_OpenManyFileDialog.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_OpenManyFileDialog.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_OpenMemFile.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_OpenMemFile.obj"	"$(INTDIR)\krnln_OpenMemFile.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_OpenMemFile.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_p2double.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_p2double.obj"	"$(INTDIR)\krnln_p2double.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_p2double.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_p2float.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_p2float.obj"	"$(INTDIR)\krnln_p2float.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_p2float.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_p2int.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_p2int.obj"	"$(INTDIR)\krnln_p2int.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_p2int.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_pbin.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_pbin.obj"	"$(INTDIR)\krnln_pbin.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_pbin.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_ping.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_ping.obj"	"$(INTDIR)\krnln_ping.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_ping.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_PlayMID.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_PlayMID.obj"	"$(INTDIR)\krnln_PlayMID.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_PlayMID.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_PlayMusic.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_PlayMusic.obj"	"$(INTDIR)\krnln_PlayMusic.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_PlayMusic.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_PlayStop.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_PlayStop.obj"	"$(INTDIR)\krnln_PlayStop.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_PlayStop.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_pow.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_pow.obj"	"$(INTDIR)\krnln_pow.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_pow.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_pstr.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_pstr.obj"	"$(INTDIR)\krnln_pstr.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_pstr.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_PutEnv.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_PutEnv.obj"	"$(INTDIR)\krnln_PutEnv.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_PutEnv.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_QJCase.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_QJCase.obj"	"$(INTDIR)\krnln_QJCase.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_QJCase.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_randomize.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_randomize.obj"	"$(INTDIR)\krnln_randomize.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_randomize.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_read.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_read.obj"	"$(INTDIR)\krnln_read.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_read.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_ReadBin.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_ReadBin.obj"	"$(INTDIR)\krnln_ReadBin.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_ReadBin.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_ReadFile.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_ReadFile.obj"	"$(INTDIR)\krnln_ReadFile.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_ReadFile.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_ReadLine.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_ReadLine.obj"	"$(INTDIR)\krnln_ReadLine.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_ReadLine.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_ReadText.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_ReadText.obj"	"$(INTDIR)\krnln_ReadText.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_ReadText.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_RemoveData.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_RemoveData.obj"	"$(INTDIR)\krnln_RemoveData.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_RemoveData.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_ReplaceText.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_ReplaceText.obj"	"$(INTDIR)\krnln_ReplaceText.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_ReplaceText.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_reset.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_reset.obj"	"$(INTDIR)\krnln_reset.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_reset.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_RestroeCursor.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_RestroeCursor.obj"	"$(INTDIR)\krnln_RestroeCursor.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_RestroeCursor.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_ReverseIntBytes.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_ReverseIntBytes.obj"	"$(INTDIR)\krnln_ReverseIntBytes.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_ReverseIntBytes.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_rgb.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_rgb.obj"	"$(INTDIR)\krnln_rgb.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_rgb.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_right.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_right.obj"	"$(INTDIR)\krnln_right.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_right.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_RmDir.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_RmDir.obj"	"$(INTDIR)\krnln_RmDir.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_RmDir.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_rnd.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_rnd.obj"	"$(INTDIR)\krnln_rnd.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_rnd.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_round.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_round.obj"	"$(INTDIR)\krnln_round.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_round.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_RpBin.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_RpBin.obj"	"$(INTDIR)\krnln_RpBin.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_RpBin.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_RpSubBin.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_RpSubBin.obj"	"$(INTDIR)\krnln_RpSubBin.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_RpSubBin.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_RpSubText.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_RpSubText.obj"	"$(INTDIR)\krnln_RpSubText.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_RpSubText.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_RTrim.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_RTrim.obj"	"$(INTDIR)\krnln_RTrim.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_RTrim.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_run.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_run.obj"	"$(INTDIR)\krnln_run.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_run.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_RunConsoleApp.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_RunConsoleApp.obj"	"$(INTDIR)\krnln_RunConsoleApp.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_RunConsoleApp.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_SaveRegItem.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_SaveRegItem.obj"	"$(INTDIR)\krnln_SaveRegItem.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_SaveRegItem.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_second.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_second.obj"	"$(INTDIR)\krnln_second.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_second.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_SeekToBegin.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_SeekToBegin.obj"	"$(INTDIR)\krnln_SeekToBegin.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_SeekToBegin.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_SeekToEnd.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_SeekToEnd.obj"	"$(INTDIR)\krnln_SeekToEnd.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_SeekToEnd.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_SetAttr.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_SetAttr.obj"	"$(INTDIR)\krnln_SetAttr.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_SetAttr.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_SetClipBoardText.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_SetClipBoardText.obj"	"$(INTDIR)\krnln_SetClipBoardText.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_SetClipBoardText.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_SetDiskLabel.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_SetDiskLabel.obj"	"$(INTDIR)\krnln_SetDiskLabel.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_SetDiskLabel.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_SetIntInsideBin.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_SetIntInsideBin.obj"	"$(INTDIR)\krnln_SetIntInsideBin.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_SetIntInsideBin.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_SetKeyText.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_SetKeyText.obj"	"$(INTDIR)\krnln_SetKeyText.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_SetKeyText.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_SetSysTime.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_SetSysTime.obj"	"$(INTDIR)\krnln_SetSysTime.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_SetSysTime.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_SetWaitCursor.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_SetWaitCursor.obj"	"$(INTDIR)\krnln_SetWaitCursor.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_SetWaitCursor.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_sgn.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_sgn.obj"	"$(INTDIR)\krnln_sgn.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_sgn.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_shl.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_shl.obj"	"$(INTDIR)\krnln_shl.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_shl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_shr.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_shr.obj"	"$(INTDIR)\krnln_shr.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_shr.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_sin.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_sin.obj"	"$(INTDIR)\krnln_sin.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_sin.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_sleep.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_sleep.obj"	"$(INTDIR)\krnln_sleep.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_sleep.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_SortAry.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_SortAry.obj"	"$(INTDIR)\krnln_SortAry.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_SortAry.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_space.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_space.obj"	"$(INTDIR)\krnln_space.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_space.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_SpaceBin.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_SpaceBin.obj"	"$(INTDIR)\krnln_SpaceBin.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_SpaceBin.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_split.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_split.obj"	"$(INTDIR)\krnln_split.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_split.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_SplitBin.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_SplitBin.obj"	"$(INTDIR)\krnln_SplitBin.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_SplitBin.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_sqr.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_sqr.obj"	"$(INTDIR)\krnln_sqr.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_sqr.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_str.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_str.obj"	"$(INTDIR)\krnln_str.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_str.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_StrComp.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_StrComp.obj"	"$(INTDIR)\krnln_StrComp.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_StrComp.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_string.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_string.obj"	"$(INTDIR)\krnln_string.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_string.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_StrToUTF8.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_StrToUTF8.obj"	"$(INTDIR)\krnln_StrToUTF8.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_StrToUTF8.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_tan.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_tan.obj"	"$(INTDIR)\krnln_tan.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_tan.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_TimeChg.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_TimeChg.obj"	"$(INTDIR)\krnln_TimeChg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_TimeChg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_TimeDiff.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_TimeDiff.obj"	"$(INTDIR)\krnln_TimeDiff.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_TimeDiff.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_TimePart.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_TimePart.obj"	"$(INTDIR)\krnln_TimePart.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_TimePart.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_TimeToText.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_TimeToText.obj"	"$(INTDIR)\krnln_TimeToText.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_TimeToText.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_ToBin.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_ToBin.obj"	"$(INTDIR)\krnln_ToBin.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_ToBin.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_ToByte.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_ToByte.obj"	"$(INTDIR)\krnln_ToByte.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_ToByte.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_ToFloat.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_ToFloat.obj"	"$(INTDIR)\krnln_ToFloat.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_ToFloat.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_ToInt.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_ToInt.obj"	"$(INTDIR)\krnln_ToInt.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_ToInt.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_ToLong.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_ToLong.obj"	"$(INTDIR)\krnln_ToLong.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_ToLong.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_ToShort.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_ToShort.obj"	"$(INTDIR)\krnln_ToShort.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_ToShort.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_ToTime.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_ToTime.obj"	"$(INTDIR)\krnln_ToTime.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_ToTime.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_trim.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_trim.obj"	"$(INTDIR)\krnln_trim.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_trim.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_TrimAll.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_TrimAll.obj"	"$(INTDIR)\krnln_TrimAll.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_TrimAll.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_UCase.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_UCase.obj"	"$(INTDIR)\krnln_UCase.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_UCase.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_Unlock.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_Unlock.obj"	"$(INTDIR)\krnln_Unlock.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_Unlock.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_UNum.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_UNum.obj"	"$(INTDIR)\krnln_UNum.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_UNum.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_UTF8ToStr.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_UTF8ToStr.obj"	"$(INTDIR)\krnln_UTF8ToStr.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_UTF8ToStr.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_val.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_val.obj"	"$(INTDIR)\krnln_val.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_val.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_Variant.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_Variant.obj"	"$(INTDIR)\krnln_Variant.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_Variant.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_WeekDay.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_WeekDay.obj"	"$(INTDIR)\krnln_WeekDay.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_WeekDay.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_write.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_write.obj"	"$(INTDIR)\krnln_write.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_write.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_WriteBin.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_WriteBin.obj"	"$(INTDIR)\krnln_WriteBin.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_WriteBin.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_WriteFile.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_WriteFile.obj"	"$(INTDIR)\krnln_WriteFile.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_WriteFile.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_WriteLine.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_WriteLine.obj"	"$(INTDIR)\krnln_WriteLine.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_WriteLine.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_WriteMem.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_WriteMem.obj"	"$(INTDIR)\krnln_WriteMem.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_WriteMem.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_WriteText.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_WriteText.obj"	"$(INTDIR)\krnln_WriteText.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_WriteText.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_year.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_year.obj"	"$(INTDIR)\krnln_year.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_year.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\krnln_ZeroAry.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\krnln_ZeroAry.obj"	"$(INTDIR)\krnln_ZeroAry.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\krnln_ZeroAry.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\LTrimZeroChr.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\LTrimZeroChr.obj"	"$(INTDIR)\LTrimZeroChr.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\LTrimZeroChr.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\md5t.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\md5t.obj"	"$(INTDIR)\md5t.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\md5t.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\mem.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\mem.obj"	"$(INTDIR)\mem.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\mem.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\midi.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\midi.obj"	"$(INTDIR)\midi.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\midi.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\Myfunctions.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\Myfunctions.obj"	"$(INTDIR)\Myfunctions.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\Myfunctions.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\MyMemFile.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\MyMemFile.obj"	"$(INTDIR)\MyMemFile.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\MyMemFile.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\NumToChinese.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\NumToChinese.obj"	"$(INTDIR)\NumToChinese.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\NumToChinese.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\replaceText.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\replaceText.obj"	"$(INTDIR)\replaceText.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\replaceText.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\SDataToStr.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"


"$(INTDIR)\SDataToStr.obj"	"$(INTDIR)\SDataToStr.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"


"$(INTDIR)\SDataToStr.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\krnln.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=".\krnln\StdAfx.cpp"

!IF  "$(CFG)" == "krnln - Win32 Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\krnln.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\krnln.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "krnln - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\krnln.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\krnln.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

