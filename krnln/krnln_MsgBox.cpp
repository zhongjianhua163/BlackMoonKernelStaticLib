#include "stdafx.h"
#include <stdio.h>
#include "LTrimZeroChr.h"

//#pragma comment(lib,"oleaut32.lib") 

//系统处理 - 信息框
/*
    调用格式： 〈整数型〉 信息框 （通用型 提示信息，整数型 按钮，［文本型 窗口标题］） - 系统核心支持库->系统处理
    英文名称：MsgBox
    在对话框中显示信息，等待用户单击按钮，并返回一个整数告诉用户单击哪一个按钮。该整数为以下常量值之一： 0、#确认钮； 1、#取消钮； 2、#放弃钮； 3、#重试钮； 4、#忽略钮； 5、#是钮； 6、#否钮。如果对话框有“取消”按钮，则按下 ESC 键与单击“取消”按钮的效果相同。本命令为初级命令。
    参数<1>的名称为“提示信息”，类型为“通用型（all）”。提示信息只能为文本、数值、逻辑值或日期时间。如果提示信息为文本且包含多行，可在各行之间用回车符 (即“字符 (13)”)、换行符 (即“字符 (10)”) 或回车换行符的组合 (即：“字符 (13) + 字符 (10)”) 来分隔。
    参数<2>的名称为“按钮”，类型为“整数型（int）”，初始值为“0”。参数值由以下几组常量值组成，在将这些常量值相加以生成参数值时，每组值只能取用一个数字（第五组除外）： 
  第一组（描述对话框中显示按钮的类型与数目）：
    0、#确认钮； 1、#确认取消钮； 2、#放弃重试忽略钮； 3、#取消是否钮；     4、#是否钮； 5、#重试取消钮
  第二组（描述图标的样式）：
    16、#错误图标； 32、#询问图标； 48、#警告图标； 64、#信息图标
  第三组（说明哪一个按钮是缺省默认值）：
    0、#默认按钮一； 256、#默认按钮二； 512、#默认按钮三； 768、#默认按钮四
  第四组（决定如何等待消息框结束）：
    0、#程序等待； 4096、#系统等待
  第五组（其它）：
    65536、#位于前台； 524288、#文本右对齐

    参数<3>的名称为“窗口标题”，类型为“文本型（text）”，可以被省略。参数值指定显示在对话框标题栏中的文本。如果省略，默认为文本“信息：”。
*/

LIBAPI(int, krnln_MsgBox)
{
	char str [MAX_PATH];
    HWND hWnd=NULL;
	LPCSTR lpText=NULL;
	LPCSTR lpCaption="信息";
    UINT uType=MB_OK;

	if((ArgInf.m_dtDataType & DT_IS_ARY) == 0)//非数组
	{
		
		
		switch(ArgInf.m_dtDataType)
		{
		case SDT_TEXT:
			lpText = ArgInf.m_pText;
			break;
		case SDT_BYTE:
			{
				INT nVal = ArgInf.m_byte;
				sprintf(str,"%d",nVal);
				lpText = str;
			}
			break;
		case SDT_SHORT:
			{
				INT nVal = ArgInf.m_short;
				sprintf(str,"%d",nVal);
				lpText = str;
			}
			break;
		case SDT_INT:
		case SDT_SUB_PTR:
			sprintf(str,"%d",ArgInf.m_int);
			lpText = str;
			break;
		case SDT_INT64:
			sprintf(str,"%I64d",ArgInf.m_int64);
			lpText = str;
			break;
		case SDT_FLOAT:
			sprintf(str,"%f",ArgInf.m_float);
			LTrimZeroChr(str);
			lpText = str;
			break;
		case SDT_DOUBLE:
			sprintf(str,"%.13g",ArgInf.m_double);
			LTrimZeroChr(str);
			lpText = str;
			break;
		case SDT_BOOL:
			if(ArgInf.m_bool)
				strcpy(str,"真");
			else
				strcpy(str,"假");
			lpText = str;
			break;

		case SDT_DATE_TIME:
			DateTimeFormat(str,ArgInf.m_double);
			lpText = str;
		}

	}
	PMDATA_INF pArgInf = &ArgInf;
	if(pArgInf[1].m_dtDataType!=_SDT_NULL)
	{
		uType=pArgInf[1].m_int;
	}
	if(pArgInf[2].m_dtDataType!=_SDT_NULL)
	{
		lpCaption=pArgInf[2].m_pText;
	}
	if(nArgCount>3)//易语言5.3新增加了"父窗口"参数
	{
		if(pArgInf[3].m_dtDataType==SDT_INT)
		{
			hWnd=(HWND)pArgInf[3].m_int;
		}
	}
	INT nRet = MessageBox(hWnd,lpText,lpCaption,uType);
	return (nRet-1);
}
