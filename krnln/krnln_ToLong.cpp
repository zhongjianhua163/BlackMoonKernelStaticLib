#include "stdafx.h"

//数值转换 - 到长整数
/*
    调用格式： 〈长整数型〉 到长整数 （通用型 待转换的文本或数值） - 系统核心支持库->数值转换
    英文名称：ToLong
    返回包含于文本内的长整数值，文本中是一个适当类型的数值，支持全角书写方式。本命令也可用作将其他类型的数据转换为长整数。本命令为初级命令。
    参数<1>的名称为“待转换的文本或数值”，类型为“通用型（all）”。
*/
LIBAPI(void, krnln_ToLong)
{
	INT64 nRet=0;
	switch(ArgInf.m_dtDataType)
	{
	case SDT_BYTE:
		{
// 			INT nVal = ArgInf.m_byte;
// 			ArgInf.m_int64 = nVal;
			nRet = ArgInf.m_byte;
		}
		break;
	case SDT_SHORT:
		{
// 			INT nVal = ArgInf.m_short;
// 			ArgInf.m_int64 = nVal;
			nRet = ArgInf.m_short;
		}
		break;
	case SDT_TEXT:
		{
			char* pStr = krnln_BJCase(1,ArgInf);
			if(pStr)
			{
				nRet = _atoi64(pStr);
				ArgInf.m_int64 = nRet;
				E_MFree(pStr);
			}
// 			else
// 				nRet = 0;
		}
		break;
	case SDT_FLOAT:
		nRet = ArgInf.m_float;
//		ArgInf.m_int64 = nRet;
		break;
	case SDT_DOUBLE:
		nRet = ArgInf.m_double;
//		ArgInf.m_int64 = nRet;
		break;
	default:
		break;
	}
	ArgInf.m_int64 = nRet;
	__asm{
		mov eax, ArgInf.m_unit.m_dwFormID;
		mov edx, ArgInf.m_unit.m_dwUnitID;
	}
}
