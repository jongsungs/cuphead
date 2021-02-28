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
	//시작할때 페이드인
	FadeOut* fadein = new FadeOut(true);

	//건물
	ObjectManager::GetInstance()->AddObjectNoDelete(ObjectLayer::Building, new Building("Flatformer", IMAGEMANAGER->FindImage(L"OverWorld_Building_Flatformer"), 2000, 800));
	ObjectManager::GetInstance()->AddObjectNoDelete(ObjectLayer::Building, new Building("ElderHouse", IMAGEMANAGER->FindImage(L"OverWorld_Building_ElderHouse"), 650, 650));
	ObjectManager::GetInstance()->AddObjectNoDelete(ObjectLayer::Building, new Building("BotanicPanic", IMAGEMANAGER->FindImage(L"OverWorld_Building_BotanicPanic"), 1680, 1490));
	ObjectManager::GetInstance()->AddObjectNoDelete(ObjectLayer::Building, new Building("PigShop", IMAGEMANAGER->FindImage(L"OverWorld_Building_PigShop"), 2200, 1000));

	//오브젝트매니저에 컵헤드 추가.
	if (ObjectManager::GetInstance()->FindObject("CupHead_OverWorld") == nullptr)
	{
		mCupHead = new Cuphead_OverWorld("CupHead_OverWorld", 800, 900);

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
	mBotanicPanic = (Building*)ObjectManager::GetInstance()->FindObject("BotanicPanic");
	
		
	ObjectManager::GetInstance()->AddObjectNoDelete(ObjectLayer::Background,
		new BackGround("BackGroundImage_OverWorld",
		IMAGEMANAGER->FindImage(L"OverWorld"), 0, 0));
	
	
	//배경 Layer2 : 이동가능한곳.
	mBackGroundImage_CanMove1 = IMAGEMANAGER->FindImage(L"OverWorld_CanMove1");
	mBackGroundImage_CanMove2 = IMAGEMANAGER->FindImage(L"OverWorld_CanMove2");
	//배경 Layer3 : 배경중 맨위에 그려지는녀석들
	ObjectManager::GetInstance()->AddObjectNoDelete(ObjectLayer::FrontGround,
		new BackGround("BackGroundImage_Layer3",
			IMAGEMANAGER->FindImage(L"OverWorld_Front"), 0, 0));

	
	ObjectManager::GetInstance()->Init();
}

void Scene_OverWorld::Release()
{
	ObjectManager::GetInstance()->Delete();
}

void Scene_OverWorld::Update()
{
	//보타닉패닉클리어시, 백그라운드 이미지 바까줌.
	if (mBotanicPanic->GetIsClear())
	{
		ObjectManager::GetInstance()->AddObjectNoDelete(ObjectLayer::Background,
			new BackGround("BackGroundImage_OverWorld2",
				IMAGEMANAGER->FindImage(L"OverWorld2"), 0, 0));
	}

	//마젠타값이면 못가게함.
	int tempX = mCupHead->GetX();
	int tempY = mCupHead->GetY();
		for (int x = tempX - 10; x < tempX + 10; x++)
		{
			COLORREF pixelColor;
			if(mBotanicPanic->GetIsClear())
				pixelColor = GetPixel(mBackGroundImage_CanMove2->GetHDC(),x, tempY);
			else
				pixelColor = GetPixel(mBackGroundImage_CanMove1->GetHDC(), x, tempY);
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
			COLORREF pixelColor;
			if (mBotanicPanic->GetIsClear())
				pixelColor = GetPixel(mBackGroundImage_CanMove2->GetHDC(), tempX, y);
			else
				pixelColor = GetPixel(mBackGroundImage_CanMove2->GetHDC(), tempX, y);
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
	

}
