#pragma once
class Scene
{
protected:
	bool mIsEndLoading = false;
public:
	virtual void Init() = 0;
	virtual void Release() = 0;
	virtual void Update() = 0;
	virtual void Render(HDC hdc) = 0;

	virtual bool GetIsEndLoading() { return mIsEndLoading; }
};

