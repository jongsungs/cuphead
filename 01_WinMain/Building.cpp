#include "pch.h"
#include "Building.h"
#include "Image.h"
#include "Camera.h"

Building::Building(const string& name, Image* image, float x, float y)
	:GameObject(name)
{
	mX = x;
	mY = y;
	mImage = image;
}

void Building::Init()
{
}

void Building::Release()
{
}

void Building::Update()
{
}

void Building::Render(HDC hdc)
{
	CameraManager::GetInstance()->GetMainCamera()->Render(hdc, mImage, mX, mY);
}
