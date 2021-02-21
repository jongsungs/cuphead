#pragma once
#include"GameObject.h"
class Bullet : public GameObject
{
	float mSpeed;
	float mAngle;
	class Animation* RightBullet;
	class Animation* LeftBullet;
	class Animation* UpBullet;

public:
	void Init()override;
	void Init(float x, float y, float speed, float angle);
	void Release()override;
	void Update()override;
	void Render(HDC hdc)override;
};