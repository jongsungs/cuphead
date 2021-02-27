#pragma once
#include "GameObject.h"
class Talk : public GameObject
{
	Image* mImage;
	bool mIsInfo;

public:
	Talk(const string& name, Image* image, float x, float y, bool isInfo);
	void Init()override;
	void Release()override;
	void Update()override;
	void Render(HDC hdc)override;

};