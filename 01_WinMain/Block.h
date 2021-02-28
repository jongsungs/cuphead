#pragma once
#include "GameObject.h"
class Block : public GameObject
{
private:

public:
	Block(string name,float x, float y, float sizeX, float sizeY);
	virtual void Init()override;
	virtual void Update()override;
	virtual void Render(HDC hdc)override;
	virtual void Release()override;
};

