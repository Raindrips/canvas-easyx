#pragma once
#ifndef DFS_H
#define DFS_H

#include "FS.h"

//深度优先搜索
class DFS:public FS
{
private:
  //用递归的方式实现深度优先搜索
  void _search(Pos s);
protected:
 
  //判断这条路径是否是合法的
  //坐标是否越界
  //是否是已经走过的路了
  bool inArea(Pos s);	

  //判断这条路是否已经走过了
  bool isVisital(Pos s);
  
public:
  DFS(Pos start,Pos end);
  ~DFS();
  //实现一个外部接口,传入一个可以判断是否越界的函数
  void callBack(std::function<bool(int, int)> func);

  //开始搜索算法
  std::vector<Pos>& search();

  //获取终点
  Pos getEnd();
};

#endif	//DFS_H