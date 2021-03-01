#include "pch.h"

#include"Image.h"
#include "Animation.h"
#include "PotatoProj.h"
#include "Camera.h"

PotatoProj::PotatoProj(const string& name, float x, float y, float speed, float angle, bool parryAble)
	:EnemyProj(name, x, y, speed, angle, parryAble)
{
	mX = x;
	mY = y;
	mSpeed = speed;
	mAngle = angle;
	mParryAble = parryAble;
}

void PotatoProj::Init(){
	ParryAbleImg = IMAGEMANAGER->FindImage(L"PotatoParryable");
	NonParryAbleImg = IMAGEMANAGER->FindImage(L"PotatoNonParryable");

	vector<GameObject*>* EnemyProj = ObjectManager::GetInstance()->GetObjectListPt(ObjectLayer::Enemy_Bullet);
	mName = to_string(EnemyProj->size());

	ParryAbleAnimation = new Animation();
	ParryAbleAnimation->InitFrameByStartEnd(0, 0, 3, 0, false);
	ParryAbleAnimation->SetIsLoop(true);
	ParryAbleAnimation->SetFrameUpdateTime(0.07f);

	NonParryAbleAnimation = new Animation();
	NonParryAbleAnimation->InitFrameByStartEnd(0, 0, 7, 0, false);
	NonParryAbleAnimation->SetIsLoop(true);
	NonParryAbleAnimation->SetFrameUpdateTime(0.07f);
}

void PotatoProj::Release(){
	SafeDelete(ParryAbleAnimation);
	SafeDelete(NonParryAbleAnimation);
}

void PotatoProj::Update(){
	if (mParryAble == true) {
		mImage = ParryAbleImg;
		mCurrentAnimation = ParryAbleAnimation;
	}
	else {
		mImage = NonParryAbleImg;
		mCurrentAnimation = NonParryAbleAnimation;
	}
	mSizeX = mImage->GetFrameWidth();
	mSizeY = mImage->GetFrameHeight();

	mCurrentAnimation->Play();

	mX += cosf(mAngle) * mSpeed;
	mY += -sinf(mAngle) * mSpeed;

	mRect = RectMakeCenter(mX, mY, mSizeX/2, mSizeY/2);
	if (mRect.right < 0) {
		mIsActive = false;
		mIsDestroy = true;
	}
		
	mCurrentAnimation->Update();
}

void PotatoProj::Render(HDC hdc){
	//RenderRect(hdc, mRect);
	
	CameraManager::GetInstance()->GetMainCamera()
		->FrameRender(hdc, mImage, mX - mImage->GetFrameWidth()/2, mY - mImage->GetFrameHeight()/2, mCurrentAnimation->GetNowFrameX(), mCurrentAnimation->GetNowFrameY());
}

void PotatoProj::InIntersectDamage(int dmage){
	mIsActive = false;
	mIsDestroy = true;
}