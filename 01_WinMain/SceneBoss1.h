#pragma once
#include "Scene.h"
#include "Image.h"
class SceneBoss1: public Scene{
	Image* mBackGround1;
	Image* mBackGround2;
	Image* mBackGround3;
	float mSceneDelayTime = 0.f;
public:
	void Init()override;
	void Release()override;
	void Update()override;
	void Render(HDC hdc)override;
};

