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
	printf("\n ���� �� �� : %d��, ���ƾ� �� �� : %d��\n", cPlayer::GetInstance()->GetMoney_info()->GetMoney(), cPlayer::GetInstance()->GetMoney_info()->GetLoan());
	printf(" ��ǻ�� �� : %d��\n\n\n", cAIPlayer::GetInstance()->GetMoney_info()->GetMoney());

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

cDrawGame cGameManager::GetDrawGame()
{
	return mDrawGame;
}

void cGameManager::InitGame()
{
	system("title Stock 2 - �ֽ� ���� 2");
	system("mode con: cols=120 lines=40");

	startLogo();

	cPlayer::GetInstance()->Init();
	cAIPlayer::GetInstance()->Init();
	cCompanyManager::GetInstance()->Init();
	cBank::GetInstance()->Init();
	cTimer::GetInstance()->Init();
}

void cGameManager::SelectStartMenu()
{
	char					select = '\0';

	printMainMenu();

	while (select != '1' && select != '2')
	{
		GetKey(&select);
		
		switch (select)
		{
		case '1':
			cData::GetInstance()->Save();
			break;

		case '2':
			cData::GetInstance()->Load();
			break;

		case '3':
			exit(0);
			break;

		default:
			break;
		}
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
		BuyMenu();
		break;

	case 'v':
	case 'V':
		ShowStockList();
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
		SellMenu();
		break;

	case 'E':
	case 'e':
		system("cls");
		cData::GetInstance()->Save();
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
		cCompanyManager::GetInstance()->ShowCompanyInfo();
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
		ShowStatistics();
		break;

	case '2':
		cBank::GetInstance()->Proc_loan();
		break;

	case '3':
		cBank::GetInstance()->Proc_payback();
		break;

	case '4':
		SelectSettingMenu();
		break;

	case '5':
		system("cls");
		printf("\n �����Ͻðڽ��ϱ�? ������� ���� ������ ������ϴ�.\n Y / N");

		char				ch;
		ch					= (char)_getch();

		if (ch == 'Y' || ch == 'y')
			exit(0);
		break;

	case 27:
		break;

	default:
		break;
	}
}

