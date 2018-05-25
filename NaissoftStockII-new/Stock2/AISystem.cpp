/*
* AISystem.cpp
*
* AI ���� ó��. ������ �º��ϴ� �ΰ�����
*
* Created on : 2018-05-25
*     Author : Jeong Ji-ung
*/
#include "global.h"

namespace GameSystem
{

int cAIPlayer::SearchBuyComp()
{
	// �ֽ� ������ ���� ����, ���°� ���� ȸ�� �ϳ� �˻�
	int						result = -1;
	int						compNum = 0;
	cCompany*				comp;

	for (int i = 0; i < MAX_COMPANY; i++)
	{
		comp				= cCompanyManager::GetInstance()->GetCompany(i);

		// ȸ�� ���°� ����, �ֽ� ������ ���� ���� ȸ�縦 �˻��Ͽ� ������ �ִ´�.
		if (comp->GetCompanyStatus() == true)
		{
			if (comp->GetPrice() < cCompanyManager::GetInstance()->GetCompany(compNum)->GetPrice())
			{
				compNum		= i;
				result		= compNum;
			}
		}
	}

	return result;
}

INT64 cAIPlayer::SearchSellComp()
{
	// ���� ���ݰ� ���ؼ� ���� ������ ���� ���� �ֽ��� ó��. ��ü �Ⱦƹ�����.
	INT64					compNum = -1;
	int						price_term;
	int						max_term = 0;
	int						list_number = 0;

	cCompany				comp;
	cStock					aiPlayer_stock = GetStock_info()->GetStock();

	for (GameSystem::cNode* pNow = aiPlayer_stock.GetHead()->GetNextNode(); pNow != NULL; pNow = pNow->GetNextNode(), list_number++)
	{
		price_term			= GET_COMPANY(pNow->GetCompanyNumber())->GetPrice() - GET_COMPANY(pNow->GetCompanyNumber())->GetPrevPrice();
	
		if (max_term < price_term)
		{
			max_term		= price_term;
			compNum			= list_number;
			compNum			= compNum << 32;
			compNum			= compNum | pNow->GetAmount();
		}
	}

	return compNum;
}

void cAIPlayer::Proc_StockBuy(int _comp)
{
	// �ش� ȸ���� ���� ���ݰ� ���� ������ ���Ͽ� ���� ����
	// ���� ������ 1 ~ ���� �������� ���ݱ����� ����
	int						price_term;
	int						max_amount;
	int						amount;
	int						money;

	price_term				= GET_COMPANY(_comp)->GetPrice() - GET_COMPANY(_comp)->GetPrevPrice();
	money					= mMoney.GetMoney() / 2;
	max_amount				= money / GET_COMPANY(_comp)->GetPrice();

	if (price_term < 0)
		return;

	if (price_term < LOW_UP_PRICE)
	{
		// 50���� Ȯ���� �ֽ� ����
		if (rand() % 2)
		{
			amount			= (rand() % max_amount) + 1;
			mMarket.BuyStock(_comp, amount);
		}
	}
	else if (price_term > LOW_UP_PRICE)
	{
		// ������ ����
		amount				= (rand() % max_amount) + 1;
		mMarket.BuyStock(_comp, amount);
	}
}

void cAIPlayer::Proc_StockSell(INT64 _comp)
{
	int						list_number;
	int						amount;

	list_number				= _comp >> 32;
	amount					= _comp & 0xFFFFFFFF;

	mMarket.SellStock(list_number, amount);
}

void cAIPlayer::onUpdate()
{
	// 1�ʿ� �ѹ��� ����
	// �ش� �Լ����� �ֽ��� ������ ������, �Ǹ��� ������, �ƹ��͵� ���� ������ ����.
	int						buycomp;
	INT64					sellcomp;

	buycomp					= SearchBuyComp();
	if (buycomp != -1)
		Proc_StockBuy(buycomp);

	sellcomp				= SearchSellComp();
	if (sellcomp != -1)
		Proc_StockSell(sellcomp);
}

}