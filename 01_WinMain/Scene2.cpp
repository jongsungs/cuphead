#include "pch.h"
#include "Scene2.h"

#include "Player.h"
#include "NPC.h"
#include "Camera.h"
#include "GameEvent.h"
void Scene2::Init()
{
	Player* player = new Player("Player", 100, WINSIZEY / 2);
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Player, player);
	NPC* npc = new NPC("NPC", 500, WINSIZEX / 2);
	ObjectManager::GetInstance()->AddObject(ObjectLayer::NPC, npc);


	Camera* camera = new Camera();
	camera->SetTarget(player);
	camera->ChangeMode(Camera::Mode::Follow);

	CameraManager::GetInstance()->SetMainCamera(camera);
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Player, camera);

	ObjectManager::GetInstance()->Init();
}

void Scene2::Release()
{
	ObjectManager::GetInstance()->Release();
}

void Scene2::Update()
{
	ObjectManager::GetInstance()->Update();
	RECT rectTemp;
	RECT playerRectTemp = ObjectManager::GetInstance()->FindObject("Player")->GetRect();
	NPC* npctemp = (NPC*)ObjectManager::GetInstance()->FindObject("NPC");
	RECT npcRangeTemp = npctemp->GetRange();
	GameEventManager::GetInstance()->Update();
	if (IntersectRect(&rectTemp, &playerRectTemp, &npcRangeTemp))
	{
		if (Input::GetInstance()->GetKey(VK_SPACE))
		{
			CameraManager::GetInstance()->GetMainCamera()->SetTarget(ObjectManager::GetInstance()->FindObject("NPC"));
			GameEventManager::GetInstance()->PushEvent(new ITalkwithNPCEvent());
			
		}
		
	}
	else
	{
		npctemp->SetIsTalk(false);
		CameraManager::GetInstance()->GetMainCamera()->SetTarget(ObjectManager::GetInstance()->FindObject("Player"));
		CameraManager::GetInstance()->GetMainCamera()->SetMode(Camera::Mode::Follow);
	}

}

void Scene2::Render(HDC hdc)
{
	CameraManager::GetInstance()->GetMainCamera()->RenderRect(hdc, ObjectManager::GetInstance()->FindObject("Player")->GetRect());
	ObjectManager::GetInstance()->Render(hdc);
}
