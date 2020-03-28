// 雪花图案.cpp
#include <easyx.h>
#include <stdio.h>
#include <stdlib.h>


int wid = 600;		//图形窗口的大小

/*
 * x,y 圆的坐标
 * r 圆的半径
 * step 圆往下面绘制的距离
 * depth 每次递归的数据
 */
void drawCircle(int x, int y, int r, int step, int depth)
{
	if (r < 1)
	{
		return;
	}
	if (depth % 3 == 1)
	{
		setlinecolor(0xff3333); //蓝色
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
	int y = wid / 2;  //计算圆的中心点
	circle(x, y, wid / 2);
	drawCircle(x, y, wid / 2, 3, 1);
}

/*绘制雪花
 *
 */
void drawSnow(int x, int y, float w, float h, int depth,int step)
{
	if (w <= 1 || depth >= step)	//递归一定要有结束条件
	{
		setfillcolor(RGB(0x33,0xcc,0xff));
		setlinecolor(RGB(0x00, 0xff, 0xff));
		fillrectangle(x, y, x + max(w, 1), y + max(h, 1));
		return;
	}
	float p = w / 3;   //计算正方形/3之后的距离

	drawSnow(x + p, y, p, p, depth + 1,step);		//x+p  表示 上面那个方块的一个距离	
	drawSnow(x, y + p, p, p, depth + 1, step);		//y+p  表示左边那个方块位置
	drawSnow(x + p, y + p, p, p, depth + 1, step);	//x+p y+p 表示中间那一个方块
	drawSnow(x + p * 2, y + p, p, p, depth + 1, step);//x+p*2   表示右边的那个方块
	drawSnow(x + p, y + p * 2, p, p, depth + 1, step);//y+p*2		表示下面那个方块
	
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

