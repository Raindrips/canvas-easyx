#pragma once
#include "draw.h"
#include <list>
#include <vector>
#include "Vec2.h"
//弹幕类
namespace danmaku {
	class Danmaku :public Draw {
	
		//存放所有子弹的容器
		std::list<std::vector<Bullet>> bullets;

		//第一种弹幕效果
		void flowering();
		//第二种弹幕效果
		void flowering2();
		//风车弹幕
		void flowering3();
		//波与粒的境界
		void flowering4();
		void update();
		void draw();

	public:
		Danmaku(int wid, int hei);
		void start();
	};
}