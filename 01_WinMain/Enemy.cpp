#include "pch.h"
#include "Enemy.h"

Enemy::Enemy(const string& name, float x, float y)
	:GameObject(name)
{
	mX = x;
	mY = y;
}
