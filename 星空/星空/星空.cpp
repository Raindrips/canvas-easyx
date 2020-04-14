// �ǿ�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<easyx.h>
#include<iostream>
#include<vector>
#include<string>
const int wid = GetSystemMetrics(SM_CXSCREEN);
const int hei = GetSystemMetrics(SM_CYSCREEN);

struct Star
{
	float x;
	float y;
	float speed;
	COLORREF color;

	Star()
	{
		x = rand()%wid;
		y = rand() % hei;
		speed = rand() % 5 + 1;
		color = RGB(rand() % 255 + 55, rand() % 255 + 55, rand() % 255 + 55);
	}
};
void init()
{
	//��������
	HWND hwnd = initgraph(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));
	//���ô��ڷ��
	SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) - WS_CAPTION);
	//���ô���λ��
	SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), SWP_SHOWWINDOW);
	//���ô��ڷ��
	long WindowLong = GetWindowLong(hwnd, GWL_EXSTYLE) | WS_EX_LAYERED;
	SetWindowLong(hwnd, GWL_EXSTYLE, WindowLong);
	//�޸ı���Ϊ��ɫ
	SetLayeredWindowAttributes(hwnd, RGB(0, 0, 0), 0, LWA_COLORKEY);

	//initgraph(wid, hei,SHOWCONSOLE);
	BeginBatchDraw();
}

class StarMove
{
	void Draw()
	{
		cleardevice();
			for (const auto &star : star)
			{
				setfillcolor(star.color);
				solidcircle(star.x, star.y,rand()%6+1);
			}
	}
	
	void upData()
	{
		for (auto &star : star)
		{
			star.x += star.speed;
			if (star.x > wid)
			{
				star.x -= wid;
			}
		}
		Sleep(10);
	}
	int num;
	std::vector<Star> star;
public:
	StarMove(int num) :num(num)
	{
		this->star.resize(num);
		
	}
	void Begin()
	{
		init();
		while (1)
		{
			BeginBatchDraw();
			Draw();
			upData();
			EndBatchDraw();
		}

	}
};


int _tmain(int argc, _TCHAR* argv[])
{

	StarMove Sm(200);
	Sm.Begin();
	
	
	closegraph();
	return 0;
}

