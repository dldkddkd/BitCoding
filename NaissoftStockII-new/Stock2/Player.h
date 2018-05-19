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

class cMoney_info
{
public:
	cMoney_info() {}
	virtual ~cMoney_info() {}

private:
	int						ready_money;		// ������ (������ + �����)
	int						loan;				// �����
	double					interest;			// ��������

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
	//TDOD:: �߰� �ʿ��� ����
	//		 �����ϰ� �ִ� ȸ�� �ֽ�
	int						stock_deal_count;	// �ֽİŷ� Ƚ��

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