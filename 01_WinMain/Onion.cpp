#include "pch.h"
#include "Onion.h"

#include "Player.h"
#include "Image.h"
#include "Animation.h"
#include "Camera.h"
#include "OnionProj.h"

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

	mChangeToAttackImage = IMAGEMANAGER->FindImage(L"OnionChangeToAttack");
	mAttackImage = IMAGEMANAGER->FindImage(L"OnionAttack");
	mBeforeAttackImage = IMAGEMANAGER->FindImage(L"OnionBeforeAttack");
	mDeathImage = IMAGEMANAGER->FindImage(L"OnionDeath");

	mDeathLeaveImage = IMAGEMANAGER->FindImage(L"OnionDeathLeave");

	mTearEffectImage = IMAGEMANAGER->FindImage(L"OnionTearEffect");
		
	//캐릭터 상태에 따라 다른 애니메이션을 보여주기 위함
	//등장 애니메이션
	mIntroAnimation = new Animation();
	mIntroAnimation->InitFrameByStartEnd(0, 0, 23, 0, false);
	mIntroAnimation->SetIsLoop(false);
	mIntroAnimation->SetFrameUpdateTime(0.07f);
	//일반 애니메이션
	mIdleAnimation = new Animation();
	mIdleAnimation->InitFrameByStartEnd(0, 0, 14, 0, true);
	mIdleAnimation->SetIsLoop(true);
	mIdleAnimation->SetFrameUpdateTime(0.07f);
	//공격 전에 나오는 일회용 애니메이션
	mBeforeAttackAnimation = new Animation();
	mBeforeAttackAnimation->InitFrameByStartEnd(0, 0, 5, 0, false);
	mBeforeAttackAnimation->SetIsLoop(false);
	mBeforeAttackAnimation->SetFrameUpdateTime(0.07f);
	mBeforeAttackAnimation->Play();
	//공격으로 변화
	mChangeToAttackAnimation = new Animation();
	mChangeToAttackAnimation->InitFrameByStartEnd(0, 0, 7, 0, false);
	mChangeToAttackAnimation->SetIsLoop(false);
	mChangeToAttackAnimation->SetFrameUpdateTime(0.1f);
	mChangeToAttackAnimation->Play();
	//공격 애니메이션
	mAttackAnimation = new Animation();
	mAttackAnimation->InitFrameByStartEnd(0, 0, 7, 0, true);
	mAttackAnimation->SetIsLoop(true);
	mAttackAnimation->SetFrameUpdateTime(0.07f);
	//공격에서 변화
	mChangeFromAttackAnimation = new Animation();
	mChangeFromAttackAnimation->InitFrameByStartEnd(0, 1, 7, 1, false);
	mChangeFromAttackAnimation->SetIsLoop(false);
	mChangeFromAttackAnimation->SetFrameUpdateTime(0.1f);
	mChangeFromAttackAnimation->Play();
	//사망 애니메이션
	mDeathAnimation = new Animation();
	mDeathAnimation->InitFrameByStartEnd(0, 0, 5, 0, true);
	mDeathAnimation->SetIsLoop(true);
	mDeathAnimation->SetFrameUpdateTime(0.07f);
	//퇴장 애니메이션
	mDeathLeaveAnimation = new Animation();
	mDeathLeaveAnimation->InitFrameByStartEnd(0, 0, 30, 0, false);
	mDeathLeaveAnimation->SetIsLoop(false);
	mDeathLeaveAnimation->SetFrameUpdateTime(0.07f);
	//공격시 나오는 눈물 효과 애니메이션
	mTearEffectAnimation = new Animation();
	mTearEffectAnimation->InitFrameByStartEnd(0, 0, 3, 0, false);
	mTearEffectAnimation->SetIsLoop(true);
	mTearEffectAnimation->SetFrameUpdateTime(0.07f);
	
	//초기생성시 들어가야 할 데이터
	mCurrentAnimation = mIntroAnimation;
	mCurrentAnimation->Play();
	
	mTearEffectAnimation->Play();
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
	SafeDelete(mBeforeAttackAnimation);
	SafeDelete(mChangeToAttackAnimation);
	SafeDelete(mChangeFromAttackAnimation);
	SafeDelete(mTearEffectAnimation);
}

