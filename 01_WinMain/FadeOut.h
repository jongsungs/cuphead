#pragma once
#include "GameObject.h"
//Effect 클래스는 호출 당시 Image만 셋팅해주면 끝 프레임에 도달했을 때 비활성화 된다.
class FadeOut : public GameObject
{
	class Image* mImage;
	class Animation* mAnimation;
	wstring mTargetSceneName;
	wstring mLoadingSceneName;
	class Scene* mLoadingScene;
	bool mIsReverse;
public:
	FadeOut(bool isReverse, float frameTime = 0.1f);
	FadeOut(bool isReverse, wstring targetSceneName, wstring loadingSceneName, float frameTime = 0.1f);
	void virtual Init()override;
	void virtual Update()override;
	void virtual Release()override;
	void virtual Render(HDC hdc)override;
	
};