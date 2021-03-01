#pragma once
#include "Scene.h"
class Scene_Shop :public Scene
{
	Image* mBackGroundImage;
	Image* mPigImage;
	Image* mSpreadBulletImage;
	Image* mLeftDoorImage;
	Image* mRightDoorImage;
	Image* mCoinImage;
	Image* mCoinNumImage;
	int mLeftDoorX;
	int mRightDoorX;

	bool mSpreadBulletIsSoldOut;

	class Animation* mPigAnimation;
	
public:

	void Init()override;
	void Release()override;
	void Update()override;
	void Render(HDC hdc)override;
};

