#include "pch.h"
#include "Building.h"
#include "Image.h"
#include "Camera.h"
#include "Talk.h"

Building::Building(const string& name, Image* image, float x, float y)
	:GameObject(name)
{
	mX = x;
	mY = y;
	mImage = image;
}

void Building::Init()
{
	mIsTalk = 0;
	mSizeX = mImage->GetWidth();
	mSizeY = mImage->GetHeight();
	mRect = RectMakeCenter(mX+mSizeX/2, mY+mSizeY/2, mSizeX, mSizeY);
	mZImage = IMAGEMANAGER->FindImage(L"ZPopUp");
	mZImageSizeX = 0;
	mIsClear = 0;
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
		if (mName == "Flatformer")
		{
			if (!mIsTalk)
			{
				if (Input::GetInstance()->GetKeyDown('Z'))
				{
				}
			}
			else
			{

			}
		}
		else if (mName == "ElderHouse")
		{
			if (!mIsTalk)
			{
				if (Input::GetInstance()->GetKeyDown('Z'))
				{
					ObjectManager::GetInstance()->AddObject(ObjectLayer::Talk,
						new Talk("ElderHouse_Talk",
							IMAGEMANAGER->FindImage(L"ElderHouse_Talk"), 350, 200));
					mIsTalk = 1;
				}
			}
			else
			{
				if (Input::GetInstance()->GetKeyDown(VK_ESCAPE))
				{
					ObjectManager::GetInstance()->DeleteObject(ObjectLayer::Talk);
					mIsTalk = 0;
				}
			}

		}
		else if (mName == "BotanicPanic")
		{
			if (!mIsTalk)
			{
				if (Input::GetInstance()->GetKeyDown('Z'))
				{
					ObjectManager::GetInstance()->AddObject(ObjectLayer::Talk,
						new Talk("BotanicPanic_Talk1",
							IMAGEMANAGER->FindImage(L"BotanicPanic_Talk1"), 350, 200));
					mIsTalk = 1;
				}
			}
			else
			{
				if (Input::GetInstance()->GetKeyDown(VK_ESCAPE))
				{
					ObjectManager::GetInstance()->DeleteObject(ObjectLayer::Talk);
					mIsTalk = 0;
				}
			}
		}
		if (!mIsTalk)
		{
			if (Input::GetInstance()->GetKeyDown('Z'))
			{
				if (mName == "Flatformer")
				{

				}
				else if (mName == "ElderHouse")
				{
					ObjectManager::GetInstance()->AddObject(ObjectLayer::Talk,
						new Talk("ElderHouse_Talk", 
							IMAGEMANAGER->FindImage(L"ElderHouse_Talk"), 350, 200));

				}
				else if (mName == "BotanicPanic")
				{

				}
				mIsTalk = true;
			}
		}
		else
		{
			if (Input::GetInstance()->GetKeyDown(VK_ESCAPE))
			{
				ObjectManager::GetInstance()->DeleteObject(ObjectLayer::Talk);
				mIsTalk = 0;
			}
		}
	}
	else
	{
		mZImageSizeX = 0;
		mZImageSizeY = 0;
	}
}

void Building::Render(HDC hdc)
{
	CameraManager::GetInstance()->GetMainCamera()->RenderRect(hdc, mRect);
	CameraManager::GetInstance()->GetMainCamera()->Render(hdc, mImage, mX, mY);
	CameraManager::GetInstance()->GetMainCamera()->ScaleRenderFromBottom(hdc,mZImage,
		ObjectManager::GetInstance()->FindObject("CupHead_OverWorld")->GetX(),
		ObjectManager::GetInstance()->FindObject("CupHead_OverWorld")->GetRect().top,mZImageSizeX,mZImageSizeY);
	if (mIsClear)
	{
		//깃발그려주기.
	}
}
