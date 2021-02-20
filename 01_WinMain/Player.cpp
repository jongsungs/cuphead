#include "pch.h"
#include "Player.h"

#include "Image.h"
#include "Animation.h"
#include "Camera.h"
Player::Player(const string& name, float x, float y)
	:GameObject(name)
{
	mX = x;
	mY = y;
	
}
//

void Player::Init()
{
	mImage = IMAGEMANAGER->FindImage(L"Player");
	mImage2 = IMAGEMANAGER->FindImage(L"SideSword");
	mImage3 = IMAGEMANAGER->FindImage(L"UpdownSword");
	mImage4 = IMAGEMANAGER->FindImage(L"die");
	mImage5 = IMAGEMANAGER->FindImage(L"UpSword");
	mImage6 = IMAGEMANAGER->FindImage(L"DownSword");
	mImage7 = IMAGEMANAGER->FindImage(L"LeftSword");
	mImage8 = IMAGEMANAGER->FindImage(L"RightSword");

//가만히있는 상태
	mDownIdleAnimation = new Animation();
	mDownIdleAnimation->InitFrameByStartEnd(1, 0, 1, 0,false);
	mDownIdleAnimation->SetIsLoop(true);
	mDownIdleAnimation->SetFrameUpdateTime(0.3f);
	mDownIdleAnimation->Play();

	mUpIdleAnimation = new Animation();  
	mUpIdleAnimation->InitFrameByStartEnd(1, 3, 1, 3, false);
	mUpIdleAnimation->SetIsLoop(true);
	mUpIdleAnimation->SetFrameUpdateTime(0.3f);
	mUpIdleAnimation->Play(); 

	mLeftIdleAnimation = new Animation();
	mLeftIdleAnimation->InitFrameByStartEnd(1, 1, 1, 1, false);
	mLeftIdleAnimation->SetIsLoop(true);
	mLeftIdleAnimation->SetFrameUpdateTime(0.3f);
	mLeftIdleAnimation->Play();

	mRightIdleAnimation = new Animation();
	mRightIdleAnimation->InitFrameByStartEnd(1, 2, 1, 2, false);
	mRightIdleAnimation->SetIsLoop(true);
	mRightIdleAnimation->SetFrameUpdateTime(0.3f);
	mRightIdleAnimation->Play();
//걷기
	mDownRunAnimation = new Animation();
	mDownRunAnimation->InitFrameByStartEnd(0, 0, 2, 0, false);
	mDownRunAnimation->SetIsLoop(true);
	mDownRunAnimation->SetFrameUpdateTime(0.3f);

	mUpRunAnimation = new Animation();
	mUpRunAnimation->InitFrameByStartEnd(0, 3, 2, 3, false);
	mUpRunAnimation->SetIsLoop(true);
	mUpRunAnimation->SetFrameUpdateTime(0.3f);

	mLeftRunAnimation = new Animation();
	mLeftRunAnimation->InitFrameByStartEnd(0, 1, 2, 1, false);
	mLeftRunAnimation->SetIsLoop(true);
	mLeftRunAnimation->SetFrameUpdateTime(0.3f);

	mRightRunAnimation = new Animation();
	mRightRunAnimation->InitFrameByStartEnd(0, 2, 2, 2, false);
	mRightRunAnimation->SetIsLoop(true);
	mRightRunAnimation->SetFrameUpdateTime(0.3f);
// 공격
	mDownAttackAnimation = new Animation();
	mDownAttackAnimation->InitFrameByStartEnd(3, 0, 3, 0, true);
	mDownAttackAnimation->SetIsLoop(false);
	mDownAttackAnimation->SetFrameUpdateTime(0.3f);

	mUpAttackAnimation = new Animation();
	mUpAttackAnimation->InitFrameByStartEnd(3, 3, 3, 3, false);
	mUpAttackAnimation->SetIsLoop(false);
	mUpAttackAnimation->SetFrameUpdateTime(0.3f);

	mLeftAttackAnimation = new Animation();
	mLeftAttackAnimation->InitFrameByStartEnd(3, 1, 3, 1, false);
	mLeftAttackAnimation->SetIsLoop(false);
	mLeftAttackAnimation->SetFrameUpdateTime(0.3f);

	mRightAttackAnimation = new Animation();
	mRightAttackAnimation->InitFrameByStartEnd(3, 2, 3, 2, false);
	mRightAttackAnimation->SetIsLoop(false);
	mRightAttackAnimation->SetFrameUpdateTime(0.3f);
	//죽음
	mDieAnimation = new Animation();
	mDieAnimation->InitFrameByStartEnd(0, 0, 7, 0, false);
	mDieAnimation->SetIsLoop(true);
	mDieAnimation->SetFrameUpdateTime(0.3f);
	
	mIsAttackMode = 0;
	mFrameCt = 0;

	mCurrentAnimation = mDownIdleAnimation;
	mSizeX = mImage->GetFrameWidth()*5;
	mSizeY = mImage->GetFrameHeight()*5;
	mRect = RectMakeCenter(mX, mY, mSizeX, mSizeY);
	mHP = 3;
	//mUpdownSwordSizeX = mImage3->GetFrameWidth()*5;
	//mUpdownSwordSizeY = mImage3->GetFrameHeight()*5;
	//mUpdownSwordRect = RectMakeCenter(mX, mY, mUpdownSwordSizeX, mUpdownSwordSizeY);
	//mSideSwordSizeX = mImage2->GetFrameWidth()*5;
	//mSideSwordSizeY = mImage2->GetFrameHeight()*5;
	//mSideSwordRect = RectMakeCenter(mX, mY, mSideSwordSizeX, mSideSwordSizeY);
	mDownSwordSizeX = mImage6->GetFrameWidth() * 5;
	mDownSwordSizeY = mImage6->GetFrameHeight() * 5;
	mUpSwordSizeX = mImage5->GetFrameWidth() * 5;
	mUpSwordSizeY = mImage5->GetFrameHeight() * 5;
	mLeftSwordSizeX = mImage7->GetFrameWidth() * 5;
	mLeftSwordSizeY = mImage7->GetFrameHeight() * 5;
	mRightSwordSizeX = mImage8->GetFrameWidth() * 5;
	mRightSwordSizeY = mImage8->GetFrameHeight() * 5;
	
}

