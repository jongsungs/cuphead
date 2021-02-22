#pragma once
#include "GameObject.h"

enum class EnemyState : int {
	Intro,
	Idle,
	InitAttack,
	Attack,
	Death,
	End
};
class Enemy : public GameObject {
	
protected:
	class Image* mImage;

	class Image* mIntroImage;
	class Image* mIdleImage;
	class Image* mAttackImage;
	class Image* mDeathImage;

	class Player* mPlayer;
	EnemyState mState;

	float mAttackStartDelay;

	class Animation* mIntroAnimation;
	class Animation* mIdleAnimation;
	class Animation* mAttackAnimation;
	class Animation* mDeathAnimation;

	class Animation* mCurrentAnimation;	//현재 애니메이션
public:
	Enemy(const string& name, float x, float y);

	void virtual Init()override = 0;
	void virtual Release()override = 0;
	void virtual Update()override = 0;
	void virtual Render(HDC hdc)override = 0;

	EnemyState GetEnemyState() const { return mState; }
	void SetEnemyState(EnemyState state) { mState = state; }

	RECT GetRect() const { return mRect; }

	int GetHP() const { return mHP; }
	void SetHP(int hp) { mHP = hp;}

	void SetPlayerPtr(Player* player) { mPlayer = player; }
};