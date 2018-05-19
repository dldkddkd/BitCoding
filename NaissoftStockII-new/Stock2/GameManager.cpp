/*
* GameManager.cpp
*
* 게임 루프 관련 처리
*
* Created on : 2018-05-12
*     Author : Jeong Ji-ung
*/
#include "global.h"

namespace GameSystem
{

void cDrawGame::ShowMain()
{
	gotoxy(0, 1);
	printf(" Stock II - Naissoft 주식 게임 2\n ver α 1.3.0128\n\n B 사기, S 팔기, V 목록, E 저장, I 회사 정보, 8 / 2 회사 선택, Esc 메뉴");

	if (cTimer::GetInstance()->GetTimerMode() == 1)
		printf("\n W 기다리기");

	gotoxy(0, 5);
	printf("\n 현재 내 돈 : %d원, 갚아야 할 돈 : %d원\n\n\n\n", cPlayer::GetInstance()->GetMoney_info()->GetMoney(), cPlayer::GetInstance()->GetMoney_info()->GetLoan());

	cCompanyManager::GetInstance()->ShowStockPrice(mStockViewMode);

	printf("\n %d월 %d일 %d시", cTimer::GetInstance()->GetMonth() + 1, cTimer::GetInstance()->GetDay() + 1, cTimer::GetInstance()->GetHour());
	printf("\n\n 이번 달 납부할 세금은 %d원입니다. %d일 남았습니다.\n", TAX(cPlayer::GetInstance()->GetMoney_info()->GetMoney()), cTimer::GetInstance()->GetDaysOfCurrent() - cTimer::GetInstance()->GetDay());
}

void cDrawGame::SetStockViewMode(int _mode)
{
	mStockViewMode			= _mode;
}

int cDrawGame::GetStockViewMode()
{
	return mStockViewMode;
}

void cGameManager::InitGame()
{
	system("title Stock 2 - 주식 게임 2");
	system("mode con: cols=120 lines=40");

	startLogo();

	cPlayer::GetInstance()->Init();
	cCompanyManager::GetInstance()->Init();
	cBank::GetInstance()->Init();
	cTimer::GetInstance()->Init();

	//TODO:: Stock List init
}

void cGameManager::SelectStartMenu()
{
	printMainMenu();
	scanf("%d", &mSelect);

	switch (mSelect)
	{
	case 1:
		cData::GetInstance()->Save();
		break;

	case 2:
		cData::GetInstance()->Load();
		break;

	case 3:
		exit(0);
		break;

	default:
		break;
	}
	
	system("cls");
}

void cGameManager::SelectGameMenu()
{

}

void cGameManager::SelectPauseMenu()
{

}

void cGameManager::onStart()
{
	InitGame();
	SelectStartMenu();

	cCompanyManager::GetInstance()->DrawNewspaper(mSelectComp);

	// Game Loop Start.
	while (true)
	{

	}
}

}