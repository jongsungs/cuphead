#include "pch.h"
#include "Scene_ElderHouse.h"
#include "Camera.h"
#include "Cuphead_OverWorld.h"
#include "Scene_OverWorld.h"
#include "LoadingScene.h"
#include "FadeOut.h"
void Scene_ElderHouse::Init()
{
	

	mImage = IMAGEMANAGER->GetInstance()->FindImage(L"ElderHouse_Inside");
	
	mPlayer = new Cuphead_OverWorld("ElderHouse_Player", 200, 200);
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Player, mPlayer);

	ObjectManager::GetInstance()->Init();
	
	Camera* camera = new Camera();
	camera->SetMode(Camera::Mode::Follow);

	CameraManager::GetInstance()->GetMainCamera()->SetTarget(mPlayer);
	CameraManager::GetInstance()->SetMainCamera(camera);
	mDoorRect = RectMakeCenter(100, 500, 100, 100);
}

void Scene_ElderHouse::Release()
{
}

void Scene_ElderHouse::Update()
{
	
	RECT rctemp;
	RECT playerrctemp = mPlayer->GetRect();
	if(IntersectRect(&rctemp, &playerrctemp,&mDoorRect))
	{
		
		if (Input::GetInstance()->GetKeyDown('Z'))
		{
			FadeOut* fadeout = new FadeOut(false, L"OverWorld", L"OverWorld_LoadingScene");
		}
		
	}
	ObjectManager::GetInstance()->Update();
}

void Scene_ElderHouse::Render(HDC hdc)
{
	CameraManager::GetInstance()->GetMainCamera()->Render(hdc,mImage, 0, 0);
	CameraManager::GetInstance()->GetMainCamera()->RenderRect(hdc, mDoorRect);
	ObjectManager::GetInstance()->Render(hdc);
}
