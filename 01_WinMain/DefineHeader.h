#pragma once
#define WINSTARTX 50
#define WINSTARTY 50
#define WINSIZEX 1280
#define WINSIZEY 720

//인자로 들어온 p를 삭제하고 NULL로 초기화 하는 매크로 함수, 안전하게 삭제
#define SafeDelete(p)\
{\
	if(p)\
	{\
		delete (p);\
		(p) = NULL;\
	}\
}

//싱글톤 매크로
#define Singleton(ClassName)\
public:\
static ClassName* GetInstance()\
{\
	static ClassName instance;\
	return &instance;\
}
#define setLambda(type) []()->##type

#define Resources(Path) (wstring(L"../02_Resources/").append(Path))
#define ResourcesImage(Path) (wstring(L"../02_Resources/Image/").append(Path))
#define ResourcesSound(Path) (wstring(L"../02_Resources/Sound/").append(Path))
#define PlatPlayerAnimationTime 0.08f
#define PlatPlayerShootAnimationTime 0.03f

//금술
#define Synthesize(VarType,VarName,FuncName)\
protected: VarType VarName;\
public: inline VarType Get##FuncName(void)const{return VarName;}\
public: inline void Set##FuncName(VarType value){VarName = value;}

