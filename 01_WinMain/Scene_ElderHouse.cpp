#include "pch.h"
#include "Scene_ElderHouse.h"
#include "Camera.h"
#include "PlatformerPlayer.h"
#include "Scene_OverWorld.h"
#include "LoadingScene.h"
#include "FadeOut.h"
#include "NPC.h"
#include "Block.h"
void Scene_ElderHouse::Init()
{
	

	mImage = IMAGEMANAGER->GetInstance()->FindImage(L"ElderHouse_Inside");
	
	mPlayer = new PlatformerPlayer("CupHead_ElderHouse", 400, 600);
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Player, mPlayer);
	
	mElderKettle = new NPC("NPC_ElderKettle", 1200, 400);
	mElderKettle->SetIsOverWorld(false);
	ObjectManager::GetInstance()->AddObject(ObjectLayer::NPC, mElderKettle);

	ObjectManager::GetInstance()->AddObject(ObjectLayer::Block, new Block("Ground", 200, 700, WINSIZEX, 100));

	mTutorialRect = RectMakeCenter(900, 600, 400, 200);
	mDoorRect = RectMakeCenter(300, 600, 200, 200);

	ObjectManager::GetInstance()->Init();

	Camera* camera = new Camera();
	camera->SetX(250);
	camera->SetY(50);
	camera->SetMode(Camera::Mode::Free);
	CameraManager::GetInstance()->SetMainCamera(camera);
	ObjectManager::GetInstance()->AddObject(ObjectLayer::UI, camera);


}

void Scene_ElderHouse::Release()
{
}

void Scene_ElderHouse::Update()
{
	
	RECT rctemp;
	RECT playerrctemp = mPlayer->GetRect();

	//ÅðÀå
	if(IntersectRect(&rctemp, &playerrctemp,&mDoorRect))
	{
		
		if (Input::GetInstance()->GetKeyDown('Z'))
		{
			FadeOut* fadeout = new FadeOut(false, L"OverWorld", L"OverWorld_LoadingScene");
		}
		
	}
	//Æ©Åä¸®¾ó
	if (IntersectRect(&rctemp, &playerrctemp, &mTutorialRect))
	{
		if (Input::GetInstance()->GetKeyDown('Z'))
		{
			FadeOut* fadeout = new FadeOut(false, L"Tutorial", L"Tutorial_LoadingScene");
		}
	}
	ObjectManager::GetInstance()->Update();
}

void Scene_ElderHouse::Render(HDC hdc)
{
	CameraManager::GetInstance()->GetMainCamera()->Render(hdc,mImage, 0, 0);
	CameraManager::GetInstance()->GetMainCamera()->RenderRect(hdc, mDoorRect);
	CameraManager::GetInstance()->GetMainCamera()->RenderRect(hdc, mTutorialRect);
	ObjectManager::GetInstance()->Render(hdc);
}
