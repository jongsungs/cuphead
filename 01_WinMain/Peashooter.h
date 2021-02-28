#pragma once
#include "Bullet.h"
class Peashooter : public Bullet
{
private:
	class Image* mImage;
	float Range = 500.f;
	class Animation* mAnimation;
public :
	Peashooter(string name, float x, float y,float angle);
	void Init()override;
	void Release()override;
	void Update()override;
	void Render(HDC hdc)override;

	void InIntersectDamage(int Damge = 0)override;
};

