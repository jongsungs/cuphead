#pragma once
#include "Block.h"
class TutorialBlock : public Block
{
	class Image* mImage;
public :
	TutorialBlock(string name,Image* image, float x, float y, float sizeX, float sizeY);
	void Init()override;
	void Render(HDC hdc)override;
};

