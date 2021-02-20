#include "pch.h"
#include "GameEvent.h"
#include "NPC.h"
#include "Camera.h"
#include "LoadingScene.h"
IChangeCameraTargetEvent::IChangeCameraTargetEvent(GameObject * target)
{
	mTarget = target;
}

void IChangeCameraTargetEvent::Start()
{
	CameraManager::GetInstance()->GetMainCamera()->SetTarget(mTarget);
}

bool IChangeCameraTargetEvent::Update()
{
	float x = CameraManager::GetInstance()->GetMainCamera()->GetX();
	float y = CameraManager::GetInstance()->GetMainCamera()->GetY();

	if (Math::GetDistance(x, y, mTarget->GetX(), mTarget->GetY()) <= 5.0f)
	{
		return true;
	}

	return false;
}

IDelayEvent::IDelayEvent(float delayTime)
{
	mDelayTime = delayTime;
	mCurrentTime = 0.f;
}

void IDelayEvent::Start()
{
}

bool IDelayEvent::Update()
{
	mCurrentTime += Time::GetInstance()->DeltaTime();

	if (mCurrentTime >= mDelayTime)
	{
		return true;
	}

	return false;
}

ITalkwithNPCEvent::ITalkwithNPCEvent()
{
}

void ITalkwithNPCEvent::Start()
{
	CameraManager::GetInstance()->GetMainCamera()->SetMode(Camera::Mode::Talk);
}

bool ITalkwithNPCEvent::Update()
{
	NPC* npctemp = (NPC*)ObjectManager::GetInstance()->FindObject("NPC");
	npctemp->SetIsTalk(true);
	if (Input::GetInstance()->GetKeyDown(VK_LBUTTON))
	{
		SceneManager::GetInstance()->
		SceneManager::GetInstance()->LoadSceneLoading(L"Scene1", L"Scene1LoadingScene");
		
	}
	return true;
}
