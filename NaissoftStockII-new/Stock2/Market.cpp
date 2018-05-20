#include "global.h"

namespace GameSystem
{

bool cPlayerMarket::BuyStock(int order, int amount) 
{
	int totalPrice;

	cNode temp;
	cNode *pNow;

	totalPrice = cCompanyManager::GetInstance()->GetCompany(order).GetPrice() * amount;

	if (cCompanyManager::GetInstance()->GetCompany(order).GetPrice() <= cPlayer::GetInstance()->GetMoney_info()->GetMoney())
	{
		system("cls");
			
		temp.SetCompanyNumber(order);
		temp.SetPrice(cCompanyManager::GetInstance()->GetCompany(order).GetPrice());
		temp.SetAmount(amount);

		pNow = cPlayer::GetInstance()->GetStock_info()->GetStock().GetHead();

		cPlayer::GetInstance()->GetStock_info()->GetStock().InsertNode(pNow, &temp);

		cPlayer::GetInstance()->GetStock_info()->SetStockDealCount(cPlayer::GetInstance()->GetStock_info()->GetStockDealCount() + 1);
		cPlayer::GetInstance()->GetMoney_info()->SetMoney(cPlayer::GetInstance()->GetMoney_info()->GetMoney() - cCompanyManager::GetInstance()->GetCompany(order).GetPrice());
		cPlayer::GetInstance()->GetStock_info()->SetStockNumber(cPlayer::GetInstance()->GetStock_info()->GetStockNumber() + amount);

		printf(" %d���� �ְ� �ֽ��� �����߽��ϴ�. �ֽ��� %d���Դϴ�.\n",
			cCompanyManager::GetInstance()->GetCompany(order).GetPrice(), 
			cPlayer::GetInstance()->GetStock_info()->GetStockNumber());

			
		printf(" ���� ���� %d���Դϴ�", cPlayer::GetInstance()->GetMoney_info()->GetMoney());

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
		+ (cCompanyManager::GetInstance()->GetCompany(saleStock->GetCompanyNumber()).GetPrice() *amount));

	if (saleStock->GetAmount() > amount)
		saleStock->SetAmount(saleStock->GetAmount() - amount);

	else if (saleStock->GetAmount() == amount)
		cPlayer::GetInstance()->GetStock_info()->GetStock().DeleteNode(saleStock);
}
}