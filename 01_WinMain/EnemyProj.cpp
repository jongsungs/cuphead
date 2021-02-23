#include "pch.h"
#include "EnemyProj.h"

EnemyProj::EnemyProj(string name, float x, float y, float speed, float angle, bool parryAble)
	:GameObject(name) {
	mX = x;
	mY = y;
	mSpeed = speed;
	mAngle = angle;
	mParryAble = parryAble;
}


void EnemyProj::Init()
{
}

void EnemyProj::Release()
{
}

void EnemyProj::Update()
{
}

void EnemyProj::Render(HDC hdc)
{
}
