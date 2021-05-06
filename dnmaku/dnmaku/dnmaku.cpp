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
  //坐标类
  class Vec2{
  public:
	float x;
	float y;
	Vec2(float x = 0, float y = 0) :x(x), y(y){}
  };
  static double const PI = 3.1415926;		//PI的值

  //角度转弧度
  float radin(float angle){
	return angle*PI / 180.0;
  }
}
using namespace M;
using namespace std;

//子弹类
class Bullet{
protected:
  float angle;		//角度
public:
  Vec2 p;			//坐标位置
  Vec2 s;			//速度

  int r;			//子弹半径
  COLORREF color;	//颜色
  Bullet(Vec2 p, int r = 0, float angle = 0)
	:p(p), r(r), angle(angle){}

  //设置角度
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
  //获取角度
  float getAngle(){
	return angle;
  }

  //设置速度
  void setSpeed(float speed){
	s.x = cos(radin(angle))*speed;
	s.y = sin(radin(angle))*speed;
  }
  //移动子弹
  void update(){
	p.x += s.x;
	p.y += s.y;
  }
};


//弹幕类
class Danmaku{
  int wid = 600;						//屏幕宽度
  float speed = 6;				//子弹速度
  float count = 0;
  float accept = 0.2;
  bool flag = true;
  IMAGE img;
  IMAGE xxy;
  deque<vector<Bullet>> bullets;	//存放子弹的容器

  //第一种弹幕
  void _flowering(){
	Vec2 center(wid / 2, wid / 2);		//获取中心点
	//25 每圈子弹的大小		
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

  //第二种弹幕
  float range = 1;
  float ra = 0.8;
  void _flowering2(){
	Vec2 center(wid / 2, wid / 2);		//获取中心点
	//25 每圈子弹的大小		
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

  //第三种弹幕
  void _flowering3(){
	Vec2 center(wid / 2, wid / 2);		//获取中心点
	//每圈的子弹数量  每圈子弹的大小		
	vector<Bullet> bt(12, Bullet(center, wid / 120));

	float step = 360.0 / bt.size();
	float i = count;

	//设置偏移角的加速度
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

  //绘制界面
  void _draw(){
	BeginBatchDraw();
	cleardevice();
	for (auto &e2 : bullets)
	{
	  for (auto &e : e2)
	  {
		//设置子弹颜色
		setfillcolor(e.color);
		//填充颜色
		//solidcircle(e.p.x, e.p.y, e.r);
		//填充图案
		putimage(e.p.x, e.p.y, &img);
		//子弹更新
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

  //开始执行
  void start(){
	while (true)
	{
	  _draw();
	  //20帧调用一次
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