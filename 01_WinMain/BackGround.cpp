#include "pch.h"
#include "BackGround.h"
#include "Camera.h"

BackGround::BackGround(const string& name, Image* image, float x, float y)
	:GameObject(name)
{
	mX = x;
	mY = y;
	mImage = image;
}

void BackGround::Init()
{
}

void BackGround::Release()
{
}

void BackGround::Update()
{
}

void BackGround::Render(HDC hdc)
{
	CameraManager::GetInstance()->GetMainCamera()->Render(hdc, mImage, mX, mY);
}
