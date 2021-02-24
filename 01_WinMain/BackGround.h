#pragma once
#include "GameObject.h"
class BackGround : public GameObject
{
	Image* mImage;

public:
	BackGround(const string& name, Image* image, float x, float y);
	void Init()override;
	void Release()override;
	void Update()override;
	void Render(HDC hdc)override;

};