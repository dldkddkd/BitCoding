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
	namespace Timer
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
}

void cTimer::Update()
{

}

	}
}