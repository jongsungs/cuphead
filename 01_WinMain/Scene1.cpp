#include "pch.h"
#include "Scene1.h"

#include "Player.h"
#include "Camera.h"
#include "GameEvent.h"
#include "Enemy.h"
#include "GameObject.h"
void Scene1::Init()
{
	mPlayer = new Player("Player", WINSIZEX / 4, WINSIZEY / 2);
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Player, mPlayer);
	for (int a = 0; a < 5; ++a) {
		string enemyname = "Enemy";
		enemyname += to_string(a);
		Enemy* enemy = new Enemy(enemyname, WINSIZEX / 2 + a* 30, WINSIZEY / 2 + a*10);
		enemy->SetPlayerPtr(mPlayer);
		ObjectManager::GetInstance()->AddObject(ObjectLayer::Enemey, enemy);
		mEnemys.push_back(enemy);
	}
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
	vector<GameObject*>* objects = ObjectManager::GetInstance()->GetObjectListPt(ObjectLayer::Enemey);
	for (int a = 0; a < objects ->size(); a++) {
		(*objects)[a]->GetName();
	}
	if (!mPlayer->GetIsAttackMode()) {
		RECT dump;
		RECT rt = mPlayer->GetRect();
		for (int a = 0; a < objects->size(); a++) {
			RECT monsterRt = (*objects)[a]->GetRect();
			if (IntersectRect(&dump,&rt,&monsterRt)){
				(*objects)[a]->SetIsDestroy(true);
			}
		}
	}
	RECT dump;
	RECT rt = mPlayer->GetRect();
	for (int a = 0; a < objects->size(); a++) {
		RECT monsterRt = (*objects)[a]->GetRect();
		if (IntersectRect(&dump, &rt, &monsterRt)) {
			
		}
	}
	ObjectManager::GetInstance()->Update();
	if (objects->size() == 0) {
		//ObjectManager::GetInstance()->Release();
		SceneManager::GetInstance()->LoadScene(L"Scene2");
	}
}

void Scene1::Render(HDC hdc)
{
	ObjectManager::GetInstance()->Render(hdc);
}
