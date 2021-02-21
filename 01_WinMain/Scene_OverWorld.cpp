#include "pch.h"
#include "Scene_OverWorld.h"
#include "Image.h"
#include "Cuphead_OverWorld.h"
#include "Camera.h"

void Scene_OverWorld::Init()
{
	//������Ʈ���̾ ����� �߰�.
	mCupHead = new Cuphead_OverWorld("CupHead_OverWorld", 100, 100);
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Player, mCupHead);
	
	//ī�޶� �߰�
	Camera* camera = new Camera();
	camera->SetTarget(mCupHead);
	camera->ChangeMode(Camera::Mode::Follow);
	CameraManager::GetInstance()->SetMainCamera(camera);
	ObjectManager::GetInstance()->AddObject(ObjectLayer::UI, camera);

	//�������� �̹��� �߰�.
	IMAGEMANAGER->LoadFromFile(L"OverWorld", Resources(L"/overworld/overworld.bmp"), 8000, 6000, true);
	mBackGroundImage_Layer1 = IMAGEMANAGER->FindImage(L"OverWorld");

	ObjectManager::GetInstance()->Init();
}

void Scene_OverWorld::Release()
{
	ObjectManager::GetInstance()->Release();
}

void Scene_OverWorld::Update()
{
	ObjectManager::GetInstance()->Update();

}

void Scene_OverWorld::Render(HDC hdc)
{
	CameraManager::GetInstance()->GetMainCamera()->Render(hdc,mBackGroundImage_Layer1, -2500, -3000);
	ObjectManager::GetInstance()->Render(hdc);
}
