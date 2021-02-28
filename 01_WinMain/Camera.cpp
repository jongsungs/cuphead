#include "pch.h"
#include "Camera.h"

#include "Image.h"

Camera::Camera(Mode mode,float x, float y):GameObject("Main_Camera")
{
	mMode = mode;
	mX = x;
	mY = y;
	mTarget = nullptr;
}
void Camera::Init()
{
	switch (mMode)
	{
	case Camera::Mode::Follow:
		if (mTarget) {
			mX = mTarget->GetX();
			mY = mTarget->GetY();
		}
		break;
	case Camera::Mode::Free:
		break;
	case Camera::Mode::Talk:
		break;
	case Camera::Mode::Platformer:
		mX = WINSIZEX / 2;
		mY = WINSIZEY / 2;
		if (mTarget) {
			mX = mTarget->GetX()+200.f;
		}
		break;
	case Camera::Mode::Boss:
		mX = WINSIZEX / 2;
		mY = WINSIZEY / 2;
		if (mTarget) {
			mPlayerX = mTarget->GetX();
			mPlayerY = mTarget->GetY();
		}
		break;
	}
	mSizeX = WINSIZEX;
	mSizeY = WINSIZEY;
	mRect = RectMakeCenter(mX, mY, mSizeX, mSizeY);
	mMoveSpeed = 5.f;
}

void Camera::Release()
{
	//얘도 쓸일이 없다 . . . 
}

void Camera::Update()
{
	switch (mMode)
	{
	case Camera::Mode::Follow:
		if (mTarget)
		{
			//mX = mTarget->GetX();
			//mY = mTarget->GetY();
			//멀리있으면 빨리 쫓아가야하고 가까이 있으면 천천히 쫓아가야함
			if (mCamerAreaCheck) {
				mX = Math::Lerp(mX, mTarget->GetX(), 2.f * Time::GetInstance()->DeltaTime());
				mY = Math::Lerp(mY, mTarget->GetY(), 2.f * Time::GetInstance()->DeltaTime());
				mRect = RectMakeCenter(mX, mY, mSizeX, mSizeY);
				float chaX = 0;
				float chaY = 0;
				if (mCamerArea.right < mRect.right) {
					chaX = mRect.right - mCamerArea.right;
					mX -= chaX;
				}
				else if (mCamerArea.left > mRect.left) {
					chaX = mCamerArea.left - mRect.left;
					mX += chaX;
				}
				if (mCamerArea.bottom < mRect.bottom) {
					chaY = mRect.bottom - mCamerArea.bottom;
					mY -= chaY;
				}
				else if (mCamerArea.top < mRect.top) {
					chaY = mCamerArea.top - mRect.top;
					mY += chaY;
				}
				mRect = RectMakeCenter(mX, mY, mSizeX, mSizeY);
			}
			else {
				mX = Math::Lerp(mX, mTarget->GetX(), 2.f * Time::GetInstance()->DeltaTime());
				mY = Math::Lerp(mY, mTarget->GetY(), 2.f * Time::GetInstance()->DeltaTime());

				mRect = RectMakeCenter(mX, mY, mSizeX, mSizeY);
			}
		}
		break;
	case Camera::Mode::Free:
		if (Input::GetInstance()->GetKey('A'))mX -= mMoveSpeed;
		if (Input::GetInstance()->GetKey('D'))mX += mMoveSpeed;
		if (Input::GetInstance()->GetKey('W'))mY -= mMoveSpeed;
		if (Input::GetInstance()->GetKey('S'))mY += mMoveSpeed;
		mRect = RectMakeCenter(mX, mY, mSizeX, mSizeY);
		break;

	case Camera::Mode::Talk:
		if (mTarget)
		{
			mX = mTarget->GetX();
			mY = mTarget->GetY()+100;
			mRect = RectMakeCenter(mX, mY, mSizeX, mSizeY);
		}
		break;
	case Camera::Mode::Platformer:
		if (mTarget) {
			
			
			mX = Math::Lerp(mX, mTarget->GetX() + 200.f, 2.f * Time::GetInstance()->DeltaTime());
			//mY = Math::Lerp(mY, mTarget->GetY() -100.f, 2.f * Time::GetInstance()->DeltaTime());
			mRect = RectMakeCenter(mX, mY, mSizeX, mSizeY);
			
			//보정
			float cha = 0;
			if (mCamerArea.right < mRect.right) {
				cha = mRect.right - mCamerArea.right;
				mX -= cha;
			}
			else if (mCamerArea.left > mRect.left) {
				cha = mCamerArea.left - mRect.left;
				mX += cha;
			}
			
			mRect = RectMakeCenter(mX, mY, mSizeX, mSizeY);
			break;
		}
	case Camera::Mode::Boss:
		if (mTarget) {	
			float mDumpX = mTarget->GetX();
			float chaX= mDumpX - mPlayerX ;
			if (chaX > 0) {
				if (mCamerArea.right > mRect.right) {
					mX += chaX;
				}
			}
			else if (chaX <0) {
				if (mCamerArea.left < mRect.left) {
					mX += chaX;
				}
			}
			mPlayerX = mTarget->GetX();
		}
		else {
			if (Input::GetInstance()->GetKey(VK_LEFT))
			{
				if (mCamerArea.left < mRect.left) {
					mX -= 1;
				}
			}
			if (Input::GetInstance()->GetKey(VK_RIGHT))
			{
				if (mCamerArea.right > mRect.right) {
					mX += 1;
				}
			}
		}
		mRect = RectMakeCenter(mX, mY, mSizeX, mSizeY);
		break;
	}
}

