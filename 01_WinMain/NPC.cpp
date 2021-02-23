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
	mImage = IMAGEMANAGER->FindImage(L"NPC_Apple");

	mRect = RectMakeCenter(mX, mY, mSizeX, mSizeY);
	//mRange = RectMakeCenter(mX+50, mY+50, mSizeX + 200, mSizeY + 200);
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
}

void NPC::Render(HDC hdc)
{
	//CameraManager::GetInstance()->GetMainCamera()->RenderRect(hdc, mRange);
	CameraManager::GetInstance()->GetMainCamera()
		->ScaleFrameRender(hdc, mImage, mRect.left, mRect.top,
			mAnimaition->GetNowFrameX(), mAnimaition->GetNowFrameY(),
			100, 100);
	if (mIsTalk)
	{
		/*CameraManager::GetInstance()->GetMainCamera()
			->ScaleRender(hdc, mFullImage, CameraManager::GetInstance()->GetMainCamera()->GetRect().left, CameraManager::GetInstance()->GetMainCamera()->GetRect().top+200,
				WINSIZEX, 500);*/

	}
}
