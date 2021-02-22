#pragma once
#include "GameObject.h"
#include "Enemy.h"

class Carrot : public Enemy {
	float mAttackStartDelay;
	int mAttackCount;

	class Animation* mInitAttackAnimation;
public:
	Carrot(const string& name, float x, float y);

	void Init()override;
	void Release()override;
	void Update()override;
	void Render(HDC hdc)override;
};