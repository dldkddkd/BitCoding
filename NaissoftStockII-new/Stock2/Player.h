/*
 * Player.h
 *
 * �÷��̾� ���� ������ �� ó��
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
	int						ready_money;		// ������ (������ + �����)
	int						loan;				// �����
	int						inter_rate;			// ��������
}MONEY_INFO;

typedef struct stock
{
	//TDOD:: �߰� �ʿ��� ����
	//		 �����ϰ� �ִ� ȸ�� �ֽ�
	int						stock_deal_count;	// �ֽİŷ� Ƚ��
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