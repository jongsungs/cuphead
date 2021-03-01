#pragma once
#include "Scene.h"
class Scene_ElderHouse :public Scene
{
	Image* mImage;
	class PlatformerPlayer* mPlayer;
	class NPC* mElderKettle;
	RECT mTutorialRect;
	RECT mDoorRect;
	Image* mZImage;
	int mZImageSizeX;
	int mZImageSizeY;
public:
	
	void Init()override;
	void Release()override;
	void Update()override;
	void Render(HDC hdc)override;
};

