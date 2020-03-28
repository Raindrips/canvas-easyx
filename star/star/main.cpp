// star.cpp : �������̨Ӧ�ó������ڵ㡣
#include "easyx.h"		//��Ҫ���ذ�װͼ�ο�
#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

int hei = 480;	//ͼ��ĸ߶�
int wid = 640;	//ͼ��Ŀ��

//������
class Star{
public:
  float x;			  //x����
  float y;			  //y����
  float speed;		  //�ٶ�
  COLORREF color;	  //��ɫ
  float size;		  //���Ǵ�С

  //����
  Star(){
	x = rand() % wid;		  //x���겻�ܳ�����Ļ���
	y = rand() % hei;		  //x���겻�ܳ�����Ļ�߶�
	speed = (rand() % 5000)/1000.0 + 1;	  //1.0~5.0
	color = RGB(
	  rand() % 200 + 55,	  //red   �� 
	  rand() % 200 + 55,	  //green ��
	  rand() % 200 + 55       //bule  ��
	);
	size = 6-speed;
  }
};

//���������ƶ�
class MoveStart{

  //���ƺ���
  void draw(){
	BeginBatchDraw();	  //��ʼ��������
	cleardevice();		//�������
	for (const auto &e:stars)
	{
	  setfillcolor(e.color);	//����Ҫ���Ƶ���ɫ
	  solidcircle(e.x,e.y,e.size);			//����������ʵ��Բ
	}
	EndBatchDraw();		//������������
  }
  void update(){
	while (true)
	{
	  for (auto &e : stars)
	  {
		e.x += e.speed;	  //���ǲ��ϵ������ƶ�
		if (e.x>wid)
		  e.x -= wid;
		if (e.x < 0)
		  e.x += wid;
	  }
	  draw();
	  Sleep((int)(1000.0 / 60));	  //60fps
	}
  }
public:
  vector<Star> stars;
  MoveStart(int nums){
	initgraph(wid, hei);
	srand(time(nullptr));
	stars.resize(nums);		//���ǵ�����
	for (int i = stars.size() / 2; i < stars.size();i++)
	{
	  stars[i].speed = -stars[i].speed;
	}
  }
  ~MoveStart(){
	closegraph();
  }

  //���г���
  void run(){
	update();
  }
};

int main()
{
  MoveStart ms(300);
  ms.run();
  return 0;
}
