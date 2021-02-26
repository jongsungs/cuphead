#pragma once
#include "Scene.h"
class Scene_Start1 : public Scene
{
	Image* mBackGroundImage;
	Image* mImage;
	class Animation* mAnimation;
public:
	void Init()override;
	void Release()override;
	void Update()override;
	void Render(HDC hdc)override;
};

