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
	Bullet(string name, float x, float y, float speed, float angle);
	void Init()override;
	void Release()override;
	void Update()override;
	void Render(HDC hdc)override;
};