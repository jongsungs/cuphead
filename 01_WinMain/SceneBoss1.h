#pragma once
#include "Scene.h"
#include "Image.h"
class SceneBoss1: public Scene{
	Image* mBackGround1;
	Image* mBackGround2;
	Image* mBackGround3;
	Image* mBlack;
	Image* mClear;

	float mSceneDelayTime = 0.f;
	float mDelayTime = 0.f;

	bool mIsPlay = false;
	int frameX=0;
	int randomReady;
	int randomStart;
public:
	void Init()override;
	void Release()override;
	void Update()override;
	void Render(HDC hdc)override;
};

