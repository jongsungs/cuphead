#pragma once
#include "Scene.h"
class BossScene
	: public Scene
{
	vector<class Enemy*> mEnemys;
public:
	void Init()override;
	void Release()override;
	void Update()override;
	void Render(HDC hdc)override;
};

