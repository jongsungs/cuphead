#include "pch.h"
#include "Peashooter.h"
#include "Image.h"
#include "Camera.h"
#include "Animation.h"
#include "Player_Bullet_Effect.h"

#define RadianAngle(angle) angle* PI/180
Peashooter::Peashooter(string name, float x, float y, float angle) 
:Bullet(name, x, y,angle)
{
	mHP = 3; // 총알 대미지
	mSpeed = 40.f;
	mAnimation = new Animation();
	mAnimation->SetFrameUpdateTime(0.1f);
	
	if (angle == RadianAngle(0)) { //0도
		mAnimation->InitFrameStartEndsetLoop(0, 1, 7, 1, 2, 1, 7, 1, false);
		mImage = ImageManager::GetInstance()->FindImage(L"BulletLeftRight");
	}
	else if (angle == RadianAngle(45)) {
		mAnimation->InitFrameStartEndsetLoop(0, 1, 7, 1, 2, 1, 7, 1, false);
		mImage = ImageManager::GetInstance()->FindImage(L"BulletUpLeftRight");
	}
	else if (angle == RadianAngle(90)) {
		mAnimation->InitFrameStartEndsetLoop(0, 0, 7, 0, 2, 0, 7, 0, false);
		mImage = ImageManager::GetInstance()->FindImage(L"BulletUpDown");
	}
	else if (angle == RadianAngle(135)) {
		mAnimation->InitFrameStartEndsetLoop(0, 0, 7, 0, 2, 0, 7, 0, false);
		mImage = ImageManager::GetInstance()->FindImage(L"BulletUpLeftRight");
	}
	else if (angle == RadianAngle(180)) {
		mAnimation->InitFrameStartEndsetLoop(0, 0, 7, 0, 2, 0, 7, 0, false);
		mImage = ImageManager::GetInstance()->FindImage(L"BulletLeftRight");
	}
	mAnimation->Play();
	//mImage = ImageManager::GetInstance()->FindImage(L"Testbullet");
}
void Peashooter::Init() {
	//vector<GameObject*>* PlayerBullet = ObjectManager::GetInstance()->GetObjectListPt(ObjectLayer::Player_Bullet);
	mName = "Peashooter";
	//ObjectManager::GetInstance()->AddObject(ObjectLayer::Player_Bullet, this);
};
void Peashooter::Release() {
	SafeDelete(mAnimation)
}

void Peashooter::Update() {
	mAnimation->Update();
	if (Range < 0) {
		mIsDestroy = true;
		return;
	}
	mX += (mSpeed*100) * cos(mAngle) * Time::GetInstance()->DeltaTime();
	mY -= (mSpeed*100) * sin(mAngle) * Time::GetInstance()->DeltaTime();
	mRect = RectMakeCenter(mX,mY,40,40);
	Range -= mSpeed;
}
void Peashooter::Render(HDC hdc) {
	
	//CameraManager::GetInstance()->GetMainCamera()->RenderRect(hdc, mRect);
	if (mAngle == RadianAngle(0)) { //0도
		CameraManager::GetInstance()->GetMainCamera()->FrameRenderFromRightCenter(hdc, mImage, mRect.right, mY, mAnimation->GetNowFrameX(),mAnimation->GetNowFrameY());
	}
	else if (mAngle == RadianAngle(45)) {
		CameraManager::GetInstance()->GetMainCamera()->FrameRenderFromRightTop(hdc, mImage, mRect.right, mRect.top, mAnimation->GetNowFrameX(), mAnimation->GetNowFrameY());
	}
	else if (mAngle == RadianAngle(90)) {
		CameraManager::GetInstance()->GetMainCamera()->FrameRenderFromTopCenter(hdc, mImage, mX, mRect.top, mAnimation->GetNowFrameX(), mAnimation->GetNowFrameY());
	}
	else if (mAngle == RadianAngle(135)) {
		CameraManager::GetInstance()->GetMainCamera()->FrameRender(hdc, mImage, mRect.left, mRect.top, mAnimation->GetNowFrameX(), mAnimation->GetNowFrameY());
	}
	else if (mAngle == RadianAngle(180)) {
		CameraManager::GetInstance()->GetMainCamera()->FrameRenderFromLeftCenter(hdc, mImage, mRect.left -20, mY, mAnimation->GetNowFrameX(), mAnimation->GetNowFrameY());
	}
	
	//CameraManager::GetInstance()->GetMainCamera()->RenderRect(hdc, mRect);
	//CameraManager::GetInstance()->GetMainCamera()->Render(hdc,mImage,mX,mY);
}

void Peashooter::InIntersectDamage(int dmage) { //삭제 처리
	new Player_Bullet_Effect(mX, mY, ImageManager::GetInstance()->FindImage(L"BulletDeath"), 0.07f);
	mIsDestroy = true;
}