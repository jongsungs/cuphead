#include "pch.h"
#include "Talk.h"
#include "Camera.h"
#include "Image.h"
Talk::Talk(const string& name, Image* image, float x, float y, bool isInfo)
	:GameObject(name)
{
	mX = x;
	mY = y;
	mImage = image;
	mIsInfo = isInfo;
}

void Talk::Init()
{
}

void Talk::Release()
{
}

void Talk::Update()
{
}

void Talk::Render(HDC hdc)
{
	if (mIsInfo)
	{
		IMAGEMANAGER->FindImage(L"Black")->AlphaRender(hdc, 0, 0, 0.5f);
		mImage->ScaleRender(hdc, mX, mY, mImage->GetWidth() * 0.7, mImage->GetHeight() * 0.7);
	}
	else
	{
		CameraManager::GetInstance()->GetMainCamera()->ScaleRenderFromBottom(hdc, mImage, mX, mY, mImage->GetWidth() * 0.5, mImage->GetHeight() * 0.5);
	}
}
