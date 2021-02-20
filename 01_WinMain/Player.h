#pragma once
#include "GameObject.h"
class Player : public GameObject
{
	class Image* mImage;
	class Image* mImage2;
	class Image* mImage3;
	class Image* mImage4;
	class Image* mImage5;
	class Image* mImage6;
	class Image* mImage7;
	class Image* mImage8;
	
	class Animation* mDownIdleAnimation;
	class Animation* mUpIdleAnimation;
	class Animation* mLeftIdleAnimation;
	class Animation* mRightIdleAnimation;
	class Animation* mLeftRunAnimation;
	class Animation* mRightRunAnimation;
	class Animation* mUpRunAnimation;
	class Animation* mDownRunAnimation;
	class Animation* mUpAttackAnimation;
	class Animation* mDownAttackAnimation;
	class Animation* mLeftAttackAnimation;
	class Animation* mRightAttackAnimation;
	class Animation* mDieAnimation;
	class Animation* mCurrentAnimation;	//현재 애니메이션
	
	RECT mUpdownSwordRect;
	float mUpdownSwordSizeX;
	float mUpdownSwordSizeY;
	RECT mSideSwordRect;
	float mSideSwordSizeX;
	float mSideSwordSizeY;
	RECT mLeftSwordRECT;
	float mLeftSwordSizeX;
	float mLeftSwordSizeY;
	RECT mRightSwordRECT;
	float mRightSwordSizeX;
	float mRightSwordSizeY;
	RECT mUpSwordRECT;
	float mUpSwordSizeX;
	float mUpSwordSizeY;
	RECT mDownSwordRECT;
	float mDownSwordSizeX;
	float mDownSwordSizeY;
	
	bool mIsAttackMode;
	int mFrameCt;


public:
	Player(const string& name,float x, float y);

	void Init()override;
	void Release()override;
	void Update()override;
	void Render(HDC hdc)override;
};

