#include "pch.h"
#include "Scene_OverWorld.h"

#include "Image.h"
#include "Camera.h"

#include "Cuphead_OverWorld.h"
#include "Building.h"
#include "NPC.h"
void Scene_OverWorld::Init()
{

	AddFontResourceW(L"../02_Resources/overworld/Madness Hyperactive.otf");
	
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


	ObjectManager::GetInstance()->AddObject(ObjectLayer::Building, new Building("Flatformer", IMAGEMANAGER->FindImage(L"OverWorld_Building_Flatformer"), 2000, 800));
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Building, new Building("ElderHouse", IMAGEMANAGER->FindImage(L"OverWorld_Building_ElderHouse"), 650, 650));
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Building, new Building("BotanicPanic", IMAGEMANAGER->FindImage(L"OverWorld_Building_BotanicPanic"), 1680, 1490));
	//오브젝트매니저에 컵헤드 추가.
	mCupHead = new Cuphead_OverWorld("CupHead_OverWorld", 2000, 800);
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Player, mCupHead);
	//오브젝트매니저에NPC추가
	
	ObjectManager::GetInstance()->AddObject(ObjectLayer::NPC, new NPC("NPC_Apple", 1715, 1010));
	//카메라 추가
	Camera* camera = new Camera();
	camera->SetTarget(mCupHead);
	camera->ChangeMode(Camera::Mode::Follow);
	CameraManager::GetInstance()->SetMainCamera(camera);
	ObjectManager::GetInstance()->AddObject(ObjectLayer::UI, camera);
	//배경 layer1 : 오버월드 이미지
	mBackGroundImage_Layer1 = IMAGEMANAGER->FindImage(L"OverWorld");
	
	//배경 Layer2 : 이동가능한곳.
	mBackGroundImage_Layer2 = IMAGEMANAGER->FindImage(L"OverWorld_CanMove");

	//배경 Layer3 : 배경중 맨위에 그려지는녀석들
	mBackGroundImage_Layer3 = IMAGEMANAGER->FindImage(L"OverWorld_Front");


	ObjectManager::GetInstance()->Init();
}

void Scene_OverWorld::Release()
{
	ObjectManager::GetInstance()->Release();
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
	
	CameraManager::GetInstance()->GetMainCamera()->Render(hdc, mBackGroundImage_Layer1, 0, 0);
	ObjectManager::GetInstance()->Render(hdc);
	CameraManager::GetInstance()->GetMainCamera()->Render(hdc, mBackGroundImage_Layer3, 0, 0);
	SetBkMode(hdc, 1);
	HFONT newFont, oldFont;
	newFont = CreateFont(50, 0, 0, 0, 1000, 0, 0, 0,
		HANGUL_CHARSET, 0, 0, 0,
		VARIABLE_PITCH || FF_ROMAN, TEXT("HY얕은샘물M"));
	oldFont = (HFONT)SelectObject(hdc, newFont);
	TextOut(hdc, 250, 300, L"어이친구들! 다시만나니 반가운걸!", strlen("어이친구들! 다시만나니 반가운걸!"));
	SelectObject(hdc, oldFont);
	DeleteObject(newFont);
}
