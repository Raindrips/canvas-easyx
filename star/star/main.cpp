// star.cpp : 定义控制台应用程序的入口点。
#include "easyx.h"		//需要下载安装图形库
#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

int hei = 480;	//图像的高度
int wid = 640;	//图像的宽度

//星星类
class Star{
public:
  float x;			  //x坐标
  float y;			  //y坐标
  float speed;		  //速度
  COLORREF color;	  //颜色
  float size;		  //星星大小

  //构造
  Star(){
	x = rand() % wid;		  //x坐标不能超过屏幕宽度
	y = rand() % hei;		  //x坐标不能超过屏幕高度
	speed = (rand() % 5000)/1000.0 + 1;	  //1.0~5.0
	color = RGB(
	  rand() % 200 + 55,	  //red   红 
	  rand() % 200 + 55,	  //green 绿
	  rand() % 200 + 55       //bule  蓝
	);
	size = 6-speed;
  }
};

//控制星星移动
class MoveStart{

  //绘制函数
  void draw(){
	BeginBatchDraw();	  //开始批量绘制
	cleardevice();		//清除画布
	for (const auto &e:stars)
	{
	  setfillcolor(e.color);	//设置要绘制的颜色
	  solidcircle(e.x,e.y,e.size);			//绘制无填充的实心圆
	}
	EndBatchDraw();		//结束批量绘制
  }
  void update(){
	while (true)
	{
	  for (auto &e : stars)
	  {
		e.x += e.speed;	  //星星不断的向右移动
		if (e.x>wid)
		  e.x -= wid;
		if (e.x < 0)
		  e.x += wid;
	  }
	  draw();
	  Sleep((int)(1000.0 / 60));	  //60fps
	}
  }
public:
  vector<Star> stars;
  MoveStart(int nums){
	initgraph(wid, hei);
	srand(time(nullptr));
	stars.resize(nums);		//星星的数量
	for (int i = stars.size() / 2; i < stars.size();i++)
	{
	  stars[i].speed = -stars[i].speed;
	}
  }
  ~MoveStart(){
	closegraph();
  }

  //运行程序
  void run(){
	update();
  }
};

int main()
{
  MoveStart ms(300);
  ms.run();
  return 0;
}
