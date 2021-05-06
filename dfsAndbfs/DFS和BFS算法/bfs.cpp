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
  //bool(func)	  �ж�����º��������Ƿ��Ѿ�ָ����һ������
  return bool(func) && func(s.x, s.y) && !isVisital(s);
}

bool BFS::isVisital(Pos s)
{
  for (auto &e : path)
  {
	//����·�߹���
	if (e.x == s.x&&e.y == s.y)
	{
	  return true;
	}
  }
  return false;
}

std::vector<Pos>& BFS::search()
{
  //���֮ǰ���ƶ�����·��
  path.clear();
  //���������ĸ�����
  static Pos dir[4] = {
	{ 1, 0 },	  
	{ 0, 1 },
	{ -1, 0 },
	{ 0, -1 },
  };
  queue<Pos> que;		  //����һ������
  que.push(start);		  //����ʼ�������

  //��ʼѰ·
  while (!que.empty())	  //�������Ϊ�վͱ�ʾû�п����ߵ�·��
  {
	auto s = que.front(); //��ȡ��ͷԪ��
	que.pop();			  //��ͷ����
	path.push_back(s);	  //�߹���·��

	for (int i = 0; i < 4;i++)
	{
	  //׼���ƶ�������λ��
	  Pos d(s.x + dir[i].x, s.y + dir[i].y);
	  //�ж�����·�Ƿ�Ϸ�
	  if (inArea(d))
	  {
		path.push_back(d);	  //��¼ÿһ���߹���·
		que.push(d);		  //·�����
		//��ǰλ���Ƿ񵽴����յ�
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
