#include "pch.h"
#include "BulletManager.h"
#include "Peashooter.h"
#include "Spread.h"
#include "Effect.h"
#include "Player_Bullet_Effect.h"
#include "SuperPeashooter.h"
#define RadianAngle(angle) angle* PI/180
BulletManager::BulletManager() {
	mPlayerHaveBullet = { {Player_Bullet_Type::Peashooter,Player_Have::IsHave},{Player_Bullet_Type::Spread,Player_Have::NoHave } };
	mPlayerBulletType = Player_Bullet_Type::Peashooter;
}

void BulletManager::Player_Shoot(float x, float y, float angle) {
	if (mPlayerBulletType == Player_Bullet_Type::Peashooter) {
		new Player_Bullet_Effect(x,y,ImageManager::GetInstance()->FindImage(L"BulletStart"),0.07f);
		ObjectManager::GetInstance()->AddObject(ObjectLayer::Player_Bullet,new Peashooter("Peashooter",x,y, angle));
	}
	else if (mPlayerBulletType == Player_Bullet_Type::Spread) {
		new Player_Bullet_Effect(x, y, ImageManager::GetInstance()->FindImage(L"RedBulletStart"), 0.07f);
		//ObjectManager::GetInstance()->AddObject(ObjectLayer::Player_Bullet_Effect, new Effect(x, y, ImageManager::GetInstance()->FindImage(L"Spread")));
		ObjectManager::GetInstance()->AddObject(ObjectLayer::Player_Bullet, new Spread("Spread", x, y, angle, 0));
		if (angle == RadianAngle(0)) { //0µµ
			ObjectManager::GetInstance()->AddObject(ObjectLayer::Player_Bullet, new Spread("Spread", x, y, RadianAngle(45), 0));
			ObjectManager::GetInstance()->AddObject(ObjectLayer::Player_Bullet, new Spread("Spread", x, y, RadianAngle(315), 0));
			ObjectManager::GetInstance()->AddObject(ObjectLayer::Player_Bullet, new Spread("Spread", x, y - 10, angle, 1));
			ObjectManager::GetInstance()->AddObject(ObjectLayer::Player_Bullet, new Spread("Spread", x, y + 10, angle, 1));
		}
		else if (angle == RadianAngle(45)) {
			ObjectManager::GetInstance()->AddObject(ObjectLayer::Player_Bullet, new Spread("Spread", x, y, RadianAngle(90), 0));
			ObjectManager::GetInstance()->AddObject(ObjectLayer::Player_Bullet, new Spread("Spread", x, y, RadianAngle(0), 0));
			ObjectManager::GetInstance()->AddObject(ObjectLayer::Player_Bullet, new Spread("Spread", x -5, y-5, angle, 1));
			ObjectManager::GetInstance()->AddObject(ObjectLayer::Player_Bullet, new Spread("Spread", x + 5, y+5, angle, 1));
		}
		else if (angle == RadianAngle(90)) {
			ObjectManager::GetInstance()->AddObject(ObjectLayer::Player_Bullet, new Spread("Spread", x, y, RadianAngle(135), 0));
			ObjectManager::GetInstance()->AddObject(ObjectLayer::Player_Bullet, new Spread("Spread", x, y, RadianAngle(45), 0));
			ObjectManager::GetInstance()->AddObject(ObjectLayer::Player_Bullet, new Spread("Spread", x -10, y, angle, 1));
			ObjectManager::GetInstance()->AddObject(ObjectLayer::Player_Bullet, new Spread("Spread", x + 10, y, angle, 1));
		}
		else if (angle == RadianAngle(135)) {
			ObjectManager::GetInstance()->AddObject(ObjectLayer::Player_Bullet, new Spread("Spread", x, y, RadianAngle(180), 0));
			ObjectManager::GetInstance()->AddObject(ObjectLayer::Player_Bullet, new Spread("Spread", x, y, RadianAngle(90), 0));
			ObjectManager::GetInstance()->AddObject(ObjectLayer::Player_Bullet, new Spread("Spread", x - 5, y-5, angle, 1));
			ObjectManager::GetInstance()->AddObject(ObjectLayer::Player_Bullet, new Spread("Spread", x + 5, y+5, angle, 1));
		}
		else if (angle == RadianAngle(180)) {
			ObjectManager::GetInstance()->AddObject(ObjectLayer::Player_Bullet, new Spread("Spread", x, y, RadianAngle(225), 0));
			ObjectManager::GetInstance()->AddObject(ObjectLayer::Player_Bullet, new Spread("Spread", x, y, RadianAngle(135), 0));
			ObjectManager::GetInstance()->AddObject(ObjectLayer::Player_Bullet, new Spread("Spread", x, y - 10, angle, 1));
			ObjectManager::GetInstance()->AddObject(ObjectLayer::Player_Bullet, new Spread("Spread", x, y + 10, angle, 1));
		}
		//ObjectManager::GetInstance()->AddObject(ObjectLayer::Player_Bullet, new Spread("Spread", x, y, angle - RadianAngle(45), 0));
		//ObjectManager::GetInstance()->AddObject(ObjectLayer::Player_Bullet, new Spread("Spread", x, y, angle + RadianAngle(45), 0));
		
	}
}

void BulletManager::Player_Special_Shoot(float x, float y, float angle) {
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Player_Bullet, new SuperPeashooter("SuperPeashooter", x, y, angle));

}

void BulletManager::Enmey_Shoot(Enemy_Bullet_Type type, float x, float y, float speed, float angle){
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