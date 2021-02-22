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
	//�⺻ ���·� �ʱ� ����
	mState = EnemyState::Intro;

	//ĳ���� ���¿� ���� �ٸ� �̹����� �����ֱ� ����
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

	//ĳ���� ���¿� ���� �ٸ� �ִϸ��̼��� �����ֱ� ����
	//���� �ִϸ��̼�
	mIntroAnimation = new Animation();
	mIntroAnimation->InitFrameByStartEnd(0, 0, 23, 0, false);
	mIntroAnimation->SetIsLoop(false);
	mIntroAnimation->SetFrameUpdateTime(0.1f);
	//�Ϲ� �ִϸ��̼�
	mIdleAnimation = new Animation();
	mIdleAnimation->InitFrameByStartEnd(0, 0, 14, 0, true);
	mIdleAnimation->SetIsLoop(true);
	mIdleAnimation->SetFrameUpdateTime(0.1f);
	//���� �ִϸ��̼�
	mAttackAnimation = new Animation();
	mAttackAnimation->InitFrameByStartEnd(0, 0, 11, 0, false);
	mAttackAnimation->SetIsLoop(true);
	mAttackAnimation->SetFrameUpdateTime(0.1f);
	//��� �ִϸ��̼�
	mDeathAnimation = new Animation();
	mDeathAnimation->InitFrameByStartEnd(0, 0, 5, 0, false);
	mDeathAnimation->SetIsLoop(false);
	mDeathAnimation->SetFrameUpdateTime(0.1f);
	//���� �ִϸ��̼�
	mDeathLeaveAnimation = new Animation();
	mDeathLeaveAnimation->InitFrameByStartEnd(0, 0, 30, 0, false);
	mDeathLeaveAnimation->SetIsLoop(false);
	mDeathLeaveAnimation->SetFrameUpdateTime(0.1f);

	mArmBashfulAnimation = new Animation();
	mArmBashfulAnimation->InitFrameByStartEnd(0, 0, 6, 0, false);
	mArmBashfulAnimation->SetIsLoop(false);
	mArmBashfulAnimation->SetFrameUpdateTime(0.1f);

	//�ʱ������ ���� �� ������
	mCurrentAnimation = mIntroAnimation;
	mCurrentAnimation->Play();
	mImage = mIntroImage;
	mSizeX = mImage->GetFrameWidth();
	mSizeY = mImage->GetFrameHeight();
	mRect = RectMakeCenter(mX, mY, mSizeX, mSizeY);

	//HP ���Ǽ���
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

	//���¿� ���� �ٸ� �ִϸ��̼� ���
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
