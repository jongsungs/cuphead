#include "pch.h"
#include "SceneTutorial.h"
#include "PlatformerPlayer.h"
#include "Camera.h"
#include "Block.h"
void SceneTutorial::Init()
{
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Player, new PlatformerPlayer("Player", 200, WINSIZEY / 8 * 7));
	mMap = RectMake(-20,0,4000,WINSIZEY);
	//for (int a = 0; a < 5; ++a) {
	//	string enemyname = "Enemy";
	//	enemyname += to_string(a);
	//	Enemy* enemy = new Enemy(enemyname, WINSIZEX / 2 + a* 30, WINSIZEY / 2 + a*10);
	//	enemy->SetPlayerPtr(mPlayer);
	//	ObjectManager::GetInstance()->AddObject(ObjectLayer::Enemey, enemy);
	//	mEnemys.push_back(enemy);
	//}
	//Player* player1 = new Player("1", 100, WINSIZEY / 2);
	Camera* camera = new Camera();
	camera->SetMode(Camera::Mode::Platformer);
	camera->SetTarget(ObjectManager::GetInstance()->FindObject("Player"));
	camera->SetCamerArea(mMap);
	CameraManager::GetInstance()->SetMainCamera(camera);
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Camera, camera);
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Block, new Block("Ground", -20, WINSIZEY / 8 * 7, 4000, 100));
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Block, new Block("Trap", WINSIZEX / 8 * 6, WINSIZEY - 200, 100, 100));
	ObjectManager::GetInstance()->Init();

}

void SceneTutorial::Release()
{
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