void Camera::Render(HDC hdc)
{
	//쓸일이 없다 . . . . 
}

void Camera::Render(HDC hdc, Image * image, int x, int y)
{
	image->Render(hdc, x - mRect.left, y - mRect.top);
}

void Camera::Render(HDC hdc, Image * image, int x, int y, int tempX, int tempY, int tempWidth, int tempHeight)
{
	image->Render(hdc, x - mRect.left, y - mRect.top, tempX, tempY, tempWidth, tempHeight);
}

void Camera::FrameRender(HDC hdc, Image * image, int x, int y, int frameX, int frameY)
{
	image->FrameRender(hdc, x - mRect.left, y - mRect.top, frameX, frameY);
}

void Camera::AlphaRender(HDC hdc, Image * image, int x, int y, float alpha)
{
	image->AlphaRender(hdc, x - mRect.left, y - mRect.top, alpha);
}

void Camera::AlphaFrameRender(HDC hdc, Image * image, int x, int y, int frameX, int frameY, float alpha)
{
	image->AlphaFrameRender(hdc, x - mRect.left, y - mRect.top, frameX, frameY, alpha);
}

void Camera::ScaleRender(HDC hdc, Image * image, int x, int y, int width, int height)
{
	image->ScaleRender(hdc, x - mRect.left, y - mRect.top, width, height);
}

void Camera::ScaleFrameRender(HDC hdc, Image * image, int x, int y, int frameX, int frameY, int width, int height)
{
	image->ScaleFrameRender(hdc, x - mRect.left, y - mRect.top, frameX, frameY, width, height);
}

void Camera::AlphaScaleRender(HDC hdc, Image * image, int x, int y, int width, int height, float alpha)
{
	image->AlphaScaleRender(hdc, x - mRect.left, y - mRect.top, width, height, alpha);
}

void Camera::AlphaScaleFrameRender(HDC hdc, Image * image, int x, int y, int frameX, int frameY, int width, int height, float alpha)
{
	image->AlphaScaleFrameRender(hdc, x - mRect.left, y - mRect.top, frameX, frameY, width, height, alpha);
}
void Camera::CenterRender(HDC hdc, Image* image, int x, int y)
{

	x += -(image->GetWidth() / 2);
	y += -(image->GetHeight() / 2);
	Render(hdc,image, x, y);

}

void Camera::CenterFrameRender(HDC hdc, Image* image, int x, int y, int frameX, int frameY)
{
	x += -(image->GetFrameWidth() / 2);
	y += -(image->GetFrameHeight() / 2);
	FrameRender(hdc,image, x, y, frameX, frameY);
}

void Camera::CenterAlphaRender(HDC hdc, Image* image, int x, int y, float alpha)
{
	x += -(image->GetWidth() / 2);
	y += -(image->GetHeight() / 2);
	AlphaRender(hdc,image, x, y, alpha);
}

