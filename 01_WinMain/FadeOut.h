#pragma once
#include "GameObject.h"
//Effect Ŭ������ ȣ�� ��� Image�� �������ָ� �� �����ӿ� �������� �� ��Ȱ��ȭ �ȴ�.
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