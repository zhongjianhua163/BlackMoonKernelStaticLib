#include "stdafx.h"
#include <stdio.h>
#include "Myfunctions.h"
//控制台操作 - 标准输出
/*
    调用格式： 〈无返回值〉 标准输出 （［整数型 输出方向］，通用型 欲输出内容，... ） - 系统核心支持库->控制台操作
    英文名称：fputs
    在标准输出设备或标准错误设备上输出指定的内容，注意本命令只能在控制台程序中使用。本命令为初级命令。命令参数表中最后一个参数可以被重复添加。
    参数<1>的名称为“输出方向”，类型为“整数型（int）”，可以被省略。本参数提供内容所输出到的设备，可以为以下常量值之一： 1、#标准输出设备； 2、#标准错误设备。如果省略本参数，默认为“#标准输出设备”。
    参数<2>的名称为“欲输出内容”，类型为“通用型（all）”。本参数只能为文本、数值、逻辑值或日期时间。如果内容为文本且包含多行，可在各行之间用回车符 (即“字符 (13)”)、换行符 (即“字符 (10)”) 或回车换行符的组合 (即：“字符 (13) + 字符 (10)”) 来分隔。
*/
LIBAPI(void, krnln_fputs)
{
	PMDATA_INF pArgInf = &ArgInf;
	
	DWORD dwSdt = STD_OUTPUT_HANDLE;
	if(pArgInf[0].m_dtDataType != _SDT_NULL && pArgInf[0].m_int==2)
		dwSdt = STD_ERROR_HANDLE;
	HANDLE hCon = GetStdHandle(dwSdt);
	if(hCon==NULL)
			return;
/*	 _iobuf* hCon = stdout;
	if(pArgInf[0].m_dtDataType != _SDT_NULL && pArgInf[0].m_int==2)
		hCon = stderr;*/

	for(INT i=1;i < nArgCount;i++)
	{
		LPSTR pData;
		BOOL bNeedFree = FALSE;
		if(pArgInf[i].m_dtDataType == SDT_TEXT)
			pData = pArgInf[i].m_pText;
		else
		{
			pData = SDataToStr(&pArgInf[i]);
			if(pData == NULL)
				continue;
			bNeedFree = TRUE;
		}
		
		UINT nLen = mystrlen(pData);
		//char text[50];
		//itoa(nLen,text,10);
		//MessageBox(NULL,text,NULL,MB_OK);
		if(nLen>0)
		{
			LPSTR pStr = pData;
			while(nLen>0){
				DWORD dwSize=0;
				UINT nSize = 1024;
				if(nLen<1024)
					nSize = nLen;
				WriteFile(hCon,pStr,nSize,&dwSize,NULL);
				nLen-=dwSize;
				pStr+=dwSize;
			}
			
			//WriteConsole(hCon,pData,nLen,&dwSize,NULL);
			

			//fprintf(hCon, "%s",pData); 
		}
		
		if(bNeedFree)
			free(pData);

	}
	

}
