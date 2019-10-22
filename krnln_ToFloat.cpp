#include "stdafx.h"
//数值转换 - 到小数
/*
    调用格式： 〈小数型〉 到小数 （通用型 待转换的文本或数值） - 系统核心支持库->数值转换
    英文名称：ToFloat
    返回包含于文本内的小数值，文本中是一个适当类型的数值，支持全角书写方式。本命令也可用作将其他类型的数据转换为小数。本命令为初级命令。
    参数<1>的名称为“待转换的文本或数值”，类型为“通用型（all）”。
*/
LIBAPI(void, krnln_ToFloat)
{
	float nRet=0;
	switch(ArgInf.m_dtDataType)
	{
	case SDT_TEXT:
		{
			char* pStr = krnln_BJCase(1,ArgInf);
			if(pStr)
			{
				nRet = (float)atof(pStr);
				E_MFree(pStr);
			}
		}
		break;
	case SDT_BYTE:
		nRet = ArgInf.m_byte;
		break;
	case SDT_SHORT:
		nRet = ArgInf.m_short;
		break;
	case SDT_INT:
	case SDT_SUB_PTR:
	case SDT_BOOL:
		nRet = ArgInf.m_int;
		break;
	case SDT_FLOAT:
		nRet = ArgInf.m_float;
		break;
	case SDT_DOUBLE:
		nRet = ArgInf.m_double;
		break;
	case SDT_INT64:
		nRet = ArgInf.m_int64;
		break;
	default:
		break;

	}
	_asm mov eax, nRet;
	_asm xor edx, edx;
	//return nRet;
}
