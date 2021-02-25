#include "pch.h"
#include"Image.h"
#include "Bullet.h"

Bullet::Bullet(string name, float x, float y, float angle)
:GameObject(name){
	mX = x;
	mY = y;
	mAngle = angle;
	mRect = RectMakeCenter(mX, mY, 20, 10); // 높이 너비 msize로 대체
}

void Bullet::Init()
{
	vector<GameObject*>* PlayerBullet = ObjectManager::GetInstance()->GetObjectListPt(ObjectLayer::Player_Bullet);
	mName = to_string(PlayerBullet->size());
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Player_Bullet, this);
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
