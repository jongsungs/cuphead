#include "pch.h"
#include "Building.h"
#include "Image.h"
#include "Camera.h"
#include "Talk.h"
#include "Scene_ElderHouse.h"
#include "Animation.h"
#include "FadeOut.h"
#include "LoadingScene.h"
Building::Building(const string& name, Image* image, float x, float y)
	:GameObject(name)
{
	mX = x;
	mY = y;
	mImage = image;
}

void Building::Init()
{
	mFlagAnimation = new Animation();
	mFlagAnimation->InitFrameByStartEnd(0, 0, 11, 0, false);
	mFlagAnimation->SetIsLoop(true);
	mFlagAnimation->SetFrameUpdateTime(0.2f);
	mFlagAnimation->Play();
	mFlagImage = IMAGEMANAGER->FindImage(L"OverWorld_Flag");
	mIsTalk = 0;
	mSizeX = mImage->GetWidth();
	mSizeY = mImage->GetHeight();
	mRect = RectMakeCenter(mX+mSizeX/2, mY+mSizeY/2, mSizeX, mSizeY);
	mZImage = IMAGEMANAGER->FindImage(L"ZPopUp");
	mZImageSizeX = 0;
	mIsClear = 1;
	mIsRegular = 0;
}

void Building::Release()
{
}

void Building::Update()
{
	mFlagAnimation->Update();
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
				if (Input::GetInstance()->GetKeyDown('Z'))
				{
					mZImageSizeX = 0;
					mZImageSizeY = 0;

					FadeOut* fadeout = new FadeOut(false, L"ElderHouse", L"ElderHouse_LoadingScene");
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
							IMAGEMANAGER->FindImage(L"BotanicPanic_Talk1"), 200, 100));
					mIsTalk = 1;
					
				}
			}
			else
			{
				if (Input::GetInstance()->GetKeyDown(VK_LEFT))
				{
					if (mIsRegular)
					{
						ObjectManager::GetInstance()->DeleteObject(ObjectLayer::Talk);
						ObjectManager::GetInstance()->AddObject(ObjectLayer::Talk,
							new Talk("BotanicPanic_Talk1",
								IMAGEMANAGER->FindImage(L"BotanicPanic_Talk1"), 200, 100));
						mIsRegular = 0;
					}
				}
				if (Input::GetInstance()->GetKeyDown(VK_RIGHT))
				{
					if (!mIsRegular)
					{
						ObjectManager::GetInstance()->DeleteObject(ObjectLayer::Talk);
						ObjectManager::GetInstance()->AddObject(ObjectLayer::Talk,
							new Talk("BotanicPanic_Talk2",
								IMAGEMANAGER->FindImage(L"BotanicPanic_Talk2"), 200, 100));
						mIsRegular = 1;
					}
				}
				if (Input::GetInstance()->GetKeyDown(VK_ESCAPE))
				{
					ObjectManager::GetInstance()->DeleteObject(ObjectLayer::Talk);
					mIsTalk = 0;
				}
				if (Input::GetInstance()->GetKeyDown('Z'))
				{
					mZImageSizeX = 0;
					mZImageSizeY = 0;

					FadeOut* fadeout = new FadeOut(false, L"BotanicPanic", L"BotanicPanic_LoadingScene");
					mIsTalk = 0;
				}
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
	CameraManager::GetInstance()->GetMainCamera()->Render(hdc, mImage, mX, mY);
	CameraManager::GetInstance()->GetMainCamera()->ScaleRenderFromBottom(hdc,mZImage,
		ObjectManager::GetInstance()->FindObject("CupHead_OverWorld")->GetX(),
		ObjectManager::GetInstance()->FindObject("CupHead_OverWorld")->GetRect().top,mZImageSizeX,mZImageSizeY);
	if (mName == "BotanicPanic" && mIsClear)
	{
		CameraManager::GetInstance()->GetMainCamera()->FrameRender(hdc, mFlagImage, mX+100, mY-50, mFlagAnimation->GetNowFrameX(),mFlagAnimation->GetNowFrameY());
	}
}
