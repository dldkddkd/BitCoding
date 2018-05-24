#include "global.h"

namespace GameSystem
{

bool cPlayerMarket::BuyStock(int order, int amount) 
{
	int totalPrice;

	cNode temp;
	cNode *pNow;

	totalPrice = cCompanyManager::GetInstance()->GetCompany(order).GetPrice() * amount;

	if (totalPrice <= cPlayer::GetInstance()->GetMoney_info()->GetMoney())
	{
		system("cls");
			
		temp.SetCompanyNumber(order);
		temp.SetPrice(cCompanyManager::GetInstance()->GetCompany(order).GetPrice());
		temp.SetAmount(amount);

		pNow = cPlayer::GetInstance()->GetStock_info()->GetStock().GetHead();

		cPlayer::GetInstance()->GetStock_info()->GetStock().InsertNode(pNow, &temp);

		cPlayer::GetInstance()->GetStock_info()->SetStockDealCount(cPlayer::GetInstance()->GetStock_info()->GetStockDealCount() + 1);
		cPlayer::GetInstance()->GetMoney_info()->SetMoney(cPlayer::GetInstance()->GetMoney_info()->GetMoney() - totalPrice);
		cPlayer::GetInstance()->GetStock_info()->SetStockAmount(cPlayer::GetInstance()->GetStock_info()->GetStockAmount() + amount);

		printf(" %d원을 주고 주식을 구입했습니다. 주식이 %d개입니다.\n",
			cCompanyManager::GetInstance()->GetCompany(order).GetPrice(), 
			cPlayer::GetInstance()->GetStock_info()->GetStockAmount());

			
		printf(" 남은 돈은 %d원입니다", cPlayer::GetInstance()->GetMoney_info()->GetMoney());

		return true;
	}
	else
	{
		return false;
	}
}

void cPlayerMarket::SellStock(int indexStock, int amount)
{
	cNode *saleStock = cPlayer::GetInstance()->GetStock_info()->GetStock().SearchNode(indexStock - 1);

	if (saleStock == NULL)
		return;

	cPlayer::GetInstance()->GetMoney_info()->SetMoney(
		cPlayer::GetInstance()->GetMoney_info()->GetMoney() 
		+ (cCompanyManager::GetInstance()->GetCompany(saleStock->GetCompanyNumber()).GetPrice() * amount)
	);

	cPlayer::GetInstance()->GetStock_info()->SetStockAmount(
		cPlayer::GetInstance()->GetStock_info()->GetStockAmount() - amount
	);

	if (saleStock->GetAmount() > amount)
		saleStock->SetAmount(saleStock->GetAmount() - amount);

	else if (saleStock->GetAmount() == amount)
		cPlayer::GetInstance()->GetStock_info()->GetStock().DeleteNode(saleStock);
}
}