#include "global.h"

namespace GameSystem
{

/** Buy stocks and insert into the stock linked list to save user's stocks
* �ֽ��� ��� ������ �ֽĵ��� �����ϱ� ���� �ֽ� ���Ḯ��Ʈ�� �����մϴ�
*
* @param order
* Company number to identify companies
*
* @param amount
* Amount of stocks
*
* @return bool
* If the user buys stock, return true
* If the user can't buy stock, return false
*/
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

		printf(" %d���� �ְ� �ֽ��� �����߽��ϴ�. �ֽ��� %d���Դϴ�.\n",
			cCompanyManager::GetInstance()->GetCompany(order).GetPrice(), 
			cPlayer::GetInstance()->GetStock_info()->GetStockAmount());

			
		printf(" ���� ���� %d���Դϴ�", cPlayer::GetInstance()->GetMoney_info()->GetMoney());

		return true;
	}
	else
	{
		return false;
	}
}

/** Sell a stock and delete it on list
*
* @param indexStock
* index of the list of stocks the user wants to sell
*
* @param amount
* amount of a stock that user selects
*
* @return void
*/
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