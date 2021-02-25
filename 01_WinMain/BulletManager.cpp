#include "pch.h"
#include "BulletManager.h"
#include "Peashooter.h"
#include "Effect.h"
BulletManager::BulletManager() {
	mPlayerHaveBullet = { {Player_Bullet_Type::Peashooter,Player_Have::IsHave},{Player_Bullet_Type::Spread,Player_Have::NoHave } };
	mPlayerBulletType = Player_Bullet_Type::Peashooter;
}

void BulletManager::Player_Shoot(float x, float y, float angle) {
	if (mPlayerBulletType == Player_Bullet_Type::Peashooter) {
		//ObjectManager::GetInstance()->AddObject(ObjectLayer::Player_Bullet_Effect,new Effect(x,y,ImageManager::GetInstance()->FindImage(L"Peashooter")));
		ObjectManager::GetInstance()->AddObject(ObjectLayer::Player_Bullet,new Peashooter("Peashooter",x,y, angle));
	}
	else if (mPlayerBulletType == Player_Bullet_Type::Spread) {
		//ObjectManager::GetInstance()->AddObject(ObjectLayer::Player_Bullet_Effect, new Effect(x, y, ImageManager::GetInstance()->FindImage(L"Spread")));
		ObjectManager::GetInstance()->AddObject(ObjectLayer::Player_Bullet, new Peashooter("Spread", x, y, angle));
		ObjectManager::GetInstance()->AddObject(ObjectLayer::Player_Bullet, new Peashooter("Spread", x + 10, y - 10, angle));
		ObjectManager::GetInstance()->AddObject(ObjectLayer::Player_Bullet, new Peashooter("Spread", x + 10, y + 10, angle));
		ObjectManager::GetInstance()->AddObject(ObjectLayer::Player_Bullet, new Peashooter("Spread", x - 10, y - 10, angle));
		ObjectManager::GetInstance()->AddObject(ObjectLayer::Player_Bullet, new Peashooter("Spread", x -10, y +10, angle));
	}
}

void BulletManager::Enmey_Shoot(Enemy_Bullet_Type type, float x, float y, float speed, float angle){
	if (type == Enemy_Bullet_Type::Potato) {

	}
}


void BulletManager::ChangeBullet() {
	if (mPlayerBulletType == Player_Bullet_Type::Peashooter) {
		if (mPlayerHaveBullet.find(Player_Bullet_Type::Spread)->second == Player_Have::IsHave) {
			mPlayerBulletType = Player_Bullet_Type::Spread;
		}
	}
	else if (mPlayerBulletType == Player_Bullet_Type::Spread) {
		if (mPlayerHaveBullet.find(Player_Bullet_Type::Peashooter)->second == Player_Have::IsHave) {
			mPlayerBulletType = Player_Bullet_Type::Peashooter;
		}
	}
}