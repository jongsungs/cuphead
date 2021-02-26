#pragma once
#include "Scene.h"
class Scene_Start2 : public Scene
{
	int mNum;
	Image* mImages[3];
public:
	void Init()override;
	void Release()override;
	void Update()override;
	void Render(HDC hdc)override;
};

