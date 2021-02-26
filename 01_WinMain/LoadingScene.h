#pragma once
#include "Scene.h"
#include <functional>
class LoadingScene : public Scene
{
	vector<function<void(void)>> mLoadList;
	int mLoadIndex;
	class Animation* mAnimation;
public:
	void AddLoadFunc(const function<void(void)>& func);
	void AddLoadFunc(const vector<function<void(void)>>& funcs);
	void Init()override;
	void Release()override;
	void Update()override;
	void Render(HDC hdc)override;
};

