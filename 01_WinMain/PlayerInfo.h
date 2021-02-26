#pragma once
class PlayerInfo
{
	Singleton(PlayerInfo)
private:
	bool mBossStage1Clear;
	bool mBossStage2Clear;
	float mPlayerX = NULL;
	float mPlayerY = NULL;
public :
	void PlayerInfoDataLoad();
	void PlayerInfoDateSave();
};

