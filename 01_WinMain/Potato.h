#pragma once
#include "GameObject.h"
#include "Enemy.h"

class Potato : public Enemy {
	float mAttackStartDelay;
	int mAttackCount;
	float mDelayTime;
public:
	Potato(const string& name, float x, float y);

	void Init()override;
	void Release()override;
	void Update()override;
	void Render(HDC hdc)override;
};