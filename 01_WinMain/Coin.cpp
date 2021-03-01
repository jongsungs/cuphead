#include "pch.h"
#include "Coin.h"
#include "Animation.h"
#include "Camera.h"
#include "Image.h"
Coin::Coin(string name, float x, float y)
	:GameObject(name)
{
	mX = x;
	mY = y;
	mNum = 0;
}

void Coin::Init()
{
	IMAGEMANAGER->LoadFromFile(L"Coin", L"../02_Resources/OverWorld/Coin.bmp", 100, 50, 2, 1, true, RGB(99, 92, 99));
	IMAGEMANAGER->LoadFromFile(L"CoinNum", L"../02_Resources/OverWorld/OverWorld_CoinNum.bmp", 500, 50, 10, 1, true, RGB(99, 92, 99));
	IMAGEMANAGER->LoadFromFile(L"GetCoin", L"../02_Resources/OverWorld/OverWorld_GetCoin.bmp", 3680, 329, 16, 1, true, RGB(99, 92, 99));
	IMAGEMANAGER->LoadFromFile(L"Shop_CoinNum", L"../02_Resources/PigShop/Shop_CoinNum.bmp", 450, 50, 9, 1, true, RGB(99, 92, 99));

	
	mCoinImage = IMAGEMANAGER->FindImage(L"Coin");
	mCoinNumImage = IMAGEMANAGER->FindImage(L"CoinNum");
	
	mSizeX = 50;
	mSizeY = 50;

	mCoinAnimation = new Animation();
	mCoinAnimation->SetIsLoop(true);
	mCoinAnimation->SetFrameUpdateTime(0.3f);
	mCoinAnimation->InitFrameByStartEnd(0, 0, 1, 0, false);
	mCoinAnimation->Play();
}

void Coin::Update()
{
	mCoinAnimation->Update();
}

void Coin::Render(HDC hdc)
{
	mCoinImage->FrameRender(hdc, mX, mY, mCoinAnimation->GetNowFrameX(), mCoinAnimation->GetNowFrameY());
	mCoinNumImage->FrameRender(hdc, mX + 30, mY, mNum, 0);
}

void Coin::Release()
{
	SafeDelete(mCoinAnimation);
}
