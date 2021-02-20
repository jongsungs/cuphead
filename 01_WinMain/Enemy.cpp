#include "pch.h"
#include "Enemy.h"

#include "Player.h"
#include "Image.h"
#include "Animation.h"
#include "Camera.h"

Enemy::Enemy(const string& name, float x, float y)
	:GameObject(name)
{
	mX = x;
	mY = y;
}

/*
※코드 개요
1. 적의 상태(기본, 공격, 사망)에 따른 다른 애니메이션 표시
2. 플레이어의 좌표를 받아와 일정 거리 이내에 들어올 때까지 꾸준히 일정한 빠르기로 이동
3. 적과 플레이어 사이의 각도를 계산하여 이동할 때
3. 적과 플레이어와의 거리를 계산하여 일정 거리 이내에 있을 때 공격(폭발효과 실행)

4. 플레이어가 공격하여 맞았다는 정보가 들어오면 현재 애니메이션의 진행에서 해당 프레임에서의 프레임Y 값만 증가
   (부드러운 정보 전달이 되지 않는다면 넉넉하게 피격 프레임 이후에도 증가한 값을 유지)
*/

void Enemy::Init() {


	//기본 상태로 초기 생성
	mState = EnemyState::Idle;

	//캐릭터 상태에 따라 다른 이미지를 보여주기 위함
	mIdleImage = IMAGEMANAGER->FindImage(L"EnemyIdle");
	mAttackImage = IMAGEMANAGER->FindImage(L"EnemyAttack");
	mDeathImage = IMAGEMANAGER->FindImage(L"EnemyDeath");

	//캐릭터 상태에 따라 다른 애니메이션을 보여주기 위함
	//일반 애니메이션
	mIdleAnimation = new Animation();
	mIdleAnimation->InitFrameByStartEnd(0, 0, 2, 0, false);
	mIdleAnimation->SetIsLoop(true);
	mIdleAnimation->SetFrameUpdateTime(0.2f);
	mIdleAnimation->Play();
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
	//폭발 이펙트
	mExplosionAnimation = new Animation();
	mExplosionAnimation->InitFrameByStartEnd(0, 0, 27, 0, false);
	mExplosionAnimation->SetIsLoop(false);
	mExplosionAnimation->SetFrameUpdateTime(0.1f);
	//초기생성시 들어가야 할 데이터
	mCurrentAnimation = mIdleAnimation;
	mImage = mIdleImage;
	mSizeX = mImage->GetFrameWidth();
	mSizeY = mImage->GetFrameHeight();
	mRect = RectMakeCenter(mX, mY, mSizeX, mSizeY);
	mSpeed = 50.f;
	mAngle = 0;
	mRandomExplosion = Random::GetInstance()->RandomInt(3);
	switch (mRandomExplosion) {
	case 0:
		mExplosionImage = IMAGEMANAGER->FindImage(L"BigExplosion");
		break;
	case 1:
		mExplosionImage = IMAGEMANAGER->FindImage(L"MiddleExplosion");
		break;
	case 2:
		mExplosionImage = IMAGEMANAGER->FindImage(L"SmallExplosion");
		break;
	}
	//HP 임의설정
	mHP = 50;
	IsAttack = false;
	mAttackStartDelay = 0;
	mBetweenAttackDelay = 2;
}

void Enemy::Release() {
	SafeDelete(mIdleAnimation);
	SafeDelete(mAttackAnimation);
	SafeDelete(mDeathAnimation);
	SafeDelete(mExplosionAnimation);
}

