#pragma once
#include "Scene.h"
class Scene_ElderHouse :public Scene
{
	Image* mImage;
	class Cuphead_OverWorld* mPlayer;
	class NPC* mElderKettle;
	RECT mDoorRect;
public:
	
	void Init()override;
	void Release()override;
	void Update()override;
	void Render(HDC hdc)override;
};

