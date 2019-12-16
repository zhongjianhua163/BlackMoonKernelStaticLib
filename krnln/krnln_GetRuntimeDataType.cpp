#include "stdafx.h"

/*
	调用格式： 〈整数型〉取运行时数据类型 (通用型 欲取其数据类型的数据)
	英文名称：GetRuntimeDataType
	返回所提供参数的运行时数据类型值. 注意: 
	如果该数据类型是在除系统核心支持库外的其它支持库中定义的,那么每一次程序启动后该数据类型值可能会发生变化(因为载入程序时重定位操作的原因),
	不过在程序运行过程中该值是不会变化的.除开此特例外,其它数据的数据类型在任何时候均始终是一个恒定值.
	参数<1>的名称为“欲取其数据类型的数据”，类型为“通用型”。欲取其运行时数据类型的数据
*/	
LIBAPI(int, krnln_GetRuntimeDataType)
{
	PMDATA_INF pArgInf = &ArgInf;
	return (int)pArgInf [0].m_dtDataType;
}
