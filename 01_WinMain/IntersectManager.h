#pragma once
//충돌 매니저
/*
	1. 상시충돌

	2. 요청이 들어와서 하는 충돌
*/


class IntersectManager
{
	Singleton(IntersectManager)
private:
	vector<class GameObject*>* mFloor;
	vector<class GameObject*>* mBullet;
	vector<class GameObject*>* mEnemyBullet;
	vector<class GameObject*>* mEnemy;
	vector<class GameObject*>* mBoss;
	vector<class GameObject*>* mPlayer;
	vector<class GameObject*>* mNPC;
public :
	void SetObjectPt();
	bool IntersectObjectList(class GameObject* object, ObjectLayer key);
	void IntersectEnemyAndBullet();
	void IntersectPlayerAndEnemyBullet();
	void IntersectPlayerAndEnemy(); //플레이어 충돌
	void IntersectPlayerAndFloor(); //플레이어 충돌
};

