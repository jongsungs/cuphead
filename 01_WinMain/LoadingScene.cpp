#include "pch.h"
#include "LoadingScene.h"
#include "Image.h"
#include "Animation.h"
void LoadingScene::AddLoadFunc(const function<void(void)>& func)
{
	ThreadManager::GetInstance()->SetFunts(func);
}
void LoadingScene::AddLoadFunc(const vector<function<void(void)>>& funcs) // vector 통짜형 -> 스테이지 변경, 맵 변경 등 대량의 데이터들
{
	mIsEndLoading = false;
	for (int i = 0; i < funcs.size(); ++i) {
		mLoadList.push_back(funcs[i]);
	}
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
	if(!ThreadManager::GetInstance()->GetIsThreadPlay())
		mIsEndLoading = true;


	//if (mLoadIndex >= mLoadList.size())
	//{
	//	mIsEndLoading = true;
	//	mLoadList.clear();
	//	return;
	//}
	//function<void(void)> func = mLoadList[mLoadIndex];
	//func();
	//mLoadIndex++;
}

void LoadingScene::Render(HDC hdc)
{
	ImageManager::GetInstance()->FindImage(L"BlackGround")->ScaleRender(hdc,0,0,WINSIZEX,WINSIZEY);
	ImageManager::GetInstance()->FindImage(L"LoadingHourGlass")->FrameRenderFromBottom(hdc, WINSIZEX/8*7,WINSIZEY,mAnimation->GetNowFrameX(), mAnimation->GetNowFrameY());
}
