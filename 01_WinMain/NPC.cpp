#include "pch.h"
#include "NPC.h"

#include "Image.h"
#include "Animation.h"
#include "Camera.h"
#include "Talk.h"
NPC::NPC(const string& name, float x, float y)
	:GameObject(name)
{
	mX = x;
	mY = y;
}
void NPC::Init()
{
	
	mIsTalk = 0;
	mTalkNum = 0;
	mZImage = IMAGEMANAGER->FindImage(L"ZPopUp");
	mZImageSizeX = 0;
	mZImageSizeY = 0;

	mRect = RectMakeCenter(mX, mY, mSizeX, mSizeY);
	mAnimaition = new Animation();
	if (mName == "NPC_Apple")
	{
		mImage = IMAGEMANAGER->FindImage(L"NPC_Apple");
		mAnimaition->InitFrameByStartEnd(0, 0, 13, 0, false);
		mTalkImage1 = IMAGEMANAGER->FindImage(L"NPC_Apple_Talk1");
		mTalkImage2 = IMAGEMANAGER->FindImage(L"NPC_Apple_Talk2");
		mTalkImage3 = IMAGEMANAGER->FindImage(L"NPC_Apple_Talk3");
		mTalkImage4 = IMAGEMANAGER->FindImage(L"NPC_Apple_Talk4");
		mTalkImage5 = IMAGEMANAGER->FindImage(L"NPC_Apple_Talk5");
		mRange = RectMakeCenter(mX + 50, mY + 50, 100,  100);
	}
	else if (mName == "NPC_ElderKettle")
	{
		mImage = IMAGEMANAGER->FindImage(L"NPC_ElderKettle");
		mAnimaition->InitFrameByStartEnd(0, 0, 1, 0, false);
		mTalkImage1 = IMAGEMANAGER->FindImage(L"NPC_Kettle_Talk1");
		mTalkImage2 = IMAGEMANAGER->FindImage(L"NPC_Kettle_Talk2");
		mTalkImage3 = IMAGEMANAGER->FindImage(L"NPC_Kettle_Talk3");
		mTalkImage4 = IMAGEMANAGER->FindImage(L"NPC_Kettle_Talk4");
		mTalkImage5 = IMAGEMANAGER->FindImage(L"NPC_Kettle_Talk5");
		mRange = RectMakeCenter(mX + 150, mY + 150, 300, 300);
	}
	mAnimaition->SetIsLoop(true);
	mAnimaition->SetFrameUpdateTime(0.3f);
	mAnimaition->Play();
}

void NPC::Release()
{
}

void NPC::Update()
{
	mAnimaition->Update();
	RECT cupheadRectTemp;
	if (mIsOverWorld)
		cupheadRectTemp = ObjectManager::GetInstance()->FindObject("CupHead_OverWorld")->GetRect();
	else
		cupheadRectTemp = ObjectManager::GetInstance()->FindObject("CupHead_ElderHouse")->GetRect();
	RECT recttemp;
	
	if (IntersectRect(&recttemp, &cupheadRectTemp, &mRange))
	{
		if (mZImageSizeX < 50)
		{
			mZImageSizeX++;
			mZImageSizeY++;
		}
		if (Input::GetInstance()->GetKeyDown('Z'))
		{
			if (mName == "NPC_Apple")
			{
				CameraManager::GetInstance()->GetMainCamera()->SetTarget(this);
				CameraManager::GetInstance()->GetMainCamera()->SetMode(Camera::Mode::Talk);
				mIsTalk = 1;
				mTalkNum++;
				if (mTalkNum > 5)
				{
					mTalkNum = 0;
					mIsTalk = 0;
					ObjectManager::GetInstance()->DeleteObject(ObjectLayer::Talk);
					CameraManager::GetInstance()->GetMainCamera()->SetTarget(ObjectManager::GetInstance()->FindObject("CupHead_OverWorld"));
					CameraManager::GetInstance()->GetMainCamera()->SetMode(Camera::Mode::Follow);
				}

			}
		}
		
	}
	else
	{
		mZImageSizeX = 0;
		mZImageSizeY = 0;
	}

	if (mTalkNum == 1)
	{
		ObjectManager::GetInstance()->AddObject(ObjectLayer::Talk,
			new Talk("Talk1",
				IMAGEMANAGER->FindImage(L"NPC_Apple_Talk1"), mX-150, mY,false));
		
	}
	else if (mTalkNum == 2)
	{
		ObjectManager::GetInstance()->DeleteObject(ObjectLayer::Talk);
		ObjectManager::GetInstance()->AddObject(ObjectLayer::Talk,
			new Talk("Talk2",
				IMAGEMANAGER->FindImage(L"NPC_Apple_Talk2"), mX - 150, mY,false));
		
	}
	else if (mTalkNum == 3)
	{
		ObjectManager::GetInstance()->DeleteObject(ObjectLayer::Talk);
		ObjectManager::GetInstance()->AddObject(ObjectLayer::Talk,
			new Talk("Talk3",
				IMAGEMANAGER->FindImage(L"NPC_Apple_Talk3"), mX - 100, mY,false));
		
	}
	else if (mTalkNum == 4)
	{
		ObjectManager::GetInstance()->DeleteObject(ObjectLayer::Talk);
		ObjectManager::GetInstance()->AddObject(ObjectLayer::Talk,
			new Talk("Talk4",
				IMAGEMANAGER->FindImage(L"NPC_Apple_Talk4"), mX - 120, mY,false));
	}
	else if (mTalkNum == 5)
	{
		ObjectManager::GetInstance()->DeleteObject(ObjectLayer::Talk);
		ObjectManager::GetInstance()->AddObject(ObjectLayer::Talk,
			new Talk("Talk5",
				IMAGEMANAGER->FindImage(L"NPC_Apple_Talk5"), mX - 110, mY,false));
	}
}

void NPC::Render(HDC hdc)
{
	CameraManager::GetInstance()->GetMainCamera()->RenderRect(hdc, mRange);
	CameraManager::GetInstance()->GetMainCamera()
		->FrameRender(hdc, mImage, mRect.left, mRect.top,
			mAnimaition->GetNowFrameX(), mAnimaition->GetNowFrameY());
	
	if(!mIsTalk)
	{
		if (mIsOverWorld)
		{
			CameraManager::GetInstance()->GetMainCamera()->ScaleRenderFromBottom(hdc, mZImage,
				ObjectManager::GetInstance()->FindObject("CupHead_OverWorld")->GetX(),
				ObjectManager::GetInstance()->FindObject("CupHead_OverWorld")->GetRect().top, mZImageSizeX, mZImageSizeY);

		}
		else
		{
			CameraManager::GetInstance()->GetMainCamera()->ScaleRenderFromBottom(hdc, mZImage,
				ObjectManager::GetInstance()->FindObject("CupHead_ElderHouse")->GetX(),
				ObjectManager::GetInstance()->FindObject("CupHead_ElderHouse")->GetRect().top, mZImageSizeX, mZImageSizeY);
		}

	}
	else
	{

		
	}
}
