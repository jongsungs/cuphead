#include "pch.h"

#include"Image.h"
#include "PotatoProj.h"
#include "EnemyProj.h"

PotatoProj::PotatoProj(const string& name, float x, float y, float speed, float angle, bool parryAble)
	:EnemyProj(name, x, y, speed, angle, parryAble)
{
	mX = x;
	mY = y;
	mSpeed = speed;
	mAngle = angle;
	mParryAble = parryAble;
}

void PotatoProj::Init(){
	vector<GameObject*>* EnemyProj = ObjectManager::GetInstance()->GetObjectListPt(ObjectLayer::Enemy_Bullet);
	mName = to_string(EnemyProj->size());
	ObjectManager::GetInstance()->AddObject(ObjectLayer::Enemy_Bullet, this);


}

void PotatoProj::Release(){

}

void PotatoProj::Update(){
	mX += cosf(mAngle) * mSpeed;
	mY += -sinf(mAngle) * mSpeed;
	mRect = RectMakeCenter(mX, mY, 20, 10);
}

void PotatoProj::Render(HDC hdc){
	RenderRect(hdc, mRect);

}
