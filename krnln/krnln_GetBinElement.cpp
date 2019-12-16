#include "stdafx.h"
#include "mem.h"
#include "Myfunctions.h"

//字节集操作 - 取字节集数据
/*
    调用格式： 〈通用型〉 取字节集数据 （字节集 欲取出其中数据的字节集，整数型 欲取出数据的类型，［整数型 起始索引位置］） - 系统核心支持库->字节集操作
    英文名称：GetBinElement
    取出字节集中指定位置指定数据类型的数据。本命令为初级命令。
    参数<1>的名称为“欲取出其中数据的字节集”，类型为“字节集（bin）”。
    参数<2>的名称为“欲取出数据的类型”，类型为“整数型（int）”。参数值可以为以下常量： 1、#字节型； 2、#短整数型； 3、#整数型； 4、#长整数型； 5、#小数型； 6、#双精度小数型； 7、#逻辑型； 8、#日期时间型； 9、#子程序指针型； 10、#文本型。转换后的数据将自动进行有效性校验及转换处理。
    参数<3>的名称为“起始索引位置”，类型为“整数型（int）”，可以被省略。指定从字节集的什么地方开始取数据，索引值从1开始。如果被省略，默认为数值1。如果为本参数提供一个整数型变量，则命令执行后将自动修改该变量内容，将其索引值移动到下一个读入位置。如果移动后到达字节集的末尾，将修改该变量的内容为-1。
*/
// 辅助函数
void SetMDataValue (PMDATA_INF pRetData, LPBYTE pData, INT nDataSize)
{
	switch (pRetData->m_dtDataType)
	{
	case SDT_BYTE:
		pRetData->m_byte = *pData;
		break;
	case SDT_SHORT:
		pRetData->m_short = *(SHORT*)pData;
		break;
	case SDT_INT:
		pRetData->m_int = *(INT*)pData;
		break;
	case SDT_INT64:
		pRetData->m_int64 = *(INT64*)pData;
		break;
	case SDT_FLOAT:
		pRetData->m_float = *(FLOAT*)pData;
		break;
	case SDT_DOUBLE:
		pRetData->m_double = *(DOUBLE*)pData;
		break;
	case SDT_BOOL:
		pRetData->m_bool = (*(BOOL*)pData != FALSE);
		break;
	case SDT_DATE_TIME:
		pRetData->m_date = *(DATE*)pData;//max (MIN_DATE, min (MAX_DATE, *(DATE*)pData));
		break;
	case SDT_SUB_PTR:
		pRetData->m_dwSubCodeAdr = *(LPDWORD)pData;
		break;
	case SDT_TEXT: {
		INT nEndPos = FindByte (pData, nDataSize, 0);
		pRetData->m_pText = CloneTextData ((char*)pData,
			(nEndPos != -1 ? nEndPos : nDataSize));
		
		break; }
	case SDT_BIN:
		pRetData->m_pBin = CloneBinData (pData, nDataSize);
		break;
//		DEFAULT_FAILD;
	}
}

LIBAPI(void, krnln_GetBinElement) // 直接修改eax,edx,ecx，所以不需要指定返回值类型
{
	PMDATA_INF pArgInf = &ArgInf;

	INT nType = pArgInf [1].m_int;
	if (nType < 1 || nType > 10)
		E_ReportError(100,0,0);

	//!!! 如果定义为返回 _SDT_ALL 数据类型数据，则必须设置
	// pRetData->m_dtDataType 为所返回数据的 DATA_TYPE 。
	MDATA_INF RetData;
	memset(&RetData,0,sizeof(MDATA_INF));
	RetData.m_dtDataType =
		nType == 1 ? SDT_BYTE :
	nType == 2 ? SDT_SHORT :
	nType == 3 ? SDT_INT :
	nType == 4 ? SDT_INT64 :
	nType == 5 ? SDT_FLOAT :
	nType == 6 ? SDT_DOUBLE :
	nType == 7 ? SDT_BOOL :
	nType == 8 ? SDT_DATE_TIME :
	nType == 9 ? SDT_SUB_PTR :
	SDT_TEXT;

	if(pArgInf [0].m_pBin==NULL) 
	{
		__asm{
			mov eax, RetData.m_unit.m_dwFormID;
			mov edx, RetData.m_unit.m_dwUnitID;
			mov ecx, RetData.m_dtDataType;
		}
		return;
	}


	LPBYTE pData = pArgInf [0].m_pBin + sizeof (INT) * 2;
	INT nDataSize = *(LPINT)(pData - sizeof (INT));
	

	INT nOffset;
	LPINT pOffset = NULL;
	if(pArgInf[2].m_dtDataType == _SDT_NULL)
		nOffset = 0;
	else
	{
		if(pArgInf[2].m_dtDataType == VAR_INT)//是变量
		{
			nOffset = *pArgInf[2].m_pInt - 1;
			pOffset = pArgInf[2].m_pInt;

		}
		else
			nOffset = pArgInf[2].m_int - 1;

	}



	INT nNeedSize = GetSysDataTypeDataSize (RetData.m_dtDataType);
	pData += nOffset;
	nDataSize -= nOffset;
	if(nOffset < 0 || nDataSize <=0)
	{
		if(pOffset)*pOffset = -1;
		goto end;
	}
	
	DWORD dwbuf [2];
	
	if (nType != 10 && nDataSize < nNeedSize)
	{
		ASSERT (nDataSize < sizeof (dwbuf));
		dwbuf [0] = dwbuf [1] = 0;
		memcpy (dwbuf, pData, nDataSize);
		pData = (LPBYTE)dwbuf;
		nDataSize = nNeedSize;
	}
	SetMDataValue (&RetData, pData, nDataSize);
	if(pOffset)
	{
		if(nType == 10){
			if(RetData.m_pText)
				*pOffset+=(mystrlen(RetData.m_pText)+1);
			else
				*pOffset+=1;//strlen取空文本指针NULL时会出错
		}else
			*pOffset+=nNeedSize;
		if(*pOffset > pArgInf [0].m_pInt[1])
			*pOffset = -1;//超出数据长度了
	}

end:
	__asm{
		mov eax, RetData.m_unit.m_dwFormID;
		mov edx, RetData.m_unit.m_dwUnitID;
		mov ecx, RetData.m_dtDataType;
	}
}
