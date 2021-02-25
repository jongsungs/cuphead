#pragma once
#include "EnemyProj.h"

class CarrotProj:public EnemyProj{
protected:
	Image* CarrotMissile;
	Image* CarrotBeam;

	Animation* CarrotMissileAnimation;
	Animation* CarrotBeamAnimation;
public:
	virtual void Init()override;
	virtual void Release()override;
	virtual void Update()override;
	virtual void Render(HDC hdc)override;
};