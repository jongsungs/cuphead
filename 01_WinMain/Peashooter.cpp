#include "pch.h"
#include "Peashooter.h"
#include "Image.h"
#include "Camera.h"
Peashooter::Peashooter(string name, float x, float y, float speed, float angle) 
:Bullet(name, x, y ,speed, angle)
{
}
void Peashooter::Init() {
	mImage;
	vector<GameObject*>* PlayerBullet = ObjectManager::GetInstance()->GetObjectListPt(ObjectLayer::Player_Bullet);
	mName = "Peashooter";
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Player_Bullet, this);
};
void Peashooter::Release() {
	
}

void Peashooter::Update() {
	mX += mSpeed *cos(mAngle);
	mY -= mSpeed * sin(mAngle);
	mRect = RectMakeCenter(mX,mY,20,20);
}
void Peashooter::Render(HDC hdc) {
	CameraManager::GetInstance()->GetMainCamera()->RenderRect(hdc, mRect);
}

void Peashooter::InIntersectDamage() { //삭제 처리
	mIsDestroy = true;
}