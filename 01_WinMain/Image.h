﻿#pragma once
class Image
{
private:
	enum class LoadType : int
	{
		Resource,
		File, 
		Empty,
		End
	};

	struct ImageBuffer
	{
		ULONG registerID;
		HDC hdc; 
		HBITMAP bitmap;
		HBITMAP oldBitmap;
		int width; 
		int height;
		int frameX;
		int frameY;
		int frameWidth;
		int frameHeight;
		LoadType loadType;

		ImageBuffer() :registerID(0), hdc(nullptr), bitmap(nullptr), oldBitmap(nullptr), width(0), height(0),
			frameX(0), frameY(0), frameWidth(0), frameHeight(0), loadType(LoadType::End) {}
	};
private:
	ImageBuffer* mImageBuffer;
	wstring mFileName;
	bool mIsTrans;
	COLORREF mTransColor;

	ImageBuffer* mBlendImageBuffer;
	BLENDFUNCTION* mBlendFunc;
public:
	Image();
	~Image();

	void ReleaseBuffer();
public:// 생성관련 ~
	bool CreateEmpty(int width, int height);
	bool LoadFromFile(wstring fileName, int width, int height, bool isTrans, COLORREF transColor = RGB(255,0,255));
	bool LoadFromFile(wstring fileName, int width, int height, int frameX, int frameY, bool isTrans, COLORREF transColor = RGB(255,0,255));
public://렌더링 관련 ~
	//기본렌더링
	void Render(HDC hdc, int x, int y);
	//요거 영역 지정해서 그리는거
	void Render(HDC hdc, int x, int y, int tempX, int tempY, int tempWidth, int tempHeight);
	//프레임렌더
	void FrameRender(HDC hdc, int x, int y, int frameX, int frameY);
	//알파값주는 렌더링
	void AlphaRender(HDC hdc,int x, int y, float alpha);
	//알파값주는 프레임 렌더링
	void AlphaFrameRender(HDC hdc, int x, int y, int frameX, int frameY, float alpha);
	//크기 조정해주는 렌더링
	void ScaleRender(HDC hdc, int x, int y, int width, int height);
	//크기 조정해주는 프레임 렌더링
	void ScaleFrameRender(HDC hdc, int x, int y, int frameX, int frameY, int width, int height);
	//알파값에 크기 조정하는 렌더링
	void AlphaScaleRender(HDC hdc, int x, int y, int width, int height, float alpha);
	//알파값 + 프레임렌더링 + 크기 조정
	void AlphaScaleFrameRender(HDC hdc, int x, int y, int frameX, int frameY, int width, int height, float alpha);
	//센터 좌표 지정해서 그려주기
	void CenterRender(HDC hdc, int x, int y);
	//센터 좌표 지정해서 프레임 렌더
	void CenterFrameRender(HDC hdc, int x, int y, int frameIndexX, int frameIndexY);
	//센터 좌표 알파값주는 렌더링
	void CenterAlphaRender(HDC hdc, int x, int y, float alpha);
	//센터 좌표 알파값주는 프레임 렌더링
	void CenterAlphaFrameRender(HDC hdc, int x, int y, int frameX, int frameY, float alpha);
	//센터 좌표 크기 조정해주는 렌더링
	void CenterScaleRender(HDC hdc, int x, int y, int width, int height);
	//센터 좌표 크기 조정해주는 프레임 렌더링
	void CenterScaleFrameRender(HDC hdc, int x, int y, int frameX, int frameY, int width, int height);
	//센터 좌표 알파값에 크기 조정하는 렌더링
	void CenterAlphaScaleRender(HDC hdc, int x, int y, int width, int height, float alpha);
	//센터 좌표 알파값 + 프레임렌더링 + 크기 조정
	void CenterAlphaScaleFrameRender(HDC hdc, int x, int y, int frameX, int frameY, int width, int height, float alpha);

	//
	void ScaleRenderFromBottom(HDC hdc, int x, int y, int width, int height);
	void ScaleFrameRenderFromBottom(HDC hdc, int x, int y, int frameX, int frameY, int width, int height);
public:// 접근 관련~
	inline HDC GetHDC()const { return mImageBuffer->hdc; }
	inline int GetFrameX()const { return mImageBuffer->frameX; }
	inline int GetFrameY()const { return mImageBuffer->frameY; }
	inline int GetFrameWidth()const { return mImageBuffer->frameWidth; }
	inline int GetFrameHeight()const { return mImageBuffer->frameHeight; }
	inline int GetWidth()const { return mImageBuffer->width; }
	inline int GetHeight()const { return mImageBuffer->height; }
};

