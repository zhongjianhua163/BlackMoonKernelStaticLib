#include "stdafx.h"

/*
    调用格式： 〈无返回值〉 数组清零 （通用型变量数组 数值数组变量） - 系统核心支持库->数组操作
    英文名称：ZeroAry
    将指定数值数组变量内的所有成员值全部设置为零，不影响数组的维定义信息。本命令为初级命令。
    参数<1>的名称为“数值数组变量”，类型为“通用型（all）”，提供参数数据时只能提供变量数组。
*/

LIBAPI(void, krnln_ZeroAry)
{
	// no data
	if(!ArgInf.m_ppAryData)
		return;

	// not supported data type
	if(ArgInf.m_dtDataType==SDT_TEXT || ArgInf.m_dtDataType==SDT_BIN)
		return;
	
	// get single element size
	// user defined struct is NOT supported, nLen will be zero
	DWORD dwElementSize = (DWORD)GetSysDataTypeDataSize(ArgInf.m_dtDataType);
	if(!dwElementSize)
		return;

	// get first element and array length
	DWORD dwArrayLen = 0;
	void* pFirstElement = GetAryElementInf(*ArgInf.m_ppAryData, dwArrayLen);
	if(!pFirstElement || !dwArrayLen)
		return;

	// zero all element
	memset(pFirstElement, 0, dwElementSize * dwArrayLen);	
}