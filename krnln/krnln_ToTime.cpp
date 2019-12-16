#include "stdafx.h"
#include "Myfunctions.h"
//时间操作 - 到时间
/*
    调用格式： 〈日期时间型〉 到时间 （通用型 欲转换的文本） - 系统核心支持库->时间操作
    英文名称：ToTime
    将指定文本转换为时间并返回。如果给定文本不符合书写格式要求或者时间值错误导致不能进行转换，将返回100年1月1日。如果给定参数本身就是时间数据，将直接返回该时间。本命令为初级命令。
    参数<1>的名称为“欲转换的文本”，类型为“通用型（all）”。文本内容应按以下格式之一提供，年份后的时间部分可以省略：
  1、1973年11月15日12时30分25秒
  2、1973/11/15 12:30:25
  3、1973/11/15/12/30/25
  4、1973/11/15/12:30:25
  5、1973-11-15-12-30-25
  6、1973-11-15-12:30:25
  7、1973.11.15 12:30:25
  8、19731115123025
*/
//1899年12月30日0时00分00秒 为0基准,单位为天数的小数值
BOOL StrToTime (double& dbDateTime,LPCSTR pStr)
{
	INT nLen = mystrlen(pStr);
	if(nLen < 8) return FALSE;

	char* pStrSrc = new char[nLen + 1];
	strcpy(pStrSrc,pStr);
	LPSTR sDtArry[6]={0};
	LPSTR pStart = pStrSrc;
	LPSTR pEnd = pStrSrc + nLen;
	INT nIDX = 0;
	LPSTR pTemp = pStart;
	BOOL spliteChn = FALSE;
	BOOL spliteEng = FALSE;
	INT spliteChr = 0;
	while(pStart < pEnd)
	{
		if(*pStart < 0)//汉字
		{
			if(spliteEng==FALSE && pStart > pStrSrc)//已经找到一些数字
			{
				if(strncmp(pStart,"年",2)==0)
				{
					if(nIDX !=0)//年不是按顺序出现
						break;
					*pStart = 0;
					pStart+=2;
					sDtArry[0] = pTemp;
					pTemp = pStart;
					nIDX++;//到月
					spliteChn = TRUE;
				}else if(strncmp(pStart,"月",2)==0)
				{
					if(nIDX !=1)//月不是按顺序出现
						break;
					*pStart = 0;
					pStart+=2;
					sDtArry[1] = pTemp;
					pTemp = pStart;
					nIDX++;//到日
				}else if(strncmp(pStart,"日",2)==0)
				{
					if(nIDX !=2)//日不是按顺序出现
						break;
					*pStart = 0;
					pStart+=2;
					sDtArry[2] = pTemp;
					pTemp = pStart;
					nIDX++;
				}else if(strncmp(pStart,"时",2)==0)
				{
					if(nIDX !=3)//日不是按顺序出现
						break;
					*pStart = 0;
					pStart+=2;
					sDtArry[3] = pTemp;
					pTemp = pStart;
					nIDX++;
				}else if(strncmp(pStart,"分",2)==0)
				{
					if(nIDX !=4)//日不是按顺序出现
						break;
					*pStart = 0;
					pStart+=2;
					sDtArry[4] = pTemp;
					pTemp = pStart;
					nIDX++;
				}else if(strncmp(pStart,"秒",2)==0)
				{
					if(nIDX !=5)//日不是按顺序出现
						break;
					*pStart = 0;
					pStart+=2;
					sDtArry[5] = pTemp;
					nIDX++;
				}else
					break;


			}
			else
				break;//非法汉字
		}
		else
		{
			if(48 <= *pStart && *pStart <= 57)//' 数字范围，48--57
			{
				pStart++;
				if(0 == *pStart)//到最后了
				{
					sDtArry[nIDX] = pTemp;
					nIDX++;
				}
			}
			else if(nIDX ==0 && spliteChr == 0)//确定英文分隔符
			{
				if(spliteChn)//已经是汉字格式了
					break;
				if(*pStart =='/' || *pStart =='-' || *pStart =='.')
				{
					spliteChr = *pStart;
					spliteEng = TRUE;
					*pStart = 0;
					pStart++;
					sDtArry[0] = pTemp;
					pTemp = pStart;
					nIDX++;



				}
				else
					break; //非合法分隔符

			}
			else if(nIDX ==3 && spliteChr == 0)//确定时间分隔符
			{
				if(spliteChn)//已经是汉字格式了
					break;
				if(*pStart =='/' || *pStart =='-' || *pStart ==':')
				{
					spliteChr = *pStart;
					*pStart = 0;
					pStart++;
					sDtArry[3] = pTemp;
					pTemp = pStart;
					nIDX++;

				}
				else
					break; //非合法分隔符
			}
			else if(nIDX ==2 && (*pStart==' ' || *pStart =='/' || *pStart =='-' || *pStart==0))//更换分隔符
			{
				*pStart = 0;
				pStart++;
				sDtArry[2] = pTemp;
				pTemp = pStart;
				nIDX++;
				spliteChr = 0;
			}
			else if(spliteChr == *pStart)//合法分隔符
			{
				*pStart = 0;
				pStart++;
				sDtArry[nIDX] = pTemp;
				pTemp = pStart;
				nIDX++;
			}else
				break; //非合法字符

		}

	}

	if(pStart >= pEnd)//全部扫描完毕才结束的,格式正确
	{
		if(nIDX==1)//全部数字串格式
		{
			delete [] pStrSrc;
			pStrSrc = new char[256];
			memset(pStrSrc,0,20);
			pStart = pStrSrc;
			INT nMax = 0;
			nIDX = 0;

			while(nMax < nLen)
			{
				if(nIDX==0)
				{
					strncpy(pStart,pStr,4);
					sDtArry[0] = pStart;
					pStart+=5;
					nIDX++;
					nMax +=4;
				}
				else
				{
					strncpy(pStart,pStr+nMax,2);
					sDtArry[nIDX] = pStart;
					pStart+=3;
					nIDX++;
					nMax +=2;
				}

			}


		}
		else if(nIDX < 2) //日期部分不全
		{
			delete [] pStrSrc;
			return FALSE;
		}
		INT nYear, nMonth, nDay, nHour, nMinute, nSecond;//检测时间是否正确
		nHour = nMinute = nSecond = 0;
		BOOL bError = FALSE;
		for(INT i=0; i < nIDX;i++)
		{
			INT nValue = atoi(sDtArry[i]);
			switch(i)
			{
			case 0://年
				
				if(nValue==0)
				{
					bError = TRUE;
					break;
				}
				nYear = nValue;
				break;
			case 1://月
				
				if(nValue < 1 || nValue > 12)
				{
					bError = TRUE;
					break;
				}
				nMonth = nValue;
				break;
			case 2://日
				{
					DWORD nMonDay [12] = {31,28,31,30,31,30,31,31,30,31,30,31};
					if((nYear % 400==0) || (nYear % 100 != 0) && (nYear %4 ==0))//闰年
						nMonDay [1] = 29; //二月				
					if(nValue < 1 || nValue > (INT)(nMonDay [nMonth-1]))
					{
						bError = TRUE;
						break;
					}
					nDay = nValue;
					break;
				}
			case 3://时
				
				if(nValue > 23)
				{
					bError = TRUE;
					break;
				}
				nHour = nValue;
				break;
			case 4://分
				
				if(nValue > 59)
				{
					bError = TRUE;
					break;
				}
				nMinute = nValue;
				break;
			case 5://秒
				
				if(nValue > 59)
				{
					bError = TRUE;
					break;
				}
				nSecond = nValue;
				break;
			}
		}
		delete [] pStrSrc;
		if(bError)
			return FALSE;

		dbDateTime = GetSpecDateTime(nYear, nMonth, nDay, nHour, nMinute, nSecond);//组合时间
		return TRUE;
	}

	delete [] pStrSrc;
	return FALSE;

}

LIBAPI(void, krnln_ToTime)
{

	switch(ArgInf.m_dtDataType)
	{
	case SDT_TEXT:
		{
			double dbDateTime;
			if(StrToTime(dbDateTime,ArgInf.m_pText)==FALSE)
				dbDateTime = -657434;//100年1月1日
			ArgInf.m_double = dbDateTime;
		}
		break;
	case SDT_DATE_TIME:
	case SDT_DOUBLE:
	case SDT_INT64:
		break;
	default:
		ArgInf.m_double = -657434;//100年1月1日
	}
	__asm{
		mov eax, ArgInf.m_unit.m_dwFormID;
		mov edx, ArgInf.m_unit.m_dwUnitID;
	}
}
