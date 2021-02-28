#include "pch.h"
#include "Player_Bullet_Effect.h"
#include "Animation.h"
#include "Image.h"
#include "Camera.h"

Player_Bullet_Effect::Player_Bullet_Effect(float x, float y, Image* image, float frameTime, bool isReverse)
{
	mX = x;
	mY = y;
	mImage = image;
	mEffectAnimation = new Animation();
	mEffectAnimation->InitFrameByStartEnd(0, 0, mImage->GetFrameX() - 1, 0, false);
	mEffectAnimation->SetIsLoop(false);
	mEffectAnimation->SetFrameUpdateTime(frameTime);
	mEffectAnimation->Play();

	vector<GameObject*>* effectvector = ObjectManager::GetInstance()->GetObjectListPt(ObjectLayer::Player_Bullet_Effect);

	mName = "Player_Bullet_Effect" + to_string(effectvector->size());
	mIsActive = true;
	mIsDestroy = false;

	ObjectManager::GetInstance()->AddObject(ObjectLayer::Player_Bullet_Effect, this);

	mRect = RectMakeCenter(mX, mY, mImage->GetFrameWidth(), mImage->GetFrameHeight());
}

void Player_Bullet_Effect::Init()
{
}

void Player_Bullet_Effect::Update()
{
	if (!mEffectAnimation->GetIsPlay()) { //끝에 도달하면 삭제처리
		mIsDestroy = true;
	}
	else {
		mEffectAnimation->Update();
	}
}
void Player_Bullet_Effect::Release()
{
	SafeDelete(mEffectAnimation);
}


void Player_Bullet_Effect::Render(HDC hdc)
{
	CameraManager::GetInstance()->GetMainCamera()
		->ScaleFrameRender(hdc, mImage, mRect.left, mRect.top, mEffectAnimation->GetNowFrameX(), mEffectAnimation->GetNowFrameY(), mImage->GetFrameWidth(), mImage->GetFrameHeight());
}