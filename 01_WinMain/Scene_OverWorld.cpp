#include "pch.h"
#include "Scene_OverWorld.h"

#include "Image.h"
#include "Camera.h"

#include "Cuphead_OverWorld.h"
#include "Building.h"
#include "NPC.h"
#include "BackGround.h"
#include "FadeOut.h"
void Scene_OverWorld::Init()
{
	FadeOut* fadeout = new FadeOut(true);
	ObjectManager::GetInstance()->AddObjectNoDelete(ObjectLayer::Building, new Building("Flatformer", IMAGEMANAGER->FindImage(L"OverWorld_Building_Flatformer"), 2000, 800));
	ObjectManager::GetInstance()->AddObjectNoDelete(ObjectLayer::Building, new Building("ElderHouse", IMAGEMANAGER->FindImage(L"OverWorld_Building_ElderHouse"), 650, 650));
	ObjectManager::GetInstance()->AddObjectNoDelete(ObjectLayer::Building, new Building("BotanicPanic", IMAGEMANAGER->FindImage(L"OverWorld_Building_BotanicPanic"), 1680, 1490));
	//������Ʈ�Ŵ����� ����� �߰�.
	if (ObjectManager::GetInstance()->FindObject("CupHead_OverWorld") == nullptr)
	{
		mCupHead = new Cuphead_OverWorld("CupHead_OverWorld", 500, 700);

	}
	else
	{
		mCupHead = (Cuphead_OverWorld*)ObjectManager::GetInstance()->FindObject("CupHead_OverWorld");
	}
	ObjectManager::GetInstance()->AddObjectNoDelete(ObjectLayer::Player, mCupHead);
	//������Ʈ�Ŵ�����NPC�߰�
	ObjectManager::GetInstance()->AddObjectNoDelete(ObjectLayer::NPC, new NPC("NPC_Apple", 1715, 1010));

	//ī�޶� �߰�
	Camera* camera = new Camera();
	camera->SetTarget(ObjectManager::GetInstance()->FindObject("CupHead_OverWorld"));
	camera->ChangeMode(Camera::Mode::Follow);
	CameraManager::GetInstance()->SetMainCamera(camera);
	ObjectManager::GetInstance()->AddObject(ObjectLayer::UI, camera);
	//��� layer1 : �������� �̹���
	ObjectManager::GetInstance()->AddObjectNoDelete(ObjectLayer::Background,
		new BackGround("BackGroundImage_Layer1", 
		IMAGEMANAGER->FindImage(L"OverWorld"), 0, 0));
	
	//��� Layer2 : �̵������Ѱ�.
	mBackGroundImage_Layer2 = IMAGEMANAGER->FindImage(L"OverWorld_CanMove");
	//��� Layer3 : ����� ������ �׷����³༮��
	ObjectManager::GetInstance()->AddObjectNoDelete(ObjectLayer::FrontGround,
		new BackGround("BackGroundImage_Layer3",
			IMAGEMANAGER->FindImage(L"OverWorld_Front"), 0, 0));

	//NPC ��ȭ
	mTalkImage1 = IMAGEMANAGER->FindImage(L"NPC_Apple_Talk1");
	mTalkImage2 = IMAGEMANAGER->FindImage(L"NPC_Apple_Talk2");
	mTalkImage3 = IMAGEMANAGER->FindImage(L"NPC_Apple_Talk3");
	mTalkImage4 = IMAGEMANAGER->FindImage(L"NPC_Apple_Talk4");
	mTalkImage5 = IMAGEMANAGER->FindImage(L"NPC_Apple_Talk5");

	ObjectManager::GetInstance()->Init();
}

void Scene_OverWorld::Release()
{
	ObjectManager::GetInstance()->Delete();
}

void Scene_OverWorld::Update()
{
	int tempX = mCupHead->GetX();
	int tempY = mCupHead->GetY();
		for (int x = tempX - 10; x < tempX + 10; x++)
		{
			COLORREF pixelColor = GetPixel(mBackGroundImage_Layer2->GetHDC(),x, tempY);
			if (pixelColor == RGB(255, 0, 255))
			{
				if (x > tempX)
					mCupHead->SetX(x - 15);
				else
					mCupHead->SetX(x + 15);
				break;
			}
		}
		for (int y = tempY - 10; y < tempY + 10; y++)
		{
			COLORREF pixelColor = GetPixel(mBackGroundImage_Layer2->GetHDC(), tempX, y);
			if (pixelColor == RGB(255, 0, 255))
			{
				if (y > tempY)
					mCupHead->SetY(y - 15);
				else
					mCupHead->SetY(y + 15);
				break;
			}
		}
	ObjectManager::GetInstance()->Update();

}

void Scene_OverWorld::Render(HDC hdc)
{
	
	ObjectManager::GetInstance()->Render(hdc);
	//��ȭ�Ҷ�
	NPC* npc_apple = (NPC*)ObjectManager::GetInstance()->FindObject("NPC_Apple");
	if (npc_apple->GetIsTalk())
	{
		if (npc_apple->GetTalkNum() == 1)
		{
			CameraManager::GetInstance()->GetMainCamera()->ScaleRenderFromBottom(hdc,
				mTalkImage1,
				npc_apple->GetX() - 150,
				npc_apple->GetY()  ,
				mTalkImage1->GetWidth() * 0.5f,
				mTalkImage1->GetHeight() * 0.5f);
		}
		else if (npc_apple->GetTalkNum() == 2)
		{
			CameraManager::GetInstance()->GetMainCamera()->ScaleRenderFromBottom(hdc,
				mTalkImage2,
				npc_apple->GetX() - 150,
				npc_apple->GetY() ,
				mTalkImage2->GetWidth() * 0.5f,
				mTalkImage2->GetHeight() * 0.5f);
		}
		else if (npc_apple->GetTalkNum() == 3)
		{
			CameraManager::GetInstance()->GetMainCamera()->ScaleRenderFromBottom(hdc,
				mTalkImage3,
				npc_apple->GetX() - 100,
				npc_apple->GetY() ,
				mTalkImage3->GetWidth() * 0.5f,
				mTalkImage3->GetHeight() * 0.5f);
		}
		else if (npc_apple->GetTalkNum() == 4)
		{
			CameraManager::GetInstance()->GetMainCamera()->ScaleRenderFromBottom(hdc,
				mTalkImage4,
				npc_apple->GetX() - 120,
				npc_apple->GetY() ,
				mTalkImage4->GetWidth() * 0.5f,
				mTalkImage4->GetHeight() * 0.5f);
		}
		else if (npc_apple->GetTalkNum() == 5)
		{
			CameraManager::GetInstance()->GetMainCamera()->ScaleRenderFromBottom(hdc,
				mTalkImage5,
				npc_apple->GetX() - 110,
				npc_apple->GetY() ,
				mTalkImage5->GetWidth() * 0.5f,
				mTalkImage5->GetHeight() * 0.5f);
		}

	}

}
