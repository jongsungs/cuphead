#include "pch.h"
#include "Spread.h"
#include "Camera.h"

Spread::Spread(string name, float x, float y, float angle) :Bullet(name, x,y,angle) {

}
void Spread::Init()
{
	mImage = ImageManager::GetInstance()->FindImage(L"Testbullet");
	vector<GameObject*>* PlayerBullet = ObjectManager::GetInstance()->GetObjectListPt(ObjectLayer::Player_Bullet);
	mName = "Peashooter";
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Player_Bullet, this);
}

void Spread::Release()
{
}

void Spread::Update()
{
	if (Range < 0) {
		mIsDestroy = true;
		return;
	}
	mX += mSpeed * cos(mAngle)*Time::GetInstance()->DeltaTime();
	mY -= mSpeed * sin(mAngle)*Time::GetInstance()->DeltaTime();
	mRect = RectMakeCenter(mX, mY, 20, 20);
	Range -= mSpeed * Time::GetInstance()->DeltaTime();;
}

void Spread::Render(HDC hdc)
{
	CameraManager::GetInstance()->GetMainCamera()->RenderRect(hdc, mRect);
	CameraManager::GetInstance()->GetMainCamera()->Render(hdc, mImage, mX, mY);
}

void Spread::InIntersectDamage()
{
	mIsDestroy = true;
}
