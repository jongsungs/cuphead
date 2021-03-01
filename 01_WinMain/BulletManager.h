#pragma once
enum class Player_Bullet_Type : int{
	Peashooter,
	Spread
};
enum class Player_Have : int {
	IsHave,
	NoHave
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
private:
	Player_Bullet_Type mPlayerBulletType;
	map<Player_Bullet_Type, Player_Have> mPlayerHaveBullet;
public :
	BulletManager(); 
	void Player_Shoot(float x, float y, float angle);
	void Player_Special_Shoot(float x, float y, float angle);
	void Enmey_Shoot(Enemy_Bullet_Type type, float x, float y, float speed, float angle);

	void BulletHaveCange(Player_Bullet_Type type) { mPlayerHaveBullet.find(type)->second = Player_Have::IsHave; }
	void ResetPlayerBullet() { mPlayerBulletType = Player_Bullet_Type::Peashooter; }
	void ChangeBullet();
};

