#include "pch.h"
#include "Scene1.h"

#include "Player.h"
#include "PlatformerPlayer.h"
#include "Camera.h"
#include "GameEvent.h"
#include "Enemy.h"
#include "GameObject.h"
void Scene1::Init()
{
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Player, new PlatformerPlayer("Player",WINSIZEX,WINSIZEY - 150));
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
	camera->SetX(100);
	camera->SetY(WINSIZEY / 2);
	camera->SetTarget(ObjectManager::GetInstance()->FindObject("Player"));
	CameraManager::GetInstance()->SetMainCamera(camera);
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Player, camera);
	ObjectManager::GetInstance()->Init();
}

void Scene1::Release()
{
	ObjectManager::GetInstance()->Release();
}

void Scene1::Update()
{
	ObjectManager::GetInstance()->Update();
}

void Scene1::Render(HDC hdc)
{
	ObjectManager::GetInstance()->Render(hdc);
}
