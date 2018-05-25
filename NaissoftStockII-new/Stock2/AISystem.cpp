/*
* AISystem.cpp
*
* AI 관련 처리. 유저와 승부하는 인공지능
*
* Created on : 2018-05-25
*     Author : Jeong Ji-ung
*/
#include "global.h"

namespace GameSystem
{

int cAIPlayer::SearchBuyComp()
{
	// 주식 가격이 가장 낮고, 상태가 좋은 회사 하나 검색
	int						result = -1;
	int						compNum = 0;
	cCompany*				comp;

	for (int i = 0; i < MAX_COMPANY; i++)
	{
		comp				= cCompanyManager::GetInstance()->GetCompany(i);

		// 회사 상태고 좋고, 주식 가격이 가장 낮은 회사를 검색하여 가지고 있는다.
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
	// 이전 가격과 비교해서 가장 가격이 많이 오른 주식을 처분. 전체 팔아버린다.
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
	// 해당 회사의 이전 가격과 현재 가격을 비교하여 구매 결정
	// 구매 갯수는 1 ~ 현재 소지금의 절반까지만 구매
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
		// 50프로 확률로 주식 구매
		if (rand() % 2)
		{
			amount			= (rand() % max_amount) + 1;
			mMarket.BuyStock(_comp, amount);
		}
	}
	else if (price_term > LOW_UP_PRICE)
	{
		// 무조건 구매
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
	// 1초에 한번씩 진입
	// 해당 함수에서 주식을 구매할 것인지, 판매할 것인지, 아무것도 안할 것인지 정함.
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