#include "pch.h"
#include "ImageSet.h"
//사용할 이미지 입력
void ImageSet::SetImage() //첫 scene1 로드
{
	//플랫포머플레이어 이미지
	//IMAGEMANAGER->LoadFromFile(L"Player", Resources(L"Player.bmp"), 64, 96, 4, 4, true);
	//IMAGEMANAGER->LoadFromFile(L"SideSword", Resources(L"SideSword.bmp"), 15, 14, 1, 2, true);
	//IMAGEMANAGER->LoadFromFile(L"UpdownSword", Resources(L"UpdownSword.bmp"), 14, 15, 2, 1, true);
	//IMAGEMANAGER->LoadFromFile(L"die", Resources(L"die.bmp"), 98, 18, 1, 7, true);
	//IMAGEMANAGER->LoadFromFile(L"UpSword", Resources(L"UpSword.bmp"), 7, 15, true);
	//IMAGEMANAGER->LoadFromFile(L"DownSword", Resources(L"DownSword.bmp"), 7, 15, true);
	//IMAGEMANAGER->LoadFromFile(L"RightSword", Resources(L"RightSword.bmp"), 15, 7, true);
	//IMAGEMANAGER->LoadFromFile(L"LeftSword", Resources(L"LeftSword.bmp"), 15, 7, true);
	IMAGEMANAGER->LoadFromFile(L"PlatformerPlayerIdle", Resources(L"PlatformerPlayer/PlayerIdle.bmp"), 500, 310, 5, 2, true,RGB(99,92,99));
	IMAGEMANAGER->LoadFromFile(L"Dash", Resources(L"PlatformerPlayer/Dash.bmp"), 2608, 326, 8, 2, true, RGB(99, 92, 99));
	IMAGEMANAGER->LoadFromFile(L"Die", Resources(L"PlatformerPlayer/Die.bmp"), 2752, 106, 16, 1, true, RGB(99, 92, 99));
	IMAGEMANAGER->LoadFromFile(L"Duckidle", Resources(L"PlatformerPlayer/Duckidle.bmp"), 2184, 244, 13, 2, true, RGB(99, 92, 99));
	IMAGEMANAGER->LoadFromFile(L"DuckShoot", Resources(L"PlatformerPlayer/DuckShoot.bmp"), 1158, 162, 6, 2, true, RGB(99, 92, 99));
	IMAGEMANAGER->LoadFromFile(L"Groundhit", Resources(L"PlatformerPlayer/Groundhit.bmp"), 750, 442, 6, 2, true, RGB(99, 92, 99));
	IMAGEMANAGER->LoadFromFile(L"GroundSpecialAttack", Resources(L"PlatformerPlayer/GroundSpecialAttack.bmp"), 2470, 300, 13, 2, true, RGB(99, 92, 99));
	IMAGEMANAGER->LoadFromFile(L"Jump", Resources(L"PlatformerPlayer/Jump.bmp"), 704, 218, 8, 2, true, RGB(99, 92, 99));
	IMAGEMANAGER->LoadFromFile(L"Dash", Resources(L"PlatformerPlayer/Dash.bmp"), 2608, 326, 8, 2, true, RGB(99, 92, 99));
	IMAGEMANAGER->LoadFromFile(L"Run", Resources(L"PlatformerPlayer/Run.bmp"), 2466, 336, 18, 2, true, RGB(99, 92, 99));
	IMAGEMANAGER->LoadFromFile(L"RunShoot", Resources(L"PlatformerPlayer/RunShoot.bmp"), 2592, 350, 18, 2, true, RGB(99, 92, 99));
	IMAGEMANAGER->LoadFromFile(L"StraightShoot", Resources(L"PlatformerPlayer/StraightShoot.bmp"), 822, 340, 6, 2, true, RGB(99, 92, 99));
	IMAGEMANAGER->LoadFromFile(L"UpspecialAttack", Resources(L"PlatformerPlayer/UpspecialAttack.bmp"), 1508, 460, 13, 2, true, RGB(99, 92, 99));
	IMAGEMANAGER->LoadFromFile(L"DiagonalUp", Resources(L"PlatformerPlayer/DiagonalUp.bmp"), 840, 328, 6, 2, true, RGB(99, 92, 99));
	IMAGEMANAGER->LoadFromFile(L"Parring", Resources(L"PlatformerPlayer/Parring.bmp"), 1120, 280, 8, 2, true, RGB(99, 92, 99));
	IMAGEMANAGER->LoadFromFile(L"RunDiagonalShoot", Resources(L"PlatformerPlayer/RunDiagonalShoot.bmp"), 2574, 350, 18, 2, true, RGB(99, 92, 99));
	IMAGEMANAGER->LoadFromFile(L"UpShoot", Resources(L"PlatformerPlayer/UpShoot.bmp"), 708, 378, 6, 2, true, RGB(99, 92, 99));
	//적 이미지
	//캐릭터 상태에 따라 다른 이미지를 보여주기 위함
	IMAGEMANAGER->LoadFromFile(L"EnemyIdle", Resources(L"EnemyIdle.bmp"), 72, 176, 3, 8, true);
	IMAGEMANAGER->LoadFromFile(L"EnemyAttack", Resources(L"EnemyAttack.bmp"), 336, 92, 12, 4, true);
	IMAGEMANAGER->LoadFromFile(L"EnemyDeath", Resources(L"EnemyDeath.bmp"), 282, 49, 6, 1, true);

	//랜덤한 폭발 크기를 주기 위함
	IMAGEMANAGER->LoadFromFile(L"BigExplosion", Resources(L"BigExplosion.bmp"), 2240, 84, 28, 1, true);
	IMAGEMANAGER->LoadFromFile(L"MiddleExplosion", Resources(L"MiddleExplosion.bmp"), 1344, 48, 28, 1, true);
	IMAGEMANAGER->LoadFromFile(L"SmallExplosion", Resources(L"SmallExplosion.bmp"), 1008, 36, 28, 1, true);
	//플레이어 이미지
	//TEST
	IMAGEMANAGER->LoadFromFile(L"cuphead_idle", Resources(L"Image/Player/cuphead_idle.bmp"), 490, 155, 5, 1, true);
	IMAGEMANAGER->LoadFromFile(L"Back", Resources(L"Map1.bmp"), 1280, 720,false);
}

void ImageSet::SetFxImage() {
	for (int a = 0; a < 127; a++) {
		wstring file = L"FX/cuphead_screen_fx_0";
		wstring key = L"FX_";
		key = key + to_wstring(a);
		if (a / 100) {
			file = file + to_wstring(a) + L".bmp";

		}
		else if (a / 10) {
			file = file +L"0" +to_wstring(a) + L".bmp";
		}
		else {
			file = file + L"00" + to_wstring(a) + L".bmp";
		}
		IMAGEMANAGER->LoadFromFile(key, ResourcesImage(file), 1024, 517, false);
	}
	IMAGEMANAGER->LoadFromFile(L"BlackGround", ResourcesImage(L"FX/BlackGround.bmp"), 1024, 517, false);
}
