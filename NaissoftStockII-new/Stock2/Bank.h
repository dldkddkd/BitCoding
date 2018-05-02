/*
* Bank.h
*
* 은행 관련 처리 (대출, 상환)
*
* Created on : 2018-05-02
*     Author : Jeong Ji-ung
*/
#pragma once

namespace GameSystem
{

using namespace				Player;

	namespace Bank
	{

class cBank : public Core::cSingleton<cBank>
{
public:
	cBank() {}
	virtual ~cBank() {}

private:
	int						mInter_rate;

private:
	bool					Loan(cMoney_info* _money_info, int _loan);
	bool					Payback(cMoney_info* _money_info, int _payback);

public:
	void					init();

	void					Proc_loan();
	void					Proc_payback();
};

	}
}