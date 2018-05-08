/*
 * Timer.h
 *
 * Timer ���� �Լ�. ������Ʈ �� �ð� ������ ���
 *
 * Created on : 2018-05-08
 *     Author : Jeong Ji-ung
 */
#pragma once

namespace Core
{
	namespace Timer
	{
#define						DELAY	50			// sleep ������ ��
#define						AUTO	0			// �ڵ�
#define						MANUAL	1			// ����

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

	int						mDays[12];			// �� ���� ��¥ ��.
	int						mTimerMode;			// 0 - �ڵ�, 1 - ����

public:
	void					Init();
	void					Update();
};

	}
}