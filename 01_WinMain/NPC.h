#pragma once
#include "GameObject.h"
class NPC : public GameObject
{
	Image* mImage;
	Image* mZImage;
	int mZImageSizeX;
	int mZImageSizeY;
	RECT mRange;
	bool mIsTalk;
	int mTalkNum;
	class Animation* mAnimaition;
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
};

