#include "pch.h"
#include "NPC.h"

#include "Image.h"
#include "Animation.h"
#include "Camera.h"

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
	mImage = IMAGEMANAGER->FindImage(L"NPC_Apple");
	mZImage = IMAGEMANAGER->FindImage(L"ZPopUp");
	mZImageSizeX = 0;
	mZImageSizeY = 0;
	mRect = RectMakeCenter(mX, mY, mSizeX, mSizeY);
	mRange = RectMakeCenter(mX+50, mY+50, mSizeX + 100, mSizeY + 100);
	mAnimaition = new Animation();
	mAnimaition->InitFrameByStartEnd(0, 0, 13, 0, false);
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

	RECT cupheadRectTemp = ObjectManager::GetInstance()->FindObject("CupHead_OverWorld")->GetRect();
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
			CameraManager::GetInstance()->GetMainCamera()->SetTarget(this);
			CameraManager::GetInstance()->GetMainCamera()->SetMode(Camera::Mode::Talk);
			mIsTalk = 1;
			mTalkNum++;
			if (mTalkNum > 5)
			{
				mTalkNum = 0;
				mIsTalk = 0;
				CameraManager::GetInstance()->GetMainCamera()->SetTarget(ObjectManager::GetInstance()->FindObject("CupHead_OverWorld"));
				CameraManager::GetInstance()->GetMainCamera()->SetMode(Camera::Mode::Follow);
			}
		}
		
	}
	else
	{
		mZImageSizeX = 0;
		mZImageSizeY = 0;
	}
}

void NPC::Render(HDC hdc)
{
	CameraManager::GetInstance()->GetMainCamera()->RenderRect(hdc, mRange);
	CameraManager::GetInstance()->GetMainCamera()
		->ScaleFrameRender(hdc, mImage, mRect.left, mRect.top,
			mAnimaition->GetNowFrameX(), mAnimaition->GetNowFrameY(),
			100, 100);
	
	if(!mIsTalk)
	{
		CameraManager::GetInstance()->GetMainCamera()->ScaleRenderFromBottom(hdc, mZImage,
			ObjectManager::GetInstance()->FindObject("CupHead_OverWorld")->GetX(),
			ObjectManager::GetInstance()->FindObject("CupHead_OverWorld")->GetRect().top, mZImageSizeX, mZImageSizeY);

	}
}
