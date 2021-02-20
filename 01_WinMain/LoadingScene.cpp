#include "pch.h"
#include "LoadingScene.h"

void LoadingScene::AddLoadFunc(const function<void(void)>& func)
{
	mLoadList.push_back(func);
}

void LoadingScene::Init()
{
	mLoadIndex = 0;
	mIsEndLoading = false;
}

void LoadingScene::Release()
{
}

void LoadingScene::Update()
{
	if (mLoadIndex >= mLoadList.size())
	{
		if (Input::GetInstance()->GetKeyDown(VK_SPACE))
		{
			mIsEndLoading = true;
		}
		return;
	}
	//if (mLoadIndex >= mLoadList.size())
	//{
	//	mIsEndLoading = true;
	//	return;
	//}

	function<void(void)> func = mLoadList[mLoadIndex];
	func();
	mLoadIndex++;
}

void LoadingScene::Render(HDC hdc)
{
	if (mLoadIndex >= mLoadList.size()) {
		wstring CheckString = L"로딩 완료 스페이스를 눌러 주세요.";
		TextOut(hdc, WINSIZEX / 2 - CheckString.size(), WINSIZEY / 2 - 30, CheckString.c_str(), CheckString.size());
	}
	TextOut(hdc, WINSIZEX / 4, WINSIZEY / 2 + 10, wstring(L"0%").c_str(), wstring(L"0%").size());
	TextOut(hdc, WINSIZEX / 4 * 3 - (wstring(L"100%").length() * 2), WINSIZEY / 2 + 10, wstring(L"100%").c_str(), wstring(L"100%").size());
	RenderLine(hdc, WINSIZEX / 4, WINSIZEY / 2, Math::Lerp(WINSIZEX / 4, WINSIZEX / 4 * 3, (float)mLoadIndex / mLoadList.size()), WINSIZEY / 2);
	wstring Index = to_wstring(mLoadIndex) + L"/" + to_wstring(mLoadList.size());
	TextOut(hdc, WINSIZEX / 2, 10, Index.c_str(), Index.size());
}
