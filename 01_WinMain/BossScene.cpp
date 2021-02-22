#include "pch.h"
#include "BossScene.h"

#include "Player.h"
#include "PlatformerPlayer.h"
#include "Camera.h"
#include "GameEvent.h"
#include "Enemy.h"
#include "GameObject.h"
#include "Potato.h"
#include "Onion.h"
#include "Carrot.h"
void BossScene::Init()
{
	//Enemy* enemy = new Potato("Potato", WINSIZEX / 2, WINSIZEY / 2);
	//Enemy* enemy = new Potato("Onion", WINSIZEX / 2, WINSIZEY / 2);
	Enemy* enemy = new Onion("Carrot", WINSIZEX / 2, WINSIZEY / 2);

	ObjectManager::GetInstance()->AddObject(ObjectLayer::Boss, enemy);
	//((Potato*)enemy)->PotatoMasisu();
	//Potato* dump = (Potato*)enemy;
	//dump->PotatoMasisu();
	//Potato* dump =(Potato*)ObjectManager::GetInstance()->FindObject("Potato");
	//dump->SetPlayerPtr(player1);

	//enemy->SetPlayerPtr(player1);

	Camera* camera = new Camera();
	CameraManager::GetInstance()->SetMainCamera(camera);
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Player, camera);
	camera->SetTarget(ObjectManager::GetInstance()->FindObject("Carrot"));
	ObjectManager::GetInstance()->Init();
}

void BossScene::Release()
{
	ObjectManager::GetInstance()->Release();
}

void BossScene::Update()
{
	ObjectManager::GetInstance()->Update();
}

void BossScene::Render(HDC hdc)
{
	ObjectManager::GetInstance()->Render(hdc);
}
