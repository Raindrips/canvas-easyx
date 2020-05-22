#include "Vec2.h"
#include <math.h>
namespace danmaku {
	Vec2::Vec2(float x, float y)
		:x(x), y(y)
	{
	}

	float Vec2::angle()
	{
		return 0.0f;
	}

	float Vec2::length()
	{
		return sqrtf(x * x + y * y);
	}

	Bullet::Bullet(Vec2 p, float r, float angle)
		:p(p),r(r),angle(angle)
	{
	}

	void Bullet::setAngle(float angle)
	{
		this->angle = radin(angle);
	}

	void Bullet::setSpeed(float speed)
	{
		s.x = cos(angle) * speed;
		s.y = sin(angle) * speed;
	}

	void Bullet::update()
	{
		p.x += s.x;
		p.y += s.y;
	}

	float radin(float angle)
	{
		return PI/180*angle;
	}
}