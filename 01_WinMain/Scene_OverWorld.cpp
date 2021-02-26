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
	//이미지
	IMAGEMANAGER->LoadFromFile(L"FadeOut", Resources(L"/FadeOut.bmp"), 12800, 720, 10, 1, true);
	//월드맵이미지
	IMAGEMANAGER->LoadFromFile(L"CupHead_OverWolrd", Resources(L"/overworld/Cuphead/CupHead_OverWorld.bmp"), 1649, 1130, 16, 10, true, RGB(99, 92, 99));
	IMAGEMANAGER->LoadFromFile(L"NPC_Apple", Resources(L"/overworld/NPC/NPC_Apple.bmp"), 2600, 100, 26, 1, true, RGB(99, 92, 99));
	IMAGEMANAGER->LoadFromFile(L"OverWorld", Resources(L"/overworld/OverWorld.bmp"), 4000, 2200, true);
	IMAGEMANAGER->LoadFromFile(L"OverWorld_CanMove", Resources(L"/overworld/OverWorld_CanMove.bmp"), 4000, 2200, true);
	IMAGEMANAGER->LoadFromFile(L"OverWorld_Front", Resources(L"/overworld/OverWorld_Front.bmp"), 4000, 2200, true,RGB(99,92,99));
	IMAGEMANAGER->LoadFromFile(L"OverWorld_Building_ElderHouse", Resources(L"/overworld/Buildings/ElderHouse.bmp"), 300, 350, true,RGB(99,92,99));
	IMAGEMANAGER->LoadFromFile(L"OverWorld_Building_Flatformer", Resources(L"/overworld/Buildings/flatformer.bmp"), 63, 46, true, RGB(99, 92, 99));
	IMAGEMANAGER->LoadFromFile(L"OverWorld_Building_BotanicPanic", Resources(L"/overworld/Buildings/BotanicPanic.bmp"), 330, 270, true, RGB(99, 92, 99));
	IMAGEMANAGER->LoadFromFile(L"Dust_OverWolrd", Resources(L"/overworld/Cuphead/Dust_Overworld.bmp"), 1622, 498, 20, 6, true, RGB(99, 92, 99));
	IMAGEMANAGER->LoadFromFile(L"ZPopUp", Resources(L"/overworld/Z.bmp"), 42, 52, true, RGB(99, 92, 99));
	IMAGEMANAGER->LoadFromFile(L"NPC_Apple_Talk1", Resources(L"/overworld/NPC/Talk1.bmp"), 1016, 263, true, RGB(99, 92, 99));
	IMAGEMANAGER->LoadFromFile(L"NPC_Apple_Talk2", Resources(L"/overworld/NPC/Talk2.bmp"), 899, 335, true, RGB(99, 92, 99));
	IMAGEMANAGER->LoadFromFile(L"NPC_Apple_Talk3", Resources(L"/overworld/NPC/Talk3.bmp"), 693, 265, true, RGB(99, 92, 99));
	IMAGEMANAGER->LoadFromFile(L"NPC_Apple_Talk4", Resources(L"/overworld/NPC/Talk4.bmp"), 903, 339, true, RGB(99, 92, 99));
	IMAGEMANAGER->LoadFromFile(L"NPC_Apple_Talk5", Resources(L"/overworld/NPC/Talk5.bmp"), 881, 285, true, RGB(99, 92, 99));
	IMAGEMANAGER->LoadFromFile(L"ElderHouse_Talk", Resources(L"/overworld/buildings/ElderHouse_Title.bmp"), 785, 418, true, RGB(99, 92, 99));
	IMAGEMANAGER->LoadFromFile(L"BotanicPanic_Talk1", Resources(L"/overworld/buildings/BotanicPanic_Title_Simple.bmp"), 1165, 834, true, RGB(99, 92, 99));
	IMAGEMANAGER->LoadFromFile(L"BotanicPanic_Talk2", Resources(L"/overworld/buildings/BotanicPanic_Title_Regular.bmp"), 1165, 834, true, RGB(99, 92, 99));
	IMAGEMANAGER->LoadFromFile(L"Black", Resources(L"/overworld/buildings/Black.bmp"), 1280, 720, false);
	
	IMAGEMANAGER->LoadFromFile(L"OverWorld_Flag", Resources(L"/overworld/Flag.bmp"), 1788, 220, 12, 1, true, RGB(99, 92, 99));

	//장로집 이미지
	IMAGEMANAGER->LoadFromFile(L"ElderHouse_Inside", Resources(L"/ElderHouse/ElderHouse_Inside.bmp"), 1695, 834, true);

	FadeOut* fadeout = new FadeOut(true);
	ObjectManager::GetInstance()->AddObjectNoDelete(ObjectLayer::Building, new Building("Flatformer", IMAGEMANAGER->FindImage(L"OverWorld_Building_Flatformer"), 2000, 800));
	ObjectManager::GetInstance()->AddObjectNoDelete(ObjectLayer::Building, new Building("ElderHouse", IMAGEMANAGER->FindImage(L"OverWorld_Building_ElderHouse"), 650, 650));
	ObjectManager::GetInstance()->AddObjectNoDelete(ObjectLayer::Building, new Building("BotanicPanic", IMAGEMANAGER->FindImage(L"OverWorld_Building_BotanicPanic"), 1680, 1490));
	//오브젝트매니저에 컵헤드 추가.
	if (ObjectManager::GetInstance()->FindObject("CupHead_OverWorld") == nullptr)
	{
		mCupHead = new Cuphead_OverWorld("CupHead_OverWorld", 500, 700);

	}
	else
	{
		mCupHead = (Cuphead_OverWorld*)ObjectManager::GetInstance()->FindObject("CupHead_OverWorld");
	}
	ObjectManager::GetInstance()->AddObjectNoDelete(ObjectLayer::Player, mCupHead);
	//오브젝트매니저에NPC추가
	ObjectManager::GetInstance()->AddObjectNoDelete(ObjectLayer::NPC, new NPC("NPC_Apple", 1715, 1010));

	//카메라 추가
	Camera* camera = new Camera();
	camera->SetTarget(ObjectManager::GetInstance()->FindObject("CupHead_OverWorld"));
	camera->ChangeMode(Camera::Mode::Follow);
	CameraManager::GetInstance()->SetMainCamera(camera);
	ObjectManager::GetInstance()->AddObject(ObjectLayer::UI, camera);
	//배경 layer1 : 오버월드 이미지
	ObjectManager::GetInstance()->AddObjectNoDelete(ObjectLayer::Background,
		new BackGround("BackGroundImage_Layer1", 
		IMAGEMANAGER->FindImage(L"OverWorld"), 0, 0));
	
	//배경 Layer2 : 이동가능한곳.
	mBackGroundImage_Layer2 = IMAGEMANAGER->FindImage(L"OverWorld_CanMove");
	//배경 Layer3 : 배경중 맨위에 그려지는녀석들
	ObjectManager::GetInstance()->AddObjectNoDelete(ObjectLayer::FrontGround,
		new BackGround("BackGroundImage_Layer3",
			IMAGEMANAGER->FindImage(L"OverWorld_Front"), 0, 0));

	//NPC 대화
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
	//대화할때
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
