#include "pch.h"

#include"Image.h"
#include "CarrotProj.h"

void CarrotProj::Init(){
	vector<GameObject*>* EnemyProj = ObjectManager::GetInstance()->GetObjectListPt(ObjectLayer::Enemy_Bullet);
	mName = to_string(EnemyProj->size());
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Enemy_Bullet, this);
}

void CarrotProj::Release(){

}

void CarrotProj::Update(){
	mX += cosf(mAngle) * mSpeed;
	mY += -sinf(mAngle) * mSpeed;
	mRect = RectMakeCenter(mX, mY, 20, 10);
}

void CarrotProj::Render(HDC hdc){
	RenderRect(hdc, mRect);

}
