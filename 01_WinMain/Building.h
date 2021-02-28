#pragma once
#include "GameObject.h"
class Building :public GameObject
{
	Image* mImage;
	class Animation* mAnimation;
	//건물근접시 z키누르라는 말풍선뜨게함.
	Image* mZImage;
	Image* mFlagImage;
	class Animation* mFlagAnimation;
	int mZImageSizeX;
	int mZImageSizeY;
	bool mIsClear;
	bool mIsTalk;
	bool mIsRegular;

public :
	Building(const string& name, Image* image,float x, float y);
	
	void Init()override;
	void Release()override;
	void Update()override;
	void Render(HDC hdc)override;

	bool GetIsClear() { return mIsClear; };
	void SetIsClear(bool b) { mIsClear = b; };
};

