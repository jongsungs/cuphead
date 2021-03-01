#include "pch.h"
#include "TutorialBackGround.h"
#include "Image.h"
TutorialBackGround::TutorialBackGround(string name, Image* image)
	:GameObject(name)
{
	mImage = image;

}

void TutorialBackGround::Init()
{


}

void TutorialBackGround::Release()
{

}

void TutorialBackGround::Update()
{

}

void TutorialBackGround::Render(HDC hdc)
{
	mImage->ScaleRender(hdc, 0,0,WINSIZEX,WINSIZEY);
}
