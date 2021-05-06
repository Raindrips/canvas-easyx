#include "DFS.h"
#include <iostream>
#include <vector>
using namespace std;

void DFS::_search(Pos s)
{
  //static 保存变量只会被初始化一次,并且不会被马上释放掉
  //上下左右 四个方向
  static Pos dir[4] = {
	{ 1, 0 },	  //
	{ 0, 1 },
	{ -1, 0 },
	{ 0, -1 },
  };
  //当前位置是否到达了终点
  if (s.x == end.x&&s.y == end.y)
  {
	is_end = true;
	return;
  }
  for (int i = 0; i < 4; i++)
  {
	/*int dx = s.x + dir[i].x;
	int dy = s.y + dir[i].y;*/
	//准备移动的路线
	Pos d(s.x + dir[i].x, s.y + dir[i].y);
	if (inArea(d)&&!is_end)
	{
	  //如果路线合法,就开始向这条路移动
	  path.push_back(d);
	  //递归调用
	  _search(d);
	}
  }
}

bool DFS::inArea(Pos s)
{
  //bool(func)	  判断这个仿函数对象是否已经指向了一个函数
  return bool(func) && func(s.x, s.y) && !isVisital(s);
}

bool DFS::isVisital(Pos s)
{
  for (auto &e:path)
  {
	//这条路走过了
	if (e.x==s.x&&e.y==s.y)
	{
	  return true;
	}
  }
  return false;
}

DFS::DFS(Pos start, Pos end) :FS(start, end)
{
  //子类对象可以继承父类的属性
  cout << start.x << ":" << end.x << endl;
}


DFS::~DFS()
{
}

void DFS::callBack(std::function<bool(int, int)> func)
{
  this->func = func;
}

std::vector<Pos>& DFS::search()
{
  is_end = false;		//是否到达终点的变量
  path.clear();			//清除原来走过的路径
  path.push_back(start);
  _search(start);		//第一步,传入起始坐标
  return path;
}

Pos DFS::getEnd()
{
  return end;
}
