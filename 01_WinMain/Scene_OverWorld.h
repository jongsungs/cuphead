#pragma once
#include "Scene.h"
class Scene_OverWorld : public Scene
{
	Image* mBackGroundImage_Layer1;
	Image* mBackGroundImage_Layer2;
	Image* mBackGroundImage_Layer3;
	class Cuphead_OverWorld* mCupHead;

public:
	void Init()override;
	void Release()override;
	void Update()override;
	void Render(HDC hdc)override;
};

