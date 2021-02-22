#pragma once
#include "GameObject.h"
class Building :public GameObject
{
	Image* mImage;

public :
	Building(const string& name, Image* image,float x, float y);

	void Init()override;
	void Release()override;
	void Update()override;
	void Render(HDC hdc)override;
};

