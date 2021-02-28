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

	mRect = RectMakeCenter(mX, mY, 98, 155);
	mGravity = 0.3f;
	mJumpPower = 0.f;
	mPlayerState = PlayerState::RightIdle;
	mHP = 3;
	isMove = true;
	bulletdelay = 0;
	mJumpStack = 0;
	mDashStack = 0;
	mSpcialAttackStack = 0;
	mParringStack = 0;
	SoundDelay = 0;


	mCurrentAnimation = new Animation();
	mCurrentAnimation->InitFrameByStartEnd(0, 0, 4, 0, false);
	mCurrentAnimation->SetIsLoop(true);
	mCurrentAnimation->SetFrameUpdateTime(PlatPlayerAnimationTime);
	mCurrentAnimation->Play();

	//아이들

	mRightIdleAnimation = new Animation();
	mRightIdleAnimation
		->InitFrameByStartEnd(0, 0, 4, 0, true);
	mRightIdleAnimation
		->SetIsLoop(true);
	mRightIdleAnimation
		->SetFrameUpdateTime(PlatPlayerAnimationTime);
	mRightIdleAnimation
		->Play();

	mLeftIdleAnimation = new Animation();
	mLeftIdleAnimation
		->InitFrameByBackStartEnd(4, 1, 0, 1, true);
	mLeftIdleAnimation
		->SetIsLoop(true);
	mLeftIdleAnimation
		->SetFrameUpdateTime(PlatPlayerAnimationTime);
	mLeftIdleAnimation
		->Play();
	//대쉬

	mRightDashAnimation = new Animation();
	mRightDashAnimation
		->InitFrameByStartEnd(0, 0, 7, 0, false);
	mRightDashAnimation
		->SetIsLoop(false);
	mRightDashAnimation
		->SetFrameUpdateTime(PlatPlayerAnimationTime);
	mRightDashAnimation
		->Play();

	mLeftDashAnimation = new Animation();
	mLeftDashAnimation
		->InitFrameByBackStartEnd(7, 1, 0, 1, false);
	mLeftDashAnimation
		->SetIsLoop(false);
	mLeftDashAnimation
		->SetFrameUpdateTime(PlatPlayerAnimationTime);
	mLeftDashAnimation
		->Play();
	//죽음

	mDieAnimation = new Animation();
	mDieAnimation
		->InitFrameByStartEnd(0, 0, 15, 0, false);
	mDieAnimation
		->SetIsLoop(false);
	mDieAnimation
		->SetFrameUpdateTime(PlatPlayerAnimationTime);
	mDieAnimation
		->Play();
	//덕 아이들

	mRightDuckIdleAnimation = new Animation();
	mRightDuckIdleAnimation
		->InitFrameByStartEnd(2, 0, 11, 0, false);
	mRightDuckIdleAnimation
		->SetIsLoop(true);
	mRightDuckIdleAnimation
		->SetFrameUpdateTime(PlatPlayerAnimationTime);
	mRightDuckIdleAnimation
		->Play();

	mLeftDuckIdleAnimation = new Animation();
	mLeftDuckIdleAnimation
		->InitFrameByBackStartEnd(10, 1, 1, 1, false);
	mLeftDuckIdleAnimation
		->SetIsLoop(true);
	mLeftDuckIdleAnimation
		->SetFrameUpdateTime(PlatPlayerAnimationTime);
	mLeftDuckIdleAnimation
		->Play();
	//덕

	mRightDuckAnimation = new Animation();
	mRightDuckAnimation
		->InitFrameByStartEnd(0, 0, 1, 0, false);
	mRightDuckAnimation
		->SetIsLoop(false);
	mRightDuckAnimation
		->SetFrameUpdateTime(PlatPlayerAnimationTime);
	mRightDuckAnimation
		->Play();

	mLeftDuckAnimation = new Animation();
	mLeftDuckAnimation
		->InitFrameByBackStartEnd(12, 1, 11, 1, false);
	mLeftDuckAnimation
		->SetIsLoop(false);
	mLeftDuckAnimation
		->SetFrameUpdateTime(PlatPlayerAnimationTime);
	mLeftDuckAnimation
		->Play();
	//덕샷

	mRightDuckShootAnimation = new Animation();
	mRightDuckShootAnimation
		->InitFrameByStartEnd(0, 0, 5, 0, false);
	mRightDuckShootAnimation
		->SetIsLoop(true);
	mRightDuckShootAnimation
		->SetFrameUpdateTime(PlatPlayerShootAnimationTime);
	mRightDuckShootAnimation
		->Play();

	mLeftDuckShootAnimation = new Animation();
	mLeftDuckShootAnimation
		->InitFrameByBackStartEnd(5, 1, 0, 1, false);
	mLeftDuckShootAnimation
		->SetIsLoop(true);
	mLeftDuckShootAnimation
		->SetFrameUpdateTime(PlatPlayerShootAnimationTime);
	mLeftDuckShootAnimation
		->Play();
	//피격

	mRightHitAnimation = new Animation();
	mRightHitAnimation
		->InitFrameByStartEnd(0, 0, 5, 0, false);
	mRightHitAnimation
		->SetIsLoop(false);
	mRightHitAnimation
		->SetFrameUpdateTime(PlatPlayerAnimationTime);
	mRightHitAnimation
		->Play();

	mLeftHitAnimation = new Animation();
	mLeftHitAnimation
		->InitFrameByBackStartEnd(5, 1, 0, 1, false);
	mLeftHitAnimation
		->SetIsLoop(false);
	mLeftHitAnimation
		->SetFrameUpdateTime(PlatPlayerAnimationTime);
	mLeftHitAnimation
		->Play();
	//필살기

	mRightSpecialAttackAnimation = new Animation();
	mRightSpecialAttackAnimation
		->InitFrameByStartEnd(0, 0, 12, 0, false);
	mRightSpecialAttackAnimation
		->SetIsLoop(false);
	mRightSpecialAttackAnimation
		->SetFrameUpdateTime(PlatPlayerShootAnimationTime);
	mRightSpecialAttackAnimation
		->Play();

	mLeftSpecialAttackAnimation = new Animation();
	mLeftSpecialAttackAnimation
		->InitFrameByBackStartEnd(12, 1, 0, 1, false);
	mLeftSpecialAttackAnimation
		->SetIsLoop(false);
	mLeftSpecialAttackAnimation
		->SetFrameUpdateTime(PlatPlayerShootAnimationTime);
	mLeftSpecialAttackAnimation
		->Play();

	//점프

	mRightJumpAnimation = new Animation();
	mRightJumpAnimation
		->InitFrameByStartEnd(0, 0, 7, 0, false);
	mRightJumpAnimation
		->SetIsLoop(true);
	mRightJumpAnimation
		->SetFrameUpdateTime(PlatPlayerAnimationTime);
	mRightJumpAnimation
		->Play();

	mLeftJumpAnimation = new Animation();
	mLeftJumpAnimation
		->InitFrameByBackStartEnd(7, 1, 0, 1, false);
	mLeftJumpAnimation
		->SetIsLoop(true);
	mLeftJumpAnimation
		->SetFrameUpdateTime(PlatPlayerAnimationTime);
	mLeftJumpAnimation
		->Play();
	//달리기

	mRightRunAnimation = new Animation();
	mRightRunAnimation
		->InitFrameByStartEnd(0, 0, 15, 0, false);
	mRightRunAnimation
		->SetIsLoop(true);
	mRightRunAnimation
		->SetFrameUpdateTime(PlatPlayerAnimationTime);
	mRightRunAnimation
		->Play();

	mLeftRunAnimation = new Animation();
	mLeftRunAnimation
		->InitFrameByBackStartEnd(17, 1, 2, 1, false);
	mLeftRunAnimation
		->SetIsLoop(true);
	mLeftRunAnimation
		->SetFrameUpdateTime(PlatPlayerAnimationTime);
	mLeftRunAnimation
		->Play();

	mRightRunturnAnimation = new Animation();
	mRightRunturnAnimation
		->InitFrameByStartEnd(16, 0, 17, 0, false);
	mRightRunturnAnimation
		->SetIsLoop(false);
	mRightRunturnAnimation
		->SetFrameUpdateTime(PlatPlayerAnimationTime);
	mRightRunturnAnimation
		->Play();

	mLeftRunturnAnimation = new Animation();
	mLeftRunturnAnimation
		->InitFrameByBackStartEnd(1, 1, 0, 1, false);
	mLeftRunturnAnimation
		->SetIsLoop(false);
	mLeftRunturnAnimation
		->SetFrameUpdateTime(PlatPlayerAnimationTime);
	mLeftRunturnAnimation
		->Play();
	//달리면서 쏘기

	mRightRunShootAnimation = new Animation();
	mRightRunShootAnimation
		->InitFrameByStartEnd(0, 0, 15, 0, false);
	mRightRunShootAnimation
		->SetIsLoop(true);
	mRightRunShootAnimation
		->SetFrameUpdateTime(PlatPlayerAnimationTime);
	mRightRunShootAnimation
		->Play();

	mLeftRunShootAnimation = new Animation();
	mLeftRunShootAnimation
		->InitFrameByBackStartEnd(17, 1, 2, 1, false);
	mLeftRunShootAnimation
		->SetIsLoop(true);
	mLeftRunShootAnimation
		->SetFrameUpdateTime(PlatPlayerAnimationTime);
	mLeftRunShootAnimation
		->Play();

	mRightRunShootturnAnimation = new Animation();
	mRightRunShootturnAnimation
		->InitFrameByStartEnd(16, 0, 17, 0, false);
	mRightRunShootturnAnimation
		->SetIsLoop(true);
	mRightRunShootturnAnimation
		->SetFrameUpdateTime(PlatPlayerAnimationTime);
	mRightRunShootturnAnimation
		->Play();

	mLeftRunShootturnAnimation = new Animation();
	mLeftRunShootturnAnimation
		->InitFrameByBackStartEnd(1, 1, 0, 1, false);
	mLeftRunShootturnAnimation
		->SetIsLoop(false);
	mLeftRunShootturnAnimation
		->SetFrameUpdateTime(PlatPlayerAnimationTime);
	mLeftRunShootturnAnimation
		->Play();

	mRightRunDiagonalUpShootAnimation = new Animation();
	mRightRunDiagonalUpShootAnimation
		->InitFrameByStartEnd(2, 0, 17, 0, false);
	mRightRunDiagonalUpShootAnimation
		->SetIsLoop(true);
	mRightRunDiagonalUpShootAnimation
		->SetFrameUpdateTime(PlatPlayerAnimationTime);
	mRightRunDiagonalUpShootAnimation
		->Play();

	mLeftRunDiagonalUpShootAnimation = new Animation();
	mLeftRunDiagonalUpShootAnimation
		->InitFrameByBackStartEnd(15, 1, 0, 1, false);
	mLeftRunDiagonalUpShootAnimation
		->SetIsLoop(true);
	mLeftRunDiagonalUpShootAnimation
		->SetFrameUpdateTime(PlatPlayerAnimationTime);
	mLeftRunDiagonalUpShootAnimation
		->Play();

	mRightRunDiagonalUpShootturnAnimation = new Animation();
	mRightRunDiagonalUpShootturnAnimation
		->InitFrameByStartEnd(0, 0, 1, 0, false);
	mRightRunDiagonalUpShootturnAnimation
		->SetIsLoop(false);
	mRightRunDiagonalUpShootturnAnimation
		->SetFrameUpdateTime(PlatPlayerAnimationTime);
	mRightRunDiagonalUpShootturnAnimation
		->Play();

	mLeftRunDiagonalUpShootturnAnimation = new Animation();
	mLeftRunDiagonalUpShootturnAnimation
		->InitFrameByBackStartEnd(17, 1, 16, 0, false);
	mLeftRunDiagonalUpShootturnAnimation
		->SetIsLoop(false);
	mLeftRunDiagonalUpShootturnAnimation
		->SetFrameUpdateTime(PlatPlayerAnimationTime);
	mLeftRunDiagonalUpShootturnAnimation
		->Play();
	//제자리 발사

	mRightShootAnimation = new Animation();
	mRightShootAnimation
		->InitFrameByStartEnd(0, 0, 5, 0, false);
	mRightShootAnimation
		->SetIsLoop(true);
	mRightShootAnimation
		->SetFrameUpdateTime(PlatPlayerShootAnimationTime);
	mRightShootAnimation
		->Play();

	mLeftShootAnimation = new Animation();
	mLeftShootAnimation
		->InitFrameByBackStartEnd(5, 1, 0, 1, false);
	mLeftShootAnimation
		->SetIsLoop(true);
	mLeftShootAnimation
		->SetFrameUpdateTime(PlatPlayerShootAnimationTime);
	mLeftShootAnimation
		->Play();

	mRightUpShootAnimation = new Animation();
	mRightUpShootAnimation
		->InitFrameByStartEnd(0, 0, 5, 0, false);
	mRightUpShootAnimation
		->SetIsLoop(true);
	mRightUpShootAnimation
		->SetFrameUpdateTime(PlatPlayerShootAnimationTime);
	mRightUpShootAnimation
		->Play();

	mLeftUpShootAnimation = new Animation();
	mLeftUpShootAnimation
		->InitFrameByBackStartEnd(5, 1, 0, 1, false);
	mLeftUpShootAnimation
		->SetIsLoop(true);
	mLeftUpShootAnimation
		->SetFrameUpdateTime(PlatPlayerShootAnimationTime);
	mLeftUpShootAnimation
		->Play();

	mRightDiagonalUpShootAnimation = new Animation();
	mRightDiagonalUpShootAnimation
		->InitFrameByStartEnd(0, 0, 5, 0, false);
	mRightDiagonalUpShootAnimation
		->SetIsLoop(true);
	mRightDiagonalUpShootAnimation
		->SetFrameUpdateTime(PlatPlayerShootAnimationTime);
	mRightDiagonalUpShootAnimation
		->Play();

	mLeftDiagonalUpShootAnimation = new Animation();
	mLeftDiagonalUpShootAnimation
		->InitFrameByBackStartEnd(5, 1, 0, 1, false);
	mLeftDiagonalUpShootAnimation
		->SetIsLoop(true);
	mLeftDiagonalUpShootAnimation
		->SetFrameUpdateTime(PlatPlayerShootAnimationTime);
	mLeftDiagonalUpShootAnimation
		->Play();

	//패링

	mRightParringAnimation = new Animation();
	mRightParringAnimation
		->InitFrameByStartEnd(0, 0, 7, 0, false);
	mRightParringAnimation
		->SetIsLoop(true);
	mRightParringAnimation
		->SetFrameUpdateTime(PlatPlayerAnimationTime);
	mRightParringAnimation
		->Play();

	mLeftParringAnimation = new Animation();
	mLeftParringAnimation
		->InitFrameByBackStartEnd(7, 1, 0, 1, false);
	mLeftParringAnimation
		->SetIsLoop(true);
	mLeftParringAnimation
		->SetFrameUpdateTime(PlatPlayerAnimationTime);
	mLeftParringAnimation
		->Play();

	mRightUpaimAnimation = new Animation();
	mRightUpaimAnimation->InitFrameByStartEnd(0, 0, 4, 0, true);
	mRightUpaimAnimation->SetIsLoop(true);
	mRightUpaimAnimation->SetFrameUpdateTime(PlatPlayerAnimationTime);
	mRightUpaimAnimation->Play();

	mLeftUpaimAnimation = new Animation();
	mLeftUpaimAnimation->InitFrameByBackStartEnd(4, 1, 0, 1, true);
	mLeftUpaimAnimation->SetIsLoop(true);
	mLeftUpaimAnimation->SetFrameUpdateTime(PlatPlayerAnimationTime);
	mLeftUpaimAnimation->Play();

	mLeftShootaimAnimation = new Animation();
	mLeftShootaimAnimation->InitFrameByBackStartEnd(4, 1, 0, 1, true);
	mLeftShootaimAnimation->SetIsLoop(true);
	mLeftShootaimAnimation->SetFrameUpdateTime(PlatPlayerAnimationTime);
	mLeftShootaimAnimation->Play();

	mRightShootaimAnimation = new Animation();
	mRightShootaimAnimation->InitFrameByStartEnd(0, 0, 4, 0, true);
	mRightShootaimAnimation->SetIsLoop(true);
	mRightShootaimAnimation->SetFrameUpdateTime(PlatPlayerAnimationTime);
	mRightShootaimAnimation->Play();

	mRightDiagonalUpaimAnimation = new Animation();
	mRightDiagonalUpaimAnimation->InitFrameByStartEnd(0, 0, 4, 0, true);
	mRightDiagonalUpaimAnimation->SetIsLoop(true);
	mRightDiagonalUpaimAnimation->SetFrameUpdateTime(PlatPlayerAnimationTime);
	mRightDiagonalUpaimAnimation->Play();

	mLeftDiagonalUpaimAnimation = new Animation();
	mLeftDiagonalUpaimAnimation->InitFrameByBackStartEnd(4, 1, 0, 1, true);
	mLeftDiagonalUpaimAnimation->SetIsLoop(true);
	mLeftDiagonalUpaimAnimation->SetFrameUpdateTime(PlatPlayerAnimationTime);
	mLeftDiagonalUpaimAnimation->Play();
	//위로보고 필살기

	mLeftUpSpecialAttackAnimation = new Animation();
	mLeftUpSpecialAttackAnimation->InitFrameByBackStartEnd(12, 1, 0, 1, false);
	mLeftUpSpecialAttackAnimation->SetIsLoop(false);
	mLeftUpSpecialAttackAnimation->SetFrameUpdateTime(PlatPlayerShootAnimationTime);
	mLeftUpSpecialAttackAnimation->Play();

	mRightUpSpecialAttackAnimation = new Animation();
	mRightUpSpecialAttackAnimation->InitFrameByStartEnd(0, 0, 12, 0, false);
	mRightUpSpecialAttackAnimation->SetIsLoop(false);
	mRightUpSpecialAttackAnimation->SetFrameUpdateTime(PlatPlayerShootAnimationTime);
	mRightUpSpecialAttackAnimation->Play();
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
	SafeDelete(mLeftUpSpecialAttackAnimation);
	SafeDelete(mRightUpSpecialAttackAnimation);
	SafeDelete(mRightHitAnimation);
	SafeDelete(mLeftHitAnimation);
	SafeDelete(mLeftDashAnimation);
	SafeDelete(mRightDashAnimation);
	SafeDelete(mDieAnimation);
	SafeDelete(mRightParringAnimation);
	SafeDelete(mLeftParringAnimation);
	SafeDelete(mLeftUpaimAnimation);
	SafeDelete(mRightUpaimAnimation);
	SafeDelete(mRightShootaimAnimation);
	SafeDelete(mLeftShootaimAnimation);
	SafeDelete(mLeftDiagonalUpaimAnimation);
	SafeDelete(mRightDiagonalUpaimAnimation);
}

