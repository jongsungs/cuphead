#pragma once
#include "Scene.h"
class Scene_OverWorld : public Scene
{
	Image* mBackGroundImage_Layer2;
	Image* mTalkImage1, * mTalkImage2, * mTalkImage3, * mTalkImage4, * mTalkImage5;
	class Cuphead_OverWorld* mCupHead;

public:
	void Init()override;
	void Release()override;
	void Update()override;
	void Render(HDC hdc)override;
};

