#pragma once
#include "GameObject.h"
enum class EnemyState : int {
	Idle,
	Attack,
	Death,
	End
};

class Enemy : public GameObject {
	class Image* mImage;
	class Image* mIdleImage;
	class Image* mAttackImage;
	class Image* mDeathImage;

	class Image* mExplosionImage;

	class Player* mPlayer;
	EnemyState mState;
	
	float mAngle;
	float mSpeed;
	int direction;
	int mRandomExplosion;

	float mAttackStartDelay;
	float mBetweenAttackDelay;

	bool IsAttack;
	RECT mExplosionRect;

	class Animation* mIdleAnimation;
	class Animation* mAttackAnimation;
	class Animation* mDeathAnimation;

	class Animation* mExplosionAnimation;

	class Animation* mCurrentAnimation;	//현재 애니메이션
public:
	Enemy(const string& name, float x, float y);

	void Init()override;
	void Release()override;
	void Update()override;
	void Render(HDC hdc)override;

	EnemyState GetEnemyState() const { return mState; }
	void SetEnemyState(EnemyState state) { mState = state; }

	RECT GetRect() const { return mRect; }
	RECT GetExplosionRect() { return mExplosionRect; }

	int GetHP() const { return mHP; }
	void SetHP(int hp) { mHP = hp; IsAttack = true; }

	void SetPlayerPtr(Player* player) { mPlayer = player; }
};