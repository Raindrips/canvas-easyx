#include "DFS.h"
#include <iostream>
#include <vector>
using namespace std;

void DFS::_search(Pos s)
{
  //static �������ֻ�ᱻ��ʼ��һ��,���Ҳ��ᱻ�����ͷŵ�
  //�������� �ĸ�����
  static Pos dir[4] = {
	{ 1, 0 },	  //
	{ 0, 1 },
	{ -1, 0 },
	{ 0, -1 },
  };
  //��ǰλ���Ƿ񵽴����յ�
  if (s.x == end.x&&s.y == end.y)
  {
	is_end = true;
	return;
  }
  for (int i = 0; i < 4; i++)
  {
	/*int dx = s.x + dir[i].x;
	int dy = s.y + dir[i].y;*/
	//׼���ƶ���·��
	Pos d(s.x + dir[i].x, s.y + dir[i].y);
	if (inArea(d)&&!is_end)
	{
	  //���·�ߺϷ�,�Ϳ�ʼ������·�ƶ�
	  path.push_back(d);
	  //�ݹ����
	  _search(d);
	}
  }
}

bool DFS::inArea(Pos s)
{
  //bool(func)	  �ж�����º��������Ƿ��Ѿ�ָ����һ������
  return bool(func) && func(s.x, s.y) && !isVisital(s);
}

bool DFS::isVisital(Pos s)
{
  for (auto &e:path)
  {
	//����·�߹���
	if (e.x==s.x&&e.y==s.y)
	{
	  return true;
	}
  }
  return false;
}

DFS::DFS(Pos start, Pos end) :FS(start, end)
{
  //���������Լ̳и��������
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
  is_end = false;		//�Ƿ񵽴��յ�ı���
  path.clear();			//���ԭ���߹���·��
  path.push_back(start);
  _search(start);		//��һ��,������ʼ����
  return path;
}

Pos DFS::getEnd()
{
  return end;
}
