/*
 * Player.h
 *
 * 플레이어 관련 데이터 및 처리
 *
 * Created on : 2018-05-01
 *     Author : Jeong Ji-ung
 */
#pragma once

namespace GameSystem
{
	namespace Player
	{
typedef struct money
{
	int						ready_money;		// 소지금 (소지금 + 대출금)
	int						loan;				// 대출금
	int						inter_rate;			// 대출이자
}MONEY_INFO;

typedef struct stock
{
	//TDOD:: 추가 필요한 변수
	//		 보유하고 있는 회사 주식
	int						stock_deal_count;	// 주식거래 횟수
}STOCK_INFO;

class cPlayer : public Core::cSingleton<cPlayer>
{
public:
	cPlayer();
	virtual ~cPlayer();

private:
	MONEY_INFO				mMoney;
	STOCK_INFO				mStock;

public:
	void					init();

	void					SetMoney(int _money);
	void					SetLoan(int _loan);
	void					SetInterRate(int _rate);
	void					SetStockDealCount(int _count);

	int						GetMoney();
	int						GetLoan();
	int						GetInterRate();
	int						GetStockDealCount();
};

	}

}