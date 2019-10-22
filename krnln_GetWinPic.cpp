#include "stdafx.h"
#pragma comment(lib,"gdi32.lib")
#include <stdio.h>
//系统处理 - 快照
/*
    调用格式： 〈字节集〉 快照 （［整数型 窗口句柄］，［整数型 输出宽度］，［整数型 输出高度］） - 系统核心支持库->系统处理
    英文名称：GetWinPic
    捕获指定窗口或屏幕上所有现有显示内容，返回相应图片数据。如果失败，返回空字节集。本命令为高级命令。
    参数<1>的名称为“窗口句柄”，类型为“整数型（int）”，可以被省略。指定欲捕获其显示内容的窗口。如果被省略，默认为捕获屏幕显示内容。
    参数<2>的名称为“输出宽度”，类型为“整数型（int）”，可以被省略。指定图片的输出宽度。如果小于0，参数值指定的是最终图片输出宽度相对于所取得图片宽度的百分比（最小为10%）；如果等于0，则按图片原宽度输出；如果大于0，指定输出图片的绝对宽度。如果本参数被省略，默认值为0。
    参数<3>的名称为“输出高度”，类型为“整数型（int）”，可以被省略。指定图片的输出高度。如果小于0，参数值指定的是最终图片输出高度相对于所取得图片高度的百分比（最小为10%）；如果等于0，则按图片原高度输出；如果大于0，指定输出图片的绝对高度。如果本参数被省略，默认值为0。
*/
LIBAPI(void*, krnln_GetWinPic)
{
	PMDATA_INF pArgInf = &ArgInf;
	HWND hWnd = (HWND)pArgInf[0].m_pCompoundData;
	HDC hdc = GetDC(hWnd);
	if(hdc==NULL)
		return NULL;
	RECT rect;

	HWND HObjWnd = hWnd;
	if(HObjWnd==NULL)
		HObjWnd = GetDesktopWindow();
	if(GetWindowRect(HObjWnd,&rect)==FALSE)
	{
		ReleaseDC(hWnd,hdc);
		return NULL;
	}

	SIZE sz; 
	sz.cx=rect.right-rect.left; 
	sz.cy=rect.bottom-rect.top; 
	int nWidth, nHeight;
	nWidth = sz.cx;
	nHeight = sz.cy;
	if(pArgInf[1].m_dtDataType != _SDT_NULL)
	{
		if(pArgInf[1].m_int > 0)
			nWidth = pArgInf[1].m_int;
		else if(pArgInf[1].m_int < 0)
		{
			if(pArgInf[1].m_int<-10)
				pArgInf[1].m_int=-10;
			nWidth = (sz.cx * -1* pArgInf[1].m_int)/100;
		}
	}
	if(pArgInf[2].m_dtDataType != _SDT_NULL)
	{
		if(pArgInf[2].m_int > 0)
			nHeight = pArgInf[2].m_int;
		else if(pArgInf[2].m_int < 0)
		{
			if(pArgInf[2].m_int<-10)
				pArgInf[2].m_int=-10;
			nHeight = (sz.cy * -1* pArgInf[2].m_int)/100;
		}
	}
	HDC hMemDC = CreateCompatibleDC(hdc);
	HBITMAP   hBitmap,hOldBitmap;   
	hBitmap = CreateCompatibleBitmap(hdc, nWidth, nHeight);
	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hBitmap);
	//StretchBlt(hMemDC, 0, 0, nWidth, nHeight,hdc, rect.left, rect.top,rect.right,rect.bottom, SRCCOPY);
	SetStretchBltMode(hMemDC, HALFTONE);//防止缩放时失真
	StretchBlt(hMemDC, 0, 0, nWidth, nHeight,hdc, -8, 0, sz.cx, sz.cy, SRCCOPY);

	BITMAP bmp; 
	::GetObject(hBitmap, sizeof(BITMAP), &bmp);
	//申请内存保存位图数据 

	DWORD dwSize = sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER) + bmp.bmWidthBytes * bmp.bmHeight;
	LPBYTE pData = (LPBYTE)E_MAlloc(dwSize+2* sizeof(INT));
	LPBYTE pArry =pData;
	*(LPINT)pArry=1;
	pArry+=sizeof(INT);
	*(LPINT)pArry=dwSize;
	pArry+=sizeof(INT);

	LPBITMAPFILEHEADER pBfh = (LPBITMAPFILEHEADER)pArry;//位图文件头 
	memset(pBfh,0,sizeof(BITMAPFILEHEADER));
	pBfh->bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);//到位图数据的偏移量 
	pBfh->bfSize = pBfh->bfOffBits + bmp.bmWidthBytes * bmp.bmHeight;//文件总的大小 
	pBfh->bfType = (WORD)0x4d42; 

	pArry+=sizeof(BITMAPFILEHEADER);

	LPBITMAPINFOHEADER pBih = (LPBITMAPINFOHEADER)pArry;//位图信息头 
	memset(pBih,0,sizeof(BITMAPINFOHEADER));
	pBih->biSize = sizeof(BITMAPINFOHEADER); 
	pBih->biWidth = bmp.bmWidth;//宽度 
	pBih->biHeight = bmp.bmHeight;//高度 
	pBih->biPlanes = 1;
	pBih->biBitCount = bmp.bmBitsPixel;//每个像素字节大小 
	pBih->biCompression = BI_RGB; 
	pBih->biSizeImage = bmp.bmWidthBytes * bmp.bmHeight;//图像数据大小 
	pBih->biXPelsPerMeter = 0;
	pBih->biYPelsPerMeter = 0;
	pBih->biClrUsed = 0;
	pBih->biClrImportant = 0;
	pArry+=sizeof(BITMAPINFOHEADER);

	GetDIBits(hMemDC, hBitmap, 0, nHeight, pArry, 
	(LPBITMAPINFO)pBih, DIB_RGB_COLORS);//获取位图数据 
	

	SelectObject(hMemDC, hOldBitmap);
	DeleteDC(hMemDC);
	ReleaseDC(hWnd,hdc);
	DeleteObject(hBitmap);
	return pData;

}
