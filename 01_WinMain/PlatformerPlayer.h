#pragma once
#include "GameObject.h"
enum struct PlayerState : int
{
	RightIdle,
	LeftIdle,
	
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

