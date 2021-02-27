#include "pch.h"
#include "Scene_Start1.h"
#include "Scene_Start2.h"
#include "Image.h"
#include "Animation.h"

void Scene_Start1::Init()
{
	
	mImage = IMAGEMANAGER->FindImage(L"StartScene_Cup&Mug");
	mBackGroundImage = IMAGEMANAGER->FindImage(L"StartScene");

	mAnimation = new Animation();
	mAnimation->SetIsLoop(true);
	mAnimation->InitFrameByStartEnd(0, 0, 6, 0, true);
	mAnimation->SetFrameUpdateTime(0.2f);
	mAnimation->Play();
	
}

void Scene_Start1::Release()
{
	SafeDelete(mAnimation);
}

void Scene_Start1::Update()
{
	mAnimation->Update();
	if (Input::GetInstance()->GetKeyDown(VK_RETURN))
	{
		SceneManager::GetInstance()->AddScene(L"Start2", new Scene_Start2);
		SceneManager::GetInstance()->LoadScene(L"Start2");
	}
}

void Scene_Start1::Render(HDC hdc)
{
	mBackGroundImage->Render(hdc, 0, 0);
	mImage->FrameRender(hdc, 0, 0,mAnimation->GetNowFrameX(), mAnimation->GetNowFrameY());
}
