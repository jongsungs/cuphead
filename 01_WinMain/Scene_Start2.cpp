#include "pch.h"
#include "Scene_Start2.h"
#include "Image.h"
#include "LoadingScene.h"
void Scene_Start2::Init()
{
	
	mImages[0] = IMAGEMANAGER->FindImage(L"Start_Select");
	mImages[1] = IMAGEMANAGER->FindImage(L"Start_Option");
	mImages[2] = IMAGEMANAGER->FindImage(L"Start_Exit");
	mNum = 0;
		
}

void Scene_Start2::Release()
{
}

void Scene_Start2::Update()
{
	if (Input::GetInstance()->GetKeyDown(VK_DOWN))
	{
		if (mNum < 2)
		{
			mNum++;
			SoundPlayer::GetInstance()->Play(L"Select", 1.f);
		}
	}
	if (Input::GetInstance()->GetKeyDown(VK_UP))
	{	
		SoundPlayer::GetInstance()->Play(L"Select", 1.f);
		if (mNum > 0)
		{
			mNum--;
			SoundPlayer::GetInstance()->Play(L"Select", 1.f);
		}
	}
	if (Input::GetInstance()->GetKeyDown(VK_RETURN) || Input::GetInstance()->GetKeyDown('Z'))
	{
		switch (mNum)
		{
		case 0:
			SoundPlayer::GetInstance()->Stop(L"Start");
			SoundPlayer::GetInstance()->Play(L"Select", 1.f);
			SceneManager::GetInstance()->LoadSceneLoading(L"ElderHouse", L"Start1LoadingScene");
			break;
		case 1:
			break;
		case 2:
			break;
		}
	}
}

void Scene_Start2::Render(HDC hdc)
{
	mImages[mNum]->Render(hdc, 0, 0);
}
