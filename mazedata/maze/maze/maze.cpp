// mazedata.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <ctime>
#include "easyx.h"
#include "Position.h"
#include "RandomQueue.h"
using namespace std;

class Maze {
private:
  double px;
  int len;
  vector<vector<int>> v;
  vector<vector<bool>> visited;
  vector<vector<int>> d = { {1,0},{-1,0},{0,-1}, {0,1} };
  vector<vector<int>> play;
  vector<vector<bool>> isVisited;

  void drawRect(int x, int y) {
	solidrectangle(x * px, y * px, x * px + px, y * px + px);
  }
  int entranceX = 1;  //起始坐标
  int entranceY = 0;
  int exitX = len - 1;//结束坐标
  int exitY = len - 2;
  double size = 101;

public:
  Maze(double len) {
	initgraph(len, len, SHOWCONSOLE);
	v = vector<vector<int>>(size, vector<int>(size, 0));
	visited = vector<vector<bool>>(size, vector<bool>(size, false));
	isVisited = visited;
	play = v;
	px = len / size;
	this->len = len;
  }

  void initMap() {
	for (size_t i = 0; i < v.size(); i++)
	{
	  for (size_t j = 0; j < v.size(); j++)
	  {
		if (i % 2 == 1 && j % 2 == 1)
		{
		  v[i][j] = 1;
		}
		else {
		  v[i][j] = 0;
		}
		visited[i][j] = false;
	  }
	}
	entranceX = 1;
	entranceY = 0;
	exitX = size - 2;
	exitY = size - 1;
	v[entranceX][entranceY] = 1;
	v[exitX][exitY] = 1;
  }

  boolean inArea(int x, int y) {
	return x >= 0 && x < size && y >= 0 && y < size;
  }

  //绘制地图
  void drawMap() {
	cleardevice();
	for (size_t i = 0; i < v.size(); i++)
	{
	  for (size_t j = 0; j < v.size(); j++)
	  {
		if (v[i][j] == 1)
		{
		  setfillcolor(0xcccccc);
		  drawRect(i, j);
		}
		if (play[i][j] == 1)
		{
		  setfillcolor(0x226644);
		  drawRect(i, j);
		}
	  }
	}
  }

  void setData(int x, int y) {
	if (inArea(x, y))
	  v[x][y] = 1;
  }
  //递归
  void goMap(int x, int y) {
	if (!inArea(x, y))
	  throw exception("x,y are out of index in go function!");
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
	  int newX = x + d[i][0] * 2;
	  int newY = y + d[i][1] * 2;
	  if (inArea(newX, newY) && !visited[newX][newY]) {
		setData(x + d[i][0], y + d[i][1]);
		goMap(newX, newY);
	  }
	}
  }

  //非递归
  void randGoMap() {
	RandomQueue<Position> s;
	Position first(entranceX, entranceY + 1);
	s.push_back(first);
	while (!s.empty()) {
	  Position curPos = s.pop_back();

	  visited[first.getX()][first.getY()] = true;
	  for (int i = 0; i < 4; i++) {
		int newX = curPos.getX() + d[i][0] * 2;
		int newY = curPos.getY() + d[i][1] * 2;
		if (inArea(newX, newY) && !visited[newX][newY] && v[newX][newY] == 1) {
		  s.push_back(Position(newX, newY));
		  visited[newX][newY] = true;
		  setData(curPos.getX() + d[i][0], curPos.getY() + d[i][1]);
		}
	  }
	}
  }

  stack<Position> godir;
  int playX = 1, playY = 0;  //人物初始位置

  //寻找出口
  void goMap() {
	if (godir.empty())
	{
	  godir.push(Position(playX, playY));
	}
	Position p = godir.top();
	godir.pop();
	play[p.getX()][p.getY()] = 1;
	for (int i = 0; i < 4; i++)
	{
	  int newX = p.getX() + d[i][0];
	  int newY = p.getY() + d[i][1];
	  if (newX >= 0 && newX < size && newY >= 0 && newY < size &&
		!isVisited[newX][newY] && v[newX][newY] == 1 && play[newX][newY] == 0)
	  {
		godir.push(Position(newX, newY));
	  }

	}

  }

  void run() {
	initMap();
	setData(-1, -1);
	randGoMap();
	while (true)
	{
	  goMap();
	  BeginBatchDraw();
	  drawMap();
	  Sleep(10);
	  EndBatchDraw();
	}
	setData(-1, -1);
  }
  ~Maze() {
	closegraph();
  }
};

int main() {
  Maze* m = new Maze(606);
  m->run();
  delete m;

}
