#include "Danmaku.h"
#include "easyx.h"
#include<ctime>
#include <thread>
using namespace std;

namespace danmaku {
	void Danmaku::flowering()
	{
		float v = 2.5;
		static float an=0;
		//获取中心点
		Vec2 center((float)wid / 2.0f, (float)hei / 2.0f);

		vector<Bullet> bt(30, Bullet(center, wid / 60));

		float step = 360.0f / bt.size();
		float i = an;
		an += 3.36;
		for (auto& e : bt) {
			e.setAngle(i);
			e.setSpeed(v);
			COLORREF color = RGB(rand() % 155 + 100, rand() % 155 + 100, rand() % 155 + 100);
			e.color = color;
			i += step;
		}
		bullets.push_back(bt);
	}
	void Danmaku::flowering2()
	{
		
		static int ro = 0;
		static float range = 1;
		static float ra = 0.8;

		//获取中心点
		Vec2 center(wid / 2, hei / 2);
		vector<Bullet> bt(60, Bullet(center, wid / 90));
		
		float step = 360.0f / bt.size();
		float i = 0;
		float v = 1.5;

		for (auto& e : bt) {
			e.setAngle(i+ro);
			e.setSpeed(v+range);
			range += ra;
			if (range>=3||range<=1)
			{
				ra = -ra;
			}
			COLORREF color = RGB(rand() % 155 + 100, rand() % 155 + 100, rand() % 155 + 100);
			e.color = color;
			i += step;
		}
		bullets.push_back(bt);
		ro += 20;
	}
	void Danmaku::flowering3()
	{
		static float rotate = 0;
		rotate += 6.36;
		//获取中心点
		Vec2 center(wid / 2, hei / 2);
		vector<Bullet> bt(12, Bullet(center, wid / 120));

		float step = 360.0f / bt.size();
		float i = rotate;
		float v = 4;

		for (auto& e : bt) {
			e.setAngle(i);
			e.setSpeed(v);

			COLORREF color = RGB(rand() % 155 + 100, rand() % 155 + 100, rand() % 155 + 100);
			e.color = color;
			i += step;
		}
		bullets.push_back(bt);
	}
	void Danmaku::flowering4()
	{
		static float rotate = 0;
		static float accept=0;	//加速度

		rotate += accept;
		accept += 0.36;
		//获取中心点
		Vec2 center(wid / 2, hei / 2);
		vector<Bullet> bt(12, Bullet(center, wid / 120));

		float step = 360.0f / bt.size();
		float i = rotate;
		float v = 3;

		for (auto& e : bt) {
			e.setAngle(i);
			e.setSpeed(v);

			COLORREF color = RGB(rand() % 155 + 100, rand() % 155 + 100, rand() % 155 + 100);
			e.color = color;
			i += step;
		}
		bullets.push_back(bt);
	}
	void Danmaku::update()
	{
		static unsigned long a = 0;		
		//每10帧调用一次
		if (a % 4 == 0)
		{
			//flowering();
			//flowering2();
			//flowering3();
			flowering4();
			//子弹4秒后开始子弹释放
			if (a > (60 * 4)) {
				bullets.pop_front();
			}
		}
		a++;
		a %= LLONG_MAX;
	}
	void Danmaku::draw()
	{
		BeginBatchDraw();
		cleardevice();
		for (auto& e2 : bullets) {
			for (auto& e : e2) {
				//设置填充颜色
			
				setfillcolor(e.color);
				//绘制圆
				solidcircle(e.p.x, e.p.y, e.r);
				//子弹更新
				e.update();
			}
		}
		EndBatchDraw();
	}
	Danmaku::Danmaku(int wid, int hei)
		:Draw(wid,hei)
	{
	}
	void Danmaku::start()
	{
		while (true)
		{
			draw();
			update();
			Sleep(1000.0 / 60);
		}
		
	}
}