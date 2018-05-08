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
	namespace Player
	{

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

void cMoney_info::SetInterRate(int _rate)
{
	inter_rate				= _rate;
}

int cMoney_info::GetMoney()
{
	return ready_money;
}

int cMoney_info::GetLoan()
{
	return loan;
}

int cMoney_info::GetInterRate()
{
	return inter_rate;
}

void cStock_info::SetStockDealCount(int _count)
{
	stock_deal_count		= _count;
}

int cStock_info::GetStockDealCount()
{
	return stock_deal_count;
}

void cPlayer::init()
{
	mMoney.SetMoney(START_MONEY);
	mMoney.SetLoan(0);
	mMoney.SetInterRate(DEFAULT_INTER_RATE);

	mStock.SetStockDealCount(0);
}

cMoney_info* cPlayer::GetMoney_info()
{
	return &mMoney;
}

cStock_info* cPlayer::GetStock_info()
{
	return &mStock;
}

	}
}

void test()
{
	cPlayer::GetInstance();
}