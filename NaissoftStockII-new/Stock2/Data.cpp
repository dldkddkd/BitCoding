/*
* Data.cpp
*
* Data ฐüทร save, load
*
* Created on : 2018-05-18
*     Author : Jeong Ji-ung
*/
#include "global.h"

namespace Core
{

void cData::Save()
{
	FILE *save							= fopen("save.ns3", "wb");

	int player_stock_count				= 0;
	
	cStock player_stock					= cPlayer::GetInstance()->GetStock_info()->GetStock();

	for (cNode *pNow = player_stock.GetHead()->GetNextNode(); pNow; pNow = pNow->GetNextNode())
		player_stock_count++;

	fprintf(save, "%d ", _rotl(player_stock_count, 1));

	for (cNode *pNow = player_stock.GetHead()->GetNextNode(); pNow; pNow = pNow->GetNextNode())
	{
		fprintf(save, "%d %d %d ",
			_rotl(pNow->GetCompanyNumber(), 1),
			_rotl(pNow->GetPrice(), 1),
			_rotl(pNow->GetAmount(), 1));
	}

	int ai_stock_count					= 0;

	cStock ai_stock						= cAIPlayer::GetInstance()->GetStock_info()->GetStock();

	for (cNode *pNow = ai_stock.GetHead()->GetNextNode(); pNow; pNow = pNow->GetNextNode())
		ai_stock_count++;

	fprintf(save, "%d ", _rotl(ai_stock_count, 1));

	for (cNode *pNow = ai_stock.GetHead()->GetNextNode(); pNow; pNow = pNow->GetNextNode())
	{
		fprintf(save, "%d %d %d ",
			_rotl(pNow->GetCompanyNumber(), 1),
			_rotl(pNow->GetPrice(), 1),
			_rotl(pNow->GetAmount(), 1));
	}

	for (int i = 0; i < MAX_COMPANY; i++) 
		fprintf(save, "%d ", _rotl(cCompanyManager::GetInstance()->GetCompany(i).GetPrice(), 1));

	for (int i = 0; i < MAX_COMPANY; i++)
		fprintf(save, "%d ", _rotl(cCompanyManager::GetInstance()->GetCompany(i).GetCompanyStatus(), 1));

	fprintf(save, "%d %d %d %d %d %d %d %d %d %d %d %d",
		_rotl(cPlayer::GetInstance()->GetMoney_info()->GetMoney(), 1),
		_rotl(cPlayer::GetInstance()->GetMoney_info()->GetLoan(), 1),
		_rotl(cPlayer::GetInstance()->GetStock_info()->GetStockAmount(), 1),
		_rotl(cPlayer::GetInstance()->GetStock_info()->GetStockDealCount(), 1),

		_rotl(cAIPlayer::GetInstance()->GetMoney_info()->GetMoney(), 1),
		_rotl(cAIPlayer::GetInstance()->GetStock_info()->GetStockAmount(), 1),
		_rotl(cAIPlayer::GetInstance()->GetStock_info()->GetStockDealCount(), 1),

		_rotl(cTimer::GetInstance()->GetMonth(), 1), 
		_rotl(cTimer::GetInstance()->GetDay(), 1),
		_rotl(cTimer::GetInstance()->GetHour(), 1),
		cGameManager::GetInstance()->GetDrawGame().GetStockViewMode(), 
		cTimer::GetInstance()->GetTimerMode());

	fclose(save);
}

void cData::Load()
{
	FILE *save = fopen("save.ns3", "rb");

	if (save == NULL)
		return;

	int player_stock_count;

	fscanf(save, "%d ", &player_stock_count);
	
	player_stock_count = _rotr(player_stock_count, 1);

	for (int i = 0; i < player_stock_count; i++)
	{
		cNode temp;

		int playerStockCompNumber;
		int playerStockPrice;
		int playerStockAmount;

		fscanf(save, "%d %d %d ", &playerStockCompNumber, &playerStockPrice, &playerStockAmount);

		temp.SetCompanyNumber(_rotr(playerStockCompNumber, 1));
		temp.SetPrice(_rotr(playerStockPrice, 1));
		temp.SetAmount(_rotr(playerStockAmount, 1));

		cNode* pPlayerHead = cPlayer::GetInstance()->GetStock_info()->GetStock().GetHead();

		cPlayer::GetInstance()->GetStock_info()->GetStock().InsertNode(pPlayerHead, &temp);
	}

	int ai_stock_count;

	fscanf(save, "%d ", &ai_stock_count);

	ai_stock_count = _rotr(ai_stock_count, 1);

	for (int i = 0; i < ai_stock_count; i++)
	{
		cNode temp;

		int aiStockCompNumber;
		int aiStockPrice;
		int aiStockAmount;

		fscanf(save, "%d %d %d ", &aiStockCompNumber, &aiStockPrice, &aiStockAmount);

		temp.SetCompanyNumber(_rotr(aiStockCompNumber, 1));
		temp.SetPrice(_rotr(aiStockPrice, 1));
		temp.SetAmount(_rotr(aiStockAmount, 1));

		cNode* pPlayerHead = cPlayer::GetInstance()->GetStock_info()->GetStock().GetHead();

		cPlayer::GetInstance()->GetStock_info()->GetStock().InsertNode(pPlayerHead, &temp);
	}

	for (int i = 0; i < MAX_COMPANY; i++)
	{
		int currentPrice;

		fscanf(save, "%d ", &currentPrice);

		cCompanyManager::GetInstance()->GetCompany(i).SetPrice(_rotr(currentPrice, 1));
	}

	for (int i = 0; i < MAX_COMPANY; i++)
	{
		int compStatus;

		fscanf(save, "%d ", &compStatus);

		cCompanyManager::GetInstance()->GetCompany(i).SetCompanyStatus(_rotr(compStatus, 1));
	}

	int playerMoney;
	int playerLoan;
	int playerStockAmount;
	int playerStockDealCnt;

	int aiMoney;
	int aiStockAmount;
	int aiStockDealCnt;

	int month;
	int day;
	int hour;

	int stockViewMode;
	int timerMode;

	fscanf(save, "%d %d %d %d %d %d %d %d %d %d %d %d",
		&playerMoney,
		&playerLoan,
		&playerStockAmount,
		&playerStockDealCnt,
		
		&aiMoney,
		&aiStockAmount,
		&aiStockDealCnt,
		
		&month,
		&day,
		&hour,
		
		&stockViewMode,
		&timerMode);

	cPlayer::GetInstance()->GetMoney_info()->SetMoney(_rotr(playerMoney, 1));
	cPlayer::GetInstance()->GetMoney_info()->SetLoan(_rotr(playerLoan, 1));
	cPlayer::GetInstance()->GetStock_info()->SetStockAmount(_rotr(playerStockAmount, 1));
	cPlayer::GetInstance()->GetStock_info()->SetStockDealCount(_rotr(playerStockDealCnt, 1));

	cAIPlayer::GetInstance()->GetMoney_info()->SetMoney(_rotr(aiMoney, 1));
	cAIPlayer::GetInstance()->GetStock_info()->SetStockAmount(_rotr(aiStockAmount, 1));
	cAIPlayer::GetInstance()->GetStock_info()->SetStockDealCount(_rotr(aiStockDealCnt, 1));

	cTimer::GetInstance()->SetMonth(_rotr(month, 1));
	cTimer::GetInstance()->SetDay(_rotr(day, 1));
	cTimer::GetInstance()->SetHour(_rotr(hour, 1));

	cGameManager::GetInstance()->GetDrawGame().SetStockViewMode(stockViewMode);
	cTimer::GetInstance()->SetTimerMode(timerMode);
	
	fclose(save);
}

}