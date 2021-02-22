#include "pch.h"
#include "Image.h"
#include "Animation.h"
#include "Camera.h"
#include "Bullet.h"
#include "PlatformerPlayer.h"
PlatformerPlayer::PlatformerPlayer(const string& name, float x, float y)
	:GameObject(name)
{
	mX = x;
	mY = y;
}


void PlatformerPlayer::Init()
{
	mImage = IMAGEMANAGER->FindImage(L"UpShoot");
	mGround = RectMake(0, 620, 3000, 200);
	mX = WINSIZEX / 4;
	mY = 300;
	mRect = RectMakeCenter(mX, mY, 98, 155);
	mGravity = 0.1f;
	mJumpPower = 0.f;
	mPlayerState = PlayerState::RightIdle;


	mAnimation = new Animation();
	mAnimation->InitFrameByStartEnd(0, 0, 5, 1, false);
	mAnimation->SetIsLoop(true);
	mAnimation->SetFrameUpdateTime(0.1f);
	mAnimation->Play();


	
}

void PlatformerPlayer::Release()
{
	//SafeDelete(mDownIdleAnimation);
	

}

void PlatformerPlayer::Update()
{
	if (Input::GetInstance()->GetKey(VK_LEFT))
	{
		mX -= 5;
	}
	if (Input::GetInstance()->GetKey(VK_RIGHT))
	{
		mX += 5;
	}
	if (Input::GetInstance()->GetKey('Z'))
	{
		mJumpPower = 5.f;
	}
	//if (Input::GetInstance()->GetKey(VK_SPACE))
	//{
	//	Bullet* bullet = new Bullet();
	//	bullet->Init();
	//	mBullet.push_back(bullet);
	//}
	mRect = RectMakeCenter(mX, mY, 98, 155);
	mJumpPower -= mGravity;
	mY -= mJumpPower;
	if (mY<= WINSIZEY)
	{
		mY = WINSIZEY - 180;
	}
	


	//mCurrentAnimation->Update();
	for (int i = 0; i < mBullet.size(); i++)
	{
		mBullet[i]->Update();
	}
	mAnimation->Update();
}

void PlatformerPlayer::Render(HDC hdc)
{
	
	//CameraManager::GetInstance()->GetMainCamera()->RenderRect(hdc, mRect);
	////Á×À½
	//if (mCurrentAnimation == mDieAnimation)
	//{
	//	CameraManager::GetInstance()->GetMainCamera()->ScaleFrameRender(hdc, mImage4, mRect.left, mRect.top, mCurrentAnimation->GetNowFrameX(), mCurrentAnimation->GetNowFrameY(), 80, 120);
	//}
	RenderRect(hdc, mRect);
	mImage->FrameRender(hdc,mRect.left, mRect.top, mAnimation->GetNowFrameX(),mAnimation->GetNowFrameY());

	//RenderRect(hdc, mGround);
	for (int i = 0; i < mBullet.size(); ++i)
	{
		mBullet[i]->Render(hdc);
	}
	

}
