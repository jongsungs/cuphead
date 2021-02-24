#include "pch.h"
#include "Potato.h"

#include "Player.h"
#include "Image.h"
#include "Animation.h"
#include "Camera.h"

Potato::Potato(const string& name, float x, float y)
	:Enemy(name,x,y)
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
	mDeathAnimation->InitFrameByStartEnd(0, 0, 8, 0, true);
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
		mHP -= 25;
	
	if (mHP < 0 && mState != EnemyState::Death && mState != EnemyState::End) {
		mState = EnemyState::Death;
		mDelayTime = 0;
	}

	//상태에 따른 다른 애니메이션 출력
	switch (mState) {
		case EnemyState::Intro:
			mImage = mIntroImage;

			mY -= 850 * Time::GetInstance()->DeltaTime();
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
				if (mDelayTime > 1) {
					mCurrentAnimation->Stop();
					mAttackStartDelay = 0;
					mDelayTime = 0;
					mState = EnemyState::Attack;
				}
			}
			else {
				mCurrentAnimation->Stop();
				mAttackStartDelay = 0;
				mDelayTime = 0;
				mState = EnemyState::Attack;
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
			mAttackStartDelay += Time::GetInstance()->DeltaTime();

			if (mAttackStartDelay > 50) {
				mAttackCount++;
				//발사체 생성
				while (mAttackCount < 4) {
					//	Bullet* bullet = new Bullet();
					//	bullet->Init();
					//	mBullet.push_back(bullet);
					if (mAttackCount == 3) {
						//패링가능 오브젝트
						//	Bullet* bullet = new Bullet();
						//	bullet->Init();
						//	mBullet.push_back(bullet);
						mAttackCount = 0;
					}
				}
			}
			if (mCurrentAnimation->GetIsPlay() == false) {
 				mState = EnemyState::Idle;
				mCurrentAnimation->Stop();
			}
			mCurrentAnimation->Play();
			break;

		case EnemyState::Death:
			if (mCurrentAnimation != mDeathAnimation) {
				mCurrentAnimation->Stop();
				mDeathAnimation->Play();
			}
			mImage = mDeathImage;
			mY += 500 * Time::GetInstance()->DeltaTime();
			mSizeX = mImage->GetFrameWidth();
			mSizeY = mImage->GetFrameHeight();
			mCurrentAnimation = mDeathAnimation;
			mDelayTime += Time::GetInstance()->DeltaTime();		
			if (mDelayTime > 1)
				mState = EnemyState::End;
			mCurrentAnimation->Play();
			break;

		case EnemyState::End:
			mIsActive = false;
			mIsDestroy = true;
			ObjectManager::GetInstance()->FindObject("Onion")->SetIsActive(true);
			break;
	}
	mRect = RectMakeCenter(mX, mY, mSizeX, mSizeY);
	mCurrentAnimation->Update();
}

void Potato::Render(HDC hdc) {
	CameraManager::GetInstance()->GetMainCamera()
		->FrameRender(hdc, mImage, mRect.left, mRect.top, mCurrentAnimation->GetNowFrameX(), mCurrentAnimation->GetNowFrameY());
	//CameraManager::GetInstance()->GetMainCamera()->RenderRect(hdc, mRect);
}
