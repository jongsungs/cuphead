#pragma once
#include "GameObject.h"
#include "Enemy.h"
class Image;
class Animation;
class Onion : public Enemy {
	Image* mDeathLeaveImage;
	Image* mBashfulImage;
	Image* mBashfulLeaveImage;
	Image* mCryImage;

	Image* mArmIntroImage;
	Image* mArmIdleImage;
	Image* mArmBashfulImage;

	Image* mTearAImage;
	Image* mTearBImage;

	Animation* mDeathLeaveAnimation;
	Animation* mArmBashfulAnimation;

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