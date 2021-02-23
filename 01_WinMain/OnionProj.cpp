#include "pch.h"

#include"Image.h"
#include "OnionProj.h"

void OnionProj::Init(){
	vector<GameObject*>* EnemyProj = ObjectManager::GetInstance()->GetObjectListPt(ObjectLayer::Enemy_Bullet);
	mName = to_string(EnemyProj->size());
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Enemy_Bullet, this);
}

void OnionProj::Release(){

}

void OnionProj::Update(){
	mX += cosf(mAngle) * mSpeed;
	mY += -sinf(mAngle) * mSpeed;
	mRect = RectMakeCenter(mX, mY, 20, 10);
}

void OnionProj::Render(HDC hdc){
	RenderRect(hdc, mRect);

}
