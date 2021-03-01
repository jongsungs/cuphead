#pragma once
#include "GameObject.h"
class TutorialPrint : public GameObject
{
	class Image* mImage;
public:
	TutorialPrint(string name, float x, float y, Image* image);
	virtual void Init() override;
	virtual void Release()override;
	virtual void Update()override;
	virtual void Render(HDC hdc) override;
};

