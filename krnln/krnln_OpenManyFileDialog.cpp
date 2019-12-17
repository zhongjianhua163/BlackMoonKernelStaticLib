#include "stdafx.h"
#include <stdio.h>
#include "mem.h"
#include "Myfunctions.h"
#pragma comment(lib,"comdlg32.lib") 

//系统处理 - 多文件对话框
/*
    调用格式： 〈文本型数组〉 多文件对话框 （［文本型 标题］，［文本型 过滤器］，［整数型 初始过滤器］，［文本型 初始目录］，［逻辑型 不改变目录］） - 系统核心支持库->系统处理
    英文名称：OpenManyFileDialog
    显示一个文件打开对话框，允许用户选择或输入多个所需要打开的已存在文件，返回用户所选择或输入后的结果文本数组。如果用户未输入或按“取消”按钮退出，则返回一个成员数为0的空文本数组。本命令为初级命令。
    参数<1>的名称为“标题”，类型为“文本型（text）”，可以被省略。指定文件打开对话框的标题，如果被省略，则默认为“请输入欲打开的文件：”。
    参数<2>的名称为“过滤器”，类型为“文本型（text）”，可以被省略。过滤器文本由单个或多个成对的文本串组成，每对文本串的第一个描述显示形式，如：“文本文件（*.txt）”；第二个指定实际的过滤匹配符，如：“*.txt”，所有各文本串之间用“|”号隔开。如果被省略，则默认没有过滤器。
    参数<3>的名称为“初始过滤器”，类型为“整数型（int）”，可以被省略。如果上一参数提供了有效的过滤器文本，则本参数用作指定初始的过滤器，0为第一个过滤器。如果被省略，则默认值为0。
    参数<4>的名称为“初始目录”，类型为“文本型（text）”，可以被省略。指定当打开对话框时所自动跳转到的目录，如果被省略，则默认为当前目录。
    参数<5>的名称为“不改变目录”，类型为“逻辑型（bool）”，可以被省略。指定在对话框关闭后是否自动返回到进入对话框前的文件目录，如果被省略，则默认值为假。
    参数<6>的名称为“父窗口”，类型为“通用型（all）”，可以被省略。指定对话框的父窗口,可以是一个"窗口"类型数据或者一个整数型窗口句柄.如果被省略,默认为无.

*/
LIBAPI(void*, krnln_OpenManyFileDialog)
{
	PMDATA_INF pArgInf = &ArgInf;
	CMyDWordArray aryText;

	OPENFILENAME fileinfo;
	memset(&fileinfo,0,sizeof(OPENFILENAME));
	fileinfo.lpstrTitle = pArgInf[0].m_pText;
	if(pArgInf[1].m_dtDataType != _SDT_NULL && pArgInf[1].m_pText)
	{
		INT nLen = mystrlen(pArgInf[1].m_pText);
		if(nLen)
		{
			LPSTR pTemp = new char[nLen+2];
			strcpy(pTemp,pArgInf[1].m_pText);
			pTemp[nLen+1]=0;
			INT i=0;
			fileinfo.lpstrFilter=pTemp;
			while(i < nLen)
			{
				if(*pTemp=='|')
					*pTemp = 0;
				pTemp++;
				i++;
			}


		}

	}
	fileinfo.nFilterIndex = pArgInf[2].m_int + 1; //从1开始，而易从0开始
	if(pArgInf[3].m_dtDataType != _SDT_NULL && pArgInf[3].m_pText)
	{
		fileinfo.lpstrInitialDir = pArgInf[3].m_pText;
	}
	


	fileinfo.lStructSize = sizeof(OPENFILENAME);
	char pszFileName[8192];
	pszFileName[0]=0;
	fileinfo.nMaxFile = 8192;
	fileinfo.lpstrFile = pszFileName;
	fileinfo.Flags = OFN_EXPLORER | OFN_ALLOWMULTISELECT |OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
	char preDir [MAX_PATH];
	preDir[0]=0;
	if(pArgInf[4].m_dtDataType != _SDT_NULL && pArgInf[4].m_bool)
	{
		GetCurrentDirectory (MAX_PATH,preDir);
	}
	if(nArgCount>5) //易语言5.3新增加了"父窗口"参数
	{
		if(pArgInf[5].m_dtDataType != _SDT_NULL)
		{
			fileinfo.hwndOwner = (HWND)pArgInf[5].m_int;
		}
	}
	if(GetOpenFileName(&fileinfo))
	{
		LPSTR pText = pszFileName+fileinfo.nFileOffset;
		LPSTR pPath = pszFileName;

		INT nLen = mystrlen(pPath);
		if(pPath[nLen-1]=='\\')
			pPath[nLen-1]=0;
		nLen = mystrlen(pText);
		if(pText[nLen+1]==0)//选单个文件
		{
			nLen = mystrlen(pPath);
			aryText.Add ((DWORD)CloneTextData (pPath, nLen));
		}else{//选多个文件
			LPSTR pEnd = pText + 8192;
			while(*pText !=0 && pText < pEnd)
			{
				char szFileName [MAX_PATH];
				sprintf(szFileName,"%s\\%s",pPath,pText);
				nLen = mystrlen(szFileName);
				aryText.Add ((DWORD)CloneTextData (szFileName, nLen));
				nLen = mystrlen(pText);
				
				pText+=(nLen+1);
			}

		}


		


		if(preDir[0] !=0)
			SetCurrentDirectory (preDir);



	}
	if(fileinfo.lpstrFilter)
		delete[] (LPSTR)fileinfo.lpstrFilter;

	
	// 建立新变量数组数据。
	INT nSize = aryText.GetDWordCount () * sizeof (DWORD);
	LPSTR p = (LPSTR)E_MAlloc (sizeof (INT) * 2 + nSize);
	*(LPINT)p = 1;  // 数组维数。
	*(LPINT)(p + sizeof (INT)) = aryText.GetDWordCount ();
	memcpy (p + sizeof (INT) * 2, aryText.GetPtr (), nSize);
	return  p;  // 将新内容写回该数组变量。
}
