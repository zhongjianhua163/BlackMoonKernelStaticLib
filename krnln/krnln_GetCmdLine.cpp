#include "stdafx.h"
#include "mem.h"

//#pragma comment(lib,"shell32.lib") 

//环境存取 - 取命令行
/*
    调用格式： 〈无返回值〉 取命令行 （文本型变量数组 存放被取回命令行文本的数组变量） - 系统核心支持库->环境存取
    英文名称：GetCmdLine
    本命令可以取出在启动易程序时附加在其可执行文件名后面的所有以空格分隔的命令行文本段。本命令为初级命令。
    参数<1>的名称为“存放被取回命令行文本的数组变量”，类型为“文本型（text）”，提供参数数据时只能提供变量数组。在命令执行完毕后，本变量数组内被顺序填入在启动易程序时附加在其可执行文件名后面的以空格分隔的命令行文本段。变量数组内原有数据被全部销毁，变量数组的维数被自动调整为命令行文本段数。
*/
/*
char* BMUnicodeToAnsi(LPWSTR lpWstr)
{
	INT nLen = WideCharToMultiByte(0, 0, lpWstr, -1, NULL, NULL, 0, 0);
	if(nLen==0)return NULL;
	char* pText = (char*)E_MAlloc(nLen +1);
	WideCharToMultiByte (0, 0, lpWstr, -1,pText, nLen, 0, 0);
	return pText;

}
*/
#define IS_CC(p) p<0

LIBAPI(void, krnln_GetCmdLine)
{
	LPWSTR *szArglist;
	int nArgs, i;
	int al;
	char *pSrc;
	LPSTR p;
	CMyDWordArray aryText;

	szArglist = CommandLineToArgvW(GetCommandLineW(), &nArgs);
	if (szArglist)
	{
		for (i=1; i<nArgs; i++)
		{
			//由UNICDOE转成ANSI
			al = WideCharToMultiByte(936, NULL, szArglist[i], -1, NULL, NULL, NULL, NULL);
			pSrc = NULL;
			if (al > 0)
			{
				pSrc = (char*)E_MAlloc_Nzero(al + 1);
				if (pSrc)
				{
					al = WideCharToMultiByte(936, NULL, szArglist[i], -1, pSrc, al, NULL, NULL);
					pSrc[al] = 0;
				}
				aryText.Add ((DWORD)pSrc);
			}
		}
	}

	//!!! 必须先释放原变量数组的数据内容。
	void * pArry = *ArgInf.m_ppAryData;
	if(pArry)
		FreeAryElement(pArry);
	
	// 建立新变量数组数据。
	INT nSize = aryText.GetDWordCount () * sizeof (DWORD);
	p = (LPSTR)E_MAlloc_Nzero (sizeof (INT) * 2 + nSize);
	*(LPINT)p = 1;  // 数组维数。
	*(LPINT)(p + sizeof (INT)) = aryText.GetDWordCount ();
	memcpy (p + sizeof (INT) * 2, aryText.GetPtr (), nSize);
	*ArgInf.m_ppAryData =  p;  // 将新内容写回该数组变量。
}

/*
extern "C" void _cdecl krnln_GetCmdLine (INT nArgCount,MDATA_INF ArgInf,...)
{
/*
	void * pArry = *ArgInf.m_ppAryData;
	if(pArry)
		FreeAryElement(pArry);

	int argCount = 0;
	LPWSTR* lpArgv = ::CommandLineToArgvW(::GetCommandLineW(), &argCount);
	LPINT pArryData;
	if(argCount < 2 )
	{
		pArryData = (LPINT)E_MAlloc(2 * sizeof(INT));
		pArryData[0]=1;
		pArryData[1]=0;
		*ArgInf.m_ppAryData = pArryData;
	}
	else
	{
		argCount --;
		pArryData = (LPINT)E_MAlloc((2+argCount) * sizeof(INT));
		pArryData[0]=1;
		pArryData[1]=argCount;
		LPSTR* pArryText = (LPSTR*)(pArryData+2);

		for(INT i=0;i < argCount;i++)
		{
			pArryText[i] = BMUnicodeToAnsi(lpArgv[i+1]);
			//MessageBox(NULL,pArryText[i],NULL,MB_OK);
		}
		

	}
	*ArgInf.m_ppAryData = pArryData;

	GlobalFree(lpArgv);
*/

/*
	LPSTR p = GetCommandLine (), pb;
	// 跳过调用程序名。
	char ch = ' ';
	if (*p++ == '\"')
		ch = '\"';
	while (*p++ != ch);
	if (ch != ' ' && *p == ' ')  p++;    // 跳过第一个空格。
	
	CMyDWordArray aryText;
	
	while (*p != '\0')
	{
		if (*p == '\"')
		{
			p++;
			pb = p;
			while (*pb != '\0' && *pb != '\"')
			{
				if (IS_CC (*pb) == TRUE)
				{
					if (pb [1] == 0)  break;
					pb++;
				}
				pb++;
			}
			
			aryText.Add ((DWORD)CloneTextData ((char*)p, pb - p));
			
			p = pb;
			if (*p != '\0')  p++;
		}
		else if (*p > ' ' || *pb<0)
		{
			pb = p;
			while (*pb != '\0' && *pb != '\"' && (*pb > ' ' || *pb<0))
			{
				if (IS_CC (*pb) == TRUE)
				{
					if (pb [1] == 0)  break;
					pb++;
				}
				pb++;
			}
			
			aryText.Add ((DWORD)CloneTextData ((char*)p, pb - p));
			
			p = pb;
		}
		else
			p++;
	}
	
	//!!! 必须先释放原变量数组的数据内容。
	void * pArry = *ArgInf.m_ppAryData;
	if(pArry)
		FreeAryElement(pArry);
	
	// 建立新变量数组数据。
	INT nSize = aryText.GetDWordCount () * sizeof (DWORD);
	p = (LPSTR)E_MAlloc_Nzero (sizeof (INT) * 2 + nSize);
	*(LPINT)p = 1;  // 数组维数。
	*(LPINT)(p + sizeof (INT)) = aryText.GetDWordCount ();
	A_memcpy (p + sizeof (INT) * 2, aryText.GetPtr (), nSize);
	*ArgInf.m_ppAryData =  p;  // 将新内容写回该数组变量。
}
*/