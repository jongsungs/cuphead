#pragma once
#include "GameObject.h"
class Building :public GameObject
{
	Image* mImage;
	//건물근접시 z키누르라는 말풍선뜨게함.
	Image* mZImage;
	int mZImageSizeX;
	int mZImageSizeY;

public :
	Building(const string& name, Image* image,float x, float y);

	void Init()override;
	void Release()override;
	void Update()override;
	void Render(HDC hdc)override;
};

