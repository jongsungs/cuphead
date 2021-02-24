#pragma once
#include "Scene.h"
#include "Image.h"
class BossScene
	: public Scene
{
	vector<class Enemy*> mEnemys;
	Image* mBackGround1;
	Image* mBackGround2;
	Image* mBackGround3;
public:
	void Init()override;
	void Release()override;
	void Update()override;
	void Render(HDC hdc)override;
};

