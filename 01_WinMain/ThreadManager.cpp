#include "pch.h"
#include "ThreadManager.h"

void ThreadManager::SetFunts(const function<void(void)>& func)
{
	mFunts.push(func);
}

void ThreadManager::LoadStartFunts()
{
	if (mLoadingThread == nullptr) {
		function<void(void)> threadFunc = bind(&ThreadManager::Loding, this);
		//스레드는 메모리 할당해주는 순간부터 바로 돌기 시작한다.
		mIsPlay = true;
		mLoadingThread = new thread(threadFunc);
	}
}

void ThreadManager::LoadStartEnd()
{
	mLoadingThread->join();
	delete mLoadingThread;
	mLoadingThread = nullptr;
	mIsThreadPlay = false;
}

void ThreadManager::Loding() {
	while (mFunts.size() != 0) {
		if (mIsPlay) {
			function<void(void)> startFunc = mFunts.front();
			startFunc();
			mFunts.pop();
		}
	}
	LoadStartEnd();
}

//void ThreadManager::Update() {
//	if (mIsPlay) {
//		if (mFunts.size() == 0) {
//			mIsThreadPlay = false;
//		}
//		else if (mFunts.size() > 0) {
//			mIsThreadPlay = true;
//		}
//	}
//}