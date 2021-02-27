#pragma once
#include "Scene.h"
class Scene_OverWorld : public Scene
{
	Image* mBackGroundImage_CanMove1;
	Image* mBackGroundImage_CanMove2;
	class Building* mBotanicPanic;
	class Cuphead_OverWorld* mCupHead;

public:
	void Init()override;
	void Release()override;
	void Update()override;
	void Render(HDC hdc)override;
};

