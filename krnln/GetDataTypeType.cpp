#include "StdAfx.h"


// 取回数据类型的类别。
INT GetDataTypeType (DATA_TYPE dtDataType)
{
	if (dtDataType == _SDT_NULL)
		return DTT_IS_NULL_DATA_TYPE;
	
	DWORD dw = dtDataType & 0xC0000000;
	return dw == DTM_SYS_DATA_TYPE_MASK ? DTT_IS_SYS_DATA_TYPE :
	dw == DTM_USER_DATA_TYPE_MASK ? DTT_IS_USER_DATA_TYPE :
	DTT_IS_LIB_DATA_TYPE;
}