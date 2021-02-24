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
	mImage = IMAGEMANAGER->FindImage(L"PlatformerPlayerIdle");
	mGround = RectMake(0, 620, 3000, 200);
	mX = WINSIZEX / 4;
	mY = 300;
	mRect = RectMakeCenter(mX, mY, 98, 155);
	mGravity = 0.1f;
	mJumpPower = 0.f;
	mPlayerState = PlayerState::RightIdle;


	mCurrentAnimation = new Animation();
	mCurrentAnimation->InitFrameByStartEnd(0, 0, 4, 0, false);
	mCurrentAnimation->SetIsLoop(true);
	mCurrentAnimation->SetFrameUpdateTime(0.1f);

	mCurrentAnimation->Play();
	
	//아이들

	mRightIdleAnimation = new Animation();
	mRightIdleAnimation
		->InitFrameByStartEnd(0, 0, 4, 0, true);
	mRightIdleAnimation
		->SetIsLoop(true);
	mRightIdleAnimation
		->SetFrameUpdateTime(0.1f);
	mRightIdleAnimation
		->Play();

	mLeftIdleAnimation = new Animation();
	mLeftIdleAnimation
		->InitFrameByBackStartEnd(4, 1, 0, 1, true);
	mLeftIdleAnimation
		->SetIsLoop(true);
	mLeftIdleAnimation
		->SetFrameUpdateTime(0.1f);
	mLeftIdleAnimation
		->Play();
	//대쉬

	mRightDashAnimation = new Animation();
	mRightDashAnimation
		->InitFrameByStartEnd(0, 0, 7, 0, false);
	mRightDashAnimation
		->SetIsLoop(false);
	mRightDashAnimation
		->SetFrameUpdateTime(0.1f);
	mRightDashAnimation
		->Play();

	mLeftDashAnimation = new Animation();
	mLeftDashAnimation
		->InitFrameByBackStartEnd(7, 1, 0, 1, false);
	mLeftDashAnimation
		->SetIsLoop(false);
	mLeftDashAnimation
		->SetFrameUpdateTime(0.1f);
	mLeftDashAnimation
		->Play();
	//죽음

	mDieAnimation = new Animation();
	mDieAnimation
		->InitFrameByStartEnd(0, 0, 15, 0, false);
	mDieAnimation
		->SetIsLoop(false);
	mDieAnimation
		->SetFrameUpdateTime(0.1f);
	mDieAnimation
		->Play();
	//덕 아이들

	mRightDuckIdleAnimation = new Animation();
	mRightDuckIdleAnimation
		->InitFrameByStartEnd(2, 0, 12, 0, false);
	mRightDuckIdleAnimation
		->SetIsLoop(true);
	mRightDuckIdleAnimation
		->SetFrameUpdateTime(0.1f);
	mRightDuckIdleAnimation
		->Play();

	mLeftDuckIdleAnimation = new Animation();
	mLeftDuckIdleAnimation
		->InitFrameByBackStartEnd(10, 1, 0, 1, false);
	mLeftDuckIdleAnimation
		->SetIsLoop(true);
	mLeftDuckIdleAnimation
		->SetFrameUpdateTime(0.1f);
	mLeftDuckIdleAnimation
		->Play();
	//덕

	mRightDuckAnimation = new Animation();
	mRightDuckAnimation
		->InitFrameByStartEnd(0, 0, 1, 0, false);
	mRightDuckAnimation
		->SetIsLoop(false);
	mRightDuckAnimation
		->SetFrameUpdateTime(0.1f);
	mRightDuckAnimation
		->Play();

	mLeftDuckAnimation = new Animation();
	mLeftDuckAnimation
		->InitFrameByBackStartEnd(12, 1, 11, 1, false);
	mLeftDuckAnimation
		->SetIsLoop(false);
	mLeftDuckAnimation
		->SetFrameUpdateTime(0.1f);
	mLeftDuckAnimation
		->Play();
	//덕샷

	mRightDuckShootAnimation = new Animation();
	mRightDuckShootAnimation
		->InitFrameByStartEnd(0, 0, 5, 0, false);
	mRightDuckShootAnimation
		->SetIsLoop(false);
	mRightDuckShootAnimation
		->SetFrameUpdateTime(0.1f);
	mRightDuckShootAnimation
		->Play();

	mLeftDuckShootAnimation = new Animation();
	mLeftDuckShootAnimation
		->InitFrameByBackStartEnd(5, 1, 0, 0, false);
	mLeftDuckShootAnimation
		->SetIsLoop(false);
	mLeftDuckShootAnimation
		->SetFrameUpdateTime(0.1f);
	mLeftDuckShootAnimation
		->Play();
	//피격

	mRightHitAnimation = new Animation();
	mRightHitAnimation
		->InitFrameByStartEnd(0, 0, 5, 0, false);
	mRightHitAnimation
		->SetIsLoop(false);
	mRightHitAnimation
		->SetFrameUpdateTime(0.1f);
	mRightHitAnimation
		->Play();

	mLeftHitAnimation = new Animation();
	mLeftHitAnimation
		->InitFrameByBackStartEnd(5, 1, 0, 1, false);
	mLeftHitAnimation
		->SetIsLoop(false);
	mLeftHitAnimation
		->SetFrameUpdateTime(0.1f);
	mLeftHitAnimation
		->Play();
	//필살기

	mRightSpecialAttackAnimation = new Animation();
	mRightSpecialAttackAnimation
		->InitFrameByStartEnd(0, 1, 12, 1, false);
	mRightSpecialAttackAnimation
		->SetIsLoop(false);
	mRightSpecialAttackAnimation
		->SetFrameUpdateTime(0.1f);
	mRightSpecialAttackAnimation
		->Play();

	mLeftSpecialAttackAnimation = new Animation();
	mLeftSpecialAttackAnimation
		->InitFrameByBackStartEnd(12, 1, 0, 1, false);
	mLeftSpecialAttackAnimation
		->SetIsLoop(false);
	mLeftSpecialAttackAnimation
		->SetFrameUpdateTime(0.1f);
	mLeftSpecialAttackAnimation
		->Play();

	mUpSpecialAttackAnimation = new Animation();
	mUpSpecialAttackAnimation
		->InitFrameByStartEnd(0, 0, 12, 0, false);
	mUpSpecialAttackAnimation
		->SetIsLoop(false);
	mUpSpecialAttackAnimation
		->SetFrameUpdateTime(0.1f);
	mUpSpecialAttackAnimation
		->Play();
	//점프

	mRightJumpAnimation = new Animation();
	mRightJumpAnimation
		->InitFrameByStartEnd(0, 0, 7, 0, false);
	mRightJumpAnimation
		->SetIsLoop(true);
	mRightJumpAnimation
		->SetFrameUpdateTime(0.1f);
	mRightJumpAnimation
		->Play();

	mLeftJumpAnimation = new Animation();
	mLeftJumpAnimation
		->InitFrameByBackStartEnd(7, 1, 0, 1, false);
	mLeftJumpAnimation
		->SetIsLoop(true);
	mLeftJumpAnimation
		->SetFrameUpdateTime(0.1f);
	mLeftJumpAnimation
		->Play();
	//달리기

	mRightRunAnimation = new Animation();
	mRightRunAnimation
		->InitFrameByStartEnd(0, 0, 15, 0, false);
	mRightRunAnimation
		->SetIsLoop(true);
	mRightRunAnimation
		->SetFrameUpdateTime(0.1f);
	mRightRunAnimation
		->Play();

	mLeftRunAnimation = new Animation();
	mLeftRunAnimation
		->InitFrameByBackStartEnd(17, 1, 2, 1, false);
	mLeftRunAnimation
		->SetIsLoop(true);
	mLeftRunAnimation
		->SetFrameUpdateTime(0.1f);
	mLeftRunAnimation
		->Play();

	mRightRunturnAnimation = new Animation();
	mRightRunturnAnimation
		->InitFrameByStartEnd(16, 0, 17, 0, false);
	mRightRunturnAnimation
		->SetIsLoop(false);
	mRightRunturnAnimation
		->SetFrameUpdateTime(0.1f);
	mRightRunturnAnimation
		->Play();

	mLeftRunturnAnimation = new Animation();
	mLeftRunturnAnimation
		->InitFrameByBackStartEnd(1, 1, 0, 1, false);
	mLeftRunturnAnimation
		->SetIsLoop(false);
	mLeftRunturnAnimation
		->SetFrameUpdateTime(0.1f);
	mLeftRunturnAnimation
		->Play();
	//달리면서 쏘기

	mRightRunShootAnimation = new Animation();
	mRightRunShootAnimation
		->InitFrameByStartEnd(0, 0, 15, 0, false);
	mRightRunShootAnimation
		->SetIsLoop(false);
	mRightRunShootAnimation
		->SetFrameUpdateTime(0.1f);
	mRightRunShootAnimation
		->Play();

	mLeftRunShootAnimation = new Animation();
	mLeftRunShootAnimation
		->InitFrameByBackStartEnd(17, 1, 2, 1, false);
	mLeftRunShootAnimation
		->SetIsLoop(false);
	mLeftRunShootAnimation
		->SetFrameUpdateTime(0.1f);
	mLeftRunShootAnimation
		->Play();

	mRightRunShootturnAnimation = new Animation();
	mRightRunShootturnAnimation
		->InitFrameByStartEnd(16, 0, 17, 0, false);
	mRightRunShootturnAnimation
		->SetIsLoop(false);
	mRightRunShootturnAnimation
		->SetFrameUpdateTime(0.1f);
	mRightRunShootturnAnimation
		->Play();

	mLeftRunShootturnAnimation = new Animation();
	mLeftRunShootturnAnimation
		->InitFrameByBackStartEnd(1, 1, 0, 1, false);
	mLeftRunShootturnAnimation
		->SetIsLoop(false);
	mLeftRunShootturnAnimation
		->SetFrameUpdateTime(0.1f);
	mLeftRunShootturnAnimation
		->Play();

	mRightRunDiagonalUpShootAnimation = new Animation();
	mRightRunDiagonalUpShootAnimation
		->InitFrameByStartEnd(2, 0, 17, 0, false);
	mRightRunDiagonalUpShootAnimation
		->SetIsLoop(true);
	mRightRunDiagonalUpShootAnimation
		->SetFrameUpdateTime(0.1f);
	mRightRunDiagonalUpShootAnimation
		->Play();

	mLeftRunDiagonalUpShootAnimation = new Animation();
	mLeftRunDiagonalUpShootAnimation
		->InitFrameByBackStartEnd(15, 1, 0, 1, false);
	mLeftRunDiagonalUpShootAnimation
		->SetIsLoop(true);
	mLeftRunDiagonalUpShootAnimation
		->SetFrameUpdateTime(0.1f);
	mLeftRunDiagonalUpShootAnimation
		->Play();

	mRightRunDiagonalUpShootturnAnimation = new Animation();
	mRightRunDiagonalUpShootturnAnimation
		->InitFrameByStartEnd(0, 0, 1, 0, false);
	mRightRunDiagonalUpShootturnAnimation
		->SetIsLoop(false);
	mRightRunDiagonalUpShootturnAnimation
		->SetFrameUpdateTime(0.1f);
	mRightRunDiagonalUpShootturnAnimation
		->Play();

	mLeftRunDiagonalUpShootturnAnimation = new Animation();
	mLeftRunDiagonalUpShootturnAnimation
		->InitFrameByBackStartEnd(17, 1, 16, 0, false);
	mLeftRunDiagonalUpShootturnAnimation
		->SetIsLoop(false);
	mLeftRunDiagonalUpShootturnAnimation
		->SetFrameUpdateTime(0.1f);
	mLeftRunDiagonalUpShootturnAnimation
		->Play();
	//제자리 발사

	mRightShootAnimation = new Animation();
	mRightShootAnimation
		->InitFrameByStartEnd(0, 0, 5, 0, false);
	mRightShootAnimation
		->SetIsLoop(false);
	mRightShootAnimation
		->SetFrameUpdateTime(0.1f);
	mRightShootAnimation
		->Play();

	mLeftShootAnimation = new Animation();
	mLeftShootAnimation
		->InitFrameByBackStartEnd(5, 1, 0, 1, false);
	mLeftShootAnimation
		->SetIsLoop(false);
	mLeftShootAnimation
		->SetFrameUpdateTime(0.1f);
	mLeftShootAnimation
		->Play();

	mRightUpShootAnimation = new Animation();
	mRightUpShootAnimation
		->InitFrameByStartEnd(0, 0, 5, 0, false);
	mRightUpShootAnimation
		->SetIsLoop(false);
	mRightUpShootAnimation
		->SetFrameUpdateTime(0.1f);
	mRightUpShootAnimation
		->Play();

	mLeftUpShootAnimation = new Animation();
	mLeftUpShootAnimation
		->InitFrameByBackStartEnd(5, 1, 0, 1, false);
	mLeftUpShootAnimation
		->SetIsLoop(false);
	mLeftUpShootAnimation
		->SetFrameUpdateTime(0.1f);
	mLeftUpShootAnimation
		->Play();

	mRightDiagonalUpShootAnimation = new Animation();
	mRightDiagonalUpShootAnimation
		->InitFrameByStartEnd(0, 0, 5, 0, false);
	mRightDiagonalUpShootAnimation
		->SetIsLoop(false);
	mRightDiagonalUpShootAnimation
		->SetFrameUpdateTime(0.1f);
	mRightDiagonalUpShootAnimation
		->Play();

	mLeftDiagonalUpShootAnimation = new Animation();
	mLeftDiagonalUpShootAnimation
		->InitFrameByBackStartEnd(5, 1, 0, 1, false);
	mLeftDiagonalUpShootAnimation
		->SetIsLoop(false);
	mLeftDiagonalUpShootAnimation
		->SetFrameUpdateTime(0.1f);
	mLeftDiagonalUpShootAnimation
		->Play();

	//패링

	mRightParringAnimation = new Animation();
	mRightParringAnimation
		->InitFrameByStartEnd(0, 0, 7, 0, false);
	mRightParringAnimation
		->SetIsLoop(false);
	mRightParringAnimation
		->SetFrameUpdateTime(0.1f);
	mRightParringAnimation
		->Play();

	mLeftParringAnimation = new Animation();
	mLeftParringAnimation
		->InitFrameByBackStartEnd(7, 1, 0, 1, false);
	mLeftParringAnimation
		->SetIsLoop(false);
	mLeftParringAnimation
		->SetFrameUpdateTime(0.1f);
	mLeftParringAnimation
		->Play();

	mRightUpaimAnimation = new Animation();
	mRightUpaimAnimation->InitFrameByStartEnd(0, 0, 4, 0, false);
	mRightUpaimAnimation->SetIsLoop(false);
	mRightUpaimAnimation->SetFrameUpdateTime(0.1f);
	mRightUpaimAnimation->Play();

	mLeftUpaimAnimation = new Animation();
	mLeftUpaimAnimation->InitFrameByBackStartEnd(4, 1, 0, 1, false);
	mLeftUpaimAnimation->SetIsLoop(false);
	mLeftUpaimAnimation->SetFrameUpdateTime(0.1f);
	mLeftUpaimAnimation->Play();

}

