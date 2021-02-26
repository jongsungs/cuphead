#pragma once
#include "GameObject.h"
class Block : public GameObject
{
private:

public:
	Block(string name,float x, float y, float sizeX, float sizeY);
	void Init()override;
	void Update()override;
	void Render(HDC hdc)override;
	void Release()override;
};

