#include "pch.h"
#include"Image.h"
#include "Bullet.h"

Bullet::Bullet(string name, float x, float y, float speed, float angle)
:GameObject(name){
	mX = x;
	mY = y;
	mSpeed = speed;
	mAngle = angle;
	mRect = RectMakeCenter(mX, mY, 20, 10); // 높이 너비 msize로 대체

	vector<GameObject*>* PlayerBullet = ObjectManager::GetInstance()->GetObjectListPt(ObjectLayer::Play_Bullet);
	mName = to_string(PlayerBullet->size());
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Play_Bullet, this);
}

void Bullet::Init()
{
	
}



void Bullet::Release()
{

}

void Bullet::Update()
{
	mX += cosf(mAngle) * mSpeed;
	mY += -sinf(mAngle) * mSpeed;
	mRect = RectMakeCenter(mX, mY, 20, 10);
}

void Bullet::Render(HDC hdc)
{
	RenderRect(hdc, mRect);
	
}
