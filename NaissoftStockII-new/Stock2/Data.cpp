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
	int stocks				= 0;

	cNode* pNow;

	cStock player_stock		= cPlayer::GetInstance()->GetStock_info()->GetStock();
	
	FILE *save				= fopen("save.ns3", "wb");

	for (pNow = player_stock.GetHead()->GetNextNode(); pNow; pNow = pNow->GetNextNode())
		stocks++;

	fprintf(save, "%d ", _rotl(stocks, 1));

	for (pNow = player_stock.GetHead()->GetNextNode(); pNow; pNow = pNow->GetNextNode())
		fprintf(save, "%d %d ", _rotl(pNow->GetCompanyNumber(), 1), _rotl(pNow->GetPrice(), 1));

	for (int i = 0; i < MAX_COMPANY; i++)
		fprintf(save, "%d ", _rotl(cCompanyManager::GetInstance()->GetCompany(i).GetPrice(), 1));

	for (int i = 0; i < MAX_COMPANY; i++)
		fprintf(save, "%d ", _rotl(cCompanyManager::GetInstance()->GetCompany(i).GetCompanyStatus(), 1));

	fprintf(save, "%d %d %d %d %d %d %d %d %d",
		_rotl(cPlayer::GetInstance()->GetMoney_info()->GetMoney(), 1),
		_rotl(cPlayer::GetInstance()->GetMoney_info()->GetLoan(), 1),
		_rotl(cPlayer::GetInstance()->GetStock_info()->GetStockAmount(), 1),
		_rotl(cPlayer::GetInstance()->GetStock_info()->GetStockDealCount(), 1),
		_rotl(cTimer::GetInstance()->GetMonth(), 1),
		_rotl(cTimer::GetInstance()->GetDay(), 1),
		_rotl(cTimer::GetInstance()->GetHour(), 1),
		cGameManager::GetInstance()->GetDrawGame().GetStockViewMode(),
		cTimer::GetInstance()->GetTimerMode());

	fclose(save);
}

void cData::Load()
{

}

}