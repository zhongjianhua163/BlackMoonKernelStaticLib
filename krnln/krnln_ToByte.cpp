#include "stdafx.h"

//数值转换 - 到字节
/*
    调用格式： 〈字节型〉 到字节 （通用型 待转换的文本或数值） - 系统核心支持库->数值转换
    英文名称：ToByte
    返回包含于文本内的字节值，文本中是一个适当类型的数值，支持全角书写方式。本命令也可用作将其他类型的数据转换为字节。本命令为初级命令。
    参数<1>的名称为“待转换的文本或数值”，类型为“通用型（all）”。
*/
LIBAPI(BYTE, krnln_ToByte)
{
	BYTE nRet=0;
	switch(ArgInf.m_dtDataType)
	{
	case SDT_TEXT:
		{
			char* pStr = krnln_BJCase(1,ArgInf);
			if(pStr)
			{
				nRet = atoi(pStr);
				E_MFree(pStr);
			}
			else
				nRet = 0;
		}
		break;
	case SDT_BYTE:
	case SDT_BOOL:
		nRet = ArgInf.m_byte;
		break;
	case SDT_SHORT:
		nRet = (BYTE)ArgInf.m_short;
		break;
	case SDT_INT:
		nRet = ArgInf.m_int;
		break;
	case SDT_FLOAT:
		nRet = (BYTE)ArgInf.m_float;
		break;
	case SDT_DOUBLE:
		nRet = (BYTE)ArgInf.m_double;
		break;
	case SDT_INT64:
		nRet = (BYTE)ArgInf.m_int64;
		break;
	default:
		nRet = ArgInf.m_byte;
		break;

	}
	return nRet;
}
