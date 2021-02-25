#pragma once
class ThreadManager
{
	Singleton(ThreadManager)
private:
	bool mIsThreadPlay = false;
	bool mIsPlay = false;
	queue<function<void(void)>> mFunts;
	thread* mLoadingThread;
public :
	void LoadStartFunts();
	void SetFunts(const function<void(void)>& funts);
	void Loding();
	void LoadStartEnd();

	void SetIsPlay(bool d) { mIsPlay = d; }
};