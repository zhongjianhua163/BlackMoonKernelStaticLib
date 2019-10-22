#include "stdafx.h"

/*
    调用格式： 〈无返回值〉 数组清零 （通用型变量数组 数值数组变量） - 系统核心支持库->数组操作
    英文名称：ZeroAry
    将指定数值数组变量内的所有成员值全部设置为零，不影响数组的维定义信息。本命令为初级命令。
    参数<1>的名称为“数值数组变量”，类型为“通用型（all）”，提供参数数据时只能提供变量数组。
*/

LIBAPI(void, krnln_ZeroAry)
{
	
	if(ArgInf.m_ppAryData==NULL)//空数组
		return;

	
	if(ArgInf.m_dtDataType==SDT_TEXT || ArgInf.m_dtDataType==SDT_BIN)
	{
		DWORD dwSize;
		LPSTR* pAryData = (LPSTR*)GetAryElementInf(*ArgInf.m_ppAryData,dwSize);

		for(UINT n=0;n<dwSize;n++)
		{
			if(pAryData[n])
				E_MFree(pAryData[n]);
			pAryData[n] = NULL;

		}

	}else{

		INT nLen = GetSysDataTypeDataSize(ArgInf.m_dtDataType);
		if(nLen==0)//不支持的数据类型
			return;
		DWORD dwSize=0;
		void* pData = GetAryElementInf(*ArgInf.m_ppAryData,dwSize);
		if(pData==NULL || dwSize==0)
			return;
		nLen *= dwSize;
		memset(pData,0,nLen);
					
	}

}