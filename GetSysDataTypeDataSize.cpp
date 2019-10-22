#include "StdAfx.h"


// 辅助函数
INT GetSysDataTypeDataSize (DATA_TYPE dtSysDataType)
{
	ASSERT (sizeof (DWORD) == 4);
	
	switch (dtSysDataType)
	{
	case SDT_BYTE:
		ASSERT (sizeof (BYTE) == 1);
		return sizeof (BYTE);
	case SDT_SHORT:
		ASSERT (sizeof (SHORT) == 2);
		return sizeof (SHORT);
	case SDT_BOOL:
		ASSERT (sizeof (BOOL) == 4);
		return sizeof (BOOL);
	case SDT_INT:
		ASSERT (sizeof (INT) == 4);
		return sizeof (INT);
	case SDT_FLOAT:
		ASSERT (sizeof (FLOAT) == 4);
		return sizeof (FLOAT);
	case SDT_SUB_PTR:    // 记录子程序代码的地址指针
		return sizeof (DWORD);
	case SDT_TEXT:    // 文本型和字节集型为一个指针,因此为四个字节.
	case SDT_BIN:
		return sizeof (DWORD);
	case SDT_INT64:
		ASSERT (sizeof (INT64) == 8);
		return sizeof (INT64);
	case SDT_DOUBLE:
		ASSERT (sizeof (DOUBLE) == 8);
		return sizeof (DOUBLE);
	case SDT_DATE_TIME:
		ASSERT (sizeof (DATE) == 8);
		return sizeof (DATE);
	default:
		ASSERT (FALSE);
		return 0;
	}
	
	return 0;
}