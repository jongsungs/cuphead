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
	//�⺻ ���·� �ʱ� ����
	mState = EnemyState::Intro;

	//ĳ���� ���¿� ���� �ٸ� �̹����� �����ֱ� ����
	mIntroImage = IMAGEMANAGER->FindImage(L"CarrotIntro");
	mAttackImage = IMAGEMANAGER->FindImage(L"CarrotBeam");
	mDeathImage = IMAGEMANAGER->FindImage(L"CarrotDeath");

	//ĳ���� ���¿� ���� �ٸ� �ִϸ��̼��� �����ֱ� ����
	//�Ϲ� �ִϸ��̼�
	mIntroAnimation = new Animation();
	mIntroAnimation->InitFrameByStartEnd(0, 0, 24, 0, false);
	mIntroAnimation->SetIsLoop(false);
	mIntroAnimation->SetFrameUpdateTime(0.1f);
	//���� ���� �ִϸ��̼�
	mInitAttackAnimation = new Animation();
	mInitAttackAnimation->InitFrameByStartEnd(0, 0, 8, 0, false);
	mInitAttackAnimation->SetIsLoop(false);
	mInitAttackAnimation->SetFrameUpdateTime(0.1f);

	//���� �ִϸ��̼�
	mAttackAnimation = new Animation();
	mAttackAnimation->InitFrameByStartEnd(9, 0, 12, 0, false);
	mAttackAnimation->SetIsLoop(true);
	mAttackAnimation->SetFrameUpdateTime(0.1f);

	//��� �ִϸ��̼�
	mDeathAnimation = new Animation();
	mDeathAnimation->InitFrameByStartEnd(0, 0, 7, 0, false);
	mDeathAnimation->SetIsLoop(false);
	mDeathAnimation->SetFrameUpdateTime(0.1f);

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

void Carrot::Release() {
	SafeDelete(mIntroAnimation);
	SafeDelete(mAttackAnimation);
	SafeDelete(mDeathAnimation);
	SafeDelete(mInitAttackAnimation);
}

void Carrot::Update() {

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
