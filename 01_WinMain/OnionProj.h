#pragma once
#include "EnemyProj.h"

class OnionProj :public EnemyProj {
protected:
	int mIndex;
	Image* NonParryAbleAImg;
	Image* NonParryAbleBImg;
	Image* NonParryAbleCImg;
	Image* NonParryAbleDImg;
	Image* NonParryAbleEImg;
	Image* ParryAbleImg;

	Image* NonParryableASplashImg;

	Animation* NonParryAbleAAnimation;
	Animation* NonParryAbleBAnimation;
	Animation* NonParryAbleCAnimation;
	Animation* NonParryAbleDAnimation;
	Animation* NonParryAbleEAnimation;
	Animation* ParryAbleAnimation;

	Animation* NonParryableASplashAnimation;
public:
	OnionProj(const string& name, float x, float y, float speed, float angle, bool parryAble);
	virtual void Init()override;
	virtual void Release()override;
	virtual void Update()override;
	virtual void Render(HDC hdc)override;
};