void Onion::Update() {
	if (Input::GetInstance()->GetKeyDown(VK_CONTROL))
		mHP -= 25;

	if (mHP < 0 && mState != EnemyState::Death && mState != EnemyState::End) {
		mState = EnemyState::End;
		mDelayTime = 0;
	}

	//상태에 따른 다른 애니메이션 출력
	switch (mState) {
	case EnemyState::Intro:
		mImage = mIntroImage;
		mSizeX = mImage->GetFrameWidth();
		mSizeY = mImage->GetFrameHeight();
		mCurrentAnimation = mIntroAnimation;
		if (mCurrentAnimation->GetIsPlay() == false) {
			mState = EnemyState::Idle;
			mDelayTime = 0;
		}
		break;
		
		
	case EnemyState::Idle:
		mImage = mIdleImage;
		mSizeX = mImage->GetFrameWidth();
		mSizeY = mImage->GetFrameHeight();
		mCurrentAnimation = mIdleAnimation;
		mDelayTime += Time::GetInstance()->DeltaTime();
		if(mDelayTime > 3)
			mState = EnemyState::BeforeAttack;
			
		mCurrentAnimation->Play();
		break;

	case EnemyState::BeforeAttack:
		mImage = mBeforeAttackImage;
		mSizeX = mImage->GetFrameWidth();
		mSizeY = mImage->GetFrameHeight();
		mCurrentAnimation = mBeforeAttackAnimation;
		if (mCurrentAnimation->GetIsPlay() == false) {
			mState = EnemyState::ToAttack;
			mCurrentAnimation->Stop();
		}
		mCurrentAnimation->Play();
		break;

	case EnemyState::ToAttack:
		mImage = mChangeToAttackImage;
		mSizeX = mImage->GetFrameWidth();
		mSizeY = mImage->GetFrameHeight();
		mCurrentAnimation = mChangeToAttackAnimation;
		if (mCurrentAnimation->GetIsPlay() == false) {
			mDelayTime = 0;
			mState = EnemyState::Attack;
		}
		mCurrentAnimation->Play();
		break;

	case EnemyState::Attack:
		mImage = mAttackImage;
		mSizeX = mImage->GetFrameWidth();
		mSizeY = mImage->GetFrameHeight();
		mCurrentAnimation = mAttackAnimation;
		mDelayTime += Time::GetInstance()->DeltaTime();
		if (mDelayTime > 5) {
			mState = EnemyState::FromAttack;
			mTearEffectAnimation->Stop();
		}
		mBetweenAttackDelay += Time::GetInstance()->DeltaTime();
		if (mBetweenAttackDelay > 0.4) {
			mProjInitX = Random::GetInstance()->RandomInt(WINSIZEX);
			OnionProj* proj = new OnionProj("proj", mProjInitX, 0, 5, PI*3/2, false);
			proj->Init();
			ObjectManager::GetInstance()->AddObject(ObjectLayer::Enemy_Bullet, proj);
			mBetweenAttackDelay = 0;
		}

		mTearEffectAnimation->Play();
		mCurrentAnimation->Play();
		break;

	case EnemyState::FromAttack:
		mImage = mChangeToAttackImage;
		mSizeX = mImage->GetFrameWidth();
		mSizeY = mImage->GetFrameHeight();
		mCurrentAnimation = mChangeFromAttackAnimation;
		if (mCurrentAnimation->GetIsPlay() == false) {
			mState = EnemyState::ToAttack;
			mCurrentAnimation->Stop();
		}
		mCurrentAnimation->Play();
		break;

	case EnemyState::Death:
		mImage = mDeathImage;
		mSizeX = mImage->GetFrameWidth();
		mSizeY = mImage->GetFrameHeight();
		mCurrentAnimation = mDeathAnimation;
		mCurrentAnimation->Play();
		
		if (mCurrentAnimation->GetIsPlay() == false)
			mState = EnemyState::End;
	
		break;

	case EnemyState::End:
		mIsActive = false;
		mIsDestroy = true;
		ObjectManager::GetInstance()->FindObject("Carrot")->SetIsActive(true);
		break;
	}

	mRect = RectMakeCenter(mX, mY, mSizeX, mSizeY);
	if(mTearEffectAnimation->GetIsPlay())
		mTearEffectAnimation->Update();
	mCurrentAnimation->Update();
}

void Onion::Render(HDC hdc) {
	CameraManager::GetInstance()->GetMainCamera()
		->ScaleFrameRenderFromBottom(hdc, mImage, mX, mRect.bottom, mCurrentAnimation->GetNowFrameX(), mCurrentAnimation->GetNowFrameY(), 472, 570);
	if(mState == EnemyState::Attack)
		CameraManager::GetInstance()->GetMainCamera()
			->FrameRenderFromBottom(hdc, mTearEffectImage, mX, mY-60, mTearEffectAnimation->GetNowFrameX(), mTearEffectAnimation->GetNowFrameY());
	//CameraManager::GetInstance()->GetMainCamera()->RenderRect(hdc, mRect);
}
