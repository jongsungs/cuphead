#pragma once
#include "GameObject.h"
#include "Enemy.h"

class Potato : public Enemy {
	float mAttackStartDelay;
	float mDelayTime;

	int mAttackCount;

	bool mIsAttack;

	int randomspit;
	int randomworm;
public:
	Potato(const string& name, float x, float y);

	void Init()override;
	void Release()override;
	void Update()override;
	void Render(HDC hdc)override;

	void InIntersectDamage(int dmage = 0)override;
};