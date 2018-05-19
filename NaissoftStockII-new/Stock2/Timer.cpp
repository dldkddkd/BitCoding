/*
* Timer.cpp
*
* Timer 관련 함수. 업데이트 및 시간 관리에 사용
*
* Created on : 2018-05-08
*     Author : Jeong Ji-ung
*/
#include "global.h"

namespace Core
{

void cTimer::Init()
{
	mDays[0]				= 31;
	mDays[1]				= 28;
	mDays[2]				= 31;
	mDays[3]				= 30;
	mDays[4]				= 31;
	mDays[5]				= 30;
	mDays[6]				= 31;
	mDays[7]				= 31;
	mDays[8]				= 30;
	mDays[9]				= 31;
	mDays[10]				= 30;
	mDays[11]				= 31;

	mTimerMode				= AUTO;

	mMonth					= 0;
	mDay					= 0;
	mHour					= 0;
	mCnt					= 0;
}

void cTimer::Update()
{
	// 특정 시간에 따른 데이터 처리 수행

	// 1초 == 1시간
	if (mCnt % 20 == 0)
	{
		cCompanyManager::GetInstance()->UpdateAllCompanyPrice();
		//TOOD:: UpdateGraphData();
		mHour++;
	}

	// 3초에 한번씩 팁 갱신
	if (mCnt % 60 == 0)
	{
		//TOOD:: showTipNews();
	}

	if (mHour == 1)
		cCompanyManager::GetInstance()->UpdateAllCompanyStatus();

	// 하루가 지났을 경우 처리
	if (mHour > 23)
	{
		mHour				= 0;
		mDay++;
		cPlayer::GetInstance()->GetMoney_info()->Interest();
	}

	if (mDay > mDays[mMonth] - 1)
	{
		mDay				= 0;
		mMonth++; 
		cPlayer::GetInstance()->GetMoney_info()->Tax();
	}

	if (mMonth > 11)
		mMonth				= 0;

	if (mTimerMode == AUTO)
	{
		//TODO:: clearbuffer();
		Sleep(DELAY);
		mCnt++;
	}
	else if (mTimerMode == MANUAL)
	{
		//TODO:: clearbuffer();
		Sleep(DELAY);
	}
}

int cTimer::GetHour()
{
	return mHour;
}

int cTimer::GetDay()
{
	return mDay;
}

int cTimer::GetMonth()
{
	return mMonth;
}

int cTimer::GetTimerMode()
{
	return mTimerMode;
}

int cTimer::GetDaysOfCurrent()
{
	return mDays[mDay];
}

}