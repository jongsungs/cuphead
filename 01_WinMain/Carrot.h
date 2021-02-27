#pragma once
#include "GameObject.h"
#include "Enemy.h"

class Animation;

class Carrot : public Enemy {
	Image* mBeamImage;
	Image* mChangeToBeamImage;
	
	Animation* mChangeToBeamAnimation;
	Animation* mChangeFromBeamAnimation;
	Animation* mBeamAnimation;

	int count;
	float mProjAngle;

	float mAttackStartDelay;
	float mBetweenAttackDelay;
public:
	Carrot(const string& name, float x, float y);

	void Init()override;
	void Release()override;
	void Update()override;
	void Render(HDC hdc)override;

	void InIntersectDamage(int dmage = 0)override;
};