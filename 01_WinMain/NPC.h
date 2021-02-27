#pragma once
#include "GameObject.h"
class NPC : public GameObject
{
	Image* mImage;
	Image* mZImage;
	Image* mTalkImage1, * mTalkImage2, * mTalkImage3, * mTalkImage4, * mTalkImage5;
	int mZImageSizeX;
	int mZImageSizeY;
	RECT mRange;
	bool mIsTalk;
	int mTalkNum;
	class Animation* mAnimaition;
	bool mIsOverWorld=1;
public:
	NPC(const string& name, float x, float y);
	void Init()override;
	void Release()override;
	void Update()override;
	void Render(HDC hdc)override;
	
	int GetTalkNum() { return mTalkNum; };
	bool GetIsTalk() { return mIsTalk; };
	void SetIsTalk(bool b) { mIsTalk = b; };
	RECT GetRange() { return mRange; };
	void SetIsOverWorld(bool b) { mIsOverWorld = b; };
};

