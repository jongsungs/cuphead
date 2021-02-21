#pragma once
#include "GameObject.h"

enum class State
{
	Idle,
	LeftMove,
	LeftUpMove,
	UpMove,
	RightUpMove,
	RightMove,
	RightDownMove,
	DownMove,
	LeftDownMove,
};
class Cuphead_OverWorld : public GameObject
{
	Image* mImage;
	Image* mDustImage;
	float mAngle;
	float mSpeed;
	bool mIsGetKeyNow;
	int mDustCount;

	
	
	//애니매이션
	class Animation* mLeftIdleAnimation;
	class Animation* mLeftDownIdleAnimation;
	class Animation* mLeftUpIdleAnimation;
	class Animation* mRightIdleAnimation;
	class Animation* mRightDownIdleAnimation;
	class Animation* mRightUpIdleAnimation;
	class Animation* mUpIdleAnimation;
	class Animation* mDownIdleAnimation;

	class Animation* mLeftMoveAnimation;
	class Animation* mLeftDownMoveAnimation;
	class Animation* mLeftUpMoveAnimation;
	class Animation* mRightMoveAnimation;
	class Animation* mRightUpMoveAnimation;
	class Animation* mRightDownMoveAnimation;
	class Animation* mUpMoveAnimation;
	class Animation* mDownMoveAnimation;

	class Animation* mCurrentAnimation;
public :
	Cuphead_OverWorld(const string& name, float x, float y);

	void Init()override;
	void Release()override;
	void Update()override;
	void Render(HDC hdc)override;
};

