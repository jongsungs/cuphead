#pragma once
#include "GameObject.h"
class Talk : public GameObject
{
	Image* mImage;

public:
	Talk(const string& name, Image* image, float x, float y);
	void Init()override;
	void Release()override;
	void Update()override;
	void Render(HDC hdc)override;

};