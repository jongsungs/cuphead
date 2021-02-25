#pragma once
#include "Bullet.h"
class Spread : public Bullet
{
private:
	class Image* mImage;
	float Range = 100.f;
public:
	Spread(string name, float x, float y, float angle);
	void Init()override;
	void Release()override;
	void Update()override;
	void Render(HDC hdc)override;

	void InIntersectDamage()override;
};

