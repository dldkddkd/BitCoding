/*
* Player.cpp
*
* 플레이어 관련 데이터 및 처리
*
* Created on : 2018-05-02
*     Author : Jeong Ji-ung
*/
#include "global.h"

namespace GameSystem
{

void cMoney_info::Interest()
{
	loan					+= (int)((double)loan * interest);
}

void cMoney_info::Tax()
{
	ready_money				-= TAX(ready_money);
}

void cMoney_info::SetMoney(int _money)
{
	ready_money				= _money;
}

void cMoney_info::SetLoan(int _loan)
{
	loan					= _loan;
	
	if (loan < 0)
		loan				= 0;
}

void cMoney_info::SetInterest(double _rate)
{
	interest				= _rate;
}

int cMoney_info::GetMoney()
{
	return ready_money;
}

int cMoney_info::GetLoan()
{
	return loan;
}

double cMoney_info::GetInterRate()
{
	return interest;
}

void cStock_info::SetStockDealCount(int _count)
{
	stock_deal_count		= _count;
}

void cStock_info::SetStockAmount(int _number)
{
	mStockAmount			= _number;
}

int cStock_info::GetStockDealCount()
{
	return stock_deal_count;
}

int cStock_info::GetStockAmount()
{
	return mStockAmount;
}

cStock cStock_info::GetStock()
{
	return mStock;
}

void cPlayData::Init()
{
	mMoney.SetMoney(START_MONEY);
	mMoney.SetLoan(0);
	mMoney.SetInterest(DEFAULT_INTER_RATE);

	mStock.SetStockDealCount(0);
	mStock.SetStockAmount(0);
}

cMoney_info* cPlayData::GetMoney_info()
{
	return &mMoney;
}

cStock_info* cPlayData::GetStock_info()
{
	return &mStock;
}


}