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
	int						select;

	printMainMenu();
	scanf("%d", &select);

	switch (select)
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
	mSelect					= '\0';
	GetKey(&mSelect);

	switch (mSelect)
	{
	case 'b':
	case 'B':
		
		break;

	case 'v':
	case 'V':
		
		break;

	case 27:
		system("cls");
		titleLine("�Ͻ� ����");
		printf(" 1. ��  ��\n\n 2. ��  ��\n\n 3. ��  ��\n\n 4. ��  ��\n\n 5. ������\n\n Esc ���ư���");

		SelectPauseMenu();

		system("cls");
		Sleep(100);
		break;

	case 's':
	case 'S':
		break;

	case 'E':
	case 'e':
		system("cls");
		//save();
		printf("\n ������ ����Ǿ����ϴ�.");
		Sleep(300);
		break;

	case 'W':
	case 'w':
		if (cTimer::GetInstance()->GetTimerMode() == 1)
		{
			cTimer::GetInstance()->ManualUpdate();
		}
		break;

	case 'I':
	case 'i':
		break;

	case '2':
		if (mSelectComp < MAX_COMPANY - 1) 
			mSelectComp++;
		
		cCompanyManager::GetInstance()->DrawNewspaper(mSelectComp);
		break;

	case '8':
		if (mSelectComp > 0) 
			mSelectComp--;
		
		cCompanyManager::GetInstance()->DrawNewspaper(mSelectComp);
		break;

	default:
		break;
	}
}

void cGameManager::SelectPauseMenu()
{
	mSelect					= (char)_getch();

	switch (mSelect)
	{
	case '1':
		break;

	case '2':
		break;

	case '3':
		break;

	case '4':
		break;

	case '5':
		system("cls");
		printf("\n �����Ͻðڽ��ϱ�? ������� ���� ������ ������ϴ�.\n Y / N");

		char				ch;
		ch					= (char)_getch();

		if (ch == 'Y' || ch == 'y')
			return;
		break;

	case 27:
		break;

	default:
		break;
	}
}

void cGameManager::GetKey(char* c)
{
	if (!cTimer::GetInstance()->GetTimerMode())
	{
		if (_kbhit()) 
			*c				= (char)_getch();
	}
	else 
		*c					= (char)_getch();
}

void cGameManager::onStart()
{
	InitGame();
	SelectStartMenu();

	cCompanyManager::GetInstance()->DrawNewspaper(mSelectComp);

	// Game Loop Start.
	while (true)
	{
		mDrawGame.ShowMain();
		cCompanyManager::GetInstance()->DrawGraph(mSelectComp);
		cCompanyManager::GetInstance()->ShowCompanyReport(mSelectComp);

		if (cPlayer::GetInstance()->GetMoney_info()->GetMoney() <= 0)
		{
			printf("\n �Ļ�... 3000�� ������ �帮�ڽ��ϴ�.");
			getchar();
			cBank::GetInstance()->Loan(cPlayer::GetInstance()->GetMoney_info(), 3000);
			system("cls");
		}

		gotoxy(57, 10 + mSelectComp - 1);
		printf("  ");
		gotoxy(57, 10 + mSelectComp + 1);
		printf("  ");
		gotoxy(57, 10 + mSelectComp);
		printf("��");

		SelectGameMenu();

		cTimer::GetInstance()->Update();
	}
}

}