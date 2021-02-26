#include "pch.h"
#include "FadeOut.h"
#include "Animation.h"
#include "Camera.h"
#include "Image.h"
#include "Scene.h"
#include "LoadingScene.h"

FadeOut::FadeOut(bool isReverse, float frameTime)
{
	mIsReverse = isReverse;
	mX = WINSIZEX/2;
	mY = WINSIZEY/2;
	mImage = IMAGEMANAGER->FindImage(L"FadeOut");
	mAnimation = new Animation();
	mAnimation->InitFrameByBackStartEnd(mImage->GetFrameX() - 1, 0, 0, 0, false);
	mAnimation->SetIsLoop(false);
	mAnimation->SetFrameUpdateTime(frameTime);
	mAnimation->Play();

	mIsActive = true;
	mIsDestroy = false;
	ObjectManager::GetInstance()->AddObject(ObjectLayer::FadeOut, this);

	mRect = RectMakeCenter(mX, mY, mImage->GetFrameWidth(), mImage->GetFrameHeight());
}

FadeOut::FadeOut(bool isReverse, wstring targetSceneName, wstring loadingSceneName ,float frameTime)
{
	mTargetSceneName = targetSceneName;
	mLoadingSceneName = loadingSceneName;
	mIsReverse = isReverse;
	mX = WINSIZEX / 2;
	mY = WINSIZEY / 2;
	mImage = IMAGEMANAGER->FindImage(L"FadeOut");
	mAnimation = new Animation();
	mAnimation->InitFrameByStartEnd(0, 0, mImage->GetFrameX() - 1, 0, false);
	mAnimation->SetIsLoop(false);
	mAnimation->SetFrameUpdateTime(frameTime);
	mAnimation->Play();

	mIsActive = true;
	mIsDestroy = false;
	ObjectManager::GetInstance()->AddObject(ObjectLayer::FadeOut, this);

	mRect = RectMakeCenter(mX, mY, mImage->GetFrameWidth(), mImage->GetFrameHeight());
}

void FadeOut::Init()
{
	
}

void FadeOut::Update()
{
	if (!mIsReverse)
	{
		if (!mAnimation->GetIsPlay())
		{
			mIsDestroy = true;
			
			SceneManager::GetInstance()->AddScene(mLoadingSceneName, new LoadingScene);
			SceneManager::GetInstance()->LoadSceneLoading(mTargetSceneName, mLoadingSceneName);
			ObjectManager::GetInstance()->Delete();
		}
		else
		{
			mAnimation->Update();
		}
	}
	else
	{
		if (!mAnimation->GetIsPlay())
		{
			mIsDestroy = true;
		}
		else
		{
			mAnimation->Update();
		}
	}
	
}

void FadeOut::Release()
{
	SafeDelete(mAnimation);
}

void FadeOut::Render(HDC hdc)
{
	mImage->ScaleFrameRender(hdc, mRect.left, mRect.top, mAnimation->GetNowFrameX(), mAnimation->GetNowFrameY(), mImage->GetFrameWidth(), mImage->GetFrameHeight());
}
