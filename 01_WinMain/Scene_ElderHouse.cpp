#include "pch.h"
#include "Scene_ElderHouse.h"
#include "Camera.h"
#include "Cuphead_OverWorld.h"
#include "Scene_OverWorld.h"
#include "LoadingScene.h"
#include "FadeOut.h"
#include "NPC.h"
void Scene_ElderHouse::Init()
{
	

	mImage = IMAGEMANAGER->GetInstance()->FindImage(L"ElderHouse_Inside");
	
	mPlayer = new Cuphead_OverWorld("ElderHouse_Player", 200, 200);
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Player, mPlayer);
	
	mElderKettle = new NPC("NPC_ElderKettle", 1100, 400);
	ObjectManager::GetInstance()->AddObject(ObjectLayer::NPC, mElderKettle);

	ObjectManager::GetInstance()->Init();

	Camera* camera = new Camera();
	camera->SetX(250);
	camera->SetY(50);
	camera->SetMode(Camera::Mode::Free);
	CameraManager::GetInstance()->SetMainCamera(camera);
	ObjectManager::GetInstance()->AddObject(ObjectLayer::UI, camera);

	mDoorRect = RectMakeCenter(300, 600, 200, 200);

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
