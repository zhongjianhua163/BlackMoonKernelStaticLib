#include "stdafx.h"
#include "Myfunctions.h"

//系统处理 - 读配置项
/*
    调用格式： 〈文本型〉 读配置项 （文本型 配置文件名，文本型 节名称，文本型 配置项名称，［文本型 默认文本］） - 系统核心支持库->系统处理
    英文名称：GetKeyText
    读取指定配置文件中指定项目的文本内容。本命令为初级命令。
    参数<1>的名称为“配置文件名”，类型为“文本型（text）”。指定配置文件的名称，通常以.ini作为文件名后缀。
    参数<2>的名称为“节名称”，类型为“文本型（text）”。包含欲读入配置项所处节的名称。
    参数<3>的名称为“配置项名称”，类型为“文本型（text）”。参数值指定欲读入配置项在其节中的名称。
    参数<4>的名称为“默认文本”，类型为“文本型（text）”，可以被省略。如果指定配置项不存在，将返回此默认文本。如果指定配置项不存在且本参数被省略，将返回空文本。
*/
LIBAPI(char*, krnln_GetKeyText)
{
	PMDATA_INF pArgInf = &ArgInf;
	LPSTR pBuff = NULL;
	INT nLen = 1024;
	do
	{

		pBuff = new char[nLen];
		INT nRet = GetPrivateProfileString (pArgInf[1].m_pText, pArgInf[2].m_pText, pArgInf[3].m_pText, pBuff, nLen, pArgInf[0].m_pText);

		if(nRet < nLen-1)
			break;
		nLen = nRet+1024;
		delete[] pBuff;
	}while(1);

	LPSTR pText = NULL;
	nLen = mystrlen(pBuff);
	if(nLen)
	{
		pText = CloneTextData(pBuff,nLen);
	}
	delete[] pBuff;
	return pText;
}
