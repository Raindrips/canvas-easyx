#pragma once

namespace danmaku {
	const float PI = 3.14159;	

	//弧度转角度
	float radin(float angle);

	//二维坐标
	class Vec2 {
	public:
		float x;
		float y;
		Vec2(float x=0,float y=0);

		//获取角度
		float angle();

		//获取长度
		float length();
	};

	//子弹类
	class Bullet {
		

	public:
		Vec2 p;			//坐标位置
		Vec2 s;			//速度
		float angle;	//角度
		float r;		//子弹半径
		unsigned color; //子弹颜色 

		Bullet(Vec2 p, float r, float angle = 0);

		//设置角度
		void setAngle(float angle);

		//设置速度
		void setSpeed(float speed);

		//子弹移动
		void update();

	};
}