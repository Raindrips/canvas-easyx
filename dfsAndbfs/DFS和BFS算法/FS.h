#pragma once
#ifndef FS_H
#define FS_H

#include <vector>
#include <functional>

//������
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
  bool is_end;				//�ж��Ƿ񵽴����յ�
  std::vector<Pos> path;	//��ʾ�ߵ�·��
public:
  /*
	start ��ʼ����
	end	  �յ�����
  */
  FS(Pos start, Pos end);
  ~FS();

  virtual std::vector<Pos>& search()=0;

};
#endif
