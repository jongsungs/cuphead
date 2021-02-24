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
}

void CarrotProj::Release(){
	SafeDelete(CarrotBeamAnimation);
	SafeDelete(CarrotBeamAnimation);
}

void CarrotProj::Update(){
	mX += cosf(mAngle) * mSpeed;
	mY += -sinf(mAngle) * mSpeed;
	mRect = RectMakeCenter(mX, mY, 20, 10);

	mCurrentAnimation->Update();
}

void CarrotProj::Render(HDC hdc){
	RenderRect(hdc, mRect);
	
	//CameraManager::GetInstance()->GetMainCamera()
	//	->FrameRender(hdc, mImage, mRect.left, mRect.top, mCurrentAnimation->GetNowFrameX(), mCurrentAnimation->GetNowFrameY());
}
