#pragma once
#include "GameObject.h"
class TutorialBackGround : public GameObject
{
	class Image* mImage;
public :
	TutorialBackGround(string name , Image* image);
	virtual void Init() override;
	virtual void Release()override;
	virtual void Update()override;
	virtual void Render(HDC hdc) override;

};

