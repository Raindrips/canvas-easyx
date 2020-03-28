#include <stdio.h>
#include <easyx.h>  //ͼ�ο�  (��������)
#include <math.h>	//��ѧ��
#include <stdlib.h>
#include <time.h>

//�ӵ�
struct Bullet{
	double x, y;
	double sx, sy;
	double angle;
	int wid;
	COLORREF color;
};
const double PI = 3.1415926;

double speed = 2;  //�����ٶ�

//����ת�Ƕ�
double angle(double rad){
	return rad*(PI / 180);
}

const int N = 30;
Bullet bt[N];
int wid = 640, hei = 480;

//�����ٶȺͷ���
void setSpeed(Bullet *b, double s)
{
	b->sx = cos(angle(b->angle))*s;
	b->sy = sin(angle(b->angle))*s;
}

void SubPoint(Bullet *b, Bullet *b2)
{
	//�����ľ��빫ʽ
	if (sqrt(pow(b->x - b2->x, 2) + pow(b->y - b2->y, 2)) < 10)
	{

		b->sx = -b->sx;
		b->sy = -b->sy;
		b2->sx = -b2->sx;
		b2->sy = -b2->sy;
	}
}

//�ƶ��߼�
void speedRun(Bullet *b)
{
	//�ƶ�λ��
	b->x += b->sx;
	b->y += b->sy;
	
	//����ǽ�ڷ�������
	if (b->x > wid)
		b->sx = -b->sx;
	if (b->y > hei)
		b->sy = -b->sy;
	if (b->x < 0)
		b->sx = -b->sx;
	if (b->y < 0)
		b->sy = -b->sy;

}

//��ʼ��
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
		setSpeed(&bt[i], speed); //�̶��ٶ�
		//setSpeed(&bt[i], rand()%3+1);
		bt[i].color = RGB(rand() % 200 + 55, rand() % 200 + 55, rand() % 200 + 55);
		//
		bt->wid = 10;
	}
	//setfillcolor(RGB(0xff, 0xcc, 0x99));
}

//����
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

//��ʼ����
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