void Camera::CenterAlphaFrameRender(HDC hdc, Image* image, int x, int y, int frameX, int frameY, float alpha)
{
	x += -(image->GetFrameWidth() / 2);
	y += -(image->GetFrameHeight() / 2);
	AlphaFrameRender(hdc, image, x, y, frameX, frameY, alpha);
}

void Camera::CenterScaleRender(HDC hdc, Image* image, int x, int y, int width, int height)
{
	x += -width / 2;
	y += -height / 2;
	ScaleRender(hdc, image, x, y, width, height);
}

void Camera::CenterScaleFrameRender(HDC hdc, Image* image, int x, int y, int frameX, int frameY, int width, int height)
{
	x += -width / 2;
	y += -height / 2;
	ScaleFrameRender(hdc, image, x, y, frameX, frameY, width, height);
}

void Camera::CenterAlphaScaleRender(HDC hdc, Image* image, int x, int y, int width, int height, float alpha)
{
	x += -width / 2;
	y += -height / 2;
	AlphaScaleRender(hdc, image, x, y, width, height, alpha);
}

void Camera::CenterAlphaScaleFrameRender(HDC hdc, Image* image, int x, int y, int frameX, int frameY, int width, int height, float alpha)
{
	x += -width / 2;
	y += -height / 2;
	AlphaScaleFrameRender(hdc, image, x, y, frameX, frameY, width, height, alpha);
}
void Camera::RenderFromBottom(HDC hdc, Image * image, int x, int y)
{
	x += -(image->GetWidth() / 2);
	y += -image->GetHeight();
	Render(hdc, image, x, y);
}
void Camera::FrameRenderFromBottom(HDC hdc, Image * image, int x, int y, int frameX, int frameY)
{
	x += -(image->GetFrameWidth()/2);
	y += -image->GetFrameHeight();
	FrameRender(hdc, image, x, y, frameX, frameY);
}
void Camera::ScaleRenderFromBottom(HDC hdc,Image* image, int x, int y, int width, int height)
{
	x += -(width / 2);
	y += -height;
	ScaleRender(hdc,image, x, y, width, height);
}

void Camera::ScaleFrameRenderFromBottom(HDC hdc, Image* image, int x, int y, int frameX, int frameY, int width, int height)
{
	x += -(width / 2);
	y += -height;
	ScaleFrameRender(hdc,image ,x, y, frameX, frameY, width, height);
}

void Camera::FrameRenderFromTopCenter(HDC hdc, Image* image, int x, int y, int frameX, int frameY)
{
	x += -(image->GetFrameWidth() / 2);
	FrameRender(hdc, image, x, y, frameX, frameY);
}

void Camera::FrameRenderFromLeftCenter(HDC hdc, Image* image, int x, int y, int frameX, int frameY)
{
	y += -(image->GetFrameHeight() / 2);
	FrameRender(hdc, image, x, y, frameX, frameY);
}

void Camera::FrameRenderFromRightCenter(HDC hdc, Image* image, int x, int y, int frameX, int frameY)
{
	x += -image->GetFrameWidth();
	y += -(image->GetFrameHeight() / 2);
	FrameRender(hdc, image, x, y, frameX, frameY);
}
void Camera::FrameRenderFromRightTop(HDC hdc, Image* image, int x, int y, int frameX, int frameY)
{
	x += -image->GetFrameWidth();
	FrameRender(hdc, image, x, y, frameX, frameY);
}


void Camera::RenderRect(HDC hdc, RECT rc)
{
	rc.left -= mRect.left;
	rc.right -= mRect.left;
	rc.top -= mRect.top;
	rc.bottom -= mRect.top;
	::RenderRect(hdc, rc);
}

void Camera::RenderEllipse(HDC hdc, float x, float y, float radius)
{
	RenderEllipse(hdc, x - mRect.left, y - mRect.top, radius);
}

bool Camera::IsInCameraArea(float x, float y, float width, float height)
{
	RECT rc = RectMakeCenter(x, y, width, height);
	return IsInCameraArea(rc);
}

bool Camera::IsInCameraArea(RECT rc)
{
	if (rc.right < mRect.left)return false;
	if (rc.left > mRect.right)return false;
	if (rc.bottom < mRect.top)return false;
	if (rc.top > mRect.bottom)return false;

	return true;
}
