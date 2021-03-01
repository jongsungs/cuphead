#pragma once
#include "GameObject.h"
class Coin : public GameObject
{
private:
	Image* mCoinImage;
	Image* mCoinNumImage;
	class Animation* mCoinAnimation;
	int mNum;
public:
	Coin(string name, float x, float y);
	void Init()override;
	void Update()override;
	void Render(HDC hdc)override;
	void Release()override;

	inline void SetNum(int num) { mNum = num; };
	inline int GetNum() { return mNum; };
};

