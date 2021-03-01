#include "pch.h"
#include "Spread.h"
#include "Camera.h"
#include "Animation.h"

#define RadianAngle(angle) angle* PI/180
Spread::Spread(string name, float x, float y, float angle, int speed) :Bullet(name, x,y,angle) {
	mHP = 3; // 총알 대미지
	if (speed == 1) {
		mSpeed = 30.f;
	}
	else {
		mSpeed = 40.f;
	}
	mImage = ImageManager::GetInstance()->FindImage(L"RedBullet");
	mAnimation = new Animation();
	mAnimation->SetFrameUpdateTime(0.1f);
	mAnimation->SetIsLoop(true);
	if (angle == RadianAngle(0)) { //0도
		mAnimation->InitFrameByStartEnd(0,0,3,0,false);
	}
	else if (angle == RadianAngle(45)) {
		mAnimation->InitFrameByStartEnd(0,1,3,1,false);
	}
	else if (angle == RadianAngle(90)) {
		mAnimation->InitFrameByStartEnd(0, 2, 3, 2, false);
	}
	else if (angle == RadianAngle(135)) {
		mAnimation->InitFrameByStartEnd(0, 3, 3, 3, false);
	}
	else if (angle == RadianAngle(180)) {
		mAnimation->InitFrameByStartEnd(0, 4, 3, 4, false);
		
	}
	else if (angle == RadianAngle(225)) {
		mAnimation->InitFrameByStartEnd(0, 5, 3, 5, false);

	}
	else if (angle == RadianAngle(315)) {
		mAnimation->InitFrameByStartEnd(0, 7, 3, 7, false);

	}
	mAnimation->Play();
}
void Spread::Init()
{
	mImage = ImageManager::GetInstance()->FindImage(L"RedBullet");
	vector<GameObject*>* PlayerBullet = ObjectManager::GetInstance()->GetObjectListPt(ObjectLayer::Player_Bullet);
	mName = "Peashooter";
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Player_Bullet, this);
}

void Spread::Release()
{
}

void Spread::Update()
{
	mAnimation->Update();
	if (Range < 0) {
		mIsDestroy = true;
		return;
	}
	mX += (mSpeed * 50) * cos(mAngle) * Time::GetInstance()->DeltaTime();
	mY -= (mSpeed * 50) * sin(mAngle) * Time::GetInstance()->DeltaTime();
	mRect = RectMakeCenter(mX, mY, 40, 40);
	Range -= mSpeed;
}

void Spread::Render(HDC hdc)
{
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
	else if (mAngle == RadianAngle(225)) {
		CameraManager::GetInstance()->GetMainCamera()->FrameRenderFromLeftCenter(hdc, mImage, mRect.left - 20, mY, mAnimation->GetNowFrameX(), mAnimation->GetNowFrameY());
	}
	else if (mAngle == RadianAngle(315)) {
		CameraManager::GetInstance()->GetMainCamera()->FrameRenderFromLeftCenter(hdc, mImage, mRect.left - 20, mY, mAnimation->GetNowFrameX(), mAnimation->GetNowFrameY());
	}
}

void Spread::InIntersectDamage(int damge)
{
	mIsDestroy = true;
}
