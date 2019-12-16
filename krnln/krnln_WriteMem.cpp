#include "stdafx.h"
#include "Myfunctions.h"
//其他 - 写到内存
/*
   调用格式： 〈无返回值〉 写到内存 （通用型数组/非数组 欲写到内存的数据，整数型 内存区域指针，［整数型 内存区域尺寸］） - 系统核心支持库->其他
    英文名称：WriteMem
    将数据写出到指定的内存区域，注意调用本命令前一定要确保所提供的内存区域真实有效。本命令的最佳使用场合就是在易语言回调子程序和易语言DLL公开子程序中用作对外输出数据。本命令为高级命令。
    参数<1>的名称为“欲写到内存的数据”，类型为“通用型（all）”，提供参数数据时可以同时提供数组或非数组数据。参数值只能为基本数据类型数据或字节数组。
    参数<2>的名称为“内存区域指针”，类型为“整数型（int）”。本参数提供欲写向内存区域首地址的指针值。
    参数<3>的名称为“内存区域尺寸”，类型为“整数型（int）”，可以被省略。本参数提供该内存区域的有效尺寸，如果欲写出数据超出此尺寸值，将被自动切除。参数值如果为 -1 ，则表示此内存区域尺寸不受限制。如果本参数被省略，则默认值为 -1。
*/
LIBAPI(void, krnln_WriteMem)
{
	PMDATA_INF pArgInf = &ArgInf;
	LPBYTE pData;
	DWORD dwLen;
	if((pArgInf[0].m_dtDataType & DT_IS_ARY) == DT_IS_ARY)//是数组
	{
		pArgInf[0].m_dtDataType &=~DT_IS_ARY; //去除数组标志
		if(pArgInf[0].m_dtDataType == SDT_BYTE)//字节数组
		{
			pData = (LPBYTE)GetAryElementInf(pArgInf[0].m_pAryData,dwLen);
			if(dwLen==0)
				return;
		}else
			return;
	}
	else 
	{
		if(pArgInf[0].m_dtDataType==SDT_TEXT)
		{
			if(pArgInf[0].m_pText==NULL)
				return;
			
			dwLen = mystrlen(pArgInf[0].m_pText);
			if(dwLen==0)
				return;
			dwLen++;
			pData = (LPBYTE)pArgInf[0].m_pText;
			
		}else if(pArgInf[0].m_dtDataType==SDT_BIN)
		{
			if(pArgInf[0].m_pBin==NULL)
				return;

			LPINT p = (LPINT)pArgInf[0].m_pBin;
			dwLen = p[1];
			p+=2;
			pData = (LPBYTE)p;

			
		}else{
			
			dwLen = GetSysDataTypeDataSize(pArgInf[0].m_dtDataType);
			if(dwLen==0)//不支持的数据类型
				return;
			pData = (LPBYTE)&pArgInf[0].m_int;
		}

	}
	if(pArgInf[2].m_dtDataType != _SDT_NULL && pArgInf[2].m_int>0)
	{
		if(pArgInf[2].m_int<(INT)dwLen)
			dwLen = pArgInf[2].m_int;
	}
	memcpy(pArgInf[1].m_pCompoundData,pData,dwLen);
	


}
