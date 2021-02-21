#pragma once
//사용할 이미지 셋팅
class ImageSet
{
	Singleton(ImageSet)
public :
	void SetImage(); // 이미지 셋팅
	void SetFxImage(); //필터 셋팅
};