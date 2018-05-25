/*
* AISystem.h
*
* AI 관련 처리. 유저와 승부하는 인공지능
*
* Created on : 2018-05-25
*     Author : Jeong Ji-ung
*/
#pragma once

namespace GameSystem
{

class cAIPlayer : public cPlayData, public Core::cSingleton<cAIPlayer>
{
public:
	cAIPlayer() {}
	virtual ~cAIPlayer() {}

private:
	cAIPlayerMarket			mMarket;

private:
	int						SearchBuyComp();
	INT64					SearchSellComp();
	
	void					Proc_StockBuy(int _comp);
	void					Proc_StockSell(INT64 _comp);

public:
	void					onUpdate();
};

}