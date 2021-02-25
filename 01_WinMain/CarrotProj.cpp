#include "pch.h"

#include"Image.h"
#include "CarrotProj.h"
#include "Animation.h"
#include "Camera.h"

void CarrotProj::Init(){
	vector<GameObject*>* EnemyProj = ObjectManager::GetInstance()->GetObjectListPt(ObjectLayer::Enemy_Bullet);
	mName = to_string(EnemyProj->size());
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Enemy_Bullet, this);

	CarrotMissile = IMAGEMANAGER->FindImage(L"CarrotProj");
	CarrotBeam = IMAGEMANAGER->FindImage(L"PotatoParryable");

	CarrotMissileAnimation = new Animation();
	CarrotMissileAnimation->InitFrameByStartEnd(0, 0, 5, 0, false);
	CarrotMissileAnimation->SetIsLoop(true);
	CarrotMissileAnimation->SetFrameUpdateTime(0.07f);
	
	CarrotBeamAnimation = new Animation();
	CarrotBeamAnimation->InitFrameByStartEnd(0, 0, 5, 0, false);
	CarrotBeamAnimation->SetIsLoop(true);
	CarrotBeamAnimation->SetFrameUpdateTime(0.07f);
}

void CarrotProj::Release(){
	SafeDelete(CarrotMissileAnimation);
	SafeDelete(CarrotBeamAnimation);
}

void CarrotProj::Update(){
	mX += cosf(mAngle) * mSpeed;
	mY += -sinf(mAngle) * mSpeed;
	
	if (mName == string("CarrotMissile")) {
		mImage = CarrotMissile;
		mCurrentAnimation = CarrotMissileAnimation;
		mCurrentAnimation->Play();
	}
	else {
		mImage = CarrotBeam;
		mCurrentAnimation = CarrotBeamAnimation;
		mCurrentAnimation->Play();
	}
	mRect = RectMakeCenter(mX, mY, 20, 10);
	mCurrentAnimation->Update();
}

void CarrotProj::Render(HDC hdc){
	RenderRect(hdc, mRect);
	
	CameraManager::GetInstance()->GetMainCamera()
		->FrameRender(hdc, CarrotMissile, mRect.left, mRect.top, mCurrentAnimation->GetNowFrameX(), mCurrentAnimation->GetNowFrameY());
}
