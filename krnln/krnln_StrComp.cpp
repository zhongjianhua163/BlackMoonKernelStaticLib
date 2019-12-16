#include "stdafx.h"

//文本操作 - 文本比较
/*
    调用格式： 〈整数型〉 文本比较 （文本型 待比较文本一，文本型 待比较文本二，逻辑型 是否区分大小写） - 系统核心支持库->文本操作
    英文名称：StrComp
    如果返回值小于0，表示文本一小于文本二；如果等于0，表示文本一等于文本二；如果大于0，表示文本一大于文本二。如果比较时区分大小写，也可以使用比较运算符进行同样的操作。本命令为初级命令。
    参数<1>的名称为“待比较文本一”，类型为“文本型（text）”。
    参数<2>的名称为“待比较文本二”，类型为“文本型（text）”。
    参数<3>的名称为“是否区分大小写”，类型为“逻辑型（bool）”，初始值为“真”。为真区分大小写，为假不区分。
*/
LIBAPI(int, krnln_StrComp)
{
	PMDATA_INF pArgInf = &ArgInf;
	if(pArgInf[2].m_bool)//区分大小写
		return strcmp(pArgInf[0].m_pText,pArgInf[1].m_pText);

	return stricmp(pArgInf[0].m_pText,pArgInf[1].m_pText);
}
