#include "pch.h"
#include "SoundSet.h"

void SoundSet::SetSound() {
	SoundPlayer::GetInstance()->LoadFromFile(L"BotanicPanicBGM", Resources(L"Boss/BotanicPanic/07 Botanic Panic.mp3"), false);
	SoundPlayer::GetInstance()->LoadFromFile(L"FloralFuryBGM", Resources(L"Boss/FloralFury/13 Floral Fury.mp3"), false);
}