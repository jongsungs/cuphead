#include "pch.h"
#include "SceneBoss2.h"

#include "PlatformerPlayer.h"
#include "Camera.h"
#include "GameEvent.h"
#include "Enemy.h"
#include "GameObject.h"
#include "Flower.h"

void SceneBoss2::Init() {
	mBackGround1;
	mBackGround2;
	mBackGround3;

	PlatformerPlayer* player = new PlatformerPlayer("Player", WINSIZEX / 4, WINSIZEY * 3 / 4);
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Player, player);

	Enemy* flower = new Flower("flower", WINSIZEX * 3 / 4, WINSIZEY / 2 + 500);
	

	ObjectManager::GetInstance()->AddObject(ObjectLayer::Boss, flower);
	flower->SetPlayerPtr(player);

	flower->SetIsActive(true);

	SoundPlayer::GetInstance()->Play(L"FloralFuryBGM", 0.2f);

	Camera* camera = new Camera(Camera::Mode::Boss, WINSIZEX / 2, WINSIZEY / 2);
	camera->SetCamerArea(RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, WINSIZEX + 10, WINSIZEY));
	CameraManager::GetInstance()->SetMainCamera(camera);
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Player, camera);
	ObjectManager::GetInstance()->Init();
}

void SceneBoss2::Release() {
	ObjectManager::GetInstance()->Release();
}

void SceneBoss2::Update() {
	ObjectManager::GetInstance()->Update();
}

void SceneBoss2::Render(HDC hdc) {
	CameraManager::GetInstance()->GetMainCamera()->ScaleRender(hdc, mBackGround1, -5, 0, WINSIZEX + 10, WINSIZEY);
	CameraManager::GetInstance()->GetMainCamera()->ScaleRender(hdc, mBackGround2, -5, 0, WINSIZEX + 10, WINSIZEY);
	
	ObjectManager::GetInstance()->Render(hdc);

	mBackGround3->ScaleRender(hdc, -5, 0, WINSIZEX + 10, WINSIZEY);
}