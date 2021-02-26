#include "pch.h"
#include "Block.h"
#include "Camera.h"

Block::Block(string name, float x, float y, float sizeX, float sizeY):GameObject(name){
	mX = x;
	mY = y;
	mSizeX = sizeX;
	mSizeY = sizeY;
	mRect = RectMake(x,y,sizeX,sizeY);
}

void Block::Init()
{
	
}

void Block::Update()
{

}

void Block::Render(HDC hdc)
{
	CameraManager::GetInstance()->GetMainCamera()->RenderRect(hdc, mRect);
}

void Block::Release()
{
	
}
