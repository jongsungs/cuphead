#pragma once
#include "GameObject.h"
class Image;
class Animation;
enum class EnemyState : int {
	Intro,
	Idle,
	ToBeam,
	Beam,
	FromBeam,
	Attack,
	Death,
	End
};
class Enemy : public GameObject {
protected:
	Image* mImage;

	Image* mIntroImage;
	Image* mIdleImage;
	Image* mAttackImage;
	Image* mDeathImage;

	class PlatformerPlayer* mPlayer;
	EnemyState mState;

	float mAttackStartDelay;
	float mDelayTime;

	Animation* mIntroAnimation;
	Animation* mIdleAnimation;
	Animation* mAttackAnimation;
	Animation* mDeathAnimation;

	Animation* mCurrentAnimation;	//현재 애니메이션
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

	void SetPlayerPtr(PlatformerPlayer* player) { mPlayer = player; }

};