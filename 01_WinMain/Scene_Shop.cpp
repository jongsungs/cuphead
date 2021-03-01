#include "pch.h"
#include "Scene_Shop.h"
#include "Image.h"
#include "Animation.h"
#include "FadeOut.h"
#include "SoundPlayer.h"
#include "Coin.h"
void Scene_Shop::Init()
{
	SoundPlayer::GetInstance()->Play(L"PigShop", 0.5f);
	SoundPlayer::GetInstance()->Play(L"PigShop_Welcome", 1.0f);
	FadeOut* fadein = new FadeOut(true);

	ObjectManager::GetInstance()->FindObject("Coin")->SetIsActive(true);

	mBackGroundImage = IMAGEMANAGER->FindImage(L"PigShop_BackGround");
	mPigImage = IMAGEMANAGER->FindImage(L"PigShop_Pig");
	mSpreadBulletImage = IMAGEMANAGER->FindImage(L"PigShop_SpreadBullet");
	mLeftDoorImage = IMAGEMANAGER->FindImage(L"PigShop_LeftDoor");
	mRightDoorImage = IMAGEMANAGER->FindImage(L"PigShop_RightDoor");
	mCoinImage = IMAGEMANAGER->FindImage(L"Coin");
	mCoinNumImage = IMAGEMANAGER->FindImage(L"Shop_CoinNum");

	mLeftDoorX = 50;
	mRightDoorX = 650;
	
	mPigAnimation = new Animation();
	mPigAnimation->InitFrameByStartEnd(0, 0, 1, 0, false);
	mPigAnimation->SetIsLoop(true);
	mPigAnimation->SetFrameUpdateTime(0.5f);
	mPigAnimation->Play();
	mSpreadBulletIsSoldOut = false;

	ObjectManager::GetInstance()->Init();
}

void Scene_Shop::Release()
{
}

void Scene_Shop::Update()
{
	ObjectManager::GetInstance()->Update();
	mPigAnimation->Update();
	if (mLeftDoorX > -500)
	{
		mLeftDoorX-=3;
		mRightDoorX+=3;

	}
	if (Input::GetInstance()->GetKeyDown('Z'))
	{
		Coin* coin = (Coin*)ObjectManager::GetInstance()->FindObject("Coin");
		if (coin->GetNum() >= 3)
		{
			SoundPlayer::GetInstance()->Play(L"CoinOpen", 1.f);
			mSpreadBulletIsSoldOut = true;
			mSpreadBulletImage = IMAGEMANAGER->FindImage(L"PigShop_SpreadBullet_SoldOut");
			coin->SetNum(coin->GetNum() - 3);
		}
	}
	if (Input::GetInstance()->GetKeyDown(VK_ESCAPE))
	{
		SoundPlayer::GetInstance()->Stop(L"PigShop");
		SoundPlayer::GetInstance()->Play(L"PigShop_GoodBye", 1.0f);
		FadeOut* fadeout = new FadeOut(false, L"OverWorld", L"OverWorldLadingScene");
	}
	
}

void Scene_Shop::Render(HDC hdc)
{
	
	mBackGroundImage->Render(hdc, -50, -50);

	
	if (!mSpreadBulletIsSoldOut)
	{
		SetTextColor(hdc, RGB(255, 255, 255));
		SetBkMode(hdc, 1);
		HFONT myFont = CreateFont(30, 0, 0, 0, 1000, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, L"HY¿±¼­M");
		HFONT oldFont = (HFONT)SelectObject(hdc, myFont);
		TextOut(hdc, 230, 510, L"SPREAD", strlen("SPREAD"));
		TextOut(hdc, 190, 540, L"EX: Eight Way", strlen("EX: Eight Way"));
		SelectObject(hdc, oldFont);
		DeleteObject(myFont);
		myFont = CreateFont(20, 0, 0, 0, 1000, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, L"HY¿±¼­M");
		oldFont = (HFONT)SelectObject(hdc, myFont);
		TextOut(hdc, 110, 590, L"Short Range with great damage - if", strlen("Short Range with great damage - if"));
		TextOut(hdc, 120, 610, L"you can keep close to your target", strlen("you can keep close to your target"));
		SelectObject(hdc, oldFont);
		DeleteObject(myFont);
		mCoinImage->FrameRender(hdc, 500, 510, 0, 0);
		mCoinNumImage->FrameRender(hdc, 530, 510, 2, 0);
	}
	

	mLeftDoorImage->Render(hdc, mLeftDoorX, 460);
	mRightDoorImage->Render(hdc, mRightDoorX, 460);
	mPigImage->FrameRender(hdc, 600, -8, mPigAnimation->GetNowFrameX(), mPigAnimation->GetNowFrameY());
	mSpreadBulletImage->Render(hdc, 200, 200);
	ObjectManager::GetInstance()->Render(hdc);
}
