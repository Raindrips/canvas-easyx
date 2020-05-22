#include <easyx.h>
#include <stdio.h>
#include <stdlib.h>

int wid = 600;		//图像大小

/*
 * x,y 圆
 * r 圆半径
 */
void drawCircle(int x, int y, int r, int step, int depth)
{
	if (r < 1)
	{
		return;
	}
	if (depth % 3 == 1)
	{
		setlinecolor(0xff3333); //颜色
	}
	else if (depth % 3 == 2)
	{
		setlinecolor(0x3333ff);
	}
	else
	{
		setlinecolor(0x33ff33);
	}
	circle(x, y, r);
	drawCircle(x, y, r - step, step, depth + 1);
}

void test1()
{
	initgraph(wid, wid);
	int x = wid / 2;
	int y = wid / 2;  
	circle(x, y, wid / 2);
	drawCircle(x, y, wid / 2, 3, 1);
}


void drawSnow(int x, int y, float w, float h, int depth,int step)
{
	if (w <= 1 || depth >= step)	
	{
		setfillcolor(RGB(0x33,0xcc,0xff));
		setlinecolor(RGB(0x00, 0xff, 0xff));
		fillrectangle(x, y, x + max(w, 1), y + max(h, 1));
		return;
	}
	float p = w / 3;  

	drawSnow(x + p, y, p, p, depth + 1,step);	
	drawSnow(x, y + p, p, p, depth + 1, step);
	drawSnow(x + p, y + p, p, p, depth + 1, step);	
	drawSnow(x + p * 2, y + p, p, p, depth + 1, step);
	drawSnow(x + p, y + p * 2, p, p, depth + 1, step);
	
}

void vicsek()
{
	initgraph(wid, wid);
	int step = 0;
	while (step<7)
	{
		BeginBatchDraw();
		//setbkcolor(WHITE);
		cleardevice();
		drawSnow(0, 0, wid, wid, 0,step);
		step++;
		EndBatchDraw();
		system("pause");
	}
	
}

int main()
{
	//test1();
	vicsek();
	system("pause");
	closegraph();
	return 0;
}

