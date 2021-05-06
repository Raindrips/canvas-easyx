#include "Draw.h"
#include <easyx.h>
#include <string>
#include <iostream>
#include <conio.h>
using namespace std;

Draw::Draw(int wid, int hei, Vec2r& level)
  :hei(hei), wid(wid)
{
  initgraph(wid, hei, SHOWCONSOLE);	  //初始化图形库,SHOWCONSOLE表示显示空制台
  int m = wid < hei ? wid : hei;
  size = m / level.size();	//动态计算小方块的宽度
  this->level = level;
}

Draw::~Draw()
{
  closegraph();
}

void Draw::update()
{
  draw();
  text();
}

int Draw::getSize()
{
  return size;
}

void Draw::draw()
{
  BeginBatchDraw();
  cleardevice();
  for (int i = 0; i < level.size(); i++)
  {
	for (int j = 0; j < level[i].size(); j++)
	{
	  if (level[i][j] == 0)		//路
	  {
		setfillcolor(RGB(0xee, 0xee, 0xee)); //设置路的颜色
	  }
	  else  if (level[i][j] == 1){  //墙
		setfillcolor(RGB(0x33, 0x66, 0xcc));
	  }
	  else  if (level[i][j] == 2) {	  //走过的路
		setfillcolor(RGB(0x33, 0xcc, 0x00));
	  }
	  else  if (level[i][j] == 3) {	  //终点
		setfillcolor(RGB(0xff, 0x33, 0x33));
	  }
	  rect(j, i);	//j代表x  i代表y
	}
  }
  EndBatchDraw();
}

void Draw::text()
{
  string m;
  for (int i = 0; i < level.size(); i++)
  {
	for (int j = 0; j < level[i].size(); j++)
	{
	  if (level[i][j] == 0)//路
	  {
		m += "  "; //设置路的颜色
	  }
	  else  if (level[i][j] == 1) {  //墙
		m += "+ ";
	  }
	  else  if (level[i][j] == 2) {	  //走过的路
		m += ". ";
	  }
	  else  if (level[i][j] == 3) {	  //终点
		m += "= ";
	  }
	}
	m += "\n";
  }
#ifdef __LINUX__
  clrscr();  	  //调用命令清屏  手机端使用
#endif
  system("cls");
  cout << m << endl;
  }

void Draw::rect(int x, int y) {
  fillrectangle(x*size, y*size, (x + 1)*size, (y + 1)*size);
}
