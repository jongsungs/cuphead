#include "pch.h"
#include"Image.h"
#include "Bullet.h"

void Bullet::Init()
{
}

void Bullet::Init(float x, float y, float speed, float angle)
{
	
	mX = x;
	mY = y;
	mSpeed = speed;
	mAngle = angle;
	mRect = RectMakeCenter(mX, mY, 20, 10); // 높이 너비 msize로 대체

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
