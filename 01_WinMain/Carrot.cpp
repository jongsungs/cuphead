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
	mAttackImage = IMAGEMANAGER->FindImage(L"CarrotAttack");
	mBeamImage = IMAGEMANAGER->FindImage(L"CarrotBeam");
	mChangeToBeamImage = IMAGEMANAGER->FindImage(L"CarrotChangeToBeam");
	mDeathImage = IMAGEMANAGER->FindImage(L"CarrotDeath");

	//캐릭터 상태에 따라 다른 애니메이션을 보여주기 위함
	//일반 애니메이션
	mIntroAnimation = new Animation();
	mIntroAnimation->InitFrameByStartEnd(0, 0, 24, 0, false);
	mIntroAnimation->SetIsLoop(false);
	mIntroAnimation->SetFrameUpdateTime(0.07f);
	//당근 소환 애니메이션
	mAttackAnimation = new Animation();
	mAttackAnimation->InitFrameByStartEnd(0, 0, 21, 0, false);
	mAttackAnimation->SetIsLoop(true);
	mAttackAnimation->SetFrameUpdateTime(0.07f);
	//빔으로 애니메이션
	mChangeToBeamAnimation = new Animation();
	mChangeToBeamAnimation->InitFrameByStartEnd(0, 0, 8, 0, false);
	mChangeToBeamAnimation->SetIsLoop(false);
	mChangeToBeamAnimation->SetFrameUpdateTime(0.07f);
	//빔 애니메이션
	mBeamAnimation = new Animation();
	mBeamAnimation->InitFrameByStartEnd(0, 0, 3, 0, false);
	mBeamAnimation->SetIsLoop(true);
	mBeamAnimation->SetFrameUpdateTime(0.07f);
	//빔에서 애니메이션
	mChangeFromBeamAnimation = new Animation();
	mChangeFromBeamAnimation->InitFrameByStartEnd(0, 1, 8, 1, false);
	mChangeFromBeamAnimation->SetIsLoop(false);
	mChangeFromBeamAnimation->SetFrameUpdateTime(0.07f);
	//사망 애니메이션
	mDeathAnimation = new Animation();
	mDeathAnimation->InitFrameByStartEnd(0, 0, 12, 0, true);
	mDeathAnimation->SetIsLoop(true);
	mDeathAnimation->SetFrameUpdateTime(0.07f);

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
	SafeDelete(mChangeToBeamAnimation);
	SafeDelete(mBeamAnimation);
	SafeDelete(mChangeFromBeamAnimation);
	SafeDelete(mDeathAnimation);
}

void Carrot::Update() {
	if (Input::GetInstance()->GetKeyDown(VK_CONTROL))
		mHP -= 25;

	if (mHP < 0 && mState != EnemyState::Death && mState != EnemyState::End) {
		mState = EnemyState::Death;
		mDelayTime = 0;
	}

	//상태에 따른 다른 애니메이션 출력
	switch (mState) {
	case EnemyState::Intro:
		mImage = mIntroImage;
		mY -= 320 * Time::GetInstance()->DeltaTime();
		mSizeX = mImage->GetFrameWidth();
		mSizeY = mImage->GetFrameHeight();
		mCurrentAnimation = mIntroAnimation;
		if (mCurrentAnimation->GetIsPlay() == false) {
			mState = EnemyState::Attack;
			mDelayTime = 0;
		}
		mCurrentAnimation->Play();
		break;

	case EnemyState::Attack:
		mImage = mAttackImage;
		mSizeX = mImage->GetFrameWidth();
		mSizeY = mImage->GetFrameHeight();
		mCurrentAnimation = mAttackAnimation;
		mDelayTime += Time::GetInstance()->DeltaTime();
		if (mDelayTime > 5)	
			mState = EnemyState::ToBeam;

		mCurrentAnimation->Play();
		break;

	case EnemyState::ToBeam:
		if (mCurrentAnimation != mChangeToBeamAnimation) {
			mCurrentAnimation->Stop();
			mChangeToBeamAnimation->Play();
		}
		mImage = mChangeToBeamImage;
		mSizeX = mImage->GetFrameWidth();
		mSizeY = mImage->GetFrameHeight();
		mCurrentAnimation = mChangeToBeamAnimation;
		if (mCurrentAnimation->GetIsPlay() == false) {
			mState = EnemyState::Beam;
			mDelayTime = 0;
		}
		mCurrentAnimation->Play();
		break;

	case EnemyState::Beam:
		if (mCurrentAnimation != mBeamAnimation) {
			mCurrentAnimation->Stop();
			mBeamAnimation->Play();
		}
		mImage = mBeamImage;
		mSizeX = mImage->GetFrameWidth();
		mSizeY = mImage->GetFrameHeight();
		mCurrentAnimation = mBeamAnimation;
		mDelayTime += Time::GetInstance()->DeltaTime();
		if (mDelayTime > 5)
			mState = EnemyState::FromBeam;
		mCurrentAnimation->Play();
		break;

	case EnemyState::FromBeam:
		if (mCurrentAnimation != mChangeFromBeamAnimation) {
			mCurrentAnimation->Stop();
			mChangeFromBeamAnimation->Play();
		}
		mImage = mChangeToBeamImage;
		mSizeX = mImage->GetFrameWidth();
		mSizeY = mImage->GetFrameHeight();
		mCurrentAnimation = mChangeFromBeamAnimation;
		if (mCurrentAnimation->GetIsPlay() == false) {
			mState = EnemyState::Attack;
			mDelayTime = 0;
		}
		mCurrentAnimation->Play();
		break;

	case EnemyState::Death:
		mImage = mDeathImage;
		mSizeX = mImage->GetFrameWidth();
		mSizeY = mImage->GetFrameHeight();
		mCurrentAnimation = mDeathAnimation;
		mCurrentAnimation->Play();
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
	//CameraManager::GetInstance()->GetMainCamera()
	//	->FrameRender(hdc, mImage, mRect.left, mRect.top, mCurrentAnimation->GetNowFrameX(), mCurrentAnimation->GetNowFrameY());
	mImage->FrameRender(hdc, mRect.left, mRect.top, mCurrentAnimation->GetNowFrameX(), mCurrentAnimation->GetNowFrameY());
	//CameraManager::GetInstance()->GetMainCamera()->RenderRect(hdc, mRect);
}
