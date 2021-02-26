#pragma once
#include "EnemyProj.h"

class CarrotProj:public EnemyProj{
protected:
	Image* CarrotMissileImage;
	Image* CarrotBeamImage;

	int mWeaponType;

	Animation* CarrotMissileAnimation;
	Animation* CarrotBeamAnimation;
public:
	CarrotProj(const string& name, float x, float y, float speed, float angle, int weapontype);
	virtual void Init()override;
	virtual void Release()override;
	virtual void Update()override;
	virtual void Render(HDC hdc)override;
};