void Player::Release()
{
	SafeDelete(mDownIdleAnimation);
	SafeDelete(mUpIdleAnimation);
	SafeDelete(mLeftIdleAnimation);
	SafeDelete(mRightIdleAnimation);
	SafeDelete(mDownRunAnimation);
	SafeDelete(mUpRunAnimation);
	SafeDelete(mLeftRunAnimation);
	SafeDelete(mRightRunAnimation);
	SafeDelete(mDownAttackAnimation);
	SafeDelete(mUpAttackAnimation);
	SafeDelete(mLeftAttackAnimation);
	SafeDelete(mRightAttackAnimation);
	SafeDelete(mDownAttackAnimation);
	SafeDelete(mUpAttackAnimation);
	SafeDelete(mLeftAttackAnimation);
	SafeDelete(mRightAttackAnimation);
	SafeDelete(mDieAnimation);

}

void Player::Update()
{
	//오른쪽 이동
	if (Input::GetInstance()->GetKeyDown(VK_RIGHT))
	{
		mCurrentAnimation->Stop();
		mCurrentAnimation = mRightRunAnimation;
		mCurrentAnimation->Play();
	}
		if (Input::GetInstance()->GetKey(VK_RIGHT))
		{
			mX += 5;
			
		}
	if (Input::GetInstance()->GetKeyUp(VK_RIGHT))
	{
		mCurrentAnimation->Stop();
		mCurrentAnimation = mRightIdleAnimation;
		mCurrentAnimation->Play();
	}
	//왼쪽 이동
	if (Input::GetInstance()->GetKeyDown(VK_LEFT))
	{
		
		mCurrentAnimation->Stop();
		mCurrentAnimation = mLeftRunAnimation;
		mCurrentAnimation->Play();
	}
	if (Input::GetInstance()->GetKey(VK_LEFT))
	{
		mX -= 5;
	}
	if (Input::GetInstance()->GetKeyUp(VK_LEFT))
	{
		mCurrentAnimation->Stop();
		mCurrentAnimation = mLeftIdleAnimation;
		mCurrentAnimation->Play();
	}
	//위 위동
	if (Input::GetInstance()->GetKeyDown(VK_UP))
	{
		mCurrentAnimation->Stop();
		mCurrentAnimation = mUpRunAnimation;
		mCurrentAnimation->Play();
	}
	if (Input::GetInstance()->GetKey(VK_UP))
	{
		mY -= 5;
	}
	if (Input::GetInstance()->GetKeyUp(VK_UP))
	{
		mCurrentAnimation->Stop();
		mCurrentAnimation = mUpIdleAnimation;
		mCurrentAnimation->Play();
	}
	//아래 이동
	if (Input::GetInstance()->GetKeyDown(VK_DOWN))
	{
		mCurrentAnimation->Stop();
		mCurrentAnimation = mDownRunAnimation;
		mCurrentAnimation->Play();
	}
	if (Input::GetInstance()->GetKey(VK_DOWN))
	{
		mY += 5;
	}
	if (Input::GetInstance()->GetKeyUp(VK_DOWN))
	{
		mCurrentAnimation->Stop();
		mCurrentAnimation = mDownIdleAnimation;
		mCurrentAnimation->Play();
	}
	//아래공격
	if (mCurrentAnimation == mDownIdleAnimation || mCurrentAnimation == mDownRunAnimation || mCurrentAnimation == mDownAttackAnimation)
	{
		if (Input::GetInstance()->GetKeyDown(VK_SPACE))
		{
			mIsAttackMode = 1;
			mCurrentAnimation->Stop();
 			mCurrentAnimation = mDownAttackAnimation;
			mCurrentAnimation->Play();
			mUpdownSwordRect = RectMakeCenter(mX+20, mY+ mDownSwordSizeY+20, mDownSwordSizeX, mDownSwordSizeY);
			
		}

		if (Input::GetInstance()->GetKeyUp(VK_SPACE))
		{
			mCurrentAnimation->Stop();
			mCurrentAnimation = mDownIdleAnimation;
			mCurrentAnimation->Play();
			mUpdownSwordRect = RectMakeCenter(-1, -1, 2, 2);
		}
		
	}
	//위 공격
	if (mCurrentAnimation == mUpIdleAnimation || mCurrentAnimation == mUpRunAnimation || mCurrentAnimation == mUpAttackAnimation)
	{
		if (Input::GetInstance()->GetKeyDown(VK_SPACE))
		{
			mIsAttackMode = 1;
			mCurrentAnimation->Stop();
			mCurrentAnimation = mUpAttackAnimation;
			mCurrentAnimation->Play();
			mUpdownSwordRect = RectMakeCenter(mX -20, mY- mUpSwordSizeY-20, mUpSwordSizeX, mUpSwordSizeY);

		}

		if (Input::GetInstance()->GetKeyUp(VK_SPACE))
		{
			mCurrentAnimation->Stop();
			mCurrentAnimation = mUpIdleAnimation;
			mCurrentAnimation->Play();
			mUpdownSwordRect = RectMakeCenter(-1, -1, 2, 2);
		}
	}
	//왼쪽 공격
	if (mCurrentAnimation == mLeftIdleAnimation || mCurrentAnimation == mLeftRunAnimation || mCurrentAnimation == mLeftAttackAnimation)
	{
		if (Input::GetInstance()->GetKeyDown(VK_SPACE))
		{
			mIsAttackMode = 1;
			mCurrentAnimation->Stop();
			mCurrentAnimation = mLeftAttackAnimation;
			mCurrentAnimation->Play();
			mSideSwordRect = RectMakeCenter(mX- mLeftSwordSizeX, mY, mLeftSwordSizeX, mLeftSwordSizeY);

		}

		if (Input::GetInstance()->GetKeyUp(VK_SPACE))
		{
			mCurrentAnimation->Stop();
			mCurrentAnimation = mLeftIdleAnimation;
			mCurrentAnimation->Play();
			mSideSwordRect = RectMakeCenter(-1, -1, 2, 2);
		}
	}
	//오른쪽 공격
	if (mCurrentAnimation == mRightIdleAnimation || mCurrentAnimation == mRightRunAnimation || mCurrentAnimation == mRightAttackAnimation)
	{
		if (Input::GetInstance()->GetKeyDown(VK_SPACE))
		{
			mIsAttackMode = 1;
			mCurrentAnimation->Stop();
			mCurrentAnimation = mRightAttackAnimation;
			mCurrentAnimation->Play();
			mSideSwordRect = RectMakeCenter(mX+mRightSwordSizeX, mY, mRightSwordSizeX, mRightSwordSizeY);

		}

		if (Input::GetInstance()->GetKeyUp(VK_SPACE))
		{
			mCurrentAnimation->Stop();
			mCurrentAnimation = mRightIdleAnimation;
			mCurrentAnimation->Play();
			mSideSwordRect = RectMakeCenter(-1, -1, 2, 2);
		}
	}
	if (mHP <= 0)
	{
		mCurrentAnimation = mDieAnimation;
		mCurrentAnimation->Play();
	}
		//if (mIsAttackMode)
		//{
		//	mFrameCt++;
		//	mCurrentAnimation->Stop();
		//	mCurrentAnimation = mDownAttackAnimation;
		//	mCurrentAnimation->Play();
		//	if (mFrameCt > 20)
		//	{
		//		mIsAttackMode = 0;
		//		mFrameCt = 0;
		//	}
		//}
		//else
		//{
		//	//mCurrentAnimation->Stop();
		//	mCurrentAnimation = mDownIdleAnimation;
		//	mCurrentAnimation->Play();
		//}
	

	mRect = RectMakeCenter(mX, mY, mSizeX, mSizeY);

	mCurrentAnimation->Update();
}

