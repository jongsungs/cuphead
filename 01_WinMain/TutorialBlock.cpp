#include "pch.h"
#include "TutorialBlock.h"
#include "Image.h"
#include "Camera.h"
TutorialBlock::TutorialBlock(string name, Image* image, float x, float y, float sizeX, float sizeY)
	:Block(name,x,y,sizeX,sizeY)
{
	mImage = image;
}

void TutorialBlock::Init()
{
}


void TutorialBlock::Render(HDC hdc)
{
	CameraManager::GetInstance()->GetMainCamera()->Render(hdc, mImage, mRect.left, mRect.top);
}

