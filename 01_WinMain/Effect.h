#pragma once
#include "GameObject.h"
//Effect 클래스는 호출 당시 Image만 셋팅해주면 끝 프레임에 도달했을 때 비활성화 된다.
class Effect : public GameObject
{
	class Image* mImage;
	class Animation* mEffectAnimation;
public :
	Effect(const string& name, float x, float y, class Image* image);
	void virtual Init()override;
	void virtual Update()override;
	void virtual Release()override;
	void virtual Render(HDC hdc)override;
};