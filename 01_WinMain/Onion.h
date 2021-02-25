#pragma once
#include "GameObject.h"
#include "Enemy.h"
class Image;
class Animation;
class Onion : public Enemy {
	Image* mDeathLeaveImage;
	Image* mChangeToAttackImage;
	Image* mBeforeAttackImage;
	
	Image* mTearEffectImage;
	Image* mTearAImage;
	Image* mTearBImage;

	Animation* mDeathLeaveAnimation;
	Animation* mBeforeAttackAnimation;
	Animation* mChangeToAttackAnimation;
	Animation* mChangeFromAttackAnimation;

	Animation* mTearEffectLoopAnimation;
	
	Animation* mTearEffectAnimation;
	Animation* mTearAAnimation;
	Animation* mTearBAnimation;

	float mAttackStartDelay;
	int mAttackCount;
public:
	Onion(const string& name, float x, float y);

	void Init()override;
	void Release()override;
	void Update()override;
	void Render(HDC hdc)override;
};