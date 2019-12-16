#include "stdafx.h"

//其他 - 取数据类型尺寸
/*
    调用格式： 〈整数型〉 取数据类型尺寸 （整数型 欲取其尺寸的数据类型） - 系统核心支持库->其他
    英文名称：GetDataTypeSize
    取指定数据类型的数据尺寸，该数据类型不能为文本、字节集、库或用户自定义数据类型。本命令为初级命令。
    参数<1>的名称为“欲取其尺寸的数据类型”，类型为“整数型（int）”。参数值可以为以下常量：
	1、#字节型； 2、#短整数型； 3、#整数型； 4、#长整数型； 5、#小数型； 6、#双精度小数型； 7、#逻辑型； 8、#日期时间型； 9、#子程序指针型。
*/
LIBAPI(int, krnln_GetDataTypeSize)
{
	switch (ArgInf.m_int)
	{
	case 1://SDT_BYTE:
		return sizeof (BYTE);
	case 2://SDT_SHORT:
		ASSERT (sizeof (SHORT) == 2);
		return sizeof (SHORT);
	case 7://SDT_BOOL:
		ASSERT (sizeof (BOOL) == 4);
		return sizeof (BOOL);
	case 3://SDT_INT:
		ASSERT (sizeof (INT) == 4);
		return sizeof (INT);
	case 5://SDT_FLOAT:
		ASSERT (sizeof (FLOAT) == 4);
		return sizeof (FLOAT);
	case 9://SDT_SUB_PTR:    // 记录子程序代码的地址指针
		return sizeof (DWORD);
	//case SDT_TEXT:    // 文本型和字节集型为一个指针,因此为四个字节.
	//case SDT_BIN:
		//return sizeof (DWORD);
	case 4://SDT_INT64:
		ASSERT (sizeof (INT64) == 8);
		return sizeof (INT64);
	case 6://SDT_DOUBLE:
		ASSERT (sizeof (DOUBLE) == 8);
		return sizeof (DOUBLE);
	case 8://SDT_DATE_TIME:
		ASSERT (sizeof (DATE) == 8);
		return sizeof (DATE);
	default:
		ASSERT (FALSE);
		return 0;
	}
	
	return 0;



}
