#pragma once
#include "GameObject.h"
#include "Enemy.h"

class Potato : public Enemy {
	Image* IntroEarthImage;
	Image* IntroEarthImage1;
	Image* IntroEarthImage2;
	float mAttackStartDelay;
	int mAttackCount;
	float mDelayTime;
	Animation* mIntroEarthAnimation;
public:
	Potato(const string& name, float x, float y);

	void Init()override;
	void Release()override;
	void Update()override;
	void Render(HDC hdc)override;
};