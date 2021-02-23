#pragma once
#include "EnemyProj.h"

class OnionProj :public EnemyProj {
protected:

public:
	void virtual Init()override;
	void virtual Release()override;
	void virtual Update()override;
	void virtual Render(HDC hdc)override;
};