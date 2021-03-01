#pragma once
#include "Scene.h"
class SceneTutorial : public Scene
{
	RECT mMap;
	bool mExitDoorCheck;
	float mDistance;
	class Image* mZImage;
public:
	void Init()override;
	void Release()override;
	void Update()override;
	void Render(HDC hdc)override;
};

