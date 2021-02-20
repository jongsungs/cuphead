#include "pch.h"
#include "Image.h"
#include "Animation.h"
#include "Camera.h"
#include "PlatformerPlayer.h"
PlatformerPlayer::PlatformerPlayer(const string& name, float x, float y)
	:GameObject(name)
{
	mX = x;
	mY = y;
}


void PlatformerPlayer::Init()
{
	mGround = RectMake(0, 620, 3000, 200);
	mX = WINSIZEX / 4;
	mY = 520;
	mRect = RectMakeCenter(mX, mY, 98, 155);
	mGravity = 0.1f;
	mJumpPower = 0.f;
}

void PlatformerPlayer::Release()
{
	//SafeDelete(mDownIdleAnimation);
	

}

void PlatformerPlayer::Update()
{
	if (Input::GetInstance()->GetKey('A'))
	{
		mX -= 5;
	}
	if (Input::GetInstance()->GetKey('D'))
	{
		mX += 5;
	}
	mY -= mJumpPower;
	mJumpPower -= mGravity;
	if (mY<= WINSIZEY)
	{
		mY = WINSIZEY - 155;
	}
	mRect = RectMakeCenter(mX, mY, 98, 155);
	//mCurrentAnimation->Update();
	
}

void PlatformerPlayer::Render(HDC hdc)
{
	
	//CameraManager::GetInstance()->GetMainCamera()->RenderRect(hdc, mRect);
	//CameraManager::GetInstance()->GetMainCamera()->ScaleFrameRender(hdc, mImage, mRect.left, mRect.top, mCurrentAnimation->GetNowFrameX(),
	//	mCurrentAnimation->GetNowFrameY(), 80, 120);
	////Á×À½
	//if (mCurrentAnimation == mDieAnimation)
	//{
	//	CameraManager::GetInstance()->GetMainCamera()->ScaleFrameRender(hdc, mImage4, mRect.left, mRect.top, mCurrentAnimation->GetNowFrameX(), mCurrentAnimation->GetNowFrameY(), 80, 120);
	//}
	RenderRect(hdc, mRect);
	RenderRect(hdc, mGround);

}
