#include <stdio.h>
#include <easyx.h>  //图形库  (第三方库)
#include <math.h>	//数学库
#include <stdlib.h>
#include <time.h>

//子弹
struct Bullet{
	double x, y;
	double sx, sy;
	double angle;
	int wid;
	COLORREF color;
};
const double PI = 3.1415926;

double speed = 2;  //设置速度

//弧度转角度
double angle(double rad){
	return rad*(PI / 180);
}

const int N = 30;
Bullet bt[N];
int wid = 640, hei = 480;

//设置速度和方向
void setSpeed(Bullet *b, double s)
{
	b->sx = cos(angle(b->angle))*s;
	b->sy = sin(angle(b->angle))*s;
}

void SubPoint(Bullet *b, Bullet *b2)
{
	//点与点的距离公式
	if (sqrt(pow(b->x - b2->x, 2) + pow(b->y - b2->y, 2)) < 10)
	{

		b->sx = -b->sx;
		b->sy = -b->sy;
		b2->sx = -b2->sx;
		b2->sy = -b2->sy;
	}
}

//移动逻辑
void speedRun(Bullet *b)
{
	//移动位置
	b->x += b->sx;
	b->y += b->sy;
	
	//碰到墙壁反弹回来
	if (b->x > wid)
		b->sx = -b->sx;
	if (b->y > hei)
		b->sy = -b->sy;
	if (b->x < 0)
		b->sx = -b->sx;
	if (b->y < 0)
		b->sy = -b->sy;

}

//初始化
void init()
{
	initgraph(wid, hei);
	srand((unsigned)time(NULL));
	for (int i = 0; i < N; i++)
	{
		bt[i].x = wid / 2;
		bt[i].y = hei / 2;
		bt[i].angle = 360.0 / N *i;
		if (bt[i].angle > 360.0)
		{
			bt[i].angle - 360.0;
		}
		setSpeed(&bt[i], speed); //固定速度
		//setSpeed(&bt[i], rand()%3+1);
		bt[i].color = RGB(rand() % 200 + 55, rand() % 200 + 55, rand() % 200 + 55);
		//
		bt->wid = 10;
	}
	//setfillcolor(RGB(0xff, 0xcc, 0x99));
}

//绘制
void draw()
{
	BeginBatchDraw();
	cleardevice();
	for (int i = 0; i < N; i++)
	{
		setfillcolor(bt[i].color);
		solidcircle(bt[i].x, bt[i].y, 10);
	}
	EndBatchDraw();
}

//开始运行
void start()
{
	init();
	while (true)
	{
		draw();
		for (int i = 0; i < N; i++)
		{
			speedRun(&bt[i]);
		}
		Sleep(10);
	}
}

int main(){
	start();
	return 0;
}

