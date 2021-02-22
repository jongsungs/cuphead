#pragma once

/*
## ObjectManager ##
GameObject 관리하는 클래스
*/

//enum (열거자) : 정수를 다른 이름으로 표현하는 것
enum class ObjectLayer : int
{
	Background = 0,
	Effect,
	NPC,
	Building,
	Enemy,
	Boss,
	Player,
	Enemy_Bullet,
	Player_Bullet,
	UI,
	End
};

class ObjectManager
{
	Singleton(ObjectManager)
private:
	typedef map<ObjectLayer, vector<class GameObject*>>::iterator ObjectIter;
	map<ObjectLayer, vector<class GameObject*>> mObjectList;
public:
	ObjectManager();

	void Init();
	void Release();
	void Update();
	void Render(HDC hdc);

	void AllActiveFalse(); //모든 오브젝트 액티브 = false 변경
	void AllActiveTrue();
	void AddObject(ObjectLayer layer, class GameObject* object);
	void AddObject(ObjectLayer layer, class GameObject* object, const string& name); //같은 이름의 오브젝트를 찾는다. 있으면 활성화를 시켜준다. 없으면 생성
	class GameObject* FindObject(const string& name);
	class GameObject* FindObject(ObjectLayer layer, const string& name);
	
	vector<class GameObject*> FindObjects(const string& name);
	vector<class GameObject*> FindObjects(ObjectLayer layer, const string& name);
	vector<class GameObject*> GetObjectList(ObjectLayer layer);
	vector<class GameObject*>* GetObjectListPt(ObjectLayer layer);
};

