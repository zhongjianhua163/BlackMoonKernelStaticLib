#include "stdafx.h"

// 调用格式： 〈整数型〉 反转整数字节序 （整数型 待反转的整数值） - 系统核心支持库->数值转换
// 英文名称：ReverseIntBytes
// 将所指定整数的字节序反转,返回反转后的结果值. 譬如十六进制整数0x12345678,反转后将返回0x78563412. 本命令在与类似Java这样的语言进行数据交互时很有用处.本命令为初级命令。
// 参数<1>的名称为“待反转的整数值”，类型为“整数型（int）”。提供所欲反转其字节序的整数值。
// 
// 操作系统需求： Windows、Linux
LIBAPI(int, krnln_ReverseIntBytes)
{
	int nRes = ArgInf.m_int >> 24;
	nRes |= ((ArgInf.m_int & 0x00FF0000) >> 8);
	nRes |= ((ArgInf.m_int & 0x0000FF00) << 8);
	nRes |= ((ArgInf.m_int & 0x000000FF) << 24);
	return nRes;
}