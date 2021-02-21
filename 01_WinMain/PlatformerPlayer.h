#pragma once
#include "GameObject.h"
class Bullet;
enum struct PlayerState : int
{
	RightIdle,
	LeftIdle,
	LeftDownIdle,
	RightDownIdle,
	RightRun,
	LeftRun,
	LeftJump,
	RightJump,
	RightDown,
	LeftDown,
	RightDownShoot,
	LeftDownShoot,
	RightShoot,
	LeftShoot,
	LeftRunShoot,
	RightSpecialAttack,
	LeftSpecialAttack,
	UpSpecialAttack,
	DownSpecialAttack,
	RightRunShot,
	RightGroundHit,//�����ʶ����� �ǰ�
	RightAirHit, // ������ ���� �ǰ�
	LeftGroundHit,
	LeftAirHit,
	LeftDash,
	RightDash,
	Die,

};
class PlatformerPlayer : public GameObject
{
	Image* mImage;
	RECT mGround;
	float mGravity;
	float mJumpPower;
	PlayerState mPlayerState;
	vector<Bullet*> mBullet;
public:
	PlatformerPlayer(const string& name, float x, float y);

	void Init()override;
	void Release()override;
	void Update()override;
	void Render(HDC hdc)override;
};

