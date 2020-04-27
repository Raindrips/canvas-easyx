#pragma once

namespace danmaku {
	const float PI = 3.14159;	

	//����ת�Ƕ�
	float radin(float angle);

	//��ά����
	class Vec2 {
	public:
		float x;
		float y;
		Vec2(float x=0,float y=0);

		//��ȡ�Ƕ�
		float angle();

		//��ȡ����
		float length();
	};

	//�ӵ���
	class Bullet {
		

	public:
		Vec2 p;			//����λ��
		Vec2 s;			//�ٶ�
		float angle;	//�Ƕ�
		float r;		//�ӵ��뾶
		unsigned color; //�ӵ���ɫ 

		Bullet(Vec2 p, float r, float angle = 0);

		//���ýǶ�
		void setAngle(float angle);

		//�����ٶ�
		void setSpeed(float speed);

		//�ӵ��ƶ�
		void update();

	};
}