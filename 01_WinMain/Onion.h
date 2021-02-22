#pragma once
#include "GameObject.h"
#include "Enemy.h"

class Onion : public Enemy {
	class Image* mDeathLeaveImage;
	class Image* mBashfulImage;
	class Image* mBashfulLeaveImage;
	class Image* mCryImage;

	class Image* mArmIntroImage;
	class Image* mArmIdleImage;
	class Image* mArmBashfulImage;

	class Image* mTearAImage;
	class Image* mTearBImage;

	class Animation* mDeathLeaveAnimation;
	class Animation* mArmBashfulAnimation;

	class Animation* mTearAAnimation;
	class Animation* mTearBAnimation;

	float mAttackStartDelay;
	int mAttackCount;
public:
	Onion(const string& name, float x, float y);

	void Init()override;
	void Release()override;
	void Update()override;
	void Render(HDC hdc)override;
};