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
	//���� ����
	mState = EnemyState::Intro;

	//�̹��� ����
	mIntroImage = IMAGEMANAGER->FindImage(L"PotatoIntro");
	mIdleImage = IMAGEMANAGER->FindImage(L"PotatoIdle");
	mAttackImage = IMAGEMANAGER->FindImage(L"PotatoSpitAttack");
	mDeathImage = IMAGEMANAGER->FindImage(L"PotatoDeath");
	
	//�ִϸ��̼� ����
	//���� �ִϸ��̼�
	mIntroAnimation = new Animation();
	mIntroAnimation->InitFrameByStartEnd(0, 0, 7, 0, false);
	mIntroAnimation->SetIsLoop(false);
	mIntroAnimation->SetFrameUpdateTime(0.1f);
	//�⺻ �ִϸ��̼�
	mIdleAnimation = new Animation();
	mIdleAnimation->InitFrameByStartEnd(0, 0, 6, 0, false);
	mIdleAnimation->SetIsLoop(true);
	mIdleAnimation->SetFrameUpdateTime(0.1f);
	//���� �ִϸ��̼�
	mAttackAnimation = new Animation();
	mAttackAnimation->InitFrameByStartEnd(0, 0, 19, 0, false);
	mAttackAnimation->SetIsLoop(false);
	mAttackAnimation->SetFrameUpdateTime(0.1f);
	//��� �ִϸ��̼�
	mDeathAnimation = new Animation();
	mDeathAnimation->InitFrameByStartEnd(0, 0, 8, 0, false);
	mDeathAnimation->SetIsLoop(false);
	mDeathAnimation->SetFrameUpdateTime(0.1f);
	
	//�ʱ������ ���� �� ������
	mCurrentAnimation = mIntroAnimation;
	mImage = mIntroImage;
	mSizeX = mImage->GetFrameWidth();
	mSizeY = mImage->GetFrameHeight();
	mRect = RectMakeCenter(mX, mY, mSizeX, mSizeY);	
	
	//HP ���Ǽ���
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
	if (mHP <= 0)
		mState = EnemyState::Death;

	//���¿� ���� �ٸ� �ִϸ��̼� ���
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
			mImage = mAttackImage;
			mSizeX = mImage->GetFrameWidth();
			mSizeY = mImage->GetFrameHeight();
			mCurrentAnimation = mAttackAnimation;
			mAttackStartDelay += Time::GetInstance()->DeltaTime();

			if (mAttackStartDelay > 50) {
				mAttackCount++;
				//�߻�ü ����
				while (mAttackCount < 4) {
					//�и��Ұ��� ������Ʈ
					if (mAttackCount == 3) {
						//�и����� ������Ʈ
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
