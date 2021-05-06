#pragma once
#include "draw.h"
#include <list>
#include <vector>
#include "Vec2.h"
//��Ļ��
namespace danmaku {
	class Danmaku :public Draw {
	
		//��������ӵ�������
		std::list<std::vector<Bullet>> bullets;

		//��һ�ֵ�ĻЧ��
		void flowering();
		//�ڶ��ֵ�ĻЧ��
		void flowering2();
		//�糵��Ļ
		void flowering3();
		//�������ľ���
		void flowering4();
		void update();
		void draw();

	public:
		Danmaku(int wid, int hei);
		void start();
	};
}