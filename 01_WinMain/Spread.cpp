#include "pch.h"
#include "Spread.h"
#include "Camera.h"

Spread::Spread(string name, float x, float y, float speed, float angle) {

}
void Spread::Init()
{
	mImage;
	vector<GameObject*>* PlayerBullet = ObjectManager::GetInstance()->GetObjectListPt(ObjectLayer::Player_Bullet);
	mName = "Peashooter";
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Player_Bullet, this);
}

void Spread::Release()
{
}

void Spread::Update()
{
	mX += mSpeed * cos(mAngle)*Time::GetInstance()->DeltaTime();
	mY -= mSpeed * sin(mAngle)*Time::GetInstance()->DeltaTime();
	mRect = RectMakeCenter(mX, mY, 20, 20);
}

void Spread::Render(HDC hdc)
{
	CameraManager::GetInstance()->GetMainCamera()->RenderRect(hdc, mRect);
}

void Spread::InIntersectDamage()
{
	mIsDestroy = true;
}
