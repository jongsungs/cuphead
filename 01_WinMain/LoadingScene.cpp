#include "pch.h"
#include "LoadingScene.h"
#include "Image.h"
#include "Animation.h"
void LoadingScene::AddLoadFunc(const function<void(void)>& func)
{
	mLoadList.push_back(func);
}

void LoadingScene::Init()
{
	mLoadIndex = 0;
	mIsEndLoading = false;
	mAnimation = new Animation();
	mAnimation->InitFrameByStartEnd(0,0,45,0,false);
	mAnimation->SetFrameUpdateTime(0.05f);
	mAnimation->SetIsLoop(true);
	mAnimation->Play();
}

void LoadingScene::Release()
{
	SafeDelete(mAnimation);
}

void LoadingScene::Update()
{
	mAnimation->Update();
	if (mLoadIndex >= mLoadList.size())
	{
		if (Input::GetInstance()->GetKeyDown(VK_SPACE))
		{
			mIsEndLoading = true;
			mLoadList.clear();
		}
		return;
	}
	function<void(void)> func = mLoadList[mLoadIndex];
	func();
	mLoadIndex++;
}

void LoadingScene::Render(HDC hdc)
{
	ImageManager::GetInstance()->FindImage(L"BlackGround")->ScaleRender(hdc,0,0,WINSIZEX,WINSIZEY);
	ImageManager::GetInstance()->FindImage(L"LoadingHourGlass")->FrameRenderFromBottom(hdc, WINSIZEX/8*7,WINSIZEY,mAnimation->GetNowFrameX(), mAnimation->GetNowFrameY());
}