void Player::Render(HDC hdc)
{
	//RenderRect(hdc, Player::GetRect());
	//CameraManager::GetInstance()->GetMainCamera()
	//	->FrameRender(hdc, mImage, mRect.left, mRect.top,
	//		mCurrentAnimation->GetNowFrameX(),
	//		mCurrentAnimation->GetNowFrameY());
	CameraManager::GetInstance()->GetMainCamera()->RenderRect(hdc, mRect);
	CameraManager::GetInstance()->GetMainCamera()->ScaleFrameRender(hdc,mImage,mRect.left,mRect.top, mCurrentAnimation->GetNowFrameX(),
		mCurrentAnimation->GetNowFrameY(),80,120);
	//죽음
	if (mCurrentAnimation == mDieAnimation)
	{
		CameraManager::GetInstance()->GetMainCamera()->ScaleFrameRender(hdc,mImage4, mRect.left, mRect.top, mCurrentAnimation->GetNowFrameX(), mCurrentAnimation->GetNowFrameY(), 80, 120);
	}
	//mImage2->Render(hdc, mSideSwordSizeX, mSideSwordSizeY);
	//mImage3->FrameRender(hdc, mRect.left, mRect.top, mCurrentAnimation->GetNowFrameX(),
	//	mCurrentAnimation->GetNowFrameY());
	//mImage4->FrameRender(hdc, mRect.left, mRect.top, mCurrentAnimation->GetNowFrameX(),
	//	mCurrentAnimation->GetNowFrameY());
	if (mCurrentAnimation == mUpAttackAnimation)
		CameraManager::GetInstance()->GetMainCamera()->ScaleRender(hdc,mImage5, mX-40 , mY - mUpSwordSizeY-60,35,75);
	if (mCurrentAnimation == mDownAttackAnimation)
		CameraManager::GetInstance()->GetMainCamera()->ScaleRender(hdc, mImage6, mX , mY + mDownSwordSizeY-20,35,75);
	if (mCurrentAnimation == mLeftAttackAnimation)
		CameraManager::GetInstance()->GetMainCamera()->ScaleRender(hdc, mImage7, mX - mLeftSwordSizeX-40, mY-20,75,35);
	if (mCurrentAnimation == mRightAttackAnimation)
		CameraManager::GetInstance()->GetMainCamera()->ScaleRender(hdc, mImage8, mX + mRightSwordSizeX -40, mY-20,75,35);

}
