#pragma once
#include "FS.h"
class BFS:public FS
{

private:
  //判断路径是否合法
  bool inArea(Pos p);
  //判断这条路是否已经走过了
  bool	isVisital(Pos s);
public:
  /*
	  start 开始位置
	  end   终点位置
  */
  BFS(Pos start,Pos end);
  ~BFS();

  //实现一个回调函数接口,传入一个可以判断是否越界的函数
  void callBack(std::function<bool(int, int)> func);

  //开始实现搜索算法
  std::vector<Pos>& search();

  //获取终点坐标
  Pos getEnd();
};

