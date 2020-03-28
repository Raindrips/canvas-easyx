#pragma once
#ifndef FS_H
#define FS_H

#include <vector>
#include <functional>

//坐标类
class Pos{
public:
  int x;
  int y;
  Pos(int x = 0, int y = 0) :x(x), y(y){}
};

class FS
{
protected:
  Pos start;
  Pos end;
  std::function<bool(int, int)> func;
  bool is_end;				//判断是否到达了终点
  std::vector<Pos> path;	//表示走的路径
public:
  /*
	start 起始坐标
	end	  终点坐标
  */
  FS(Pos start, Pos end);
  ~FS();

  virtual std::vector<Pos>& search()=0;

};
#endif
