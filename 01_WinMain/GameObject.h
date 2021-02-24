#pragma once

//조상님!!!
class GameObject
{
protected:
	string mName;
	float mX;
	float mY;
	float mSizeX;
	float mSizeY;
	RECT mRect;
	RECT mAttakArea;
	int mHP;

	bool mIsActive;		//활성화 상태
	bool mIsDestroy;	//삭제할지 말지
	bool mIsDelete = true; //Delete 함수에서 삭제할 지 여부 체크
public:
	GameObject();
	GameObject(const string& name);

	//순수가상함수 : 반드시 자식에서 해당 함수를 오버라이딩 해야함
	virtual void Init() = 0;
	virtual void Release() = 0;
	virtual void Update() = 0;
	virtual void Render(HDC hdc) = 0;
public:
	inline string GetName()const { return mName; }
	inline void SetName(const string& name) { mName = name; }
	inline float GetX()const { return mX; }
	inline void SetX(float x) { mX = x; }
	inline float GetY()const { return mY; }
	inline void SetY(float y) { mY = y; }
	inline float GetSizeX()const { return mSizeX; }
	inline void SetSizeX(float x) { mSizeX = x; }
	inline float GetSizeY()const { return mSizeY; }
	inline void SetSizeY(float y) { mSizeY = y; }
	inline RECT GetRect()const { return mRect; }
	inline void SetHP (int HP) {  mHP = HP; }
	inline int GetHP()const { return mHP; }
	inline void SetAttakArea(RECT rect) { mAttakArea = rect; }
	inline RECT GetAttakArea()const { return mAttakArea; }

	inline bool GetIsDelete()const { return mIsDelete; }
	inline void SetIsDelete(bool b) { mIsDelete = b; }
	inline bool GetIsActive()const { return mIsActive; }
	inline void SetIsActive(bool b) { mIsActive = b; }
	inline bool GetIsDestroy()const { return mIsDestroy; }
	inline void SetIsDestroy(bool b) { mIsDestroy = b; }

	//상시 충돌값 함수
	void virtual InInterscet(){}
	void virtual InIntersectDamage() {}
};

