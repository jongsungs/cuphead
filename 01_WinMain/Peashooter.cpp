#include "pch.h"
#include "Peashooter.h"
#include "Image.h"
#include "Camera.h"
Peashooter::Peashooter(string name, float x, float y, float angle) 
:Bullet(name, x, y,angle)
{
	mHP = 1; // 총알 대미지
	mImage = ImageManager::GetInstance()->FindImage(L"Testbullet");
	mSpeed = 10.f;
}
void Peashooter::Init() {
	//vector<GameObject*>* PlayerBullet = ObjectManager::GetInstance()->GetObjectListPt(ObjectLayer::Player_Bullet);
	mName = "Peashooter";
	//ObjectManager::GetInstance()->AddObject(ObjectLayer::Player_Bullet, this);
};
void Peashooter::Release() {
	
}

void Peashooter::Update() {
	if (Range < 0) {
		mIsDestroy = true;
		return;
	}
	mX += mSpeed * cos(mAngle);
	mY -= mSpeed * sin(mAngle);
	mRect = RectMakeCenter(mX,mY,21,21);
	Range -= mSpeed;
}
void Peashooter::Render(HDC hdc) {
	CameraManager::GetInstance()->GetMainCamera()->RenderRect(hdc, mRect);
	CameraManager::GetInstance()->GetMainCamera()->Render(hdc, mImage,mX, mY);
	//CameraManager::GetInstance()->GetMainCamera()->RenderRect(hdc, mRect);
	//CameraManager::GetInstance()->GetMainCamera()->Render(hdc,mImage,mX,mY);
}

void Peashooter::InIntersectDamage(int dmage = 0) { //삭제 처리
	mIsDestroy = true;
}