void cGameManager::SelectSettingMenu()
{
	char					select;
	system("cls");
	titleLine("��  ��");
	printf(" 1. ���� ��� ��ȯ\n 2. �ð� �帧 ��� ��ȯ\n Esc ���ư���");

	select					= (char)_getch();

	switch (select)
	{
	case '1':
		mDrawGame.SetStockViewMode(mDrawGame.GetStockViewMode() + 1);
		
		if (mDrawGame.GetStockViewMode() > 2)
			mDrawGame.SetStockViewMode(0);

		switch (mDrawGame.GetStockViewMode())
		{
		case 0:
			printf(" ���� ����� �⺻ ���� ��ȯ�Ǿ����ϴ�.");
			break;
		case 1:
			printf(" ���� ����� �������� ���� ��ȯ�Ǿ����ϴ�.");
			break;
		case 2:
			printf(" ���� ����� �������� ���� ��ȯ�Ǿ����ϴ�.");
			break;
		}
		break;

	case '2':
		cTimer::GetInstance()->SetTimerMode(cTimer::GetInstance()->GetTimerMode() + 1);

		if (cTimer::GetInstance()->GetTimerMode() > 1) 
			cTimer::GetInstance()->SetTimerMode(0);

		switch (cTimer::GetInstance()->GetTimerMode())
		{
		case 0:
			printf(" �ð� �帧�� �ڵ����� ��ȯ�Ǿ����ϴ�.");
			break;
		case 1:
			printf(" �ð� �帧�� �������� ��ȯ�Ǿ����ϴ�.");
			break;
		}
		break;

	case 27:
		break;

	default:
		break;
	}
	Sleep(300);
	system("cls");
	return;
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

void cGameManager::BuyMenu()
{
	int						stock_amount;

	bool					deal;

	system("cls");
	titleLine("�ֽ� ���");

	printf(" ���� %s ȸ���� �ְ��� %d���Դϴ�.\n\n �� ���� �����Ͻðڽ��ϱ�? (��� : 0)",
		cCompanyManager::GetInstance()->GetCompany(mSelectComp)->GetCompanyName(), 
		cCompanyManager::GetInstance()->GetCompany(mSelectComp)->GetPrice());

	scanf("%d", &stock_amount);

	while (getchar() != '\n');

	if (stock_amount > 0)
	{
		deal				= mPlayerMarket.BuyStock(mSelectComp, stock_amount);

		if (deal)
			printf("\n\n �����Ͽ����ϴ�.");
		
		else
			printf("\n\n �������� ���߽��ϴ�");

		Sleep(2000);
	
	}

	system("cls");

	return;
}

void cGameManager::SellMenu()
{	
	int						idx;
	int						page;

	int						sale_profit;

	int						stock_number;
	int						stock_amount;

	char					key;

	cNode					*selectStock;
	cNode					*pNow;

	cStock					player_stock;

	key						= '\0';
	page					= 1;
	idx						= 1;

	player_stock			= cPlayer::GetInstance()->GetStock_info()->GetStock();

	system("cls");

	if (cPlayer::GetInstance()->GetStock_info()->GetStockAmount() <= 0)
	{
		printf("\n �ֽ��� �����ϴ�.\n");

		Sleep(600);

		system("cls");
		return;
	}

	/* ������ A, D, W, S, B, Q Ű�� �Է��մϴ�					*/
	/* �ֽ��� �� ������ �� 10�� �� ����մϴ�						*/
	/* AŰ�� �Է��ϸ� ���� �������� ����մϴ�						*/
	/* DŰ�� �Է��ϸ� ���� �������� ����մϴ�						*/
	/* WŰ�� �Է��ϸ� ���� ������ �ֽ� ���� �ֽ��� �����մϴ�		*/
	/* SŰ�� �Է��ϸ� ���� ������ �ֽ� �Ʒ��� �ֽ��� �����մϴ�		*/
	/* BŰ�� �Է��ϸ� ������ �ֽ� �Ǹ��մϴ�						*/
	/* QŰ�� �Է��ϸ� �� �ݺ����� �����մϴ�						*/
	while (true)
	{
		titleLine("�ֽ� �ȱ�");
		printf("\n [ W / S�� �� �ֽ��� ������. A / D�� �� �� �� �ֽ��ϴ�. B�� ������ �˴ϴ�. ]\n\n");

		stock_number		= 1;

		/* �ֽ� ���Ḯ��Ʈ�� ��ȸ�ϸ鼭 ������ �ִ� ȸ�� �ֽ� ������ ����մϴ� */
		for (pNow = player_stock.GetHead()->GetNextNode(); pNow != NULL; pNow = pNow->GetNextNode())
		{
			/* �ֽ��� �� ������ �� 10���� ����մϴ�. */
			/* Format: (idx) ȸ�� : (ȸ���̸�), ���� : (�ֽİ���)�� */
			if (stock_number >= page && stock_number < page + 10)
				printf("\n %d. ȸ�� : %-20s, ���� : %d��, ���� : %d��",
					stock_number,
					cCompanyManager::GetInstance()->GetCompany(pNow->GetCompanyNumber())->GetCompanyName(),
					pNow->GetPrice(), 
					pNow->GetAmount());

			stock_number++;
		}

		selectStock			= player_stock.SearchNode(idx - 1);

		if (selectStock == NULL) {
			system("cls");
			return;
		}

		sale_profit			= cCompanyManager::GetInstance()->GetCompany(selectStock->GetCompanyNumber())->GetPrice() - selectStock->GetPrice();

		printf("\n ���ư����� Q�� ��������.\n");

		printf("\n [ ���� �ֽ� ���� ]\n\n ��ȣ : %d\n ȸ�� : %s\n ���� : %d\n ���� ���� : %d\n �ŵ� ���� : %d",
			idx,
			cCompanyManager::GetInstance()->GetCompany(selectStock->GetCompanyNumber())->GetCompanyName(),
			selectStock->GetPrice(),
			cCompanyManager::GetInstance()->GetCompany(selectStock->GetCompanyNumber())->GetPrice(),
			sale_profit);

		key					= (char)_getch();

		switch (key)
		{

		case 'A':
		case 'a':
			if (page > 10)
				page		-= 10;
			break;

		case 'D':
		case 'd':
			page			+= 10;
			break;

		case 'W':
		case 'w':
			if (idx > 1)
				idx--;
			break;

		case 'S':
		case 's':
			if (idx < stock_number)
				idx++;
			break;

		case 'Q':
		case 'q':
			system("cls");
			return;

		case 'B':
		case 'b':
			printf("\n\n �ŵ��� �ֽ� ����(���ڸ� �Է��ϼ���) : ");

			scanf("%d", &stock_amount);

			while (getchar() != '\n');

			if (0 < stock_amount && stock_amount <= selectStock->GetAmount())
			{
				mPlayerMarket.SellStock(idx, stock_amount);
				printf("\n\n �ֽ��� �Ⱦҽ��ϴ�.");
			}

			else
			{
				printf("\n\n ��ȿ�� ���� �Է��߽��ϴ�.(������ ��� �ֽ� ���� ���Ϸ� �Է��Ͻʽÿ�)");
			}

			Sleep(1000);

			break;
		}

		key					= '\0';

		system("cls");
	}
}

void cGameManager::ShowStockList()
{
	int						stock_number;
	int						page;

	char					key;

	cStock					player_stock;

	system("cls");

	key						= '\0';
	page					= 1;

	player_stock			= cPlayer::GetInstance()->GetStock_info()->GetStock();

	if (cPlayer::GetInstance()->GetStock_info()->GetStockAmount() <= 0)
	{
		printf("\n �ֽ��� �����ϴ�.\n");
		Sleep(600);
	}

	else
	{
		/* ������ A, D, Q Ű�� �Է��մϴ�				*/
		/* �ֽ��� �� ������ �� 10�� �� ����մϴ�		*/
		/* AŰ�� �Է��ϸ� ���� �������� ����մϴ�		*/
		/* DŰ�� �Է��ϸ� ���� �������� ����մϴ�		*/
		/* QŰ�� �Է��ϸ� �� �ݺ����� �����մϴ�		*/
		while (key != 'Q' && key != 'q')
		{
			system("cls");
			titleLine("�ֽ� ��� ����");

			printf("\n [ A, D�� �� ���� �� �ֽ��ϴ�. ]\n\n");

			stock_number	= 1;

			/* �ֽ� ���Ḯ��Ʈ�� ��ȸ�ϸ鼭 ������ �ִ� ȸ�� �ֽ� ������ ����մϴ� */
			for (cNode *pNow = player_stock.GetHead()->GetNextNode(); pNow != NULL; pNow = pNow->GetNextNode())
			{
				if (stock_number >= page && stock_number < page + 10) /* �ֽ��� �� ������ �� 10���� ����մϴ�. */
					printf("\n %d. ȸ�� : %-20s, ���� : %d��, ���� : %d��",
						stock_number,
						cCompanyManager::GetInstance()->GetCompany(pNow->GetCompanyNumber())->GetCompanyName(),
						pNow->GetPrice(),
						pNow->GetAmount());

				stock_number++;
			}
			printf("\n ���ư����� Q�� ��������.\n");

			key = (char)_getch();

			if (key == 'D' || key == 'd')
			{
				page			+= 10;
			}

			else if (key == 'A' || key == 'a')
			{
				if (page > 10)
					page	-= 10;
			}
		}
	}

	system("cls");
}

void cGameManager::ShowStatistics()
{
	char key				= '\0';

	system("cls");

	titleLine("��  ��");
	printf("\n �ֽ��� ��ų� �� Ƚ�� : %d\n ���� ���� �� : %d��\n �ֽ� ���� : %d\n\n ���ư����� Enter�� ��������.\n", 
		cPlayer::GetInstance()->GetStock_info()->GetStockDealCount(),
		cPlayer::GetInstance()->GetMoney_info()->GetMoney(),
		cPlayer::GetInstance()->GetStock_info()->GetStockAmount());
	
	/* ���͸� �Է��ϸ� ���� */
	while (key != ENTER)
	{
		GetKey(&key);
	}

	system("cls");
}

}