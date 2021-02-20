#include "pch.h"
#include "Effect.h"
#include "Image.h"
#include "Animation.h"
#include "Camera.h"
/*
처음 호출 시 x 좌표, y좌표 셋팅 및 이미지 셋팅
*/
Effect::Effect(const string& name, float x, float y, Image* image)
	: GameObject(name)
{
	mX = x;
	mY = y;
	mImage = image;
}

void Effect::Init()
{
	mEffectAnimation = new Animation();
	mEffectAnimation->InitFrameByStartEnd(0, 0, mImage->GetFrameX()-1, 0, false);
	mEffectAnimation->SetIsLoop(false);
	mEffectAnimation->SetFrameUpdateTime(0.2f);
	mEffectAnimation->Play();
	
	mRect = RectMakeCenter(mX, mY, mImage->GetFrameWidth(), mImage->GetFrameHeight());
}

void Effect::Update()
{
	if (!mEffectAnimation->GetIsPlay()) { //끝에 도달하면 삭제처리
		mIsDestroy = true;
	}
	else {
		mEffectAnimation->Update();
	}
}
void Effect::Release()
{
	SafeDelete(mEffectAnimation);
}


void Effect::Render(HDC hdc)
{
	CameraManager::GetInstance()->GetMainCamera()
		->ScaleFrameRender(hdc, mImage, mRect.left, mRect.top, mEffectAnimation->GetNowFrameX(), mEffectAnimation->GetNowFrameY(), mImage->GetFrameWidth(), mImage->GetFrameHeight());
}

