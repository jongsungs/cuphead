#include "pch.h"
#include "Potato.h"

#include "Player.h"
#include "Image.h"
#include "Animation.h"
#include "Camera.h"
#include "PotatoProj.h"

Potato::Potato(const string& name, float x, float y)
	:Enemy(name, x, y)
{
}

void Potato::Init() {
	//상태 설정
	mState = EnemyState::Intro;
	//이미지 설정
	mIntroImage = IMAGEMANAGER->FindImage(L"PotatoIntro");
	mIdleImage = IMAGEMANAGER->FindImage(L"PotatoIdle");
	mAttackImage = IMAGEMANAGER->FindImage(L"PotatoSpitAttack");
	mDeathImage = IMAGEMANAGER->FindImage(L"PotatoDeath");

	//애니메이션 설정
	//등장 애니메이션
	mIntroAnimation = new Animation();
	mIntroAnimation->InitFrameByStartEnd(0, 0, 7, 0, false);
	mIntroAnimation->SetIsLoop(false);
	mIntroAnimation->SetFrameUpdateTime(0.07f);
	//기본 애니메이션
	mIdleAnimation = new Animation();
	mIdleAnimation->InitFrameByStartEnd(0, 0, 6, 0, false);
	mIdleAnimation->SetIsLoop(true);
	mIdleAnimation->SetFrameUpdateTime(0.07f);
	//공격 애니메이션
	mAttackAnimation = new Animation();
	mAttackAnimation->InitFrameByStartEnd(0, 0, 23, 0, false);
	mAttackAnimation->SetIsLoop(false);
	mAttackAnimation->SetFrameUpdateTime(0.07f);
	//사망 애니메이션
	mDeathAnimation = new Animation();
	mDeathAnimation->InitFrameByStartEnd(0, 0, 8, 0, false);
	mDeathAnimation->SetIsLoop(false);
	mDeathAnimation->SetFrameUpdateTime(0.07f);

	//초기생성시 들어가야 할 데이터
	mCurrentAnimation = mIntroAnimation;
	mCurrentAnimation->Play();
	mImage = mIntroImage;
	mSizeX = mImage->GetFrameWidth();
	mSizeY = mImage->GetFrameHeight();
	mRect = RectMakeCenter(mX, mY, mSizeX, mSizeY);

	//HP 임의설정
	mHP = 10;
	mAttackStartDelay = 0;
	mAttackCount = 0;
}

void Potato::Release() {
	SafeDelete(mIntroAnimation);
	SafeDelete(mIdleAnimation);
	SafeDelete(mAttackAnimation);
	SafeDelete(mDeathAnimation);
}

