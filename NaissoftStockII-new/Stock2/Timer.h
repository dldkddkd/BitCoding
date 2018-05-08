/*
 * Timer.h
 *
 * Timer 관련 함수. 업데이트 및 시간 관리에 사용
 *
 * Created on : 2018-05-08
 *     Author : Jeong Ji-ung
 */
#pragma once

namespace Core
{
	namespace Timer
	{
#define						DELAY	50			// sleep 딜레이 값
#define						AUTO	0			// 자동
#define						MANUAL	1			// 수동

class cTimer : public DeignPattern::cSingleton<cTimer>
{
public:
	cTimer() {}
	virtual ~cTimer() {}

private:
	int						mCnt;
	int						mHour;
	int						mDay;
	int						mMonth;

	int						mDays[12];			// 각 달의 날짜 수.
	int						mTimerMode;			// 0 - 자동, 1 - 수동

public:
	void					Init();
	void					Update();
};

	}
}