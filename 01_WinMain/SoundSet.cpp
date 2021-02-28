#include "pch.h"
#include "SoundSet.h"

void SoundSet::SetSound() {
	//보스 OST
	SoundPlayer::GetInstance()->LoadFromFile(L"BotanicPanicBGM", Resources(L"Boss/BotanicPanic/07 Botanic Panic.mp3"), true);
	SoundPlayer::GetInstance()->LoadFromFile(L"FloralFuryBGM", Resources(L"Boss/FloralFury/13 Floral Fury.mp3"), true);
	
	//아나운서 게임 시작준비 안내
	SoundPlayer::GetInstance()->LoadFromFile(L"Ready1", Resources(L"Announcer Voice/Here's a real high class bout!.mp3"), false);
	SoundPlayer::GetInstance()->LoadFromFile(L"Ready2", Resources(L"Announcer Voice/A good day for a swell battle!.mp3"), false);
	SoundPlayer::GetInstance()->LoadFromFile(L"Ready3", Resources(L"Announcer Voice/This match will get red hot!.mp3"), false);
	SoundPlayer::GetInstance()->LoadFromFile(L"Ready4", Resources(L"Announcer Voice/A great slam and then some!.mp3"), false);
	SoundPlayer::GetInstance()->LoadFromFile(L"Ready5", Resources(L"Announcer Voice/A brawl is surely brewing!.mp3"), false);
	//아나운서 게임 시작 안내
	SoundPlayer::GetInstance()->LoadFromFile(L"Start1", Resources(L"Announcer Voice/You're up!.mp3"), false);
	SoundPlayer::GetInstance()->LoadFromFile(L"Start2", Resources(L"Announcer Voice/Here goes!.mp3"), false);
	SoundPlayer::GetInstance()->LoadFromFile(L"Start3", Resources(L"Announcer Voice/It's on!.mp3"), false);
	SoundPlayer::GetInstance()->LoadFromFile(L"Start4", Resources(L"Announcer Voice/And begin!.mp3"), false);
	SoundPlayer::GetInstance()->LoadFromFile(L"Start5", Resources(L"Announcer Voice/Now go!.mp3"), false);
	//아나운서 게임 종료 안내
	SoundPlayer::GetInstance()->LoadFromFile(L"End1", Resources(L"Announcer Voice/Knockout!.mp3"), false);
	//플랫포머 플레이어 효과음
	SoundPlayer::GetInstance()->LoadFromFile(L"SpecialAttack", Resources(L"PlayerSound/palyer_specialattack.wav"), false);
	SoundPlayer::GetInstance()->LoadFromFile(L"Dash", Resources(L"PlayerSound/player_dash.wav"), false);
	SoundPlayer::GetInstance()->LoadFromFile(L"Death", Resources(L"PlayerSound/player_daath.wav"), false);
	SoundPlayer::GetInstance()->LoadFromFile(L"PeashootFire", Resources(L"PlayerSound/player_default_fire.mp3"), false);
	SoundPlayer::GetInstance()->LoadFromFile(L"SpreadshootFire", Resources(L"PlayerSound/player_default_spread_fire.mp3"), false);
	SoundPlayer::GetInstance()->LoadFromFile(L"GameOver", Resources(L"PlayerSound/player_game_over.wav"), false);
	SoundPlayer::GetInstance()->LoadFromFile(L"PlyerHit", Resources(L"PlayerSound/player_hit.wav"), false);
	SoundPlayer::GetInstance()->LoadFromFile(L"PlyerJump", Resources(L"PlayerSound/player_jump.wav"), false);
	SoundPlayer::GetInstance()->LoadFromFile(L"LandGround", Resources(L"PlayerSound/player_land_ground.wav"), false);
	SoundPlayer::GetInstance()->LoadFromFile(L"ParringSlap", Resources(L"PlayerSound/player_parry_slap.wav"), false);



}