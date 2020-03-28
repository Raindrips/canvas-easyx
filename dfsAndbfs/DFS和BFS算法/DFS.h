#pragma once
#ifndef DFS_H
#define DFS_H

#include "FS.h"

//�����������
class DFS:public FS
{
private:
  //�õݹ�ķ�ʽʵ�������������
  void _search(Pos s);
protected:
 
  //�ж�����·���Ƿ��ǺϷ���
  //�����Ƿ�Խ��
  //�Ƿ����Ѿ��߹���·��
  bool inArea(Pos s);	

  //�ж�����·�Ƿ��Ѿ��߹���
  bool isVisital(Pos s);
  
public:
  DFS(Pos start,Pos end);
  ~DFS();
  //ʵ��һ���ⲿ�ӿ�,����һ�������ж��Ƿ�Խ��ĺ���
  void callBack(std::function<bool(int, int)> func);

  //��ʼ�����㷨
  std::vector<Pos>& search();

  //��ȡ�յ�
  Pos getEnd();
};

#endif	//DFS_H