void Enemy::Update() {
	IsAttack = false;
	if (mHP <= 0)
		mState = EnemyState::Death;

	//플레이어와 자신과의 각도 계산
	mAngle = Math::GetAngle(4 * mX, 4 * mY, mPlayer->GetX(), mPlayer->GetY());
	//각도에 따라 다른 애니메이션을 호출하기 위해
	if (mAngle >= 0 && mAngle < PI / 2)
		direction = 0;
	else if (mAngle >= PI / 2 && mAngle < PI)
		direction = 1;
	else if (mAngle >= PI && mAngle < PI * 3 / 2)
		direction = 2;
	else
		direction = 3;

	//상태에 따른 다른 애니메이션 출력
	switch (mState) {
	case EnemyState::Idle:
		mImage = mIdleImage;
		mSizeX = mImage->GetFrameWidth();
		mSizeY = mImage->GetFrameHeight();
		mCurrentAnimation = mIdleAnimation;
		mCurrentAnimation->Play();

		mX += mSpeed * Time::GetInstance()->DeltaTime() * cosf(mAngle);
		mY += mSpeed * Time::GetInstance()->DeltaTime() * -sinf(mAngle);

		if (Math::GetDistance(4 * mX, 4 * mY, mPlayer->GetX(), mPlayer->GetY()) <= mExplosionImage->GetFrameHeight() * 3) {
			mBetweenAttackDelay += Time::GetInstance()->DeltaTime();
			if (mBetweenAttackDelay > 2) {
				mAttackStartDelay = 0;
				mState = EnemyState::Attack;
				mRandomExplosion = Random::GetInstance()->RandomInt(3);

				switch (mRandomExplosion) {
				case 0:
					mExplosionImage = IMAGEMANAGER->FindImage(L"BigExplosion");
					break;
				case 1:
					mExplosionImage = IMAGEMANAGER->FindImage(L"MiddleExplosion");
					break;
				case 2:
					mExplosionImage = IMAGEMANAGER->FindImage(L"SmallExplosion");
					break;
				}
			}

			mExplosionRect = RectMakeCenter(4 * mX, 4 * mY, mExplosionImage->GetFrameWidth() * 4, mExplosionImage->GetFrameHeight() * 4);
		}
		break;

	case EnemyState::Attack:
		mImage = mAttackImage;
		mSizeX = mImage->GetFrameWidth();
		mSizeY = mImage->GetFrameHeight();
		mCurrentAnimation = mAttackAnimation;
		mCurrentAnimation->Play();

		mAttackStartDelay += Time::GetInstance()->DeltaTime();

		if (mAttackStartDelay > 1)
			mExplosionAnimation->Play();

		if (mExplosionAnimation->GetNowFrameX() >= 27) {
			mExplosionAnimation->Stop();
			mBetweenAttackDelay = 0;
			mState = EnemyState::Idle;
		}
		break;

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

	mRect = RectMakeCenter(4 * mX, 4 * mY, mSizeX*4, mSizeY*4);
	mCurrentAnimation->Update();
	mExplosionAnimation->Update();
}

void Enemy::Render(HDC hdc) {
	//폭발 이펙트
	if (mExplosionAnimation->GetIsPlay() == true) {
		CameraManager::GetInstance()->GetMainCamera()
			->ScaleFrameRender(hdc, mExplosionImage, mExplosionRect.left, mExplosionRect.top, mExplosionAnimation->GetNowFrameX(), mExplosionAnimation->GetNowFrameY(), mExplosionImage->GetFrameWidth() * 4, mExplosionImage->GetFrameHeight() * 4);
		//CameraManager::GetInstance()->GetMainCamera()->RenderRect(hdc, mExplosionRect);
	}

	//에너미
	if (mState == EnemyState::Idle) {
		CameraManager::GetInstance()->GetMainCamera()
			->ScaleFrameRender(hdc, mImage, mRect.left, mRect.top, mCurrentAnimation->GetNowFrameX(), direction + (IsAttack == true ? 4 : 0), mImage->GetFrameWidth() * 4, mImage->GetFrameHeight() * 4);
	}
	else if (mState == EnemyState::Attack) {
		CameraManager::GetInstance()->GetMainCamera()
			->ScaleFrameRender(hdc, mImage, mRect.left, mRect.top, mCurrentAnimation->GetNowFrameX(), (direction > 2 ? 0 : 1) + (IsAttack == true ? 2 : 0), mImage->GetFrameWidth() * 4, mImage->GetFrameHeight() * 4);
	}
	else if(mState == EnemyState::Death)
		CameraManager::GetInstance()->GetMainCamera()
		->ScaleFrameRender(hdc, mImage, mRect.left, mRect.top, mCurrentAnimation->GetNowFrameX(), mCurrentAnimation->GetNowFrameY(), mImage->GetFrameWidth() * 4, mImage->GetFrameHeight() * 4);

	//CameraManager::GetInstance()->GetMainCamera()->RenderRect(hdc, mRect);
}