void PlatformerPlayer::Release()
{
	SafeDelete(mRightIdleAnimation);
	SafeDelete(mLeftIdleAnimation);
	SafeDelete(mLeftDuckIdleAnimation);
	SafeDelete(mRightDuckIdleAnimation);
	SafeDelete(mRightRunAnimation);
	SafeDelete(mRightRunturnAnimation);
	SafeDelete(mLeftRunAnimation);
	SafeDelete(mLeftRunturnAnimation);
	SafeDelete(mLeftJumpAnimation);
	SafeDelete(mRightJumpAnimation);
	SafeDelete(mRightDuckAnimation);
	SafeDelete(mLeftDuckAnimation);
	SafeDelete(mRightDuckShootAnimation);
	SafeDelete(mLeftDuckShootAnimation);
	SafeDelete(mRightShootAnimation);
	SafeDelete(mRightUpShootAnimation);
	SafeDelete(mRightDiagonalUpShootAnimation);
	SafeDelete(mLeftShootAnimation);
	SafeDelete(mLeftUpShootAnimation);
	SafeDelete(mLeftDiagonalUpShootAnimation);
	SafeDelete(mLeftRunShootAnimation);
	SafeDelete(mLeftRunShootturnAnimation);
	SafeDelete(mLeftRunDiagonalUpShootAnimation);
	SafeDelete(mLeftRunDiagonalUpShootturnAnimation);
	SafeDelete(mRightRunShootAnimation);
	SafeDelete(mRightRunShootturnAnimation);
	SafeDelete(mRightRunDiagonalUpShootAnimation);
	SafeDelete(mRightRunDiagonalUpShootturnAnimation);
	SafeDelete(mRightSpecialAttackAnimation);
	SafeDelete(mLeftSpecialAttackAnimation);
	SafeDelete(mUpSpecialAttackAnimation);
	SafeDelete(mRightHitAnimation);
	SafeDelete(mLeftHitAnimation);
	SafeDelete(mLeftDashAnimation);
	SafeDelete(mRightDashAnimation);
	SafeDelete(mDieAnimation);
	SafeDelete(mRightParringAnimation);
	SafeDelete(mLeftParringAnimation);
	SafeDelete(mLeftUpaimAnimation);
	SafeDelete(mRightUpaimAnimation);
	

}

