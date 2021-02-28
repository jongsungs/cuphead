#include "pch.h"
#include "SuperPeashooter.h"
#include "Image.h"
#include "Animation.h"
#include "Camera.h"
#include "Effect.h"

#define RadianAngle(angle) angle* PI/180
SuperPeashooter::SuperPeashooter(string name, float x, float y, float angle)
	:Bullet(name, x, y, angle)
{
	mHP = 10; // 총알 대미지
	mSpeed = 10.f;
	mAnimation = new Animation();
	mAnimation->SetFrameUpdateTime(0.1f);

	if (angle == RadianAngle(0)) { //0도
		mAnimation->InitFrameByStartEnd(0, 1, 7, 1,false);
		mAnimation->SetIsLoop(true);
		mImage = ImageManager::GetInstance()->FindImage(L"SuperBulletLeftRight");
	}
	else if (angle == RadianAngle(45)) {
		mAnimation->InitFrameByStartEnd(0, 1, 7, 1, false);
		mAnimation->SetIsLoop(true);
		mImage = ImageManager::GetInstance()->FindImage(L"SuperBulletUpLeftRight");
	}
	else if (angle == RadianAngle(90)) {
		mAnimation->InitFrameByStartEnd(0, 0, 7, 0, false);
		mAnimation->SetIsLoop(true);
		mImage = ImageManager::GetInstance()->FindImage(L"SuperBulletUp");
	}
	else if (angle == RadianAngle(135)) {
		mAnimation->InitFrameByStartEnd(0, 0, 7, 0, false);
		mAnimation->SetIsLoop(true);
		mImage = ImageManager::GetInstance()->FindImage(L"SuperBulletUpLeftRight");
	}
	else if (angle == RadianAngle(180)) {
		mAnimation->InitFrameByStartEnd(0, 0, 7, 0, false);
		mAnimation->SetIsLoop(true);
		mImage = ImageManager::GetInstance()->FindImage(L"SuperBulletLeftRight");
	}
	mAnimation->Play();
	//mImage = ImageManager::GetInstance()->FindImage(L"Testbullet");
}
void SuperPeashooter::Init() {
	//vector<GameObject*>* PlayerBullet = ObjectManager::GetInstance()->GetObjectListPt(ObjectLayer::Player_Bullet);
	mName = "Peashooter";
	//ObjectManager::GetInstance()->AddObject(ObjectLayer::Player_Bullet, this);
};
void SuperPeashooter::Release() {
	SafeDelete(mAnimation)
}

void SuperPeashooter::Update() {
	mAnimation->Update();
	if (Range < 0) {
		mIsDestroy = true;
		return;
	}
	mX += mSpeed * cos(mAngle);
	mY -= mSpeed * sin(mAngle);
	mRect = RectMakeCenter(mX, mY, 40, 40);
	Range -= mSpeed;
}
void SuperPeashooter::Render(HDC hdc) {

	CameraManager::GetInstance()->GetMainCamera()->RenderRect(hdc, mRect);
	if (mAngle == RadianAngle(0)) { //0도
		CameraManager::GetInstance()->GetMainCamera()->FrameRenderFromRightCenter(hdc, mImage, mRect.right, mY, mAnimation->GetNowFrameX(), mAnimation->GetNowFrameY());
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
		CameraManager::GetInstance()->GetMainCamera()->FrameRenderFromLeftCenter(hdc, mImage, mRect.left - 20, mY, mAnimation->GetNowFrameX(), mAnimation->GetNowFrameY());
	}

	//CameraManager::GetInstance()->GetMainCamera()->RenderRect(hdc, mRect);
	//CameraManager::GetInstance()->GetMainCamera()->Render(hdc,mImage,mX,mY);
}

void SuperPeashooter::InIntersectDamage(int dmage) { //삭제 처리
	new Effect(mX, mY, ImageManager::GetInstance()->FindImage(L"SuperBulletDeath"), 0.07f);
	mIsDestroy = true;
}