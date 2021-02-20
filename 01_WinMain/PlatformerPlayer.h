#pragma once
#include "GameObject.h"
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
	RightDownShot,
	LeftDownShot,
	RightShot,
	LeftShot,
	LeftRunShot,
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
	RECT mGround;
	float mGravity;
	float mJumpPower;
public:
	PlatformerPlayer(const string& name, float x, float y);

	void Init()override;
	void Release()override;
	void Update()override;
	void Render(HDC hdc)override;
};

