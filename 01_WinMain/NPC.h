#pragma once
#include "GameObject.h"
class Image;

class NPC : public GameObject
{
	Image* mImage;
	Image* mTalkImage1;
	RECT mRange;
	bool mIsTalk;
	class Animation* mAnimaition;
public:
	NPC(const string& name, float x, float y);
	void Init()override;
	void Release()override;
	void Update()override;
	void Render(HDC hdc)override;
	
	void SetIsTalk(bool b) { mIsTalk = b; };
	RECT GetRange() { return mRange; };
};

