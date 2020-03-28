#pragma once
#include "FS.h"
class BFS:public FS
{

private:
  //�ж�·���Ƿ�Ϸ�
  bool inArea(Pos p);
  //�ж�����·�Ƿ��Ѿ��߹���
  bool	isVisital(Pos s);
public:
  /*
	  start ��ʼλ��
	  end   �յ�λ��
  */
  BFS(Pos start,Pos end);
  ~BFS();

  //ʵ��һ���ص������ӿ�,����һ�������ж��Ƿ�Խ��ĺ���
  void callBack(std::function<bool(int, int)> func);

  //��ʼʵ�������㷨
  std::vector<Pos>& search();

  //��ȡ�յ�����
  Pos getEnd();
};

