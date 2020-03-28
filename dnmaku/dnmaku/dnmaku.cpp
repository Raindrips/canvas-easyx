// dnmaku.cpp 
#include "stdafx.h"
#include <easyx.h>
#include <cmath>
#include <ctime>
#include <climits>

#include <iostream>
#include <deque>
#include <vector>

namespace M{
  //������
  class Vec2{
  public:
	float x;
	float y;
	Vec2(float x = 0, float y = 0) :x(x), y(y){}
  };
  static double const PI = 3.1415926;		//PI��ֵ

  //�Ƕ�ת����
  float radin(float angle){
	return angle*PI / 180.0;
  }
}
using namespace M;
using namespace std;

//�ӵ���
class Bullet{
protected:
  float angle;		//�Ƕ�
public:
  Vec2 p;			//����λ��
  Vec2 s;			//�ٶ�

  int r;			//�ӵ��뾶
  COLORREF color;	//��ɫ
  Bullet(Vec2 p, int r = 0, float angle = 0)
	:p(p), r(r), angle(angle){}

  //���ýǶ�
  void setAngle(float angle){
	if (angle > 360){
	  angle = (int)angle % 360;
	}
	else if (angle < 0){
	  angle = 360 + (int)angle % 360;
	}
	//cout << angle << endl;
	this->angle = angle;
  }
  //��ȡ�Ƕ�
  float getAngle(){
	return angle;
  }

  //�����ٶ�
  void setSpeed(float speed){
	s.x = cos(radin(angle))*speed;
	s.y = sin(radin(angle))*speed;
  }
  //�ƶ��ӵ�
  void update(){
	p.x += s.x;
	p.y += s.y;
  }
};


//��Ļ��
class Danmaku{
  int wid = 600;						//��Ļ���
  float speed = 6;				//�ӵ��ٶ�
  float count = 0;
  float accept = 0.2;
  bool flag = true;
  IMAGE img;
  IMAGE xxy;
  deque<vector<Bullet>> bullets;	//����ӵ�������

  //��һ�ֵ�Ļ
  void _flowering(){
	Vec2 center(wid / 2, wid / 2);		//��ȡ���ĵ�
	//25 ÿȦ�ӵ��Ĵ�С		
	vector<Bullet> bt(30, Bullet(center, wid / 90));

	float step = 360.0 / bt.size();
	float i = count;
	if (flag)
	{
	  count += accept;
	  accept += 0.25;
	}
	else{
	  count -= accept;
	  accept -= 0.25;
	}

	for (auto &e : bt)
	{
	  e.setAngle(i);

	  e.setSpeed(speed);
	  e.color = RGB(rand() % 200 + 55, rand() % 200 + 55, rand() % 200 + 55);
	  i += step;
	}
	bullets.push_back(bt);
  }

  //�ڶ��ֵ�Ļ
  float range = 1;
  float ra = 0.8;
  void _flowering2(){
	Vec2 center(wid / 2, wid / 2);		//��ȡ���ĵ�
	//25 ÿȦ�ӵ��Ĵ�С		
	vector<Bullet> bt(60, Bullet(center, wid / 90));

	float step = 360.0 / bt.size();
	float i = 0;

	for (auto &e : bt)
	{
	  e.setAngle(i);
	  e.setSpeed(range);
	  range += ra;
	  if (range >= 4 || range <= 1)
		ra = -ra;
	  e.color = RGB(rand() % 200 + 55, rand() % 200 + 55, rand() % 200 + 55);
	  i += step;
	}
	bullets.push_back(bt);
  }

  //�����ֵ�Ļ
  void _flowering3(){
	Vec2 center(wid / 2, wid / 2);		//��ȡ���ĵ�
	//ÿȦ���ӵ�����  ÿȦ�ӵ��Ĵ�С		
	vector<Bullet> bt(12, Bullet(center, wid / 120));

	float step = 360.0 / bt.size();
	float i = count;

	//����ƫ�ƽǵļ��ٶ�
	count -= accept;
	accept -= 0.24;
	for (auto &e : bt)
	{
	  e.setAngle(i);
	  e.setSpeed(speed);
	  e.color = RGB(rand() % 200 + 55, rand() % 200 + 55, rand() % 200 + 55);
	  i += step;
	}
	bullets.push_back(bt);
  }

  //���ƽ���
  void _draw(){
	BeginBatchDraw();
	cleardevice();
	for (auto &e2 : bullets)
	{
	  for (auto &e : e2)
	  {
		//�����ӵ���ɫ
		setfillcolor(e.color);
		//�����ɫ
		solidcircle(e.p.x, e.p.y, e.r);
		//���ͼ��
		//putimage(e.p.x, e.p.y, &img);
		//�ӵ�����
		e.update();
	  }
	}
	EndBatchDraw();
  }

  unsigned long long a = 0;
public:
  Danmaku(){
	initgraph(wid, wid,SHOWCONSOLE);
	srand(time(nullptr));
	loadimage(&img, _T("XXY.png"), wid / 20,wid/20);
  }

  //��ʼִ��
  void start(){
	while (true)
	{
	  _draw();
	  //20֡����һ��
	  if (a % 2 == 0)
	  {
		//_flowering();
		//_flowering2();
		_flowering3();
		if (a > (60 * 4))
		{
		  bullets.pop_front();
		}
	  }
	  if (a % (60 * 4))
	  {
		flag = !flag;
	  }
	  a++;
	  a %= LLONG_MAX;
	  Sleep((int)(1000.0 / 60));
	}
  }
};

int main()
{
  cout << sizeof(IMAGE) << endl;
  Danmaku d;
  d.start();
  return 0;
}