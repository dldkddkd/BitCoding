/*
* GameManager.cpp
*
* ���� ���� ���� ó��
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
	printf(" Stock II - Naissoft �ֽ� ���� 2\n ver �� 1.3.0128\n\n B ���, S �ȱ�, V ���, E ����, I ȸ�� ����, 8 / 2 ȸ�� ����, Esc �޴�");

	if (cTimer::GetInstance()->GetTimerMode() == 1)
		printf("\n W ��ٸ���");

	gotoxy(0, 5);
	printf("\n ���� �� �� : %d��, ���ƾ� �� �� : %d��\n\n\n\n", cPlayer::GetInstance()->GetMoney_info()->GetMoney(), cPlayer::GetInstance()->GetMoney_info()->GetLoan());

	cCompanyManager::GetInstance()->ShowStockPrice(mStockViewMode);

	printf("\n %d�� %d�� %d��", cTimer::GetInstance()->GetMonth() + 1, cTimer::GetInstance()->GetDay() + 1, cTimer::GetInstance()->GetHour());
	printf("\n\n �̹� �� ������ ������ %d���Դϴ�. %d�� ���ҽ��ϴ�.\n", TAX(cPlayer::GetInstance()->GetMoney_info()->GetMoney()), cTimer::GetInstance()->GetDaysOfCurrent() - cTimer::GetInstance()->GetDay());
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
	system("title Stock 2 - �ֽ� ���� 2");
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