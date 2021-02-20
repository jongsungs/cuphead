#include "pch.h"
#include "ImageSet.h"

void ImageSet::Stage1()
{
	//플레이어 이미지
	IMAGEMANAGER->LoadFromFile(L"Player", Resources(L"Player.bmp"), 64, 96, 4, 4, true);
	IMAGEMANAGER->LoadFromFile(L"SideSword", Resources(L"SideSword.bmp"), 15, 14, 1, 2, true);
	IMAGEMANAGER->LoadFromFile(L"UpdownSword", Resources(L"UpdownSword.bmp"), 14, 15, 2, 1, true);
	IMAGEMANAGER->LoadFromFile(L"die", Resources(L"die.bmp"), 98, 18, 1, 7, true);
	IMAGEMANAGER->LoadFromFile(L"UpSword", Resources(L"UpSword.bmp"), 7, 15, true);
	IMAGEMANAGER->LoadFromFile(L"DownSword", Resources(L"DownSword.bmp"), 7, 15, true);
	IMAGEMANAGER->LoadFromFile(L"RightSword", Resources(L"RightSword.bmp"), 15, 7, true);
	IMAGEMANAGER->LoadFromFile(L"LeftSword", Resources(L"LeftSword.bmp"), 15, 7, true);
	//적 이미지
	//캐릭터 상태에 따라 다른 이미지를 보여주기 위함
	IMAGEMANAGER->LoadFromFile(L"EnemyIdle", Resources(L"EnemyIdle.bmp"), 72, 176, 3, 8, true);
	IMAGEMANAGER->LoadFromFile(L"EnemyAttack", Resources(L"EnemyAttack.bmp"), 336, 92, 12, 4, true);
	IMAGEMANAGER->LoadFromFile(L"EnemyDeath", Resources(L"EnemyDeath.bmp"), 282, 49, 6, 1, true);

	//랜덤한 폭발 크기를 주기 위함
	IMAGEMANAGER->LoadFromFile(L"BigExplosion", Resources(L"BigExplosion.bmp"), 2240, 84, 28, 1, true);
	IMAGEMANAGER->LoadFromFile(L"MiddleExplosion", Resources(L"MiddleExplosion.bmp"), 1344, 48, 28, 1, true);
	IMAGEMANAGER->LoadFromFile(L"SmallExplosion", Resources(L"SmallExplosion.bmp"), 1008, 36, 28, 1, true);
}
