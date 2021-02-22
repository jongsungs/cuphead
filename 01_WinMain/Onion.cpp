#include "pch.h"
#include "Onion.h"

#include "Player.h"
#include "Image.h"
#include "Animation.h"
#include "Camera.h"

Onion::Onion(const string& name, float x, float y)
	:Enemy(name, x, y)
{
	mX = x;
	mY = y;
}

void Onion::Init() {
	//기본 상태로 초기 생성
	mState = EnemyState::Intro;

	//캐릭터 상태에 따라 다른 이미지를 보여주기 위함
	mIntroImage = IMAGEMANAGER->FindImage(L"OnionIntro");
	mIdleImage = IMAGEMANAGER->FindImage(L"OnionIdle");
	mAttackImage = IMAGEMANAGER->FindImage(L"EnemyAttack");
	mDeathImage = IMAGEMANAGER->FindImage(L"OnionDeath");
	mDeathLeaveImage = IMAGEMANAGER->FindImage(L"OnionDeathLeave");

	mBashfulImage = IMAGEMANAGER->FindImage(L"OnionDeath");
	mBashfulLeaveImage = IMAGEMANAGER->FindImage(L"OnionDeath");
	mCryImage = IMAGEMANAGER->FindImage(L"OnionDeath");

	mArmIntroImage = IMAGEMANAGER->FindImage(L"OnionDeath");
	mArmIdleImage = IMAGEMANAGER->FindImage(L"OnionDeath");
	mArmBashfulImage = IMAGEMANAGER->FindImage(L"OnionArmBashful");

	mTearAImage = IMAGEMANAGER->FindImage(L"OnionTearA");
	mTearBImage = IMAGEMANAGER->FindImage(L"OnionTearB");

	//캐릭터 상태에 따라 다른 애니메이션을 보여주기 위함
	//등장 애니메이션
	mIntroAnimation = new Animation();
	mIntroAnimation->InitFrameByStartEnd(0, 0, 23, 0, false);
	mIntroAnimation->SetIsLoop(false);
	mIntroAnimation->SetFrameUpdateTime(0.1f);
	//일반 애니메이션
	mIdleAnimation = new Animation();
	mIdleAnimation->InitFrameByStartEnd(0, 0, 14, 0, true);
	mIdleAnimation->SetIsLoop(true);
	mIdleAnimation->SetFrameUpdateTime(0.1f);
	//공격 애니메이션
	mAttackAnimation = new Animation();
	mAttackAnimation->InitFrameByStartEnd(0, 0, 11, 0, false);
	mAttackAnimation->SetIsLoop(true);
	mAttackAnimation->SetFrameUpdateTime(0.1f);
	//사망 애니메이션
	mDeathAnimation = new Animation();
	mDeathAnimation->InitFrameByStartEnd(0, 0, 5, 0, false);
	mDeathAnimation->SetIsLoop(false);
	mDeathAnimation->SetFrameUpdateTime(0.1f);
	//퇴장 애니메이션
	mDeathLeaveAnimation = new Animation();
	mDeathLeaveAnimation->InitFrameByStartEnd(0, 0, 30, 0, false);
	mDeathLeaveAnimation->SetIsLoop(false);
	mDeathLeaveAnimation->SetFrameUpdateTime(0.1f);

	mArmBashfulAnimation = new Animation();
	mArmBashfulAnimation->InitFrameByStartEnd(0, 0, 6, 0, false);
	mArmBashfulAnimation->SetIsLoop(false);
	mArmBashfulAnimation->SetFrameUpdateTime(0.1f);

	//초기생성시 들어가야 할 데이터
	mCurrentAnimation = mIntroAnimation;
	mCurrentAnimation->Play();
	mImage = mIntroImage;
	mSizeX = mImage->GetFrameWidth();
	mSizeY = mImage->GetFrameHeight();
	mRect = RectMakeCenter(mX, mY, mSizeX, mSizeY);

	//HP 임의설정
	mHP = 50;
	mAttackStartDelay = 0;
}

void Onion::Release() {
	SafeDelete(mIntroAnimation);
	SafeDelete(mIdleAnimation);
	SafeDelete(mAttackAnimation);
	SafeDelete(mDeathAnimation);
	SafeDelete(mDeathLeaveAnimation);
	SafeDelete(mArmBashfulAnimation);
}

void Onion::Update() {
	if (mHP <= 0)
		mState = EnemyState::Death;

	//상태에 따른 다른 애니메이션 출력
	switch (mState) {
	case EnemyState::Intro:
		mImage = mIntroImage;
		mSizeX = mImage->GetFrameWidth();
		mSizeY = mImage->GetFrameHeight();
		mCurrentAnimation = mIntroAnimation;
		if (mCurrentAnimation->GetIsPlay() == false)
			mState = EnemyState::Idle;
		mCurrentAnimation->Play();
		break;

	case EnemyState::Idle:
		mImage = mIdleImage;
		mSizeX = mImage->GetFrameWidth();
		mSizeY = mImage->GetFrameHeight();
		mCurrentAnimation = mIdleAnimation;
		if (mCurrentAnimation->GetIsPlay() == false)
			mState = EnemyState::Attack;
		mCurrentAnimation->Play();
		break;

	//case EnemyState::Attack:
	//	mImage = mAttackImage;
	//	mSizeX = mImage->GetFrameWidth();
	//	mSizeY = mImage->GetFrameHeight();
	//	mCurrentAnimation = mAttackAnimation;
	//	mCurrentAnimation->Play();

	//	mAttackStartDelay += Time::GetInstance()->DeltaTime();

	//	break;

	case EnemyState::Death:
		mImage = mDeathImage;
		mSizeX = mImage->GetFrameWidth();
		mSizeY = mImage->GetFrameHeight();
		mCurrentAnimation = mDeathAnimation;
		mCurrentAnimation->Play();
		if (mCurrentAnimation->GetNowFrameX() >= 5) {
			mState = EnemyState::End;
		}
		break;

	case EnemyState::End:
		mIsActive = false;
		mIsDestroy = true;
		break;
	}

	mRect = RectMakeCenter(mX, mY, mSizeX, mSizeY);
	mCurrentAnimation->Update();
}

void Onion::Render(HDC hdc) {
	CameraManager::GetInstance()->GetMainCamera()
		->FrameRender(hdc, mImage, mRect.left, mRect.top, mCurrentAnimation->GetNowFrameX(), mCurrentAnimation->GetNowFrameY());
	//CameraManager::GetInstance()->GetMainCamera()->RenderRect(hdc, mRect);
}
