#include "pch.h"
#include "SceneBoss1.h"

#include "PlatformerPlayer.h"
#include "Camera.h"
#include "GameEvent.h"
#include "Enemy.h"
#include "GameObject.h"
#include "Potato.h"
#include "Onion.h"
#include "Carrot.h"
#include "Block.h"
#include "FadeOut.h"
#include "LoadingScene.h"
#include "BackGround.h"

void SceneBoss1::Init(){
	mBackGround1 = IMAGEMANAGER->FindImage(L"BotanicPanicBackground1");
	mBackGround2 = IMAGEMANAGER->FindImage(L"BotanicPanicBackground2");
	mBackGround3 = IMAGEMANAGER->FindImage(L"BotanicPanicBackground3");

	PlatformerPlayer* player = new PlatformerPlayer("Player", WINSIZEX / 4, WINSIZEY * 3 / 4);
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Player, player);

	ObjectManager::GetInstance()->AddObject(ObjectLayer::Block, new Block("Ground", 0, WINSIZEY / 8 * 7, WINSIZEX, 100));

	Enemy* potato = new Potato("Potato", WINSIZEX * 3 / 4, WINSIZEY / 2+50);
	Enemy* carrot = new Carrot("Carrot", WINSIZEX / 2, WINSIZEY * 3 / 8 + 549);
	Enemy* onion = new Onion("Onion", WINSIZEX / 2, WINSIZEY * 3 / 8);

	ObjectManager::GetInstance()->AddObject(ObjectLayer::Boss, potato);
	potato->SetPlayerPtr(player);
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Boss, onion);
	onion->SetPlayerPtr(player);
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Boss, carrot);
	carrot->SetPlayerPtr(player);

	potato->SetIsActive(true);
	if (potato->GetIsActive() == false)
		onion->SetIsActive(true);
	if (potato->GetIsActive() == false && onion->GetIsActive() == false)
		carrot->SetIsActive(true);

	Camera* camera = new Camera(Camera::Mode::Boss,WINSIZEX/2,WINSIZEY/2);
	camera->SetCamerArea(RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, WINSIZEX + 10,WINSIZEY));
	CameraManager::GetInstance()->SetMainCamera(camera);
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Player, camera);
	ObjectManager::GetInstance()->Init();
	mSceneDelayTime = 0.f;
	SoundPlayer::GetInstance()->Play(L"BotanicPanicBGM", 0.2f);
	randomReady = Random::GetInstance()->RandomInt(5);
	randomStart = Random::GetInstance()->RandomInt(5);
	switch (randomReady) {
	case 0:
		SoundPlayer::GetInstance()->Play(L"Ready1", 0.2f);
		break;
	case 1:
		SoundPlayer::GetInstance()->Play(L"Ready2", 0.2f);
		break;
	case 2:
		SoundPlayer::GetInstance()->Play(L"Ready3", 0.2f);
		break;
	case 3:
		SoundPlayer::GetInstance()->Play(L"Ready4", 0.2f);
		break;
	case 4:
		SoundPlayer::GetInstance()->Play(L"Ready5", 0.2f);
		break;
	}
}

void SceneBoss1::Release(){
	ObjectManager::GetInstance()->Delete();
}

void SceneBoss1::Update(){
	mDelayTime += Time::GetInstance()->DeltaTime();
	if (mDelayTime > 2.2 && mIsPlay == false) {
		switch (randomStart) {
		case 0:
			SoundPlayer::GetInstance()->Play(L"Start1", 0.2f);
			mIsPlay = true;
			break;
		case 1:
			SoundPlayer::GetInstance()->Play(L"Start2", 0.2f);
			mIsPlay = true;
			break;
		case 2:
			SoundPlayer::GetInstance()->Play(L"Start3", 0.2f);
			mIsPlay = true;
			break;
		case 3:
			SoundPlayer::GetInstance()->Play(L"Start4", 0.2f);
			mIsPlay = true;
			break;
		case 4:
			SoundPlayer::GetInstance()->Play(L"Start5", 0.2f);
			mIsPlay = true;
			break;
		}
	}

	float CarrotHp = ObjectManager::GetInstance()->FindObject(ObjectLayer::Boss, "Carrot")->GetHP();
	if(CarrotHp < 0){
		mSceneDelayTime += Time::GetInstance()->DeltaTime();
	}
	if (mSceneDelayTime > 3) {
		LoadingScene* loadingScene = new LoadingScene();
		SceneManager::GetInstance()->AddScene(L"Overworld_LoadingScene", loadingScene);
		SoundPlayer::GetInstance()->Stop(L"BotanicPanicBGM");
		FadeOut* fadeout = new FadeOut(false, L"OverWorld", L"Overworld_LoadingScene");
	}
	ObjectManager::GetInstance()->Update();
	IntersectManager::GetInstance()->IntersectPlayerAndFloor();
	IntersectManager::GetInstance()->IntersectPlayerAndEnemyBullet();
	IntersectManager::GetInstance()->IntersectPlayerAndEnemy();
	IntersectManager::GetInstance()->IntersectEnemyAndBullet();
}

void SceneBoss1::Render(HDC hdc){
	CameraManager::GetInstance()->GetMainCamera()->ScaleRender(hdc, mBackGround1, -5, 0, WINSIZEX + 10, WINSIZEY);

	if (ObjectManager::GetInstance()->FindObject(ObjectLayer::Boss, "Carrot")->GetIsActive()) {
		ObjectManager::GetInstance()->FindObject(ObjectLayer::Boss, "Carrot")->Render(hdc);
	}

	CameraManager::GetInstance()->GetMainCamera()->ScaleRender(hdc, mBackGround2, -5, 0, WINSIZEX + 10, WINSIZEY);

	ObjectManager::GetInstance()->Render(hdc);

	mBackGround3->ScaleRender(hdc, -5, 0, WINSIZEX + 10, WINSIZEY);
}
