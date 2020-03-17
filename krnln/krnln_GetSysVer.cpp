#include "stdafx.h"

#define VER_NT_WORKSTATION              0x0000001
#define VER_NT_DOMAIN_CONTROLLER        0x0000002
#define VER_NT_SERVER                   0x0000003
typedef   struct   OSVERSIONINFOEX1
{ 
	DWORD   dwOSVersionInfoSize; 
	DWORD   dwMajorVersion; 
	DWORD   dwMinorVersion; 
	DWORD   dwBuildNumber; 
	DWORD   dwPlatformId; 
	WCHAR     szCSDVersion[128];           //   Maintenance   string   for   PSS   usage
	WORD       wServicePackMajor; 
	WORD       wServicePackMinor; 
	WORD       wSuiteMask; 
	BYTE     wProductType; 
	BYTE     wReserved; 
}   OSVERSIONINFOEXW1; 

#if _MSC_VER >= 1916 //VS2017 VS2019
typedef BOOL (WINAPI *MyGetVersionExA)(_Inout_ LPOSVERSIONINFOA lpVersionInformation);
#endif

//系统处理 - 取操作系统类别
/*
    调用格式： 〈整数型〉 取操作系统类别 （） - 系统核心支持库->系统处理
    英文名称：GetSysVer
    返回当前操作系统的版本类别。返回值为以下值之一：0、未知； 1、Windows 32S； 2、Windows 9X (包含Win95、Win98、WinME等)； 3、Windows NT (包含WinNT、Win2000、WinXP等)； 4、Linux。本命令为初级命令。
*/
LIBAPI(int, krnln_GetSysVer)
{
	OSVERSIONINFO VersionInformation;
	INT nRet = 0;
	memset(&VersionInformation,0,sizeof(OSVERSIONINFO));
	VersionInformation.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);

#if _MSC_VER >= 1916 //VS2017 VS2019
	HMODULE hKernel32 = GetModuleHandle("Kernel32.dll");
	if (!hKernel32)
		return 0;
	MyGetVersionExA MyGetVersion = (MyGetVersionExA)GetProcAddress(hKernel32, "GetVersionExA");
	if (!MyGetVersion)
		return 0;
	if (MyGetVersion(&VersionInformation))
#else
	if(GetVersionEx(&VersionInformation))
#endif
	{
		switch(VersionInformation.dwPlatformId)
		{
		case VER_PLATFORM_WIN32s:
			nRet = 1;
			break;
		case VER_PLATFORM_WIN32_WINDOWS:
			nRet = 2;
			break;
		case VER_PLATFORM_WIN32_NT:
			nRet = 3;
			break;
		}

	}
	return nRet;

}


//系统处理 - 取操作系统类别2
/*
    调用格式： 〈整数型〉 取操作系统类别2 （） - 系统核心支持库->系统处理
    英文名称：GetSysVer2
    返回当前操作系统的版本类别。返回值为以下值之一：0、未知； 1、Windows 32S； 2、Windows 9X (包含Win95、Win98、WinME等)； 3、其它Windows NT操作系统(不包括后面列出的)； 
	4、Linux； 5、Windows 10； 6、Windows Server 2016 Technical Preview； 7、Windows 8.1； 8、Windows Server 2012 R2； 9、Windows 8； 10、Windows Server 2012； 
	11、Windows 7； 12、Windows Server 2008 R2； 13、Windows Server 2008； 14、Windows Vista。本命令为初级命令。
*/

LIBAPI(int, krnln_GetSysVer2)
{
	OSVERSIONINFOEX1 VerInfoEx;
	INT nRet = 0;
	memset(&VerInfoEx,0,sizeof(OSVERSIONINFOEX1));
	VerInfoEx.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX1);

#if _MSC_VER >= 1916 //VS2017 VS2019
	HMODULE hKernel32 = GetModuleHandle("Kernel32.dll");
	if (!hKernel32)
		return 0;
	MyGetVersionExA MyGetVersion = (MyGetVersionExA)GetProcAddress(hKernel32, "GetVersionExA");
	if (!MyGetVersion)
		return 0;
	if (MyGetVersion((OSVERSIONINFO*)&VerInfoEx))
#else
	if(GetVersionEx((OSVERSIONINFO*)&VerInfoEx))
#endif
	{
		switch(VerInfoEx.dwPlatformId)
		{
		case VER_PLATFORM_WIN32s:
			nRet = 1; //Windows 32S
			break;
		case VER_PLATFORM_WIN32_WINDOWS:
			nRet = 2; //Windows 9X (包含Win95、Win98、WinME等)
			break;
		case VER_PLATFORM_WIN32_NT:
			switch (VerInfoEx.dwMajorVersion)
			{
			case 10:
				if (VerInfoEx.wProductType==VER_NT_WORKSTATION)
					nRet = 5; //Windows 10
				else
					nRet = 6; //Windows Server 2016 Technical Preview
			
				break;
			case 6:
				switch (VerInfoEx.dwMinorVersion)
				{
				case 3:
					if (VerInfoEx.wProductType==VER_NT_WORKSTATION)
						nRet = 7; //Windows 8.1
					else
						nRet = 8; //Windows Server 2012 R2
				
					break;
				case 2:
					if (VerInfoEx.wProductType==VER_NT_WORKSTATION)
						nRet = 9; //Windows 8
					else
						nRet = 10; //Windows Server 2012

					break;
				case 1:
					if (VerInfoEx.wProductType==VER_NT_WORKSTATION)
						nRet = 11; //Windows 7
					else
						nRet = 12; //Windows Server 2008 R2

					break;
				default:
					if (VerInfoEx.wProductType==VER_NT_WORKSTATION)
						nRet = 14; //Windows Vista
					else
						nRet = 13; //Windows Server 2008

					break;
				}
				break;
			default:
				nRet = 3; //其它Windows NT操作系统(不包括后面列出的)
				break;
			}
		}
	}
	return nRet;
}