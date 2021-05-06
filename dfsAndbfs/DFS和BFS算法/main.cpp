//�����㷨 DFS��BFS
#include "DFS.h"
#include "bfs.h"
#include "Draw.h"

#include <iostream>
#include <vector>


#include <windows.h>

using namespace std;

//vector<vector<int>> level = {
//  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
//  { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
//  { 1, 1, 1, 0, 0, 1, 1, 1, 0, 1 },
//  { 1, 0, 0, 1, 0, 1, 0, 1, 0, 1 },
//  { 1, 1, 0, 1, 0, 1, 0, 1, 0, 1 },
//  { 1, 0, 0, 0, 0, 1, 0, 1, 0, 1 },
//  { 1, 0, 1, 1, 0, 1, 0, 0, 0, 1 },
//  { 1, 0, 1, 1, 0, 1, 0, 1, 0, 1 },
//  { 1, 0, 0, 1, 0, 0, 0, 1, 0, 1 },
//  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
//};
vector<vector<int>> level = {
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
  { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
  { 1, 1, 1, 0, 0, 1, 1, 1, 0, 1 },
  { 1, 0, 0, 1, 0, 1, 0, 1, 0, 1 },
  { 1, 1, 0, 1, 0, 1, 0, 1, 0, 1 },
  { 1, 0, 0, 0, 0, 1, 0, 1, 0, 1 },
  { 1, 0, 1, 1, 0, 1, 0, 0, 0, 1 },
  { 1, 0, 1, 1, 0, 1, 0, 1, 0, 1 },
  { 1, 0, 0, 1, 0, 0, 0, 1, 0, 1 },
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
};

//�Ƿ�Խ��,�Ƿ�����ǽ��
bool isOut(int x, int y){
  if (y>=level.size()||y<0||x>=level[y].size()||x<0
	||level[y][x]==1)
  {
	return false;
  }
  return true;
}

void test_dfs(){
  DFS dfs(Pos(1, 1), Pos(1, 8));
  dfs.callBack(isOut);	  //���뺯����ַ ,ע�ⲻҪд����

  //���Ƶ�ͼ����
  Draw draw(300,300,level);
  auto end = dfs.getEnd();
  draw.level[end.y][end.x]=3;
  draw.update();
  auto vec = dfs.search();
  for (auto e : vec)
  {
	draw.level[e.y][e.x] = 2;	//��ʾ�߹���·
	draw.update();
	Sleep(300);
  }
  system("pause");
}

void test_bfs(){
  BFS bfs(Pos(1, 1), Pos(1, 8));
  bfs.callBack(isOut);	  //���뺯����ַ ,ע�ⲻҪд����

  //���Ƶ�ͼ����
  Draw draw(600, 600, level);
  auto end = bfs.getEnd();
  draw.level[end.y][end.x] = 3;
  draw.update();
  auto vec = bfs.search();
  for (auto e : vec)
  {
	draw.level[e.y][e.x] = 2;	//��ʾ�߹���·
	draw.update();
	Sleep(300);
  }
  system("pause");
}

int main()
{
  //test_dfs();
  test_bfs();
  return 0;
}
