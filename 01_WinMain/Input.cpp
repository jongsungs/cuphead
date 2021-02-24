﻿#include "pch.h"
#include "Input.h"

/****************************************************
## Input ##
*****************************************************/
Input::Input()
{
	//처음엔 모든 키를 눌려있지 않은 상태로 초기화
	mKeyCurrent.reset();
	mKeyPast.reset();

}
Input::~Input() {}

/****************************************************
## Update ##
*****************************************************/
void Input::Update()
{
	//계속 과거키를 현재키로 갱신해준다
	mKeyPast = mKeyCurrent;
}


bool Input::GetKeyDown(const int& key)
{
	//해당 키를 누른 상태
	if (GetAsyncKeyState(key) & 0x8000)
	{
		//그 키가 눌려있지 않았다면
		if (!mKeyPast[key])
		{
			//현재키를 눌린 상태로 바꾸고 return true
			mKeyCurrent.set(key, true);
			return true;
		}
	}
	//해당 키를 누르지 않은 상태
	else mKeyCurrent.set(key, false);   //현재키를 누르지 않은 상태로 바꿈

	return false;
}

bool Input::GetKeyUp(const int& key)
{
	//해당 키를 누른 상태					현재키를 눌린 상태로 바꿈
	if (GetAsyncKeyState(key) & 0x8000) mKeyCurrent.set(key, true);
	//해당 키를 누르지 않은 상태
	else
	{
		//그 키가 눌려있었다면
		if (mKeyPast[key])
		{
			//현재키를 누르지 않은 상태로 바꾸고 return true
			mKeyCurrent.set(key, false);
			return true;
		}
	}

	return false;
}

bool Input::GetKey(const int& key)
{
	if (GetAsyncKeyState(key) & 0x8000) return true;

	return false;
}

bool Input::ToggleKey(const int& key)
{
	if (GetKeyState(key) & 0x0001) return true;

	return false;
}