void PlatformerPlayer::Update()
{
	
	
	
	
	//왼쪽으로 달릴때
	if (Input::GetInstance()->GetKeyDown(VK_LEFT))
	{
		mCurrentAnimation->Stop();
		mPlayerState = PlayerState::LeftRun;
		mCurrentAnimation = mLeftRunAnimation;
		mCurrentAnimation->Play();
	}
	if (Input::GetInstance()->GetKey(VK_LEFT))
	{
		mX -= 1;
		if (Input::GetInstance()->GetKey(VK_UP))
		{
			if (Input::GetInstance()->GetKeyDown('X'))
			{
				mPlayerState = PlayerState::LeftRunDiagonalUpShoot;
				if (mCurrentAnimation != mLeftRunDiagonalUpShootAnimation)
				{
					mCurrentAnimation->Stop();
					mCurrentAnimation = mLeftRunDiagonalUpShootAnimation;
				}
				mCurrentAnimation->Play();
			}
		}
		if (Input::GetInstance()->GetKeyDown('Z'))
		{
			mJumpPower = 5.f;
			mCurrentAnimation->Stop();
			mPlayerState = PlayerState::LeftJump;
			mCurrentAnimation = mLeftJumpAnimation;
			mCurrentAnimation->Play();
		}
		if (Input::GetInstance()->GetKeyDown('V'))
		{
			mX += 0.5f;
			mCurrentAnimation->Stop();
			mPlayerState = PlayerState::LeftSpecialAttack;
			mCurrentAnimation->Play();
		}
	}
	if (Input::GetInstance()->GetKeyUp(VK_LEFT))
	{
		mCurrentAnimation->Stop();
		mPlayerState = PlayerState::LeftIdle;
		mCurrentAnimation = mLeftIdleAnimation;
		mCurrentAnimation->Play();
	}
	//오른쪽으로 달릴때
	if (Input::GetInstance()->GetKeyDown(VK_RIGHT))
	{
		mCurrentAnimation->Stop();
		mPlayerState = PlayerState::RightRun;
		mCurrentAnimation = mRightRunAnimation;
		mCurrentAnimation->Play();
	}
	//달리면서 업샷 및 점프
	if (Input::GetInstance()->GetKey(VK_RIGHT))
	{
		mX += 1;
		if (Input::GetInstance()->GetKey(VK_UP))
		{
			if (Input::GetInstance()->GetKeyDown('X'))
			{
				mPlayerState = PlayerState::RightRunDiagonalUpShoot;
				if (mCurrentAnimation != mRightRunDiagonalUpShootAnimation) {
					mCurrentAnimation->Stop();
					mCurrentAnimation = mRightRunDiagonalUpShootAnimation;
				}
				mCurrentAnimation->Play();
			}

		}
		if (Input::GetInstance()->GetKeyDown('Z'))
		{
			mJumpPower = 5.f;
			mCurrentAnimation->Stop();
			mPlayerState = PlayerState::RightJump;
			mCurrentAnimation = mRightJumpAnimation;
			mCurrentAnimation->Play();
			
		}
	}
	if ( Input::GetInstance()->GetKeyUp(VK_RIGHT))
	{
		mCurrentAnimation->Stop();
		mPlayerState = PlayerState::RightIdle;
		mCurrentAnimation = mRightIdleAnimation;
		mCurrentAnimation->Play();
	}
	//if (Input::GetInstance()->GetKey(VK_SPACE))
	//{
	//	Bullet* bullet = new Bullet();
	//	bullet->Init();
	//	mBullet.push_back(bullet);
	//}
	mRect = RectMakeCenter(mX, mY, 98, 155);
	//중력
	//mJumpPower -= mGravity;
	//mY -= mJumpPower;
	if (mY<= WINSIZEY)
	{
		mY = WINSIZEY - 180;
	}
	


	//mCurrentAnimation->Update();
	for (int i = 0; i < mBullet.size(); i++)
	{
		mBullet[i]->Update();
	}
	
	mCurrentAnimation->Update();
	if (mPlayerState == PlayerState::RightIdle)
	{
		mImage = IMAGEMANAGER->FindImage(L"PlatformerPlayerIdle");
	}
	if (mPlayerState == PlayerState::LeftIdle)
	{
		mImage = IMAGEMANAGER->FindImage(L"PlatformerPlayerIdle");
	}
	if (mPlayerState == PlayerState::RightDash)
	{
		mImage = IMAGEMANAGER->FindImage(L"Dash");
	}
	if (mPlayerState == PlayerState::LeftDash)
	{
		mImage = IMAGEMANAGER->FindImage(L"Dash");
	}
	if (mPlayerState == PlayerState::Die)
	{
		mImage = IMAGEMANAGER->FindImage(L"Die");
	}
	if (mPlayerState == PlayerState::RightDuckIdle)
	{
		mImage = IMAGEMANAGER->FindImage(L"Duckidle");
	}
	if (mPlayerState == PlayerState::LeftDuckIdle)
	{
		mImage = IMAGEMANAGER->FindImage(L"Duckidle");
	}
	if (mPlayerState == PlayerState::RightDuck)
	{
		mImage = IMAGEMANAGER->FindImage(L"Duckidle");
	}
	if (mPlayerState == PlayerState::LeftDuck)
	{
		mImage = IMAGEMANAGER->FindImage(L"Duckidle");
	}
	if (mPlayerState == PlayerState::RightDuckShoot)
	{
		mImage = IMAGEMANAGER->FindImage(L"DuckShoot");
	}
	if (mPlayerState == PlayerState::LeftDuckShoot)
	{
		mImage = IMAGEMANAGER->FindImage(L"DuckShoot");
	}
	if (mPlayerState == PlayerState::RightHit)
	{
		mImage = IMAGEMANAGER->FindImage(L"Groundhit");
	}
	if (mPlayerState == PlayerState::LeftHit)
	{
		mImage = IMAGEMANAGER->FindImage(L"Groundhit");
	}
	if (mPlayerState == PlayerState::RightSpecialAttack)
	{
		mImage = IMAGEMANAGER->FindImage(L"GroundSpecialAttack");
	}
	if (mPlayerState == PlayerState::LeftSpecialAttack)
	{
		mImage = IMAGEMANAGER->FindImage(L"GroundSpecialAttack");
	}
	if (mPlayerState == PlayerState::UpSpecialAttack)
	{
		mImage = IMAGEMANAGER->FindImage(L"UpSpecialAttack");
	}
	if (mPlayerState == PlayerState::RightJump)
	{
		mImage = IMAGEMANAGER->FindImage(L"Jump");
	}
	if (mPlayerState == PlayerState::LeftJump)
	{
		mImage = IMAGEMANAGER->FindImage(L"Jump");
	}
	if (mPlayerState == PlayerState::RightRun)
	{
		mImage = IMAGEMANAGER->FindImage(L"Run");
	}
	if (mPlayerState == PlayerState::LeftRun)
	{
		mImage = IMAGEMANAGER->FindImage(L"Run");
	}
	if (mPlayerState == PlayerState::RightRunturn)
	{
		mImage = IMAGEMANAGER->FindImage(L"Run");
	}
	if (mPlayerState == PlayerState::LeftRunturn)
	{
		mImage = IMAGEMANAGER->FindImage(L"Run");
	}
	if (mPlayerState == PlayerState::RightRunShoot)
	{
		mImage = IMAGEMANAGER->FindImage(L"RunShoot");
	}
	if (mPlayerState == PlayerState::LeftRunShoot)
	{
		mImage = IMAGEMANAGER->FindImage(L"RunShoot");
	}
	if (mPlayerState == PlayerState::RightRunShootturn)
	{
		mImage = IMAGEMANAGER->FindImage(L"RunShoot");
	}
	if (mPlayerState == PlayerState::LeftRunShootturn)
	{
		mImage = IMAGEMANAGER->FindImage(L"RunShoot");
	}
	if (mPlayerState == PlayerState::RightRunDiagonalUpShoot)
	{
		mImage = IMAGEMANAGER->FindImage(L"RunDiagonalShoot");
	}
	if (mPlayerState == PlayerState::LeftRunDiagonalUpShoot)
	{
		mImage = IMAGEMANAGER->FindImage(L"RunDiagonalShoot");
	}
	if (mPlayerState == PlayerState::RightRunDiagonalUpShootturn)
	{
		mImage = IMAGEMANAGER->FindImage(L"RunDiagonalShoot");
	}
	if (mPlayerState == PlayerState::LeftRunDiagonalUpShootturn)
	{
		mImage = IMAGEMANAGER->FindImage(L"RunDiagonalShoot");
	}
	if (mPlayerState == PlayerState::RightShoot)
	{
		mImage = IMAGEMANAGER->FindImage(L"StraightShoot");
	}
	if (mPlayerState == PlayerState::LeftShoot)
	{
		mImage = IMAGEMANAGER->FindImage(L"StraightShoot");
	}
	if (mPlayerState == PlayerState::RightUpShoot)
	{
		mImage = IMAGEMANAGER->FindImage(L"UpShoot");
	}
	if (mPlayerState == PlayerState::LeftUpShoot)
	{
		mImage = IMAGEMANAGER->FindImage(L"UpShoot");
	}
	if (mPlayerState == PlayerState::RightDiagonalUpShoot)
	{
		mImage = IMAGEMANAGER->FindImage(L"DiagonalUp");
	}
	if (mPlayerState == PlayerState::LeftDiagonalUpShoot)
	{
		mImage = IMAGEMANAGER->FindImage(L"DiagonalUp");
	}
	if (mPlayerState == PlayerState::RightParring)
	{
		mImage = IMAGEMANAGER->FindImage(L"Parring");
	}
	if (mPlayerState == PlayerState::LeftParring)
	{
		mImage = IMAGEMANAGER->FindImage(L"Parring");
	}
	if (mPlayerState == PlayerState::RightUpaim)
	{
		mImage = IMAGEMANAGER->FindImage(L"Upaim");
	}
	if (mPlayerState == PlayerState::LeftUpaim)
	{
		mImage = IMAGEMANAGER->FindImage(L"Upaim");
	}
}

void PlatformerPlayer::Render(HDC hdc)
{
	
	//CameraManager::GetInstance()->GetMainCamera()->RenderRect(hdc, mRect);
	////죽음
	//if (mCurrentAnimation == mDieAnimation)
	//{
	//	CameraManager::GetInstance()->GetMainCamera()->ScaleFrameRender(hdc, mImage4, mRect.left, mRect.top, mCurrentAnimation->GetNowFrameX(), mCurrentAnimation->GetNowFrameY(), 80, 120);
	//}
	RenderRect(hdc, mRect);
	mImage->FrameRender(hdc,mRect.left, mRect.top, mCurrentAnimation->GetNowFrameX(), mCurrentAnimation->GetNowFrameY());

	//RenderRect(hdc, mGround);
	for (int i = 0; i < mBullet.size(); ++i)
	{
		mBullet[i]->Render(hdc);
	}
	

}
