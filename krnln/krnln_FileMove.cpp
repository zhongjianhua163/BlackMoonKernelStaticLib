#include "stdafx.h"

//磁盘操作 - 移动文件
/*
    调用格式： 〈逻辑型〉 移动文件 （文本型 被移动的文件，文本型 移动到的位置） - 系统核心支持库->磁盘操作
    英文名称：FileMove
    将文件从一个位置移动到另外一个位置。成功返回真，失败返回假。本命令为初级命令。
    参数<1>的名称为“被移动的文件”，类型为“文本型（text）”。
    参数<2>的名称为“移动到的位置”，类型为“文本型（text）”。
*/
LIBAPI(BOOL, krnln_FileMove)
{
	PMDATA_INF pArgInf = &ArgInf;
	BOOL result = MoveFile(pArgInf[0].m_pText,pArgInf[1].m_pText);
	if(!result){
		result = CopyFile(pArgInf[0].m_pText,pArgInf[1].m_pText, 0);
		if (result)
			result = DeleteFile(pArgInf[0].m_pText);

	}
	return result;
}
