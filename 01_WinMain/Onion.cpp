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
	mAttackImage = IMAGEMANAGER->FindImage(L"OnionCry");
	mDeathImage = IMAGEMANAGER->FindImage(L"OnionDeath");
	mDeathLeaveImage = IMAGEMANAGER->FindImage(L"OnionDeathLeave");

	mBashfulImage = IMAGEMANAGER->FindImage(L"OnionDeath");
	mBashfulLeaveImage = IMAGEMANAGER->FindImage(L"OnionDeath");

	mTearAImage = IMAGEMANAGER->FindImage(L"OnionTearA");
	mTearBImage = IMAGEMANAGER->FindImage(L"OnionTearB");

	//ĳ���� ���¿� ���� �ٸ� �ִϸ��̼��� �����ֱ� ����
	//���� �ִϸ��̼�
	mIntroAnimation = new Animation();
	mIntroAnimation->InitFrameByStartEnd(0, 0, 23, 0, false);
	mIntroAnimation->SetIsLoop(false);
	mIntroAnimation->SetFrameUpdateTime(0.07f);
	//�Ϲ� �ִϸ��̼�
	mIdleAnimation = new Animation();
	mIdleAnimation->InitFrameByStartEnd(0, 0, 14, 0, true);
	mIdleAnimation->SetIsLoop(true);
	mIdleAnimation->SetFrameUpdateTime(0.07f);
	//���� �ִϸ��̼�
	mAttackAnimation = new Animation();
	mAttackAnimation->InitFrameByStartEnd(0, 0, 21, 0, false);
	mAttackAnimation->SetIsLoop(true);
	mAttackAnimation->SetFrameUpdateTime(0.07f);
	//��� �ִϸ��̼�
	mDeathAnimation = new Animation();
	mDeathAnimation->InitFrameByStartEnd(0, 0, 5, 0, true);
	mDeathAnimation->SetIsLoop(true);
	mDeathAnimation->SetFrameUpdateTime(0.07f);
	//���� �ִϸ��̼�
	mDeathLeaveAnimation = new Animation();
	mDeathLeaveAnimation->InitFrameByStartEnd(0, 0, 30, 0, false);
	mDeathLeaveAnimation->SetIsLoop(false);
	mDeathLeaveAnimation->SetFrameUpdateTime(0.07f);
	
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
}

void Onion::Update() {
	if (Input::GetInstance()->GetKeyDown(VK_CONTROL))
		mHP -= 25;

	if (mHP < 0 && mState != EnemyState::Death && mState != EnemyState::End) {
		mState = EnemyState::Death;
		mDelayTime = 0;
	}

	//���¿� ���� �ٸ� �ִϸ��̼� ���
	switch (mState) {
	case EnemyState::Intro:
		mY -= 270 * Time::GetInstance()->DeltaTime();
		mImage = mIntroImage;
		mSizeX = mImage->GetFrameWidth();
		mSizeY = mImage->GetFrameHeight();
		mCurrentAnimation = mIntroAnimation;
		if (mCurrentAnimation->GetIsPlay() == false)
			mState = EnemyState::Idle;
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

	case EnemyState::Attack:
		mImage = mAttackImage;
		mSizeX = mImage->GetFrameWidth();
		mSizeY = mImage->GetFrameHeight();
		mCurrentAnimation = mAttackAnimation;
		//if (mCurrentAnimation->GetIsPlay() == false)
		//	mState = EnemyState::Death;
		mCurrentAnimation->Play();
		break;

	case EnemyState::Death:
		mImage = mDeathImage;
		mY += 200 * Time::GetInstance()->DeltaTime();
		mSizeX = mImage->GetFrameWidth();
		mSizeY = mImage->GetFrameHeight();
		mCurrentAnimation = mDeathAnimation;
		mCurrentAnimation->Play();
		mDelayTime += Time::GetInstance()->DeltaTime();
		if (mDelayTime > 1)
			mState = EnemyState::End;
		break;

	case EnemyState::End:
		mIsActive = false;
		mIsDestroy = true;
		ObjectManager::GetInstance()->FindObject("Carrot")->SetIsActive(true);
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
