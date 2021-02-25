#pragma once
#include"GameObject.h"
class Bullet : public GameObject
{
protected:
	float mSpeed;
	float mAngle;
	float mDistance; //발사거리
	class Animation* RightBullet;
	class Animation* LeftBullet;
	class Animation* UpBullet;

public:
	Bullet(string name, float x, float y, float angle);
	void virtual Init()override;
	void virtual Release()override;
	void virtual Update()override;
	void virtual Render(HDC hdc)override;
};