void PlatformerPlayer::Update()
{
	

	if (mPlayerState == PlayerState::RightJump||mPlayerState==PlayerState::LeftJump)
	{
		if (Input::GetInstance()->GetKeyDown(VK_RIGHT))
		{
			mX += 5.f;
			mCurrentAnimation->Stop();
			mPlayerState = PlayerState::RightJump;
			mCurrentAnimation = mRightJumpAnimation;
			mCurrentAnimation->Play();
		}
		if (Input::GetInstance()->GetKeyDown(VK_LEFT))
		{
			mX -= 5.f;
			mCurrentAnimation->Stop();
			mPlayerState = PlayerState::LeftJump;
			mCurrentAnimation = mLeftJumpAnimation;
			mCurrentAnimation->Play();

		}
	}
	if (mPlayerState == PlayerState::LeftJump ||mPlayerState==PlayerState::RightJump)
	{
		if (Input::GetInstance()->GetKeyDown(VK_RIGHT))
		{
			mX += 5.f;
			mCurrentAnimation->Stop();
			mPlayerState = PlayerState::RightJump;
			mCurrentAnimation = mRightJumpAnimation;
			mCurrentAnimation->Play();
		}
		else if (Input::GetInstance()->GetKeyDown(VK_LEFT))
		{
			mX -= 5.f;
			mCurrentAnimation->Stop();
			mPlayerState = PlayerState::LeftJump;
			mCurrentAnimation = mLeftJumpAnimation;
			mCurrentAnimation->Play();

		}
	}

	if (isMove)
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
			mX -= 5;
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
				if (Input::GetInstance()->GetKey('X'))
				{
					if (mPlayerState == PlayerState::LeftRunDiagonalUpShoot)
					{
						if (SoundDelay == 4)
						{
							SoundPlayer::GetInstance()->Play(L"PeashootFire", 0.2f);
						}
						if (bulletdelay == 9)
						{
							BulletManager::GetInstance()->Player_Shoot(mX - 70, mY - 80, (PI / 2) + (PI / 4));
						}
					}
				}

			}
			if (Input::GetInstance()->GetKeyDown('X'))
			{
				if (mPlayerState == PlayerState::LeftRun)
				{
					mCurrentAnimation->Stop();
					mPlayerState = PlayerState::LeftRunShoot;
					mCurrentAnimation = mLeftRunShootAnimation;
					mCurrentAnimation->Play();
				}

			}
			if (Input::GetInstance()->GetKey('X'))
			{
				if (mPlayerState == PlayerState::LeftRunShoot)
				{
					if (SoundDelay == 4)
					{
						SoundPlayer::GetInstance()->Play(L"PeashootFire", 0.2f);
					}
					if (bulletdelay == 9)
					{
						BulletManager::GetInstance()->Player_Shoot(mX - 70, mY, PI);
					}
				}
			}
			if (Input::GetInstance()->GetKeyUp(VK_UP))
			{
				mCurrentAnimation->Stop();
				mPlayerState = PlayerState::LeftRun;
				mCurrentAnimation = mLeftRunAnimation;
				mCurrentAnimation->Play();
			}
			//왼쪽패링
			if (mPlayerState == PlayerState::LeftJump)
			{
				if (Input::GetInstance()->GetKeyDown('Z'))
				{
					mCurrentAnimation->Stop();
					mPlayerState = PlayerState::LeftParring;
					mCurrentAnimation = mLeftParringAnimation;
					mCurrentAnimation->Play();
				}
			}
			if (mJumpStack < 1)
			{
				if (Input::GetInstance()->GetKeyDown('Z'))
				{
					SoundPlayer::GetInstance()->Play(L"PlyerJump", 0.2f);
					mJumpStack++;
					mJumpPower = 10.f;
					mCurrentAnimation->Stop();
					mPlayerState = PlayerState::LeftJump;
					mCurrentAnimation = mLeftJumpAnimation;
					mCurrentAnimation->Play();
				}
			}
			if (Input::GetInstance()->GetKeyDown('V'))
			{
				SoundPlayer::GetInstance()->Play(L"SpecialAttack", 0.5f);
				isMove = false;
				mX += 0.5f;
				mCurrentAnimation->Stop();
				mPlayerState = PlayerState::LeftSpecialAttack;
				mCurrentAnimation = mLeftSpecialAttackAnimation;
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
			mX += 5;
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

				if (Input::GetInstance()->GetKey('X'))
				{
					if (mPlayerState == PlayerState::RightRunDiagonalUpShoot)
					{
						if (SoundDelay == 4)
						{
							SoundPlayer::GetInstance()->Play(L"PeashootFire", 0.2f);
						}
						if (bulletdelay == 9)
						{
							BulletManager::GetInstance()->Player_Shoot(mX + 70, mY - 80, PI / 4);
						}
					}
				}
			}
			if (Input::GetInstance()->GetKey('X'))
			{
				if (mPlayerState == PlayerState::RightRunShoot)
				{
					if (SoundDelay == 4)
					{
						SoundPlayer::GetInstance()->Play(L"PeashootFire", 0.2f);
					}
					if (bulletdelay == 9)
					{
						BulletManager::GetInstance()->Player_Shoot(mX + 70, mY, 0);
					}
				}
			}
			if (Input::GetInstance()->GetKeyDown('X'))
			{
				if (mPlayerState == PlayerState::RightRun)
				{
					mCurrentAnimation->Stop();
					mPlayerState = PlayerState::RightRunShoot;
					mCurrentAnimation = mRightRunShootAnimation;
					mCurrentAnimation->Play();
				}

			}

			if (Input::GetInstance()->GetKeyUp(VK_UP))
			{
				mCurrentAnimation->Stop();
				mPlayerState = PlayerState::RightRun;
				mCurrentAnimation = mRightRunAnimation;
				mCurrentAnimation->Play();
			}
			//오른쪽패링
			if (mPlayerState == PlayerState::RightJump)
			{
				if (Input::GetInstance()->GetKeyDown('Z'))
				{
					mJumpStack++;
					mCurrentAnimation->Stop();
					mPlayerState = PlayerState::RightParring;
					mCurrentAnimation = mRightParringAnimation;
					mCurrentAnimation->Play();
				}
			}
			if (mJumpStack < 1)
			{
				if (Input::GetInstance()->GetKeyDown('Z'))
				{
					SoundPlayer::GetInstance()->Play(L"PlyerJump", 0.2f);
					mJumpStack++;
					mJumpPower = 10.f;
					mCurrentAnimation->Stop();
					mPlayerState = PlayerState::RightJump;
					mCurrentAnimation = mRightJumpAnimation;
					mCurrentAnimation->Play();


				}
			}
			if (Input::GetInstance()->GetKeyDown('V'))
			{
				SoundPlayer::GetInstance()->Play(L"SpecialAttack", 0.5f);
				isMove = false;
				mX += 0.5f;
				mCurrentAnimation->Stop();
				mPlayerState = PlayerState::RightSpecialAttack;
				mCurrentAnimation = mRightSpecialAttackAnimation;
				mCurrentAnimation->Play();
			}

		}
		if (Input::GetInstance()->GetKeyUp(VK_RIGHT))
		{
			mCurrentAnimation->Stop();
			mPlayerState = PlayerState::RightIdle;
			mCurrentAnimation = mRightIdleAnimation;
			mCurrentAnimation->Play();
		}


	}
	else
	{

		//제자리에임

		if (Input::GetInstance()->GetKey('C'))
		{
			if (Input::GetInstance()->GetKey(VK_LEFT))
			{
				//대각샷
				if (Input::GetInstance()->GetKeyDown(VK_UP))
				{
					mCurrentAnimation->Stop();
					mPlayerState = PlayerState::LeftDiagonalUpaim;
					mCurrentAnimation = mLeftDiagonalUpaimAnimation;
					mCurrentAnimation->Play();

				}
				if (Input::GetInstance()->GetKey(VK_UP))
				{

					if (Input::GetInstance()->GetKeyDown('X'))
					{
						mCurrentAnimation->Stop();
						mPlayerState = PlayerState::LeftDiagonalUpShoot;
						mCurrentAnimation = mLeftDiagonalUpShootAnimation;
						mCurrentAnimation->Play();
					}
					if (Input::GetInstance()->GetKey('X'))
					{
						if (mPlayerState == PlayerState::LeftDiagonalUpShoot)
						{
							if (SoundDelay == 4)
							{
								SoundPlayer::GetInstance()->Play(L"PeashootFire", 0.2f);
							}
							if (bulletdelay == 9)
							{
								BulletManager::GetInstance()->Player_Shoot(mX - 70, mY - 80, (PI / 2) + (PI / 4));
							}
						}
					}
					if (Input::GetInstance()->GetKeyUp('X'))
					{
						mCurrentAnimation->Stop();
						mPlayerState = PlayerState::LeftDiagonalUpaim;
						mCurrentAnimation = mLeftDiagonalUpaimAnimation;
						mCurrentAnimation->Play();
					}
				}
				if (Input::GetInstance()->GetKeyUp(VK_UP))
				{
					mCurrentAnimation->Stop();
					mPlayerState = PlayerState::LeftShootaim;
					mCurrentAnimation = mLeftShootaimAnimation;
					mCurrentAnimation->Play();
				}
			}
			if (Input::GetInstance()->GetKey(VK_RIGHT))
			{
				if (Input::GetInstance()->GetKeyDown(VK_UP))
				{
					mCurrentAnimation->Stop();
					mPlayerState = PlayerState::RightDiagonalUpaim;
					mCurrentAnimation = mRightDiagonalUpaimAnimation;
					mCurrentAnimation->Play();
				}
				if (Input::GetInstance()->GetKey(VK_UP))
				{
					if (Input::GetInstance()->GetKeyDown('X'))
					{
						mCurrentAnimation->Stop();
						mPlayerState = PlayerState::RightDiagonalUpShoot;
						mCurrentAnimation = mRightDiagonalUpShootAnimation;
						mCurrentAnimation->Play();
					}
					if (Input::GetInstance()->GetKey('X'))
					{
						if (mPlayerState == PlayerState::RightDiagonalUpShoot)
						{
							if (SoundDelay == 4)
							{
								SoundPlayer::GetInstance()->Play(L"PeashootFire", 0.2f);
							}
							if (bulletdelay == 9)
							{
								BulletManager::GetInstance()->Player_Shoot(mX + 70, mY - 80, PI / 4);
							}
						}
					}
					if (Input::GetInstance()->GetKeyUp('X'))
					{
						mCurrentAnimation->Stop();
						mPlayerState = PlayerState::RightDiagonalUpaim;
						mCurrentAnimation = mRightDiagonalUpaimAnimation;
						mCurrentAnimation->Play();
					}
				}
				if (Input::GetInstance()->GetKeyUp(VK_UP))
				{
					mCurrentAnimation->Stop();
					mPlayerState = PlayerState::RightShootaim;
					mCurrentAnimation = mRightShootaimAnimation;
					mCurrentAnimation->Play();

				}
			}
			if (Input::GetInstance()->GetKeyDown(VK_RIGHT))
			{
				mCurrentAnimation->Stop();
				mPlayerState = PlayerState::RightShootaim;
				mCurrentAnimation = mRightShootaimAnimation;
				mCurrentAnimation->Play();

			}
			if (Input::GetInstance()->GetKeyDown(VK_LEFT))
			{
				mCurrentAnimation->Stop();
				mPlayerState = PlayerState::LeftShootaim;
				mCurrentAnimation = mLeftShootaimAnimation;
				mCurrentAnimation->Play();
			}
			else if (Input::GetInstance()->GetKeyDown(VK_UP))
			{
				if (mPlayerState == PlayerState::LeftShootaim)
				{
					mCurrentAnimation->Stop();
					mPlayerState = PlayerState::LeftUpaim;
					mCurrentAnimation = mLeftUpaimAnimation;
					mCurrentAnimation->Play();
				}
				if (mPlayerState == PlayerState::RightShootaim)
				{
					mCurrentAnimation->Stop();
					mPlayerState = PlayerState::RightUpaim;
					mCurrentAnimation = mRightUpaimAnimation;
					mCurrentAnimation->Play();
				}
			}
			if (Input::GetInstance()->GetKey(VK_UP))
			{
				if (Input::GetInstance()->GetKeyDown('X'))
				{
					if (mPlayerState == PlayerState::LeftUpaim)
					{
						mCurrentAnimation->Stop();
						mPlayerState = PlayerState::LeftUpShoot;
						mCurrentAnimation = mLeftUpShootAnimation;
						mCurrentAnimation->Play();
					}
					else if (mPlayerState == PlayerState::RightUpaim)
					{
						mCurrentAnimation->Stop();
						mPlayerState = PlayerState::RightUpShoot;
						mCurrentAnimation->Play();
					}
				}

				if (Input::GetInstance()->GetKeyUp('X'))
				{
					if (mPlayerState == PlayerState::LeftUpShoot)
					{
						mCurrentAnimation->Stop();
						mPlayerState = PlayerState::LeftUpaim;
						mCurrentAnimation = mLeftUpaimAnimation;
						mCurrentAnimation->Play();
					}
					else if (mPlayerState == PlayerState::RightUpShoot)
					{
						mCurrentAnimation->Stop();
						mPlayerState = PlayerState::RightUpShoot;
						mCurrentAnimation = mRightUpaimAnimation;
						mCurrentAnimation->Play();
					}
				}
			}
			if (Input::GetInstance()->GetKeyUp(VK_UP))
			{
				if (mPlayerState == PlayerState::LeftUpaim)
				{
					mCurrentAnimation->Stop();
					mPlayerState = PlayerState::LeftShootaim;
					mCurrentAnimation = mLeftShootaimAnimation;
					mCurrentAnimation->Play();
				}
				else if (mPlayerState == PlayerState::RightUpaim)
				{
					mCurrentAnimation->Stop();
					mPlayerState = PlayerState::RightShootaim;
					mCurrentAnimation = mRightShootAnimation;
					mCurrentAnimation->Play();
				}
			}


			//총알발사
			if (Input::GetInstance()->GetKeyDown('X'))
			{
				if (mPlayerState == PlayerState::RightShootaim)
				{
					mCurrentAnimation->Stop();
					mPlayerState = PlayerState::RightShoot;
					mCurrentAnimation = mRightShootAnimation;
					mCurrentAnimation->Play();
				}
				else if (mPlayerState == PlayerState::LeftShootaim)
				{
					mCurrentAnimation->Stop();
					mPlayerState = PlayerState::LeftShoot;
					mCurrentAnimation = mLeftShootAnimation;
					mCurrentAnimation->Play();
				}


			}
			if (Input::GetInstance()->GetKeyUp('X'))
			{
				if (mPlayerState == PlayerState::RightShoot)
				{
					mCurrentAnimation->Stop();
					mPlayerState = PlayerState::RightShootaim;
					mCurrentAnimation = mRightShootaimAnimation;
					mCurrentAnimation->Play();
				}
				else if (mPlayerState == PlayerState::LeftShoot)
				{
					mCurrentAnimation->Stop();
					mPlayerState = PlayerState::LeftShootaim;
					mCurrentAnimation = mLeftShootaimAnimation;
					mCurrentAnimation->Play();
				}
			}

			if (Input::GetInstance()->GetKeyUp('C'))
			{
				mCurrentAnimation->Stop();
				mPlayerState = PlayerState::LeftIdle;
				mCurrentAnimation = mLeftIdleAnimation;
				mCurrentAnimation->Play();
				isMove = true;
			}
		}
		//제자리쏘기 해제
		if (Input::GetInstance()->GetKeyUp('C'))
		{
			if (mPlayerState == PlayerState::RightShootaim)
			{
				mCurrentAnimation->Stop();
				mPlayerState = PlayerState::RightIdle;
				mCurrentAnimation = mRightIdleAnimation;
				mCurrentAnimation->Play();
				isMove = true;
			}
			if (mPlayerState == PlayerState::LeftShootaim)
			{
				mCurrentAnimation->Stop();
				mPlayerState = PlayerState::LeftIdle;
				mCurrentAnimation = mLeftIdleAnimation;
				mCurrentAnimation->Play();
				isMove = true;
			}
		}
		//덕 샷
		if (Input::GetInstance()->GetKey(VK_DOWN))
		{
			mRect = RectMakeCenter(mX, mY, 98, 50);

			if (Input::GetInstance()->GetKeyDown(VK_LEFT))
			{
				mCurrentAnimation->Stop();
				mPlayerState = PlayerState::LeftDuckIdle;
				mCurrentAnimation = mLeftDuckIdleAnimation;
				mCurrentAnimation->Play();
			}
			else if (Input::GetInstance()->GetKeyDown(VK_RIGHT))
			{
				mCurrentAnimation->Stop();
				mPlayerState = PlayerState::RightDuckIdle;
				mCurrentAnimation = mRightDuckIdleAnimation;
				mCurrentAnimation->Play();
			}
		}
		if (Input::GetInstance()->GetKeyDown('X'))
		{
			
			if (mPlayerState == PlayerState::RightDuckIdle)
			{
				mCurrentAnimation->Stop();
				mPlayerState = PlayerState::RightDuckShoot;
				mCurrentAnimation = mRightDuckShootAnimation;
				mCurrentAnimation->Play();
			}
			else if (mPlayerState == PlayerState::LeftDuckIdle)
			{
				mCurrentAnimation->Stop();
				mPlayerState = PlayerState::LeftDuckShoot;
				mCurrentAnimation = mLeftDuckShootAnimation;
				mCurrentAnimation->Play();
			}
		}
		if (Input::GetInstance()->GetKey('X'))
		{
			

			if (mPlayerState == PlayerState::LeftDuckShoot)
			{
				if (SoundDelay == 4)
				{
					SoundPlayer::GetInstance()->Play(L"PeashootFire", 0.2f);
				}
				if (bulletdelay == 9)
				{
					BulletManager::GetInstance()->Player_Shoot(mX - 90, mY + 40, PI);
				}
			}
			if (mPlayerState == PlayerState::RightDuckShoot)
			{
				if (SoundDelay == 4)
				{
					SoundPlayer::GetInstance()->Play(L"PeashootFire", 0.2f);
				}
				if (bulletdelay == 9)
				{
					BulletManager::GetInstance()->Player_Shoot(mX + 90, mY + 40, 0);
				}
			}

		}
		if (Input::GetInstance()->GetKeyUp('X'))
		{
			if (mPlayerState == PlayerState::RightDuckShoot)
			{
				mCurrentAnimation->Stop();
				mPlayerState = PlayerState::RightDuckIdle;
				mCurrentAnimation = mRightDuckIdleAnimation;
				mCurrentAnimation->Play();
			}
			else if (mPlayerState == PlayerState::LeftDuckShoot)
			{
				mCurrentAnimation->Stop();
				mPlayerState = PlayerState::LeftDuckIdle;
				mCurrentAnimation = mLeftDuckIdleAnimation;
				mCurrentAnimation->Play();
			}
		}

	}
	//else 끝
	//위보고 있을때 쏨

	if (Input::GetInstance()->GetKeyDown(VK_UP))
	{
		if (mPlayerState == PlayerState::LeftIdle)
		{

			mCurrentAnimation->Stop();
			mPlayerState = PlayerState::LeftUpaim;
			mCurrentAnimation = mLeftUpaimAnimation;
			mCurrentAnimation->Play();
		}
		if (mPlayerState == PlayerState::RightIdle)
		{

			mCurrentAnimation->Stop();
			mPlayerState = PlayerState::RightUpaim;
			mCurrentAnimation = mRightUpaimAnimation;
			mCurrentAnimation->Play();
		}
	}
	if (Input::GetInstance()->GetKey(VK_UP))
	{
		if (Input::GetInstance()->GetKeyDown('X'))
		{
			if (mPlayerState == PlayerState::LeftUpaim)
			{
				mCurrentAnimation->Stop();
				mPlayerState = PlayerState::LeftUpShoot;
				mCurrentAnimation = mLeftUpShootAnimation;
				mCurrentAnimation->Play();
			}
			if (mPlayerState == PlayerState::RightUpaim)
			{
				mCurrentAnimation->Stop();
				mPlayerState = PlayerState::RightUpShoot;
				mCurrentAnimation = mRightUpShootAnimation;
				mCurrentAnimation->Play();
			}
		}
		if (Input::GetInstance()->GetKey('X'))
		{
			if (mPlayerState == PlayerState::LeftUpShoot)
			{
				if (SoundDelay == 4)
				{
					SoundPlayer::GetInstance()->Play(L"PeashootFire", 0.2f);
				}
				if (bulletdelay == 9)
				{
					BulletManager::GetInstance()->Player_Shoot(mX - 30, mY - 100, PI / 2);
				}
			}
			if (mPlayerState == PlayerState::RightUpShoot)
			{
				if (SoundDelay == 4)
				{
					SoundPlayer::GetInstance()->Play(L"PeashootFire", 0.2f);
				}
				if (bulletdelay == 9)
				{
					BulletManager::GetInstance()->Player_Shoot(mX + 30, mY - 100, PI / 2);
				}
			}
		
		}

		if (Input::GetInstance()->GetKeyUp('X'))
		{
			if (mPlayerState == PlayerState::LeftUpShoot)
			{
				mCurrentAnimation->Stop();
				mPlayerState = PlayerState::LeftUpaim;
				mCurrentAnimation = mLeftUpaimAnimation;
				mCurrentAnimation->Play();
			}
			else if (mPlayerState == PlayerState::RightUpShoot)
			{
				mCurrentAnimation->Stop();
				mPlayerState = PlayerState::RightUpaim;
				mCurrentAnimation = mRightUpaimAnimation;
				mCurrentAnimation->Play();
			}
		}
	}
	if (Input::GetInstance()->GetKeyUp(VK_UP))
	{
		if (mPlayerState == PlayerState::LeftUpaim)
		{

			mCurrentAnimation->Stop();
			mPlayerState = PlayerState::LeftIdle;
			mCurrentAnimation = mLeftIdleAnimation;
			mCurrentAnimation->Play();
		}
		else if (mPlayerState == PlayerState::RightUpaim)
		{

			mCurrentAnimation->Stop();
			mPlayerState = PlayerState::RightIdle;
			mCurrentAnimation = mRightIdleAnimation;
			mCurrentAnimation->Play();
		}
	}
	//제자리쏘기
	if (Input::GetInstance()->GetKeyDown('C'))
	{
		if (mPlayerState == PlayerState::LeftIdle)
		{
			isMove = false;
			mCurrentAnimation->Stop();
			mPlayerState = PlayerState::LeftShootaim;
			mCurrentAnimation = mLeftShootaimAnimation;
			mCurrentAnimation->Play();
		}
		else if (mPlayerState == PlayerState::RightIdle)
		{
			isMove = false;
			mCurrentAnimation->Stop();
			mPlayerState = PlayerState::RightShootaim;
			mCurrentAnimation = mRightShootaimAnimation;
			mCurrentAnimation->Play();
		}
	}
	//덕 아이들
	if (Input::GetInstance()->GetKeyDown(VK_DOWN))
	{
		mRect = RectMakeCenter(mX, mY, 98, 50);

		if (mPlayerState == PlayerState::LeftIdle)
		{
			isMove = false;
			mCurrentAnimation->Stop();
			mPlayerState = PlayerState::LeftDuckIdle;
			mCurrentAnimation = mLeftDuckIdleAnimation;
			mCurrentAnimation->Play();
		}
		else if (mPlayerState == PlayerState::RightIdle)
		{
			isMove = false;
			mCurrentAnimation->Stop();
			mPlayerState = PlayerState::RightDuckIdle;
			mCurrentAnimation = mRightDuckIdleAnimation;
			mCurrentAnimation->Play();
		}
	}

	if (Input::GetInstance()->GetKeyUp(VK_DOWN))
	{
		if (mPlayerState == PlayerState::LeftDuckIdle)
		{
			isMove = true;
			mCurrentAnimation->Stop();
			mPlayerState = PlayerState::LeftIdle;
			mCurrentAnimation = mLeftIdleAnimation;
			mCurrentAnimation->Play();
		}
		else if (mPlayerState == PlayerState::RightDuckIdle)
		{
			isMove = true;
			mCurrentAnimation->Stop();
			mPlayerState = PlayerState::RightIdle;
			mCurrentAnimation = mRightIdleAnimation;
			mCurrentAnimation->Play();
		}
	}

	//위로보고 필살기
	if (Input::GetInstance()->GetKey(VK_UP))
	{
		if (Input::GetInstance()->GetKeyDown('V'))
		{
			
			mSpcialAttackStack++;
			if (mPlayerState == PlayerState::LeftUpaim)
			{
				SoundPlayer::GetInstance()->Play(L"SpecialAttack", 0.5f);
				mCurrentAnimation->Stop();
				mPlayerState = PlayerState::LeftUpSpecialAttack;
				mCurrentAnimation = mLeftUpSpecialAttackAnimation;
				mCurrentAnimation->Play();
			}
			else if (mPlayerState == PlayerState::RightUpaim)
			{
				SoundPlayer::GetInstance()->Play(L"SpecialAttack", 0.5f);
				mCurrentAnimation->Stop();
				mPlayerState = PlayerState::RightUpSpecialAttack;
				mCurrentAnimation = mRightUpSpecialAttackAnimation;
				mCurrentAnimation->Play();
			}
		}
	}

	//제자리점프
	if (mJumpStack < 1)
	{
		if (Input::GetInstance()->GetKeyDown('Z'))
		{
			SoundPlayer::GetInstance()->Play(L"PlyerJump", 0.2f);
			mJumpPower = 10.f;
			mJumpStack++;
			if (mPlayerState == PlayerState::RightJump)
			{
				mCurrentAnimation->Stop();
				mPlayerState = PlayerState::RightParring;
				mCurrentAnimation = mRightParringAnimation;
				mCurrentAnimation->Play();
			}

			else if (mPlayerState == PlayerState::LeftJump)
			{
				mCurrentAnimation->Stop();
				mPlayerState = PlayerState::LeftParring;
				mCurrentAnimation = mLeftParringAnimation;
				mCurrentAnimation->Play();
			}
			else if (mPlayerState == PlayerState::RightIdle)
			{
				mCurrentAnimation->Stop();
				mPlayerState = PlayerState::RightJump;
				mCurrentAnimation = mRightJumpAnimation;
				mCurrentAnimation->Play();

			}
			else if (mPlayerState == PlayerState::LeftIdle)
			{
				mCurrentAnimation->Stop();
				mPlayerState = PlayerState::LeftJump;
				mCurrentAnimation = mLeftJumpAnimation;
				mCurrentAnimation->Play();
			}
			
		}
	}
	if (Input::GetInstance()->GetKeyDown('X'))
	{
		if (mPlayerState == PlayerState::LeftIdle)
		{
			mCurrentAnimation->Stop();
			mPlayerState = PlayerState::LeftShoot;
			mCurrentAnimation = mLeftShootAnimation;
			mCurrentAnimation->Play();
			BulletManager::GetInstance()->Player_Shoot(mX - 70, mY, PI);
		}
		else if (mPlayerState == PlayerState::RightIdle)
		{
			mCurrentAnimation->Stop();
			mPlayerState = PlayerState::RightShoot;
			mCurrentAnimation = mRightShootAnimation;
			mCurrentAnimation->Play();
		}
	}
	if (Input::GetInstance()->GetKey('X'))
	{
		if (mPlayerState == PlayerState::LeftShoot)
		{
			if (SoundDelay == 4)
			{
				SoundPlayer::GetInstance()->Play(L"PeashootFire", 0.2f);
			}
			if (bulletdelay == 9)
			{
				BulletManager::GetInstance()->Player_Shoot(mX - 70, mY, PI);
			}
		}
		if (mPlayerState == PlayerState::RightShoot)
		{
			if (SoundDelay == 4)
			{
				SoundPlayer::GetInstance()->Play(L"PeashootFire", 0.2f);
			}
			if (bulletdelay == 9)
			{
				BulletManager::GetInstance()->Player_Shoot(mX + 70, mY, 0);
			}
		}
	}
	if (Input::GetInstance()->GetKeyUp('X'))
	{
		if (mPlayerState == PlayerState::LeftShoot)
		{
			mCurrentAnimation->Stop();
			mPlayerState = PlayerState::LeftIdle;
			mCurrentAnimation = mLeftIdleAnimation;
			mCurrentAnimation->Play();


		}
		else if (mPlayerState == PlayerState::RightShoot)
		{
			mCurrentAnimation->Stop();
			mPlayerState = PlayerState::RightIdle;
			mCurrentAnimation = mRightIdleAnimation;
			mCurrentAnimation->Play();
		}
	}
	//필살기
	if (Input::GetInstance()->GetKeyDown('V'))
	{
		if (mPlayerState == PlayerState::LeftIdle)
		{
			mCurrentAnimation->Stop();
			mPlayerState = PlayerState::LeftSpecialAttack;
			mCurrentAnimation = mLeftSpecialAttackAnimation;
			mCurrentAnimation->Play();
		}

		else if (mPlayerState == PlayerState::RightIdle)
		{
			mCurrentAnimation->Stop();
			mPlayerState = PlayerState::RightSpecialAttack;
			mCurrentAnimation = mRightSpecialAttackAnimation;
			mCurrentAnimation->Play();
			if (mCurrentAnimation->GetIsPlay() == false)
				mPlayerState = PlayerState::RightIdle;
		}
	}
	if (mPlayerState == PlayerState::LeftSpecialAttack)
	{
		if (mCurrentAnimation->GetIsPlay() == false)
		{
			mCurrentAnimation->Stop();
			mPlayerState = PlayerState::LeftIdle;
			mCurrentAnimation = mLeftIdleAnimation;
			mCurrentAnimation->Play();
			isMove = true;
		}
	}
	if (mPlayerState == PlayerState::RightSpecialAttack)
	{
		if (mCurrentAnimation->GetIsPlay() == false)
		{
			mCurrentAnimation->Stop();
			mPlayerState = PlayerState::RightIdle;
			mCurrentAnimation = mRightIdleAnimation;
			mCurrentAnimation->Play();
			isMove = true;
		}
	}
	if (mPlayerState == PlayerState::RightUpSpecialAttack)
	{
		if (mCurrentAnimation->GetIsPlay() == false)
		{
			mCurrentAnimation->Stop();
			mPlayerState = PlayerState::RightIdle;
			mCurrentAnimation = mRightIdleAnimation;
			mCurrentAnimation->Play();
			isMove = true;
		}
	}
	if (mPlayerState == PlayerState::LeftUpSpecialAttack)
	{
		if (mCurrentAnimation->GetIsPlay() == false)
		{
			mCurrentAnimation->Stop();
			mPlayerState = PlayerState::LeftIdle;
			mCurrentAnimation = mLeftIdleAnimation;
			mCurrentAnimation->Play();
			isMove = true;
		}
	}
	//대쉬
	if (Input::GetInstance()->GetKeyDown(VK_LSHIFT))
	{
		SoundPlayer::GetInstance()->Play(L"Dash", 0.2f);
		if (mPlayerState == PlayerState::RightRun)
		{
			mCurrentAnimation->Stop();
			mPlayerState = PlayerState::RightDash;
			mCurrentAnimation = mRightDashAnimation;
			mCurrentAnimation->Play();
			mX += 100;
		}
		else if (mPlayerState == PlayerState::LeftRun)
		{
			mCurrentAnimation->Stop();
			mPlayerState = PlayerState::LeftDash;
			mCurrentAnimation = mLeftDashAnimation;
			mCurrentAnimation->Play();
			mX -= 100;
		}
		else if (mPlayerState == PlayerState::LeftIdle)
		{
			mCurrentAnimation->Stop();
			mPlayerState = PlayerState::LeftDash;
			mCurrentAnimation = mLeftDashAnimation;
			mCurrentAnimation->Play();
			mX -= 100;
		}

	}
	if (mPlayerState == PlayerState::RightDash)
	{
		if (mCurrentAnimation->GetIsPlay() == false)
		{
			mCurrentAnimation->Stop();
			mPlayerState = PlayerState::RightRun;
			mCurrentAnimation = mRightRunAnimation;
			mCurrentAnimation->Play();
		}
	}
	if (mPlayerState == PlayerState::LeftDash)
	{
		if (mCurrentAnimation->GetIsPlay() == false)
		{
			mCurrentAnimation->Stop();
			mPlayerState = PlayerState::LeftRun;
			mCurrentAnimation = mLeftRunAnimation;
			mCurrentAnimation->Play();
		}
	}
	//공격중 이동
	if (Input::GetInstance()->GetKey('X'))
	{
		
		if (mPlayerState == PlayerState::LeftJump)
		{
			if (bulletdelay == 9)
			{
				BulletManager::GetInstance()->Player_Shoot(mX - 70, mY, PI);
			}
		}
		if (mPlayerState == PlayerState::RightJump)
		{
			if (bulletdelay == 9)
			{
				BulletManager::GetInstance()->Player_Shoot(mX +70, mY, 0);
			}

		}
		if (mPlayerState == PlayerState::LeftRun)
		{
			mCurrentAnimation->Stop();
			mPlayerState = PlayerState::LeftRunShoot;
			mCurrentAnimation = mLeftRunShootAnimation;
			mCurrentAnimation->Play();
			if (bulletdelay == 9)
			{
				BulletManager::GetInstance()->Player_Shoot(mX - 70, mY, PI);
			}
		}
		if (mPlayerState == PlayerState::RightRun)
		{
			mCurrentAnimation->Stop();
			mPlayerState = PlayerState::RightRunShoot;
			mCurrentAnimation = mRightRunShootAnimation;
			mCurrentAnimation->Play();
			if (bulletdelay == 9)
			{
				BulletManager::GetInstance()->Player_Shoot(mX + 70, mY, 0);
			}
		}
		if (Input::GetInstance()->GetKey(VK_LEFT))
		{
			if (Input::GetInstance()->GetKey(VK_UP))
			{
				if (mPlayerState == PlayerState::LeftRun)
				{
					mPlayerState = PlayerState::LeftRunDiagonalUpShoot;
					if (mCurrentAnimation != mLeftRunDiagonalUpShootAnimation) {
						mCurrentAnimation->Stop();
						mCurrentAnimation = mLeftRunDiagonalUpShootAnimation;
					}
					mCurrentAnimation->Play();
				 
					if (mPlayerState == PlayerState::LeftRunDiagonalUpShoot)
					{
						if (bulletdelay == 9)
						{
							BulletManager::GetInstance()->Player_Shoot(mX - 70, mY - 80, (PI / 2) + (PI / 4));
						}
					}
				}
				if (mPlayerState == PlayerState::LeftDiagonalUpaim)
				{
					mCurrentAnimation->Stop();
					mPlayerState = PlayerState::LeftDiagonalUpShoot;
					mCurrentAnimation = mLeftDiagonalUpShootAnimation;
					mCurrentAnimation->Play();
					if (mPlayerState == PlayerState::LeftDiagonalUpShoot)
					{
						if (bulletdelay == 9)
						{
							BulletManager::GetInstance()->Player_Shoot(mX - 70, mY - 80, (PI / 2) + (PI / 4));
						}
					}
				}
			}
		}
		if (Input::GetInstance()->GetKey(VK_RIGHT))
		{
			if (Input::GetInstance()->GetKey(VK_UP))
			{
				if (mPlayerState == PlayerState::RightRun)
				{
					mPlayerState = PlayerState::RightRunDiagonalUpShoot;
					if (mCurrentAnimation != mRightRunDiagonalUpShootAnimation) {
						mCurrentAnimation->Stop();
						mCurrentAnimation = mRightRunDiagonalUpShootAnimation;
					}
					mCurrentAnimation->Play();

					if (mPlayerState == PlayerState::RightRunDiagonalUpShoot)
					{
						if (bulletdelay == 9)
						{
							BulletManager::GetInstance()->Player_Shoot(mX - 70, mY - 80, (PI / 4));
						}
					}
				}
				if (mPlayerState == PlayerState::RightDiagonalUpaim)
				{
					mCurrentAnimation->Stop();
					mPlayerState = PlayerState::RightDiagonalUpShoot;
					mCurrentAnimation = mRightDiagonalUpShootAnimation;
					mCurrentAnimation->Play();
					if (mPlayerState == PlayerState::RightDiagonalUpShoot)
					{
						if (bulletdelay == 9)
						{
							BulletManager::GetInstance()->Player_Shoot(mX - 70, mY - 80, (PI / 4));
						}
					}
				}
			}
		}
		
		
		
	}
	



	SoundDelay++;
	bulletdelay++;
	if (SoundDelay > 4)
	{
		SoundDelay = 0;
	}
	if (bulletdelay > 10)
	{
		bulletdelay = 0;
	}
	mGravity = 0.3f;
	if (mPlayerState == PlayerState::RightDuckIdle || mPlayerState == PlayerState::LeftDuckIdle || mPlayerState == PlayerState::RightDuckShoot || mPlayerState == PlayerState::LeftDuckShoot)
	{
		mRect = RectMakeCenter(mX, mY+50, 98, 50);
	}
	else
	{
		mRect = RectMakeCenter(mX, mY, 98, 155);
	}
		//중력
	mJumpPower -= mGravity;
	mY -= mJumpPower;




	for (int i = 0; i < mBullet.size(); i++)
	{
		mBullet[i]->Update();
	}

	mCurrentAnimation->Update();

	if (mPlayerState == PlayerState::RightIdle)
	{
		mImage = IMAGEMANAGER->FindImage(L"PlatformerPlayerIdle");
	}
	else if (mPlayerState == PlayerState::LeftIdle)
	{
		mImage = IMAGEMANAGER->FindImage(L"PlatformerPlayerIdle");
	}
	else if (mPlayerState == PlayerState::RightDash)
	{
		mImage = IMAGEMANAGER->FindImage(L"Dash");
	}
	else if (mPlayerState == PlayerState::LeftDash)
	{
		mImage = IMAGEMANAGER->FindImage(L"Dash");
	}
	else if (mPlayerState == PlayerState::Die)
	{
		mImage = IMAGEMANAGER->FindImage(L"Die");
	}
	else if (mPlayerState == PlayerState::RightDuckIdle)
	{
		mImage = IMAGEMANAGER->FindImage(L"Duckidle");
	}
	else if (mPlayerState == PlayerState::LeftDuckIdle)
	{
		mImage = IMAGEMANAGER->FindImage(L"Duckidle");
	}
	else if (mPlayerState == PlayerState::RightDuck)
	{
		mImage = IMAGEMANAGER->FindImage(L"Duckidle");
	}
	else if (mPlayerState == PlayerState::LeftDuck)
	{
		mImage = IMAGEMANAGER->FindImage(L"Duckidle");
	}
	else if (mPlayerState == PlayerState::RightDuckShoot)
	{
		mImage = IMAGEMANAGER->FindImage(L"DuckShoot");
	}
	else if (mPlayerState == PlayerState::LeftDuckShoot)
	{
		mImage = IMAGEMANAGER->FindImage(L"DuckShoot");
	}
	else if (mPlayerState == PlayerState::RightHit)
	{
		mImage = IMAGEMANAGER->FindImage(L"Groundhit");
	}
	else if (mPlayerState == PlayerState::LeftHit)
	{
		mImage = IMAGEMANAGER->FindImage(L"Groundhit");
	}
	else if (mPlayerState == PlayerState::RightSpecialAttack)
	{
		mImage = IMAGEMANAGER->FindImage(L"GroundSpecialAttack");
	}
	else if (mPlayerState == PlayerState::LeftSpecialAttack)
	{
		mImage = IMAGEMANAGER->FindImage(L"GroundSpecialAttack");
	}
	else if (mPlayerState == PlayerState::LeftUpSpecialAttack)
	{
		mImage = IMAGEMANAGER->FindImage(L"UpspecialAttack");
	}
	else if (mPlayerState == PlayerState::RightUpSpecialAttack)
	{
		mImage = IMAGEMANAGER->FindImage(L"UpspecialAttack");
	}
	else if (mPlayerState == PlayerState::RightJump)
	{
		mImage = IMAGEMANAGER->FindImage(L"Jump");
	}
	else if (mPlayerState == PlayerState::LeftJump)
	{
		mImage = IMAGEMANAGER->FindImage(L"Jump");
	}
	else if (mPlayerState == PlayerState::RightRun)
	{
		mImage = IMAGEMANAGER->FindImage(L"Run");
	}
	else if (mPlayerState == PlayerState::LeftRun)
	{
		mImage = IMAGEMANAGER->FindImage(L"Run");
	}
	else if (mPlayerState == PlayerState::RightRunturn)
	{
		mImage = IMAGEMANAGER->FindImage(L"Run");
	}
	else if (mPlayerState == PlayerState::LeftRunturn)
	{
		mImage = IMAGEMANAGER->FindImage(L"Run");
	}
	else if (mPlayerState == PlayerState::RightRunShoot)
	{
		mImage = IMAGEMANAGER->FindImage(L"RunShoot");
	}
	else if (mPlayerState == PlayerState::LeftRunShoot)
	{
		mImage = IMAGEMANAGER->FindImage(L"RunShoot");
	}
	else if (mPlayerState == PlayerState::RightRunShootturn)
	{
		mImage = IMAGEMANAGER->FindImage(L"RunShoot");
	}
	else if (mPlayerState == PlayerState::LeftRunShootturn)
	{
		mImage = IMAGEMANAGER->FindImage(L"RunShoot");
	}
	else if (mPlayerState == PlayerState::RightRunDiagonalUpShoot || mPlayerState == PlayerState::LeftRunDiagonalUpShoot || mPlayerState == PlayerState::RightRunDiagonalUpShootturn || mPlayerState == PlayerState::LeftRunDiagonalUpShootturn)
	{
		mImage = IMAGEMANAGER->FindImage(L"RunDiagonalShoot");
	}
	else if (mPlayerState == PlayerState::RightShoot || mPlayerState == PlayerState::LeftShoot)
	{
		mImage = IMAGEMANAGER->FindImage(L"StraightShoot");
	}
	else if (mPlayerState == PlayerState::RightUpShoot || mPlayerState == PlayerState::LeftUpShoot)
	{
		mImage = IMAGEMANAGER->FindImage(L"UpShoot");
	}
	else if (mPlayerState == PlayerState::RightDiagonalUpShoot || mPlayerState == PlayerState::LeftDiagonalUpShoot)
	{
		mImage = IMAGEMANAGER->FindImage(L"DiagonalUp");
	}
	else if (mPlayerState == PlayerState::RightParring || mPlayerState == PlayerState::LeftParring)
	{
		mImage = IMAGEMANAGER->FindImage(L"Parring");
	}
	else if (mPlayerState == PlayerState::RightUpaim || mPlayerState == PlayerState::LeftUpaim)
	{
		mImage = IMAGEMANAGER->FindImage(L"Upaim");
	}
	else if (mPlayerState == PlayerState::LeftShootaim || mPlayerState == PlayerState::RightShootaim)
	{
		mImage = IMAGEMANAGER->FindImage(L"Shootaim");
	}
	else if (mPlayerState == PlayerState::LeftDiagonalUpaim || mPlayerState == PlayerState::RightDiagonalUpaim)
	{
		mImage = IMAGEMANAGER->FindImage(L"DiagonalUpaim");
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
	//CameraManager::GetInstance()->GetMainCamera()->RenderRect(hdc, mRect);
	CameraManager::GetInstance()->GetMainCamera()->FrameRenderFromBottom(hdc, mImage, mX, mRect.bottom, mCurrentAnimation->GetNowFrameX(), mCurrentAnimation->GetNowFrameY());

	//RenderRect(hdc, mGround);
	for (int i = 0; i < mBullet.size(); ++i)
	{
		mBullet[i]->Render(hdc);
	}


}

