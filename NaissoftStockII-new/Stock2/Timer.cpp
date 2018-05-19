/*
* Timer.cpp
*
* Timer ���� �Լ�. ������Ʈ �� �ð� ������ ���
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
	// Ư�� �ð��� ���� ������ ó�� ����

	// 1�� == 1�ð�
	if (mCnt % 20 == 0)
	{
		cCompanyManager::GetInstance()->UpdateAllCompanyPrice();
		//TOOD:: UpdateGraphData();
		mHour++;
	}

	// 3�ʿ� �ѹ��� �� ����
	if (mCnt % 60 == 0)
	{
		//TOOD:: showTipNews();
	}

	if (mHour == 1)
		cCompanyManager::GetInstance()->UpdateAllCompanyStatus();

	// �Ϸ簡 ������ ��� ó��
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