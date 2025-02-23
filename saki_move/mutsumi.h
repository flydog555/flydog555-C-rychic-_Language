#pragma once
#ifndef MUTSUMI_H
#define MUTSUMI_H  

#include<stdio.h>
#include<time.h>
#include<easyx.h>
#include<graphics.h>
#include <conio.h>
#include<mmsystem.h>
#include<windows.h> 
#pragma comment( lib, "MSIMG32.LIB")
#pragma comment(lib,"winmm.lib")  

void transparentimage3(IMAGE* dstimg, int x, int y, IMAGE* srcimg)
{
	HDC dstDC = GetImageHDC(dstimg);
	HDC srcDC = GetImageHDC(srcimg);
	int w = srcimg->getwidth();
	int h = srcimg->getheight();
	BLENDFUNCTION bf = { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA };
	AlphaBlend(dstDC, x, y, w, h, srcDC, 0, 0, w, h, bf);
}

void move(const char x[10])
{
	initgraph(1280, 720);

	time_t start_time = time(NULL);
	IMAGE saki;
	IMAGE mutsumi;
	IMAGE talk;
	IMAGE bg;
	while (difftime(time(NULL), start_time) < 1)
	{
		BeginBatchDraw();
		//setbkcolor(WHITE);
		//cleardevice();
		loadimage(&bg, _T("./bg.png"), 1280, 720);
		loadimage(&saki, _T("./saki.png"), 380, 572);
		loadimage(&mutsumi, _T("./mutsumi.png"), 380, 572);
		loadimage(&talk, _T("./talk.png"), 158, 91);
		transparentimage3(NULL, 0, 0, &bg);
		transparentimage3(NULL, 380, 100, &saki);
		transparentimage3(NULL, 0, 100, &mutsumi);
		transparentimage3(NULL, 280, 100, &talk);
		EndBatchDraw();
	}
	Sleep(10);
	for (int i = 0; i < 1000; i++)
	{
		BeginBatchDraw();
		//setbkcolor(WHITE);
		//cleardevice();
		transparentimage3(NULL, 0, 0, &bg); 
		transparentimage3(NULL, 380+i, 100, &saki);
		transparentimage3(NULL, 0 , 100, &mutsumi);
		Sleep(1);
		
		EndBatchDraw();
	}

	getchar();
	closegraph;
}



#endif