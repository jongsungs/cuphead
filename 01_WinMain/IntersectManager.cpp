#include "pch.h"
#include "IntersectManager.h"
#include "GameObject.h"

void IntersectManager::SetObjectPt()
{
	mFloor;
	mBullet =ObjectManager::GetInstance()->GetObjectListPt(ObjectLayer::Player_Bullet);
	mEnemyBullet = ObjectManager::GetInstance()->GetObjectListPt(ObjectLayer::Enemy_Bullet);
	mEnemy = ObjectManager::GetInstance()->GetObjectListPt(ObjectLayer::Enemy);
	mBoss = ObjectManager::GetInstance()->GetObjectListPt(ObjectLayer::Boss);
	mPlayer = ObjectManager::GetInstance()->GetObjectListPt(ObjectLayer::Player);
	mNPC = ObjectManager::GetInstance()->GetObjectListPt(ObjectLayer::NPC);
}

//요청 받았을 때 하는 충돌
bool IntersectManager::IntersectObjectList(GameObject* object, ObjectLayer name) {
	vector<GameObject*>* ObjectListPt  =  ObjectManager::GetInstance()->GetObjectListPt(name);
	for (int i = 0; i < ObjectListPt->size();++i) {
		RECT ObjectRc;
		RECT ListRc;
		RECT dump;
		if(IntersectRect (&dump,&ObjectRc,&ListRc)) {
			return true;
		}
	}
	return false;
}
void IntersectManager::IntersectEnemyAndBullet()
{
	if (mBullet->size()){
		return;
	}
	if (mEnemy->size() && mBoss->size()) {
		return;
	}
	for (int a = 0; a < mBullet->size(); ++a) {
		if (!(*mBullet)[a]->GetIsActive() && (*mBullet)[a]->GetIsDestroy() )
			continue;
		for (int b = 0; b < mEnemy->size(); ++b) {
			if (!(*mEnemy)[a]->GetIsActive() && (*mEnemy)[a]->GetIsDestroy())
				continue;
			RECT enemyRect = (*mEnemy)[b]->GetRect();
			RECT bulletRect = (*mBullet)[a]->GetRect();
			RECT dump;
			if (IntersectRect(&dump, &enemyRect, &bulletRect)) {
				(*mEnemy)[b]->InIntersectDamage();
				(*mBullet)[a]->InIntersectDamage();
				break;
			}
		}
		for (int b = 0; b < mBoss->size(); ++b) {
			if (!(*mBoss)[a]->GetIsActive() && (*mBoss)[a]->GetIsDestroy())
				continue;
			RECT bossRect = (*mBoss)[b]->GetRect();
			RECT bulletRect = (*mBullet)[a]->GetRect();
			RECT dump;
			if (IntersectRect(&dump, &bossRect, &bulletRect)) {
				(*mBoss)[b]->InIntersectDamage();
				(*mBullet)[a]->InIntersectDamage();
				break;
			}
		}
	}
}

void IntersectManager::IntersectPlayerAndEnemyBullet()
{
	if (mEnemyBullet->size()) {
		return;
	}
	for (int a = 0; a < mEnemyBullet->size(); ++a) {
		if (!(*mEnemyBullet)[a]->GetIsActive() && (*mEnemyBullet)[a]->GetIsDestroy())
			continue;
		for (int b = 0; b < mPlayer->size(); ++b) {
			if (!(*mPlayer)[b]->GetIsActive() && (*mPlayer)[b]->GetIsDestroy())
				continue;
			RECT enemyBulletRect = (*mPlayer)[a]->GetRect();
			RECT playerRect = (*mPlayer)[b]->GetRect();
			RECT dump;
			if (IntersectRect(&dump, &enemyBulletRect, &playerRect)) {
				(*mEnemyBullet)[a]->InIntersectDamage();
				(*mPlayer)[b]->InIntersectDamage();
				return;
			}
		}
	}
}

void IntersectManager::IntersectPlayerAndEnemy()
{
	if (mPlayer->size()) {
		return;
	}
	if (mEnemy->size() && mBoss->size()) {
		return;
	}
	for (int a = 0; a < mPlayer->size(); ++a) {
		if (!(*mPlayer)[a]->GetIsActive() && (*mPlayer)[a]->GetIsDestroy())
			continue;
		for (int b = 0; b < mEnemy->size(); ++b) {
			if (!(*mEnemy)[b]->GetIsActive() && (*mEnemy)[b]->GetIsDestroy())
				continue;
			RECT enemyRect = (*mEnemy)[b]->GetRect();
			RECT playerRect = (*mPlayer)[a]->GetRect();
			RECT dump;
			if (IntersectRect(&dump, &enemyRect, &playerRect)) {
				(*mPlayer)[a]->InIntersectDamage();
				return;
			}
		}
		for (int b = 0; b < mBoss->size(); ++b) {
			if (!(*mBoss)[b]->GetIsActive() && (*mBoss)[b]->GetIsDestroy())
				continue;
			RECT bossRect = (*mBoss)[b]->GetRect();
			RECT playerRect = (*mPlayer)[a]->GetRect();
			RECT dump;
			if (IntersectRect(&dump, &bossRect, &playerRect)) {
				(*mPlayer)[a]->InIntersectDamage();
				return;
			}
		}
	}
}

void IntersectManager::IntersectPlayerAndFloor()
{
	if (mPlayer->size() || mFloor->size()) {
		return;
	}
	for (int a = 0; a < mPlayer->size(); ++a) {
		if (!(*mPlayer)[a]->GetIsActive() && (*mPlayer)[a]->GetIsDestroy())
			continue;
		for (int b = 0; b < mFloor->size(); ++b) {
			if (!(*mFloor)[a]->GetIsActive() && (*mFloor)[a]->GetIsDestroy())
				continue;
			RECT floorRect = (*mFloor)[a]->GetRect();
			RECT playerRect = (*mPlayer)[a]->GetRect();
			RECT dump;
			if (IntersectRect(&dump, &floorRect, &playerRect)) {
				(*mPlayer)[a]->InInterscet();
				(*mFloor)[b]->InInterscet();
				return;
			}
		}
	}
}
