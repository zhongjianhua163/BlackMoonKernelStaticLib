#include "stdafx.h"

//算术运算 - 取随机数
/*
    调用格式： 〈整数型〉 取随机数 （［整数型 欲取随机数的最小值］，［整数型 欲取随机数的最大值］） - 系统核心支持库->算术运算
    英文名称：rnd
    返回一个指定范围内的随机数值。在使用本命令取一系列的随机数之前，应该先使用“置随机数种子”命令为随机数生成器初始化一个种子值。本命令为初级命令。
    参数<1>的名称为“欲取随机数的最小值”，类型为“整数型（int）”，可以被省略。参数必须大于或等于零。本参数如果被省略，默认为 0 。
    参数<2>的名称为“欲取随机数的最大值”，类型为“整数型（int）”，可以被省略。参数必须大于或等于零。本参数如果被省略，默认为无限。
*/
LIBAPI(int, krnln_rnd)
{
/*
	INT nMin,nMax;
	PMDATA_INF pArg = &ArgInf;
	if(pArg[0].m_dtDataType == _SDT_NULL || pArg[0].m_int < 0)
		nMin = 0;
	else
		nMin = pArg[0].m_int;

	if(pArg[1].m_dtDataType == _SDT_NULL || pArg[1].m_int < 0)
		nMax = 0x7FFFFFFF;
	else
		nMax = pArg[1].m_int;
	INT nSub = nMax-nMin;
	if(nSub > 0 && nSub < RAND_MAX)
	{
		nSub++;
		nSub = (int)((double)rand()/((double)RAND_MAX/(double)nSub));

	}else if (nSub > RAND_MAX)
	{
		nSub = (int)((double)nSub*((double)rand()/(double)RAND_MAX));

	}else if(nSub == RAND_MAX)
	{
		nSub = rand();
	}

	return nSub+nMin;
*/
	PMDATA_INF pArg = &ArgInf;
  int v3; // esi@2
  int result; // eax@5
  int v5; // ecx@7
  signed int v6; // edi@13

  if (pArg[0].m_dtDataType != _SDT_NULL)
    v3 = pArg[0].m_int & ((pArg[0].m_int < 0) - 1);
  else
    v3 = 0;
  if (pArg[1].m_dtDataType != _SDT_NULL)
    result = ((pArg[1].m_int < 0) - 1) & pArg[1].m_int;
  else
    result = 2147483647;
  v5 = v3;
  if ( v3 >= result )
    v3 = result;
  if ( v5 > result )
    result = v5;
  if ( v3 == result )
  {
    result = v3;
  }
  else
  {
    result -= v3;
    v6 = 2147483646;
    if ( result <= 2147483646 )
      v6 = result;
    result = v3 + abs(rand()) % (v6 + 1);
  }
  return result;

}
