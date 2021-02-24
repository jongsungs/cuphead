#include "pch.h"
#include "BulletManager.h"
#include "Peashooter.h"
#include "Effect.h"

void BulletManager::Player_Shoot(Player_Bullet_Type type, float x, float y,float speed, float angle) {
	if (type == Player_Bullet_Type::Peashooter) {
		ObjectManager::GetInstance()->AddObject(ObjectLayer::Player_Bullet_Effect,new Effect(x,y,ImageManager::GetInstance()->FindImage(L"Peashooter")));
		ObjectManager::GetInstance()->AddObject(ObjectLayer::Player_Bullet,new Peashooter("Peashooter",x,y,speed, angle));
	}
	else if (type == Player_Bullet_Type::Spread) {
		ObjectManager::GetInstance()->AddObject(ObjectLayer::Player_Bullet_Effect, new Effect(x, y, ImageManager::GetInstance()->FindImage(L"Spread")));
		ObjectManager::GetInstance()->AddObject(ObjectLayer::Player_Bullet, new Peashooter("Spread", x, y, speed, angle));
		ObjectManager::GetInstance()->AddObject(ObjectLayer::Player_Bullet, new Peashooter("Spread", x + 10, y - 10, speed, angle));
		ObjectManager::GetInstance()->AddObject(ObjectLayer::Player_Bullet, new Peashooter("Spread", x + 10, y + 10, speed, angle));
		ObjectManager::GetInstance()->AddObject(ObjectLayer::Player_Bullet, new Peashooter("Spread", x - 10, y - 10, speed, angle));
		ObjectManager::GetInstance()->AddObject(ObjectLayer::Player_Bullet, new Peashooter("Spread", x -10, y +10, speed, angle));
	}
}

void BulletManager::Enmey_Shoot(Enemy_Bullet_Type type, float x, float y, float speed, float angle){
	if (type == Enemy_Bullet_Type::Potato) {

	}
}