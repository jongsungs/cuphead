#include "pch.h"
#include "TutorialCube.h"
#include "Camera.h"
TutorialCube::TutorialCube(string name, float x, float y, float sizeX, float sizeY, Image* image)
	:Block(name, x, y, sizeX, sizeY)
{
	mImage = image;
	mCenterX = mX + (sizeX / 2);
}

void TutorialCube::Init()
{
}

void TutorialCube::Release()
{
}

void TutorialCube::Update()
{
}

void TutorialCube::Render(HDC hdc)
{
	CameraManager::GetInstance()->GetMainCamera()->RenderFromBottom(hdc, mImage, mCenterX,mRect.bottom);
	//CameraManager::GetInstance()->GetMainCamera()->RenderRect(hdc, mRect);
}
