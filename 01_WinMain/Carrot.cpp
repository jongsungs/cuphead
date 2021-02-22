#include "pch.h"
#include "Carrot.h"

#include "Player.h"
#include "Image.h"
#include "Animation.h"
#include "Camera.h"

Carrot::Carrot(const string& name, float x, float y)
	:Enemy(name, x, y)
{
	mX = x;
	mY = y;
}

void Carrot::Init() {
	//기본 상태로 초기 생성
	mState = EnemyState::Intro;

	//캐릭터 상태에 따라 다른 이미지를 보여주기 위함
	mIntroImage = IMAGEMANAGER->FindImage(L"CarrotIntro");
	mAttackImage = IMAGEMANAGER->FindImage(L"CarrotBeam");
	mDeathImage = IMAGEMANAGER->FindImage(L"CarrotDeath");

	//캐릭터 상태에 따라 다른 애니메이션을 보여주기 위함
	//일반 애니메이션
	mIntroAnimation = new Animation();
	mIntroAnimation->InitFrameByStartEnd(0, 0, 24, 0, false);
	mIntroAnimation->SetIsLoop(false);
	mIntroAnimation->SetFrameUpdateTime(0.1f);
	//공격 도입 애니메이션
	mInitAttackAnimation = new Animation();
	mInitAttackAnimation->InitFrameByStartEnd(0, 0, 8, 0, false);
	mInitAttackAnimation->SetIsLoop(false);
	mInitAttackAnimation->SetFrameUpdateTime(0.1f);

	//공격 애니메이션
	mAttackAnimation = new Animation();
	mAttackAnimation->InitFrameByStartEnd(9, 0, 12, 0, false);
	mAttackAnimation->SetIsLoop(true);
	mAttackAnimation->SetFrameUpdateTime(0.1f);

	//사망 애니메이션
	mDeathAnimation = new Animation();
	mDeathAnimation->InitFrameByStartEnd(0, 0, 7, 0, false);
	mDeathAnimation->SetIsLoop(false);
	mDeathAnimation->SetFrameUpdateTime(0.1f);

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

void Carrot::Release() {
	SafeDelete(mIntroAnimation);
	SafeDelete(mAttackAnimation);
	SafeDelete(mDeathAnimation);
	SafeDelete(mInitAttackAnimation);
}

void Carrot::Update() {

	if (mHP <= 0)
		mState = EnemyState::Death;

	//상태에 따른 다른 애니메이션 출력
	switch (mState) {
	case EnemyState::Intro:
		mImage = mIntroImage;
		mSizeX = mImage->GetFrameWidth();
		mSizeY = mImage->GetFrameHeight();
		mCurrentAnimation = mIntroAnimation;
		if (mCurrentAnimation->GetIsPlay() == false) {
			mState = EnemyState::InitAttack;
		}
		mCurrentAnimation->Play();
		break;

	case EnemyState::InitAttack:
		mImage = mAttackImage;
		mSizeX = mImage->GetFrameWidth();
		mSizeY = mImage->GetFrameHeight();
		mCurrentAnimation = mInitAttackAnimation;
		if (mCurrentAnimation->GetIsPlay() == false) {
			mState = EnemyState::Attack;
		}
		mCurrentAnimation->Play();
		break;

	case EnemyState::Attack:
		mImage = mAttackImage;
		mSizeX = mImage->GetFrameWidth();
		mSizeY = mImage->GetFrameHeight();
		mCurrentAnimation = mAttackAnimation;
		mCurrentAnimation->Play();

		mAttackStartDelay += Time::GetInstance()->DeltaTime();

		break;

	case EnemyState::Death:
		mImage = mDeathImage;
		mSizeX = mImage->GetFrameWidth();
		mSizeY = mImage->GetFrameHeight();
		mCurrentAnimation = mDeathAnimation;
		mCurrentAnimation->Play();
		if (mCurrentAnimation->GetNowFrameX() >= 5)
			mState = EnemyState::End;
		break;

	case EnemyState::End:
		mIsActive = false;
		mIsDestroy = true;
		break;
	}

	mRect = RectMakeCenter(mX, mY, mSizeX, mSizeY);
	mCurrentAnimation->Update();
}

void Carrot::Render(HDC hdc) {
	CameraManager::GetInstance()->GetMainCamera()
		->FrameRender(hdc, mImage, mRect.left, mRect.top, mCurrentAnimation->GetNowFrameX(), mCurrentAnimation->GetNowFrameY());
	//CameraManager::GetInstance()->GetMainCamera()->RenderRect(hdc, mRect);
}
