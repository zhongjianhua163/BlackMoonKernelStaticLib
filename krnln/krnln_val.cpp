#include "stdafx.h"

//数值转换 - 到数值
/*
    调用格式： 〈双精度小数型〉 到数值 （通用型 待转换的文本或数值） - 系统核心支持库->数值转换
    英文名称：val
    返回包含于文本内的数值，文本中是一个适当类型的数值，支持全角书写方式。本命令也可用作将其他类型的数据转换为双精度小数。本命令为初级命令。
    参数<1>的名称为“待转换的文本或数值”，类型为“通用型（all）”。
*/
LIBAPI(void, krnln_val)
{
	switch(ArgInf.m_dtDataType)
	{
	case SDT_BYTE:
		{
			INT nVal = ArgInf.m_byte;
			ArgInf.m_double = nVal;
		}
		break;
	case SDT_SHORT:
		{
			INT nVal = ArgInf.m_short;
			ArgInf.m_double = nVal;
		}
		break;
	case SDT_TEXT:
		{
			char* pStr = krnln_BJCase(1,ArgInf);
			if(pStr)
			{
				ArgInf.m_double = strtod(pStr,NULL);
				E_MFree(pStr);
			}
			else
				ArgInf.m_double = 0;
			//ArgInf.m_double = strtod(ArgInf.m_pText,NULL);
		}
		break;
	case SDT_DATE_TIME:
	case SDT_DOUBLE:
		break;
	case SDT_FLOAT:
		{
			FLOAT floatval = ArgInf.m_float;
			ArgInf.m_double = floatval;
		}
		break;
	case SDT_INT64:
		{
			INT64 int64 = ArgInf.m_int64;
			ArgInf.m_double = int64;
		}
		break;
	default:
		{
			INT nVal = ArgInf.m_int;
			ArgInf.m_double = nVal;//100年1月1日
		}
	}
	__asm{
		mov eax, ArgInf.m_unit.m_dwFormID;
		mov edx, ArgInf.m_unit.m_dwUnitID;
	}
}
