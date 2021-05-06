#pragma once
#ifndef DRAW_H
#define DRAW_H

#include <vector>

//给类模板取别名
using Vec2r = std::vector<std::vector<int>>;

//绘制地图的类
class Draw
{
public:
  /*
	@wid  图像的宽度
	@hei  图像的高度
	@level 二维数组,存储的地图
   */
  Draw(int wid,int hei, Vec2r& level);
  ~Draw();

  //绘制的地图
  //0 表示路
  //1 表示墙
  //2 表示走过的路
  //3 表示终点
  Vec2r level;   

  //地图更新函数,会刷新地图的绘制
  void update();
private:

  int wid, hei;			//宽度和高度
  int size;				//每个单元的大小
  void draw();
  void text();
  void rect(int x,int y);

};

#endif // !DRAW_H