void PlatformerPlayer::InIntersectBlock(RECT rc)
{
	if ((rc.bottom - rc.top) < (rc.right - rc.left) && rc.bottom == mRect.bottom)
		mY -= rc.bottom - rc.top;
	if ((rc.bottom - rc.top) < (rc.right - rc.left) && rc.top == mRect.top)
		mY += rc.bottom - rc.top;
	if ((rc.bottom - rc.top) > (rc.right - rc.left) && rc.left == mRect.left)
		mX += rc.right - rc.left;
	if ((rc.bottom - rc.top) > (rc.right - rc.left) && rc.right == mRect.right)
		mX -= rc.right - rc.left;
	if (mPlayerState == PlayerState::LeftJump)
	{
		mCurrentAnimation->Stop();
		mPlayerState = PlayerState::LeftIdle;
		mCurrentAnimation = mLeftIdleAnimation;
		mCurrentAnimation->Play();
		if (Input::GetInstance()->GetKey(VK_LEFT))
		{
			mCurrentAnimation->Stop();
			mPlayerState = PlayerState::LeftRun;
			mCurrentAnimation = mLeftRunAnimation;
			mCurrentAnimation->Play();
		}
	}
	if (mPlayerState == PlayerState::RightJump)
	{
		mCurrentAnimation->Stop();
		mPlayerState = PlayerState::RightIdle;
		mCurrentAnimation = mRightIdleAnimation;
		mCurrentAnimation->Play();
		if (Input::GetInstance()->GetKey(VK_RIGHT))
		{
			mCurrentAnimation->Stop();
			mPlayerState = PlayerState::RightRun;
			mCurrentAnimation = mRightRunAnimation;
			mCurrentAnimation->Play();
		}
	}
	if (mPlayerState == PlayerState::LeftParring)
	{
		mCurrentAnimation->Stop();
		mPlayerState = PlayerState::LeftIdle;
		mCurrentAnimation = mLeftIdleAnimation;
		mCurrentAnimation->Play();
		if (Input::GetInstance()->GetKey(VK_LEFT))
		{
			mCurrentAnimation->Stop();
			mPlayerState = PlayerState::LeftRun;
			mCurrentAnimation = mLeftRunAnimation;
			mCurrentAnimation->Play();
		}
	}
	if (mPlayerState == PlayerState::RightParring)
	{
		mCurrentAnimation->Stop();
		mPlayerState = PlayerState::RightIdle;
		mCurrentAnimation = mRightIdleAnimation;
		mCurrentAnimation->Play();
		if (Input::GetInstance()->GetKey(VK_RIGHT))
		{
			mCurrentAnimation->Stop();
			mPlayerState = PlayerState::RightRun;
			mCurrentAnimation = mRightRunAnimation;
			mCurrentAnimation->Play();
		}
	}
	mJumpPower = 0.f;
	mGravity = 0.f;
	mJumpStack = 0;
	mSpcialAttackStack = 0;
	mDashStack = 0;
	mParringStack = 0;
}

void PlatformerPlayer::InIntersectDamage(int dmage)
{
	mHP -= 1;
}


