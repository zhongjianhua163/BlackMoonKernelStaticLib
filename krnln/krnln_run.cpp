#include "stdafx.h"

//系统处理 - 运行
/*
    调用格式： 〈逻辑型〉 运行 （文本型 欲运行的命令行，逻辑型 是否等待程序运行完毕，［整数型 被运行程序窗口显示方式］） - 系统核心支持库->系统处理
    英文名称：run
    本命令运行指定的可执行文件或者外部命令。如果成功，返回真，否则返回假。本命令为初级命令。
    参数<1>的名称为“欲运行的命令行”，类型为“文本型（text）”。
    参数<2>的名称为“是否等待程序运行完毕”，类型为“逻辑型（bool）”，初始值为“假”。
    参数<3>的名称为“被运行程序窗口显示方式”，类型为“整数型（int）”，可以被省略。参数值可以为以下常量之一：
	1、#隐藏窗口； 2、#普通激活； 3、#最小化激活； 4、#最大化激活； 5、#普通不激活； 6、#最小化不激活。如果省略本参数，默认为“普通激活”方式。
*/
LIBAPI(BOOL, krnln_run)
{
	PMDATA_INF pArgInf = &ArgInf;

	STARTUPINFO startupinfo;
	PROCESS_INFORMATION pinfo;

	startupinfo.cb=sizeof(STARTUPINFO);
	GetStartupInfo(&startupinfo);
	startupinfo.hStdOutput=NULL;
	startupinfo.hStdError=NULL;
	startupinfo.dwFlags=STARTF_USESHOWWINDOW;

	if(pArgInf[2].m_dtDataType != _SDT_NULL)
	{

		switch(pArgInf[2].m_int)
		{
		case 1:
			startupinfo.wShowWindow=SW_HIDE;
			break;
		case 3:
			startupinfo.wShowWindow = SW_SHOWMINIMIZED;
			break;
		case 4:
			startupinfo.wShowWindow = SW_SHOWMAXIMIZED;
			break;	
		case 5:
			startupinfo.wShowWindow = SW_SHOWNOACTIVATE;
			break;	
		case 6:
			startupinfo.wShowWindow = SW_SHOWMINNOACTIVE;
			break;		
		default:
			startupinfo.wShowWindow = SW_SHOW;
			
		}
	}
	else
		startupinfo.wShowWindow = SW_SHOW;

	
	// Create process
	BOOL bRet = CreateProcess(NULL,pArgInf->m_pText,NULL,NULL,TRUE,NULL,NULL,NULL,&startupinfo,&pinfo);
	if(bRet)
	{
		if(pArgInf[1].m_bool)
			WaitForSingleObject(pinfo.hProcess, INFINITE);
		CloseHandle(pinfo.hProcess);
		CloseHandle(pinfo.hThread);
	}

	return bRet;
}
