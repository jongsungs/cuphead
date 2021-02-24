#pragma once
#include "GameObject.h"
class Bullet;
enum class PlayerState : int
{
	RightIdle,
	LeftIdle,
	LeftDuckIdle,
	RightDuckIdle,
	RightRun,
	RightRunturn,
	LeftRun,
	LeftRunturn,
	LeftJump,
	RightJump,
	RightDuck,
	LeftDuck,
	RightDuckShoot,
	LeftDuckShoot,
	RightShoot,
	RightUpShoot,
	RightDiagonalUpShoot,
	LeftShoot,
	LeftUpShoot,
	LeftDiagonalUpShoot,
	LeftRunShoot,
	LeftRunShootturn,
	LeftRunDiagonalUpShoot,
	LeftRunDiagonalUpShootturn,
	RightRunShoot,
	RightRunShootturn,
	RightRunDiagonalUpShoot,
	RightRunDiagonalUpShootturn,
	RightSpecialAttack,
	LeftSpecialAttack,
	UpSpecialAttack,
	RightHit,//오른쪽땅에서 피격
	LeftHit,
	LeftDash,
	RightDash,
	LeftAirDash,
	RightAirDash,
	Die,
	RightParring,
	LeftParring,
	RightUpaim,
	LeftUpaim,
	LeftShootaim,
	RightShootaim,
	LeftDiagonalUpaim,
	RightDiagonalUpaim,

};

class PlatformerPlayer : public GameObject
{
	
	Image* mImage;
	RECT mGround;
	float mGravity;
	float mJumpPower;
	PlayerState mPlayerState;
	vector<Bullet*> mBullet;

	Animation* mCurrentAnimation;

	Animation* mRightIdleAnimation;
	Animation* mLeftIdleAnimation;
	Animation* mLeftDuckIdleAnimation;
	Animation* mRightDuckIdleAnimation;
	Animation* mRightRunAnimation;
	Animation* mRightRunturnAnimation;
	Animation* mLeftRunAnimation;
	Animation* mLeftRunturnAnimation;
	Animation* mLeftJumpAnimation;
	Animation* mRightJumpAnimation;
	Animation* mRightDuckAnimation;
	Animation* mLeftDuckAnimation;
	Animation* mRightDuckShootAnimation;
	Animation* mLeftDuckShootAnimation;
	Animation* mRightShootAnimation;
	Animation* mRightUpShootAnimation;
	Animation* mRightDiagonalUpShootAnimation;
	Animation* mLeftShootAnimation;
	Animation* mLeftUpShootAnimation;
	Animation* mLeftDiagonalUpShootAnimation;
	Animation* mLeftRunShootAnimation;
	Animation* mLeftRunShootturnAnimation;
	Animation* mLeftRunDiagonalUpShootAnimation;
	Animation* mLeftRunDiagonalUpShootturnAnimation;
	Animation* mRightRunShootAnimation;
	Animation* mRightRunShootturnAnimation;
	Animation* mRightRunDiagonalUpShootAnimation;
	Animation* mRightRunDiagonalUpShootturnAnimation;
	Animation* mRightSpecialAttackAnimation;
	Animation* mLeftSpecialAttackAnimation;
	Animation* mUpSpecialAttackAnimation;
	Animation* mRightHitAnimation;
	Animation* mLeftHitAnimation;
	Animation* mLeftDashAnimation;
	Animation* mRightDashAnimation;
	Animation* mLeftAirDashAnimation;
	Animation* mRightAirDashAnimation;
	Animation* mDieAnimation;
	Animation* mRightParringAnimation;
	Animation* mLeftParringAnimation;
	Animation* mRightUpaimAnimation;
	Animation* mLeftUpaimAnimation;
	Animation* mRightShootaimAnimation;
	Animation* mLeftShootaimAnimation;
	Animation* mLeftDiagonalUpaimAnimation;
	Animation* mRightDiagonalUpaimAnimation;

	bool isMove;
public:
	PlatformerPlayer(const string& name, float x, float y);

	void Init()override;
	void Release()override;
	void Update()override;
	void Render(HDC hdc)override;
};

