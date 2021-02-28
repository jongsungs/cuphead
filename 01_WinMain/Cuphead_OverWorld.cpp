#include "pch.h"
#include "Cuphead_OverWorld.h"
#include "Image.h"
#include "Animation.h"
#include "Camera.h"
#include "Effect.h"

Cuphead_OverWorld::Cuphead_OverWorld(const string& name, float x, float y)
	:GameObject(name)
{
	mX = x;
	mY = y;

}

void Cuphead_OverWorld::Init()
{
	mImage = IMAGEMANAGER->FindImage(L"CupHead_OverWolrd");
	
	mDustCount = 0;

	mSizeX = mImage->GetWidth()/16;
	mSizeY = mImage->GetHeight()/10;
	mRect = RectMakeCenter(mX, mY, mSizeX, mSizeY);
	mAngle = 0;
	mSpeed = 3.f;
	//애니메이션 부분
	mUpIdleAnimation = new Animation();
	mUpIdleAnimation->InitFrameByStartEnd(0, 0, 1, 0, false);
	mUpIdleAnimation->SetIsLoop(true);
	mUpIdleAnimation->SetFrameUpdateTime(0.3f);
	mDownIdleAnimation = new Animation();
	mDownIdleAnimation->InitFrameByStartEnd(0, 4, 1, 4, false);
	mDownIdleAnimation->SetIsLoop(true);
	mDownIdleAnimation->SetFrameUpdateTime(0.3f);
	mLeftIdleAnimation = new Animation();
	mLeftIdleAnimation->InitFrameByStartEnd(14, 6, 15, 6, true);
	mLeftIdleAnimation->SetIsLoop(true);
	mLeftIdleAnimation->SetFrameUpdateTime(0.3f);
	mLeftDownIdleAnimation = new Animation();
	mLeftDownIdleAnimation->InitFrameByStartEnd(15, 7, 16, 7, true);
	mLeftDownIdleAnimation->SetIsLoop(true);
	mLeftDownIdleAnimation->SetFrameUpdateTime(0.3f);
	mLeftUpIdleAnimation = new Animation();
	mLeftUpIdleAnimation->InitFrameByStartEnd(15, 5, 16, 5, true);
	mLeftUpIdleAnimation->SetIsLoop(true);
	mLeftUpIdleAnimation->SetFrameUpdateTime(0.3f);
	mRightIdleAnimation = new Animation();
	mRightIdleAnimation->InitFrameByStartEnd(0, 2, 1, 2, false);
	mRightIdleAnimation->SetIsLoop(true);
	mRightIdleAnimation->SetFrameUpdateTime(0.3f);
	mRightUpIdleAnimation = new Animation();
	mRightUpIdleAnimation->InitFrameByStartEnd(0, 1, 1, 1, false);
	mRightUpIdleAnimation->SetIsLoop(true);
	mRightUpIdleAnimation->SetFrameUpdateTime(0.3f);
	mRightDownIdleAnimation = new Animation();
	mRightDownIdleAnimation->InitFrameByStartEnd(0, 3, 1, 3, false);
	mRightDownIdleAnimation->SetIsLoop(true);
	mRightDownIdleAnimation->SetFrameUpdateTime(0.3f);

	mUpMoveAnimation = new Animation();
	mUpMoveAnimation->InitFrameByStartEnd(5, 0, 15, 0, false);
	mUpMoveAnimation->SetIsLoop(true);
	mUpMoveAnimation->SetFrameUpdateTime(0.1f);
	mDownMoveAnimation = new Animation();
	mDownMoveAnimation->InitFrameByStartEnd(2, 4, 14, 4, false);
	mDownMoveAnimation->SetIsLoop(true);
	mDownMoveAnimation->SetFrameUpdateTime(0.1f);
	mLeftMoveAnimation = new Animation();
	mLeftMoveAnimation->InitFrameByStartEnd(2, 6, 11, 6, true);
	mLeftMoveAnimation->SetIsLoop(true);
	mLeftMoveAnimation->SetFrameUpdateTime(0.1f);
	mLeftDownMoveAnimation = new Animation();
	mLeftDownMoveAnimation->InitFrameByStartEnd(0, 7, 11, 7, true);
	mLeftDownMoveAnimation->SetIsLoop(true);
	mLeftDownMoveAnimation->SetFrameUpdateTime(0.1f);
	mLeftUpMoveAnimation = new Animation();
	mLeftUpMoveAnimation->InitFrameByStartEnd(1, 5, 11, 5, true);
	mLeftUpMoveAnimation->SetIsLoop(true);
	mLeftUpMoveAnimation->SetFrameUpdateTime(0.1f);
	mRightMoveAnimation = new Animation();
	mRightMoveAnimation->InitFrameByStartEnd(4, 2, 13, 2, false);
	mRightMoveAnimation->SetIsLoop(true);
	mRightMoveAnimation->SetFrameUpdateTime(0.1f);
	mRightUpMoveAnimation = new Animation();
	mRightUpMoveAnimation->InitFrameByStartEnd(4, 1, 14, 1, false);
	mRightUpMoveAnimation->SetIsLoop(true);
	mRightUpMoveAnimation->SetFrameUpdateTime(0.1f);
	mRightDownMoveAnimation = new Animation();
	mRightDownMoveAnimation->InitFrameByStartEnd(4, 3, 15, 3, false);
	mRightDownMoveAnimation->SetIsLoop(true);
	mRightDownMoveAnimation->SetFrameUpdateTime(0.1f);

	mCurrentAnimation = mDownIdleAnimation;
	mCurrentAnimation->Play();

}

