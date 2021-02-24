#include "EnemyProj.h"

class PotatoProj :public EnemyProj {
protected:
	Image* ParryAbleImg;
	Image* NonParryAbleImg;

	Animation* ParryAbleAnimation;
	Animation* NonParryAbleAnimation;
public:
	PotatoProj(const string& name, float x, float y, float speed, float angle, bool parryAble);
	virtual void Init()override;
	virtual void Release()override;
	virtual void Update()override;
	virtual void Render(HDC hdc)override;
};