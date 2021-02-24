#pragma once
#include "GameObject.h"

class Animation;
class EnemyProj : public GameObject {
protected:
	float mSpeed;
	float mAngle;
	bool mParryAble;

	Image* mImage;
	Animation* mCurrentAnimation;

public:
	EnemyProj(string name, float x, float y, float speed, float angle, bool parryAble);

	void virtual Init()override;
	void virtual Release()override;
	void virtual Update()override;
	void virtual Render(HDC hdc)override;

	bool GetParryAble() const { return mParryAble; }
};