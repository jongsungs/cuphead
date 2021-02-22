#include "pch.h"
#include "ImageSet.h"
//사용할 이미지 입력
void ImageSet::SetImage() //첫 scene1 로드
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

	//플레이어 이미지
	//TEST
	IMAGEMANAGER->LoadFromFile(L"cuphead_idle", Resources(L"Image/Player/cuphead_idle.bmp"), 490, 155, 5, 1, true);
	IMAGEMANAGER->LoadFromFile(L"Back", Resources(L"Map1.bmp"), 1280, 720,false);

	//보스 이미지
	//감자
	IMAGEMANAGER->LoadFromFile(L"PotatoIntro", Resources(L"Boss/BotanicPanic/Potato/Potato_Intro.bmp"), 4208, 512, 8, 1, true);
	IMAGEMANAGER->LoadFromFile(L"PotatoIntroEarth", Resources(L"Boss/BotanicPanic/Potato/Potato_Intro_Earth.bmp"), 10583, 461, 18, 1, true);
	IMAGEMANAGER->LoadFromFile(L"PotatoIdle", Resources(L"Boss/BotanicPanic/Potato/Potato_Idle.bmp"), 3682, 512, 7, 1, true);
	IMAGEMANAGER->LoadFromFile(L"PotatoSpitAttack", Resources(L"Boss/BotanicPanic/Potato/Potato_Spit_Attack.bmp"), 10520, 512, 20, 1, true);
	IMAGEMANAGER->LoadFromFile(L"PotatoDeath", Resources(L"Boss/BotanicPanic/Potato/Potato_Death.bmp"), 2727, 439, 9, 1, true);

	IMAGEMANAGER->LoadFromFile(L"PotatoParryable", Resources(L"Boss/BotanicPanic/Potato/Potato_Parryable.bmp"), 528, 142, 4, 1, true);
	IMAGEMANAGER->LoadFromFile(L"PotatoNonParryable", Resources(L"Boss/BotanicPanic/Potato/Potato_NonParryable.bmp"), 1072, 139, 8, 1, true);


	//당근
	IMAGEMANAGER->LoadFromFile(L"CarrotIntro", Resources(L"Boss/BotanicPanic/Carrot/Carrot_Intro.bmp"), 14800, 549, 25, 1, true);
	IMAGEMANAGER->LoadFromFile(L"CarrotBeam", Resources(L"Boss/BotanicPanic/Carrot/Carrot_Beam.bmp"), 5954, 522, 13, 1, true);
	IMAGEMANAGER->LoadFromFile(L"CarrotDeath", Resources(L"Boss/BotanicPanic/Carrot/Carrot_Death.bmp"), 1072, 139, 8, 1, true);


	//양파
	IMAGEMANAGER->LoadFromFile(L"OnionIntro", Resources(L"Boss/BotanicPanic/Onion/Onion_Intro.bmp"), 12312, 643, 24, 1, true);
	IMAGEMANAGER->LoadFromFile(L"OnionIdle", Resources(L"Boss/BotanicPanic/Onion/Onion_Idle.bmp"), 7440, 563, 15, 1, true);
	IMAGEMANAGER->LoadFromFile(L"OnionDeath", Resources(L"Boss/BotanicPanic/Onion/Onion_Death.bmp"), 2976, 599, 6, 1, true);
	IMAGEMANAGER->LoadFromFile(L"OnionDeathLeave", Resources(L"Boss/BotanicPanic/Onion/Onion_Death_Leave.bmp"), 16768, 596, 31, 1, true);

	IMAGEMANAGER->LoadFromFile(L"OnionArmBashful", Resources(L"Boss/BotanicPanic/Onion/Onion_Arm_Bashful.bmp"), 3171, 195, 7, 1, true);

	IMAGEMANAGER->LoadFromFile(L"OnionTearA", Resources(L"Boss/BotanicPanic/Onion/Onion_TearA.bmp"), 111, 68, 3, 1, true);
	IMAGEMANAGER->LoadFromFile(L"OnionTearB", Resources(L"Boss/BotanicPanic/Onion/Onion_TearB.bmp"), 111, 67, 3, 1, true);
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
