#include "bfs.h"

#include <queue>

using namespace std;

BFS::BFS(Pos start, Pos end) :FS(start, end){}

BFS::~BFS()
{
}

void BFS::callBack(std::function<bool(int, int)> func)
{
  this->func = func;
}

bool BFS::inArea(Pos s)
{
  //bool(func)	  判断这个仿函数对象是否已经指向了一个函数
  return bool(func) && func(s.x, s.y) && !isVisital(s);
}

bool BFS::isVisital(Pos s)
{
  for (auto &e : path)
  {
	//这条路走过了
	if (e.x == s.x&&e.y == s.y)
	{
	  return true;
	}
  }
  return false;
}

std::vector<Pos>& BFS::search()
{
  //清除之前的移动过的路径
  path.clear();
  //上下左右四个方向
  static Pos dir[4] = {
	{ 1, 0 },	  
	{ 0, 1 },
	{ -1, 0 },
	{ 0, -1 },
  };
  queue<Pos> que;		  //创建一个队列
  que.push(start);		  //将起始坐标入队

  //开始寻路
  while (!que.empty())	  //如果队列为空就表示没有可以走的路了
  {
	auto s = que.front(); //获取队头元素
	que.pop();			  //队头出队
	path.push_back(s);	  //走过的路径

	for (int i = 0; i < 4;i++)
	{
	  //准备移动的坐标位置
	  Pos d(s.x + dir[i].x, s.y + dir[i].y);
	  //判断这条路是否合法
	  if (inArea(d))
	  {
		path.push_back(d);	  //记录每一次走过的路
		que.push(d);		  //路径入队
		//当前位置是否到达了终点
		if (d.x == end.x&&d.y == end.y)
		{
		  return path;
		}
	  }
	}	
  } 
  return path;
}

Pos BFS::getEnd()
{
  return end;
}
