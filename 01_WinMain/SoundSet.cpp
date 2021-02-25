#include "pch.h"
#include "SoundSet.h"

void SoundSet::SetSound() {
	//게임 OST
	SoundPlayer::GetInstance()->LoadFromFile(L"BotanicPanicBGM", Resources(L"Boss/BotanicPanic/07 Botanic Panic.mp3"), true);
	SoundPlayer::GetInstance()->LoadFromFile(L"FloralFuryBGM", Resources(L"Boss/FloralFury/13 Floral Fury.mp3"), true);
	//아나운서 게임 시작 안내
	SoundPlayer::GetInstance()->LoadFromFile(L"Start1", Resources(L"Announcer Voice/A brawl is surely brewing!.mp3"), false);
	SoundPlayer::GetInstance()->LoadFromFile(L"Start2", Resources(L"Announcer Voice/A good day for a swell battle!.mp3"), false);
	SoundPlayer::GetInstance()->LoadFromFile(L"Start3", Resources(L"Announcer Voice/A great slam and then some!.mp3"), false);
	SoundPlayer::GetInstance()->LoadFromFile(L"Start4", Resources(L"Announcer Voice/And begin!.mp3"), false);
	SoundPlayer::GetInstance()->LoadFromFile(L"Start5", Resources(L"Announcer Voice/Here goes!.mp3"), false);
	SoundPlayer::GetInstance()->LoadFromFile(L"Start6", Resources(L"Announcer Voice/Here's a real high class bout!.mp3"), false);
	//아나운서 게임 종료 안내
	SoundPlayer::GetInstance()->LoadFromFile(L"End1", Resources(L"Announcer Voice/It's on!.mp3"), false);
	SoundPlayer::GetInstance()->LoadFromFile(L"End2", Resources(L"Announcer Voice/Knockout!.mp3"), false);
	SoundPlayer::GetInstance()->LoadFromFile(L"End3", Resources(L"Announcer Voice/Now go!.mp3"), false);
	SoundPlayer::GetInstance()->LoadFromFile(L"End4", Resources(L"Announcer Voice/This match will get red hot!.mp3"), false);
	SoundPlayer::GetInstance()->LoadFromFile(L"End5", Resources(L"Announcer Voice/You're up!.mp3"), false);
}