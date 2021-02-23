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
	mSizeX = mImage->GetWidth();
	mSizeY = mImage->GetHeight();
	mRect = RectMakeCenter(mX, mY, mSizeX, mSizeY);
	mZImage = IMAGEMANAGER->FindImage(L"ZPopUp");
	mZImageSizeX = 0;
}

void Building::Release()
{
}

void Building::Update()
{
	RECT cupheadRectTemp = ObjectManager::GetInstance()->FindObject("CupHead_OverWorld")->GetRect();
	RECT recttemp;
	if (IntersectRect(&recttemp, &cupheadRectTemp, &mRect))
	{
		if (mZImageSizeX < 50)
		{
			mZImageSizeX++;
			mZImageSizeY++;
		}
		/*
		여기에 씬넘어가는거 추가.
		
		if (mName == "Flatformer")
		{

		}
		else if (mName == "ElderHouse")
		{

		}
		else if (mName == "BotanicPanic")
		{

		}
		*/
	}
	else
	{
		mZImageSizeX = 0;
		mZImageSizeY = 0;
	}
}

void Building::Render(HDC hdc)
{
	CameraManager::GetInstance()->GetMainCamera()->CenterScaleRender(hdc,mZImage,
		ObjectManager::GetInstance()->FindObject("CupHead_OverWorld")->GetX(),
		ObjectManager::GetInstance()->FindObject("CupHead_OverWorld")->GetY()-100,mZImageSizeX,mZImageSizeY);
	CameraManager::GetInstance()->GetMainCamera()->Render(hdc, mImage, mX, mY);
}
