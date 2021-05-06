#include <iostream>
#include "AStar.h"
#include "Draw.h"
#include <easyx.h>

using namespace std;
using namespace CPP37;


vector<vector<int>> level_map = {
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1 },
	{ 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1 },
	{ 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1 },
	{ 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1 },
	{ 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1 },
	{ 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1 },
	{ 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1 },
	{ 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
};

bool inArea(int x, int y){
	if (y<0 || y>=level_map.size() || x<0 || x>=level_map[y].size()
		|| level_map[y][x] == 1)
	{
		return false;
	}
	return true;
} 

void test1(){
	AStar as(inArea);

	Pos start = { 1, 1 };
	Pos end = { 15,15};
	cin >> start.x >> start.y >> end.x >> end.y;

	vector<Pos> path;
	bool isFind = as.findPath(start, end, path);
	if (!isFind)
	{
		cout << "没有找到路径" << endl;
		return;
	}

	for (int i = 0; i < path.size(); i++)
	{
		cout << path[i].x << ":" << path[i].y << endl;
	}
}

void test2(){
	AStar as(inArea);
	Draw d(600,600,level_map);

	Pos start = { 1, 1 };
	Pos end = { 14, 14};

	vector<Pos> path;
	bool isFind = as.findPath(start, end, path);
	d.level[end.y][end.x] = 3;
	d.update();
	if (!isFind)
	{
		cout << "没有找到路径" << endl;
		return;
	}
	for (auto e:path)
	{
		d.level[e.y][e.x] = 2;
		d.update();
	}
	system("pause");
}

void test3(){
  AStar astar(inArea);
  vector<Pos> path;		

  Pos start(-1,-1);	  //起点
  Pos end(-1,-1);		  //终点

  Draw d(600,600,level_map);
  d.update();
  while (true)
  {
	bool flag=true;
	int x, y;
	d.level = level_map;
	while (true)
	{
	  MOUSEMSG msg = GetMouseMsg();	  //获取鼠标信息
	  x = msg.x / d.getSize();  //转换坐标系
	  y = msg.y / d.getSize();  //鼠标坐标信息转换为数组坐标
	  //cout << x << ":" << y << endl;
	  if (msg.uMsg == WM_RBUTTONDOWN)
	  {
		level_map[y][x] = d.level[y][x] =
		  d.level[y][x] == Draw::wall ? Draw::road : Draw::wall;
		
		d.update();
	  }
	  if (msg.uMsg == WM_LBUTTONDOWN)
	  {
		if (flag && d.level[y][x] == Draw::road)	  //第一次点击
		{
		  start.x = x;
		  start.y = y;
		  d.level[y][x] = Draw::visited;
		  d.update();
		  flag = false;
		}
		else if (d.level[y][x] == Draw::road)
		{
		  end.x = x;
		  end.y = y;
		  d.level[y][x] = Draw::end;
		  d.update();
		  flag = true;
		  break;
		}
	  }
	}

	bool r = astar.findPath(start, end, path);
	for (auto e : path)
	{
	  d.level[e.y][e.x] = Draw::visited;
	  d.update();
	  Sleep(1000.0 / 60);
	}
  }
  system("pause");
}

int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}