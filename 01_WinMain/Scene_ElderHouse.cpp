#include "pch.h"
#include "Scene_ElderHouse.h"
#include "Camera.h"
#include "Cuphead_OverWorld.h"
#include "Scene_OverWorld.h"
#include "LoadingScene.h"
#include "Effect.h"
void Scene_ElderHouse::Init()
{
	
	IMAGEMANAGER->LoadFromFile(L"ElderHouse_Inside", Resources(L"/ElderHouse/ElderHouse_Inside.bmp"), 1695, 834, true);

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
		
		/*Effect* fadeout = new Effect(
			300,
			300,
			IMAGEMANAGER->FindImage(L"FadeOut"));*/
		//if (fadeout->GetIsDestroy())
		{
			ObjectManager::GetInstance()->Delete();
			/*SceneManager::GetInstance()->AddScene(L"Scene1LoadingScene", new LoadingScene);
			SceneManager::GetInstance()->LoadSceneLoading(L"Scene_OverWorld", L"Scene1LoadingScene");*/
			SceneManager::GetInstance()->AddScene(L"Scene_OverWorld", new Scene_OverWorld);
			SceneManager::GetInstance()->LoadScene(L"Scene_OverWorld");
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
