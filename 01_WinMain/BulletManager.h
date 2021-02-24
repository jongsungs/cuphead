#pragma once
enum class Player_Bullet_Type : int{
	Peashooter,
	Spread
};
enum class Enemy_Bullet_Type : int {
	Potato,
	Carrot,
	Onion,
	Enemy
};
class BulletManager
{
	Singleton(BulletManager)
public :
	void Player_Shoot(Player_Bullet_Type type, float x, float y,float speed, float angle);
	void Enmey_Shoot(Enemy_Bullet_Type type, float x, float y, float speed, float angle);

};

