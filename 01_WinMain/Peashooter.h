#pragma once
#include "Bullet.h"
class Peashooter : public Bullet
{
	class Image* mImage;
public :
	Peashooter(string name, float x, float y, float speed, float angle);
	void Init()override;
	void Release()override;
	void Update()override;
	void Render(HDC hdc)override;

	void InIntersectDamage()override;
};