void Cuphead_OverWorld::Release()
{
	
}

void Cuphead_OverWorld::Update()
{
	
	
	

	if (Input::GetInstance()->GetKey(VK_LEFT))
	{
		if (Input::GetInstance()->GetKeyDown(VK_UP))
		{

			mCurrentAnimation->Stop();
			mCurrentAnimation = mLeftUpMoveAnimation;
			mCurrentAnimation->Play();
			SoundPlayer::GetInstance()->Play(L"FootStep", 1.f);
		}
		else if (Input::GetInstance()->GetKeyDown(VK_DOWN))
		{

			mCurrentAnimation->Stop();
			mCurrentAnimation = mLeftDownMoveAnimation;
			mCurrentAnimation->Play();
			SoundPlayer::GetInstance()->Play(L"FootStep", 1.f);
		}
		if (Input::GetInstance()->GetKey(VK_UP))
		{
			mAngle = 3*PI/4;
		}
		else if (Input::GetInstance()->GetKey(VK_DOWN))
		{
			mAngle = 5  * PI/4;
		}
		else
		{
			mAngle =  4 *PI/4;
		}
	}
	if (Input::GetInstance()->GetKey(VK_RIGHT))
	{
		if (Input::GetInstance()->GetKeyDown(VK_UP))
		{

			mCurrentAnimation->Stop();
			mCurrentAnimation = mRightUpMoveAnimation;
			mCurrentAnimation->Play();
		}
		else if (Input::GetInstance()->GetKeyDown(VK_DOWN))
		{

			mCurrentAnimation->Stop();
			mCurrentAnimation = mRightDownMoveAnimation;
			mCurrentAnimation->Play();
		}
		if (Input::GetInstance()->GetKey(VK_UP))
		{
			mAngle = 1*PI/4;
		}
		else if (Input::GetInstance()->GetKey(VK_DOWN))
		{
			mAngle = 7*PI/4;
		}
		else
		{
			mAngle = 0 * PI;
		}
	}
	if (Input::GetInstance()->GetKey(VK_UP))
	{
		if (Input::GetInstance()->GetKeyDown(VK_RIGHT))
		{
			mCurrentAnimation->Stop();
			mCurrentAnimation = mRightUpMoveAnimation;
			mCurrentAnimation->Play();
		}
		else if (Input::GetInstance()->GetKeyDown(VK_LEFT))
		{
			mCurrentAnimation->Stop();
			mCurrentAnimation = mLeftUpMoveAnimation;
			mCurrentAnimation->Play();
		}
		if (Input::GetInstance()->GetKey(VK_LEFT))
		{
			mAngle = 3 * PI / 4;
		}
		else if (Input::GetInstance()->GetKey(VK_RIGHT))
		{
			mAngle = 1 * PI / 4;
		}
		else
		{
			mAngle = 2 * PI / 4;
		}
	}
	if (Input::GetInstance()->GetKey(VK_DOWN))
	{
		if (Input::GetInstance()->GetKeyDown(VK_RIGHT))
		{

			mCurrentAnimation->Stop();
			mCurrentAnimation = mRightDownMoveAnimation;
			mCurrentAnimation->Play();
		}
		else if (Input::GetInstance()->GetKeyDown(VK_LEFT))
		{

			mCurrentAnimation->Stop();
			mCurrentAnimation = mLeftDownMoveAnimation;
			mCurrentAnimation->Play();
		}
		if (Input::GetInstance()->GetKey(VK_RIGHT))
		{
			mAngle = 7 * PI / 4;
		}
		else if (Input::GetInstance()->GetKey(VK_LEFT))
		{
			mAngle = 5 * PI / 4;
		}
		else
		{
			mAngle = 6 * PI / 4;
		}
	}
	
	if (Input::GetInstance()->GetKeyDown(VK_LEFT))
	{
			mCurrentAnimation->Stop();
			mCurrentAnimation = mLeftMoveAnimation;
			mCurrentAnimation->Play();
			mIsGetKeyNow = true;
			SoundPlayer::GetInstance()->Play(L"FootStep", 1.f);
	}
	if (Input::GetInstance()->GetKeyDown(VK_RIGHT))
	{
		
			mCurrentAnimation->Stop();
			mCurrentAnimation = mRightMoveAnimation;
			mCurrentAnimation->Play();
			mIsGetKeyNow = true;
			SoundPlayer::GetInstance()->Play(L"FootStep", 1.f);
	}
	if (Input::GetInstance()->GetKeyDown(VK_UP))
	{
			mCurrentAnimation->Stop();
			mCurrentAnimation = mUpMoveAnimation;
			mCurrentAnimation->Play();
			mIsGetKeyNow = true;
			SoundPlayer::GetInstance()->Play(L"FootStep", 1.f);
	}
	if (Input::GetInstance()->GetKeyDown(VK_DOWN))
	{
	
			mCurrentAnimation->Stop();
			mCurrentAnimation = mDownMoveAnimation;
			mCurrentAnimation->Play();
			mIsGetKeyNow = true;
			SoundPlayer::GetInstance()->Play(L"FootStep", 1.f);
	}

	
		if (Input::GetInstance()->GetKeyUp(VK_LEFT))
		{
			if (!(Input::GetInstance()->GetKey(VK_UP)) && !(Input::GetInstance()->GetKey(VK_DOWN)))
			{
				mCurrentAnimation->Stop();
				mCurrentAnimation = mLeftIdleAnimation;
				mCurrentAnimation->Play();
				mIsGetKeyNow = false;
			}
			else
			{
				if (Input::GetInstance()->GetKey(VK_UP))
				{
					mCurrentAnimation->Stop();
					mCurrentAnimation = mUpMoveAnimation;
					mCurrentAnimation->Play();
				}
				if (Input::GetInstance()->GetKey(VK_DOWN))
				{
					mCurrentAnimation->Stop();
					mCurrentAnimation = mDownMoveAnimation;
					mCurrentAnimation->Play();
				}
			}
		}
		if (Input::GetInstance()->GetKeyUp(VK_RIGHT))
		{
			if (!(Input::GetInstance()->GetKey(VK_UP)) && !(Input::GetInstance()->GetKey(VK_DOWN)))
			{
				mCurrentAnimation->Stop();
				mCurrentAnimation = mRightIdleAnimation;
				mCurrentAnimation->Play();
				mIsGetKeyNow = false;
			}
			else
			{
				if (Input::GetInstance()->GetKey(VK_UP))
				{
					mCurrentAnimation->Stop();
					mCurrentAnimation = mUpMoveAnimation;
					mCurrentAnimation->Play();
				}
				if (Input::GetInstance()->GetKey(VK_DOWN))
				{
					mCurrentAnimation->Stop();
					mCurrentAnimation = mDownMoveAnimation;
					mCurrentAnimation->Play();
				}
			}
		}
		if (Input::GetInstance()->GetKeyUp(VK_UP))
		{
			if (!(Input::GetInstance()->GetKey(VK_LEFT)) && !(Input::GetInstance()->GetKey(VK_RIGHT)))
			{
				mCurrentAnimation->Stop();
				mCurrentAnimation = mUpIdleAnimation;
				mCurrentAnimation->Play();
				mIsGetKeyNow = false;
			}
			else
			{
				if (Input::GetInstance()->GetKey(VK_RIGHT))
				{
					mCurrentAnimation->Stop();
					mCurrentAnimation = mRightMoveAnimation;
					mCurrentAnimation->Play();
				}
				if (Input::GetInstance()->GetKey(VK_LEFT))
				{
					mCurrentAnimation->Stop();
					mCurrentAnimation = mLeftMoveAnimation;
					mCurrentAnimation->Play();
				}
			}
		}
		if (Input::GetInstance()->GetKeyUp(VK_DOWN))
		{
			if (!(Input::GetInstance()->GetKey(VK_LEFT)) && !(Input::GetInstance()->GetKey(VK_RIGHT)))
			{
				mCurrentAnimation->Stop();
				mCurrentAnimation = mDownIdleAnimation;
				mCurrentAnimation->Play();
				mIsGetKeyNow = false;
			}
			else
			{
				if (Input::GetInstance()->GetKey(VK_RIGHT))
				{
					mCurrentAnimation->Stop();
					mCurrentAnimation = mRightMoveAnimation;
					mCurrentAnimation->Play();
				}
				if (Input::GetInstance()->GetKey(VK_LEFT))
				{
					mCurrentAnimation->Stop();
					mCurrentAnimation = mLeftMoveAnimation;
					mCurrentAnimation->Play();
				}
			}
		}
	mCurrentAnimation->Update();
	if (mIsGetKeyNow)
	{
		mX += mSpeed * cosf(mAngle);
		mY -= mSpeed * sinf(mAngle);
		mRect = RectMakeCenter(mX, mY, mSizeX, mSizeY);

		

		if (mDustCount > 50)
		{
			Effect* dust = new Effect(mX, mRect.bottom-45, IMAGEMANAGER->FindImage(L"Dust_OverWolrd"));
			mDustCount = 0;
		}
	}
	else
	{
		SoundPlayer::GetInstance()->Stop(L"FootStep");
	}
	mDustCount++;
	mRect = RectMakeCenter(mX, mY, mSizeX, mSizeY);
}

void Cuphead_OverWorld::Render(HDC hdc)
{
	CameraManager::GetInstance()->GetMainCamera()->FrameRender(hdc, mImage, mX-mSizeX/2, mY-mSizeY/2, mCurrentAnimation->GetNowFrameX(), mCurrentAnimation->GetNowFrameY());
}