void Potato::Update() {
	if (Input::GetInstance()->GetKeyDown(VK_CONTROL))
		mHP -= 5;

	if (mHP <= 0 && mState != EnemyState::Death && mState != EnemyState::End) {
		mState = EnemyState::Death;
	}

	//상태에 따른 다른 애니메이션 출력
	switch (mState) {
	case EnemyState::Intro:
		mImage = mIntroImage;
		mSizeX = mImage->GetFrameWidth();
		mSizeY = mImage->GetFrameHeight();
		mCurrentAnimation = mIntroAnimation;
		if (mCurrentAnimation->GetIsPlay() == false) {
			mDelayTime = 0;
			mState = EnemyState::Idle;
		}

		mCurrentAnimation->Play();
		break;
	case EnemyState::Idle:
		if (mCurrentAnimation != mIdleAnimation) {
			mCurrentAnimation->Stop();
			mIdleAnimation->Play();
		}
		mImage = mIdleImage;
		mSizeX = mImage->GetFrameWidth();
		mSizeY = mImage->GetFrameHeight();
		mCurrentAnimation = mIdleAnimation;
		mDelayTime += Time::GetInstance()->DeltaTime();
		if (mAttackCount == 0) {
			if (mDelayTime > 3) {
				mCurrentAnimation->Stop();
				mAttackStartDelay = 0;
				mDelayTime = 0;
				mState = EnemyState::Attack;
				mIsPlay = false;
			}
		}
		else {
			mCurrentAnimation->Stop();
			mAttackStartDelay = 0;
			mDelayTime = 0;
			mState = EnemyState::Attack;
			mIsPlay = false;
			randomspit = Random::GetInstance()->RandomInt(3);
			randomworm = Random::GetInstance()->RandomInt(2);
		}
		mCurrentAnimation->Play();
		break;

	case EnemyState::Attack:
		if (mCurrentAnimation != mAttackAnimation) {
			mCurrentAnimation->Stop();
			mAttackAnimation->Play();
		}
		mImage = mAttackImage;
		mSizeX = mImage->GetFrameWidth();
		mSizeY = mImage->GetFrameHeight();
		mCurrentAnimation = mAttackAnimation;
		if (mIsAttack == false) {
			if (mAttackAnimation->GetNowFrameX() == 16) {
				mAttackCount++;
				if (mAttackCount < 4) {
					if (mIsPlay == false) {
						switch (randomspit) {
						case 0:
							SoundPlayer::GetInstance()->Play(L"PotatoSpit1", 0.4f);
							break;
						case 1:
							SoundPlayer::GetInstance()->Play(L"PotatoSpit2", 0.4f);
							break;
						case 2:
							SoundPlayer::GetInstance()->Play(L"PotatoSpit3", 0.4f);
							break;
						}
					}
					PotatoProj* proj = new PotatoProj("proj", mX - 213, mY + 155, 7, PI, false);
					proj->Init();
					ObjectManager::GetInstance()->AddObject(ObjectLayer::Enemy_Bullet, proj);
					mIsAttack = true;
					mIsPlay = true;
				}
				else {
					if (mIsPlay == false) {
						switch (randomworm) {
						case 0:
							SoundPlayer::GetInstance()->Play(L"PotatoSpitWorm1", 0.4f);
							break;
						case 1:
							SoundPlayer::GetInstance()->Play(L"PotatoSpitWorm2", 0.4f);
							break;
						}
					}
					PotatoProj* proj = new PotatoProj("proj", mX - 213, mY + 155, 7, PI, true);
					proj->Init();
					ObjectManager::GetInstance()->AddObject(ObjectLayer::Enemy_Bullet, proj);
					mIsAttack = true;
					mIsPlay = true;
					mAttackCount = 0;
				}
			}
		}

		if (mCurrentAnimation->GetIsPlay() == false) {
			mState = EnemyState::Idle;
			mCurrentAnimation->Stop();
			mIsAttack = false;
		}
		mCurrentAnimation->Play();
		break;

	case EnemyState::Death:
		if (mCurrentAnimation != mDeathAnimation) {
			mCurrentAnimation->Stop();
			mDeathAnimation->Play();
		}
		mImage = mDeathImage;
		mSizeX = mImage->GetFrameWidth();
		mSizeY = mImage->GetFrameHeight();
		mCurrentAnimation = mDeathAnimation;
		if (mCurrentAnimation->GetIsPlay() == false)
			mState = EnemyState::End;
		mCurrentAnimation->Play();
		break;

	case EnemyState::End:
		mIsActive = false;
		mIsDestroy = true;
		ObjectManager::GetInstance()->FindObject("Onion")->SetIsActive(true);
		break;
	}
	mRect = RectMakeCenter(mX, mY, mSizeX/2, mSizeY*3/4);
	mCurrentAnimation->Update();
}

void Potato::Render(HDC hdc) {
	//CameraManager::GetInstance()->GetMainCamera()->RenderRect(hdc, mRect);
	CameraManager::GetInstance()->GetMainCamera()
		->FrameRender(hdc, mImage, mX-mSizeX/2, mY-mSizeY/2, mCurrentAnimation->GetNowFrameX(), mCurrentAnimation->GetNowFrameY());
}

void Potato::InIntersectDamage(int dmage){
	mHP -= 1;
}