#pragma once
#include "GameObject.h"
class Player_Bullet_Effect : public GameObject
{
	class Image* mImage;
	class Animation* mEffectAnimation;
public :
	Player_Bullet_Effect(float x, float y, class Image* image, float frameTime = 0.1f, bool isReverse = false);
	void virtual Init()override;
	void virtual Update()override;
	void virtual Release()override;
	void virtual Render(HDC hdc)override;
};

