#pragma once
#include "Bullet.h"
class Spread : public Bullet
{
private:
	class Image* mImage;
	float Range = 400.f;
	class Animation* mAnimation;
public:
	Spread(string name, float x, float y, float angle, int speed);
	void Init()override;
	void Release()override;
	void Update()override;
	void Render(HDC hdc)override;

	void InIntersectDamage(int damage = 0)override;
};

