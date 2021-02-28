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
	void SetBossStage1Clear(bool d) { mBossStage1Clear = d; }
	void SetBossStage2Clear(bool d) { mBossStage2Clear = d; }
};

