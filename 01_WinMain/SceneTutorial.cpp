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
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Player, new PlatformerPlayer("TutorialPlayer", 200, WINSIZEY / 8 * 7));
	mZImage = IMAGEMANAGER->FindImage(L"ZPopUp");
	mMap = RectMake(-15,0,3950,WINSIZEY);
	Camera* camera = new Camera();
	camera->SetMode(Camera::Mode::Platformer);
	camera->SetTarget(ObjectManager::GetInstance()->FindObject("TutorialPlayer"));
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
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Block, new TutorialCube("Trap", 2000, WINSIZEY - 350, 180, 350, ImageManager::GetInstance()->FindImage(L"Tutorial_cylinder_1")));
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Block, new TutorialCube("Trap", 2200, WINSIZEY - 200, 180, 170, ImageManager::GetInstance()->FindImage(L"Tutorial_cube")));
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Print, new TutorialPrint("Dash", 2350, WINSIZEY - 500, ImageManager::GetInstance()->FindImage(L"Tutorial_Dash")));
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Block, new TutorialCube("Trap", 2700, WINSIZEY - 350, 180, 350, ImageManager::GetInstance()->FindImage(L"Tutorial_cylinder_1")));
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Print, new TutorialPrint("Ex", 3100, WINSIZEY - 400, ImageManager::GetInstance()->FindImage(L"Tutorial_Ex")));
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Print, new TutorialPrint("ExitDoor", 3500, WINSIZEY - 350, ImageManager::GetInstance()->FindImage(L"Tutorial_exit_door")));
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
	GameObject* mPlayer = ObjectManager::GetInstance()->FindObject(ObjectLayer::Player,"TutorialPlayer");
	GameObject * mExitDoor = ObjectManager::GetInstance()->FindObject(ObjectLayer::Print, "ExitDoor");
	RECT rt1 = mPlayer->GetRect();
	RECT rt2 = mExitDoor->GetRect();
	float chaX = rt2.right - rt2.left; //가로
	float centerX = rt2.left + chaX/2; //가운데 점
	RECT temp;
	if (IntersectRect(&temp, &rt1, &rt2)) {
		mExitDoorCheck = true;
		if (mPlayer->GetX() < centerX) {
			mDistance = (chaX - (centerX - mPlayer->GetX()))/ chaX;
		}
		else {
			mDistance = (chaX - (mPlayer->GetX() - centerX))/chaX;
		}
		if (Input::GetInstance()->GetKeyDown('Z')) {
			mExitDoorCheck = false;
			SceneManager::GetInstance()->LoadScene(L"ElderHouse");
		}
	}
	else {
		mExitDoorCheck = false;
	}
	ObjectManager::GetInstance()->Update();
	IntersectManager::GetInstance()->IntersectPlayerAndFloor();
}

void SceneTutorial::Render(HDC hdc)
{
	ObjectManager::GetInstance()->Render(hdc);
	if (mExitDoorCheck) {
		GameObject* mExitDoor = ObjectManager::GetInstance()->FindObject(ObjectLayer::Player, "TutorialPlayer");
		RECT rt2 = mExitDoor->GetRect();
		float chaX = rt2.right - rt2.left; //가로
		float centerX = rt2.left + chaX; //가운데 점
		CameraManager::GetInstance()->GetMainCamera()->ScaleRenderFromBottom(hdc, mZImage,centerX,
			rt2.top, mZImage->GetWidth()*mDistance, mZImage->GetHeight()* mDistance);
	}
}