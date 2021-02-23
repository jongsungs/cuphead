#pragma once
#include "EnemyProj.h"

class PotatoProj :public EnemyProj {
protected:

public:
	PotatoProj(const string& name, float x, float y, float speed, float angle, bool parryAble);
	void virtual Init()override;
	void virtual Release()override;
	void virtual Update()override;
	void virtual Render(HDC hdc)override;
};