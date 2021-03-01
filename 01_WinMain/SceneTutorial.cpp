#include "pch.h"
#include "SceneTutorial.h"
#include "PlatformerPlayer.h"
#include "Camera.h"
#include "Block.h"
#include "Image.h"
#include "TutorialBackGround.h"
#include "TutorialPrint.h"
#include "TutorialCube.h"
void SceneTutorial::Init()
{
	SoundPlayer::GetInstance()->Play(L"TutorialMap", 1.f);
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Player, new PlatformerPlayer("Player", 200, WINSIZEY / 8 * 7));
	mMap = RectMake(-15,0,3950,WINSIZEY);
	Camera* camera = new Camera();
	camera->SetMode(Camera::Mode::Platformer);
	camera->SetTarget(ObjectManager::GetInstance()->FindObject("Player"));
	camera->SetCamerArea(mMap);
	CameraManager::GetInstance()->SetMainCamera(camera);
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Camera, camera);
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Block, new Block("Ground", -20, WINSIZEY / 8 * 7, 4000, 100));
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Block, new Block("Ground", -20, 0, 10, WINSIZEY));
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Block, new Block("Ground", 3930, 0, 4000, WINSIZEY));
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Block, new TutorialCube("Trap",1000, WINSIZEY - 200, 180, 170, ImageManager::GetInstance()->FindImage(L"Tutorial_cube")));
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Print, new TutorialPrint("Tutorial", 150, WINSIZEY-400, ImageManager::GetInstance()->FindImage(L"Tutorial_Tutorial")));
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Print, new TutorialPrint("Duck", 400, WINSIZEY - 400, ImageManager::GetInstance()->FindImage(L"Tutorial_Duck")));
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Print, new TutorialPrint("Jump", 750, WINSIZEY-400, ImageManager::GetInstance()->FindImage(L"Tutorial_Jump")));
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Print, new TutorialPrint("Shoot", 1200, WINSIZEY - 400, ImageManager::GetInstance()->FindImage(L"Tutorial_Shoot")));
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Print, new TutorialPrint("Lock", 1600, WINSIZEY - 400, ImageManager::GetInstance()->FindImage(L"Tutorial_Lock")));
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Block, new TutorialCube("Trap", 1800, WINSIZEY - 200, 180, 170, ImageManager::GetInstance()->FindImage(L"Tutorial_cube")));
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Print, new TutorialPrint("ExitDoor", 1600, WINSIZEY - 400, ImageManager::GetInstance()->FindImage(L"Tutorial_Lock")));
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Background, new TutorialBackGround("TutorialBackgroud" , ImageManager::GetInstance()->FindImage(L"Tutorial_BackGround")));
	ObjectManager::GetInstance()->AddObject(ObjectLayer::FrontGround, new TutorialBackGround("TutorialFrontGround", ImageManager::GetInstance()->FindImage(L"Tutorial_FrontGround")));
	ObjectManager::GetInstance()->Init();

}

void SceneTutorial::Release()
{
	SoundPlayer::GetInstance()->Stop(L"TutorialMap");
	ObjectManager::GetInstance()->Release();
}

void SceneTutorial::Update()
{
	ObjectManager::GetInstance()->Update();
	IntersectManager::GetInstance()->IntersectPlayerAndFloor();
}

void SceneTutorial::Render(HDC hdc)
{
	ObjectManager::GetInstance()->Render(hdc);
}