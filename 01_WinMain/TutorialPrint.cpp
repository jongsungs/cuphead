#include "pch.h"
#include "TutorialPrint.h"
#include "Image.h"
#include "Camera.h"
TutorialPrint::TutorialPrint(string name, float x, float y, Image* image)
	:GameObject(name)
{
	mX = x;
	mY = y;
	mImage = image;
}

void TutorialPrint::Init()
{
}

void TutorialPrint::Release()
{
}

void TutorialPrint::Update()
{
}

void TutorialPrint::Render(HDC hdc)
{
	CameraManager::GetInstance()->GetMainCamera()->Render(hdc,mImage, mX, mY);
}
