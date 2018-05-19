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

class cMoney_info
{
public:
	cMoney_info() {}
	virtual ~cMoney_info() {}

private:
	int						ready_money;		// 소지금 (소지금 + 대출금)
	int						loan;				// 대출금
	double					interest;			// 대출이자

public:
	void					Interest();
	void					Tax();

	void					SetMoney(int _money);
	void					SetLoan(int _loan);
	void					SetInterest(double _rate);

	int						GetMoney();
	int						GetLoan();
	double					GetInterRate();
};

class cStock_info
{
public:
	cStock_info() {}
	virtual ~cStock_info() {}

private:
	//TDOD:: 추가 필요한 변수
	//		 보유하고 있는 회사 주식
	int						stock_deal_count;	// 주식거래 횟수

public:
	void					SetStockDealCount(int _count);

	int						GetStockDealCount();
};

class cPlayer : public Core::cSingleton<cPlayer>
{
public:
	cPlayer() {}
	virtual ~cPlayer() {}

private:
	cMoney_info				mMoney;
	cStock_info				mStock;

public:
	void					Init();

	cMoney_info*			GetMoney_info();
	cStock_info*			GetStock_info();
};

}