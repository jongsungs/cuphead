#pragma once
#include "GameObject.h"

class Camera : public GameObject
{
public:
	enum class Mode : int
	{
		Follow, Free , Talk, Platformer, Boss
	};
protected:
	Mode mMode;
	GameObject* mTarget;		//쫓아가야할 타겟
	RECT mCamerArea;
	float mMoveSpeed;
public:
	Camera(Mode mode = Mode::Follow, float x = WINSIZEX/2, float y = WINSIZEX/2);
	void Init()override; 
	void Release()override; 
	void Update()override; 
	void Render(HDC hdc)override;

	void SetTarget(GameObject* target) { mTarget = target; if(target)mX = mTarget->GetX(); if (target)mY = mTarget->GetY(); }
	void ChangeMode(Mode mode) { mMode = mode; }
public:
	void Render(HDC hdc, class Image* image, int x, int y);
	void Render(HDC hdc, class Image* image, int x, int y, int tempX, int tempY, int tempWidth, int tempHeight);
	void FrameRender(HDC hdc, class Image* image, int x, int y, int frameX, int frameY);
	void AlphaRender(HDC hdc, class Image* image, int x, int y, float alpha);
	void AlphaFrameRender(HDC hdc, class Image* image, int x, int y, int frameX, int frameY, float alpha);
	void ScaleRender(HDC hdc, class Image* image, int x, int y, int width, int height);
	void ScaleFrameRender(HDC hdc,class Image* image, int x, int y, int frameX, int frameY, int width, int height);
	void AlphaScaleRender(HDC hdc,class Image* image, int x, int y, int width, int height, float alpha);
	void AlphaScaleFrameRender(HDC hdc, class Image* image, int x, int y, int frameX, int frameY, int width, int height, float alpha);
	void CenterRender(HDC hdc, Image* image, int x, int y);
	void CenterFrameRender(HDC hdc, Image* image, int x, int y, int frameIndexX, int frameIndexY);
	void CenterAlphaRender(HDC hdc, Image* image, int x, int y, float alpha);
	void CenterAlphaFrameRender(HDC hdc, Image* image, int x, int y, int frameX, int frameY, float alpha);
	void CenterScaleRender(HDC hdc, Image* image, int x, int y, int width, int height);
	void CenterScaleFrameRender(HDC hdc, Image* image, int x, int y, int frameX, int frameY, int width, int height);
	void CenterAlphaScaleRender(HDC hdc, Image* image, int x, int y, int width, int height, float alpha);
	void CenterAlphaScaleFrameRender(HDC hdc, Image* image, int x, int y, int frameX, int frameY, int width, int height, float alpha);
	void RenderFromBottom(HDC hdc, class Image* image, int x, int y);
	void FrameRenderFromBottom(HDC hdc, class Image* image, int x, int y, int frameX, int frameY);
	void ScaleRenderFromBottom(HDC hdc, Image* image, int x, int y, int width, int height);
	void ScaleFrameRenderFromBottom(HDC hdc, Image* image, int x, int y, int frameX, int frameY, int width, int height);

	void RenderRect(HDC hdc, RECT rc);
	void RenderEllipse(HDC hdc, float x, float y, float radius);

	bool IsInCameraArea(float x, float y, float width, float height);
	bool IsInCameraArea(RECT rc);

	inline float GetMoveSpeed()const { return mMoveSpeed; }
	inline void SetMoveSpeed(float speed) { mMoveSpeed = speed; }
	inline void SetCamerArea(RECT rc) { mCamerArea = rc; }
	inline void SetMode(Mode mode) { mMode = mode; };
};

