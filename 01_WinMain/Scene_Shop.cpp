#include "pch.h"
#include "Scene_Shop.h"
#include "Image.h"
#include "Animation.h"
#include "FadeOut.h"
#include "SoundPlayer.h"
void Scene_Shop::Init()
{
	FadeOut* fadein = new FadeOut(true);
	mBackGroundImage = IMAGEMANAGER->FindImage(L"PigShop_BackGround");
	mPigImage = IMAGEMANAGER->FindImage(L"PigShop_Pig");
	mSpreadBulletImage = IMAGEMANAGER->FindImage(L"PigShop_SpreadBullet");
	mLeftDoorImage = IMAGEMANAGER->FindImage(L"PigShop_LeftDoor");
	mRightDoorImage = IMAGEMANAGER->FindImage(L"PigShop_RightDoor");

	mLeftDoorX = 100;
	mRightDoorX = 400;

	mPigAnimation = new Animation();
	mPigAnimation->InitFrameByStartEnd(0, 0, 1, 0, false);
	mPigAnimation->SetIsLoop(true);
	mSpreadBulletIsSoldOut = false;
}

void Scene_Shop::Release()
{
}

void Scene_Shop::Update()
{
	if (mLeftDoorX > -100)
	{
		mLeftDoorX--;
		mRightDoorX++;

	}
	if (Input::GetInstance()->GetKeyDown('Z'))
	{
		mSpreadBulletIsSoldOut = true;
		mSpreadBulletImage = IMAGEMANAGER->FindImage(L"PigShop_SpreadBullet_SoldOut");
	}
	if (Input::GetInstance()->GetKeyDown(VK_ESCAPE))
	{
		FadeOut* fadeout = new FadeOut(false, L"OverWorld", L"OverWorldLadingScene");
	}
	
}

void Scene_Shop::Render(HDC hdc)
{
	mBackGroundImage->Render(hdc, 0, 0);
	mLeftDoorImage->Render(hdc, mLeftDoorX, 500);
	mRightDoorImage->Render(hdc, mRightDoorX, 500);
	mPigImage->FrameRender(hdc, 600, 300, mPigAnimation->GetNowFrameX(), mPigAnimation->GetNowFrameY());
	mSpreadBulletImage->Render(hdc, 200, 600);
}
