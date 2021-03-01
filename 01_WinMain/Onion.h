#pragma once
#include "GameObject.h"
#include "Enemy.h"
class Image;
class Animation;
class Onion : public Enemy {
	Image* mChangeToAttackImage;
	Image* mBeforeAttackImage;
	
	Image* mTearEffectImage;

	Animation* mBeforeAttackAnimation;
	Animation* mChangeToAttackAnimation;
	Animation* mChangeFromAttackAnimation;
	
	int mProjInitX;

	Animation* mTearEffectAnimation;

	float mBetweenAttackDelay;
public:
	Onion(const string& name, float x, float y);

	void Init()override;
	void Release()override;
	void Update()override;
	void Render(HDC hdc)override;

	void InIntersectDamage(int dmage = 0)override;
};