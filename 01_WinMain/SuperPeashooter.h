#pragma once
#include "Bullet.h"
class SuperPeashooter : public Bullet
{
private:
	class Image* mImage;
	float Range = 1000.f;
	class Animation* mAnimation;
public:
	SuperPeashooter(string name, float x, float y, float angle);
	void Init()override;
	void Release()override;
	void Update()override;
	void Render(HDC hdc)override;

	void InIntersectDamage(int Damge = 0)override;
};

