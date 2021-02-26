#pragma once
//사용할 이미지 셋팅
class ImageSet
{
	Singleton(ImageSet)

private:
	vector<function<void(void)>> mImageLoadList;
public :
	void SetImage(); // 이미지 셋팅
	void SetFxImage(); //필터 셋팅
	void SetOverWorldImage();
};