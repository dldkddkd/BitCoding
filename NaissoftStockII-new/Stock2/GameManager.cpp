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
		BuyMenu();
		break;

	case 'v':
	case 'V':
		ShowStockList();
		break;

	case 27:
		system("cls");
		titleLine("일시 정지");
		printf(" 1. 통  계\n\n 2. 대  출\n\n 3. 갚  기\n\n 4. 설  정\n\n 5. 끝내기\n\n Esc 돌아가기");

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
		//save();
		printf("\n 게임이 저장되었습니다.");
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
		printf("\n 종료하시겠습니까? 저장되지 않은 정보는 사라집니다.\n Y / N");

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
			printf("\n 파산... 3000원 대출해 드리겠습니다.");
			getchar();
			cBank::GetInstance()->Loan(cPlayer::GetInstance()->GetMoney_info(), 3000);
			system("cls");
		}

		gotoxy(57, 10 + mSelectComp - 1);
		printf("  ");
		gotoxy(57, 10 + mSelectComp + 1);
		printf("  ");
		gotoxy(57, 10 + mSelectComp);
		printf("◀");

		SelectGameMenu();

		cTimer::GetInstance()->Update();
	}
}

void cGameManager::BuyMenu()
{
	int amountOfStocks;

	bool deal;

	system("cls");
	titleLine("주식 사기");

	printf(" 현재 %s 회사의 주가는 %d원입니다.\n\n 몇 개를 구입하시겠습니까? (취소 : 0)"
		, cCompanyManager::GetInstance()->GetCompany(mSelectComp).GetCompanyName(), cCompanyManager::GetInstance()->GetCompany(mSelectComp).GetPrice());

	scanf("%d", &amountOfStocks);

	while (getchar() != '\n');

	if (amountOfStocks > 0)
	{
		deal = mPlayerMarket.BuyStock(mSelectComp, amountOfStocks);

		if (deal)
			printf("\n\n 구입하였습니다.");
		
		else
			printf("\n\n 구입하지 못했습니다");

		Sleep(2000);
	
	}

	system("cls");
	return;
}

void cGameManager::SellMenu()
{
	int idx;
	int numberOfStocks;
	int listPage;
	int profitOnSale;
	int amount;

	char key;

	cNode *selectStock;
	cNode *pNow;
	key = '\0';
	listPage = idx = 1;
	system("cls");

	if (cPlayer::GetInstance()->GetStock_info()->GetStockNumber() <= 0)
	{
		printf("\n 주식이 없습니다.\n");
		Sleep(600);

		system("cls");
		return;
	}

	/* 유저는 A, D, W, S, B, Q 키를 입력합니다					*/
	/* 주식은 한 페이지 당 10개 씩 출력합니다						*/
	/* A키를 입력하면 이전 페이지를 출력합니다						*/
	/* D키를 입력하면 다음 페이지를 출력합니다						*/
	/* W키를 입력하면 현재 선택한 주식 위의 주식을 선택합니다		*/
	/* S키를 입력하면 현재 선택한 주식 아래의 주식을 선택합니다		*/
	/* B키를 입력하면 선택한 주식 판매합니다						*/
	/* Q키를 입력하면 이 반복문을 중지합니다						*/
	while (true)
	{
		titleLine("주식 팔기");
		printf("\n [ W / S로 팔 주식을 고르세요. A / D로 더 볼 수 있습니다. B를 누르면 팝니다. ]\n\n");

		numberOfStocks = 1;

		/* 주식 연결리스트를 순회하면서 가지고 있는 회사 주식 가격을 출력합니다 */
		for (pNow = cPlayer::GetInstance()->GetStock_info()->GetStock().GetHead()->GetNextNode(); pNow != NULL; pNow = pNow->GetNextNode())
		{
			/* 주식을 한 페이지 당 10개씩 출력합니다. */
			/* Format: (idx) 회사 : (회사이름), 가격 : (주식가격)원 */
			if (numberOfStocks >= listPage && numberOfStocks < listPage + 10)
				printf("\n %d. 회사 : %-20s, 가격 : %d원, 개수 : %d개",
					numberOfStocks, 
					cCompanyManager::GetInstance()->GetCompany(pNow->GetCompanyNumber()).GetCompanyName(),
					pNow->GetPrice(), 
					pNow->GetAmount());

			numberOfStocks++;
		}

		printf("\n 돌아가려면 Q를 누르세요.\n");

		selectStock = cPlayer::GetInstance()->GetStock_info()->GetStock().SearchNode(idx - 1);

		if (selectStock == NULL) {
			system("cls");
			return;
		}

		profitOnSale = cCompanyManager::GetInstance()->GetCompany(selectStock->GetCompanyNumber()).GetPrice()
			- selectStock->GetPrice();

		printf("\n [ 선택 주식 정보 ]\n\n 번호 : %d\n 회사 : %s\n 가격 : %d\n 현재 가격 : %d\n 매도 이익 : %d",
			idx,
			cCompanyManager::GetInstance()->GetCompany(selectStock->GetCompanyNumber()).GetCompanyName(),
			selectStock->GetPrice(),
			cCompanyManager::GetInstance()->GetCompany(selectStock->GetCompanyNumber()).GetPrice(),
			profitOnSale);

		key = (char)_getch();

		switch (key)
		{
		case 'A':
		case 'a':
			if (listPage > 10)
				listPage -= 10;
			break;

		case 'D':
		case 'd':
			listPage += 10;
			break;

		case 'W':
		case 'w':
			if (idx > 1)
				idx--;
			break;

		case 'S':
		case 's':
			if (idx < numberOfStocks)
				idx++;
			break;

		case 'Q':
		case 'q':
			system("cls");
			return;

		case 'B':
		case 'b':
			printf("\n\n 매도할 주식 개수(숫자를 입력하세요) : ");
			scanf("%d", &amount);

			while (getchar() != '\n');

			if (0 < amount && amount <= selectStock->GetAmount())
			{
				mPlayerMarket.SellStock(idx, amount);
				printf("\n\n 주식을 팔았습니다.");
			}
			else
			{
				printf("\n\n 무효한 값을 입력했습니다.(가지고 계신 주식 개수 이하로 입력하십시오)");
			}
			Sleep(1000);
			break;
		}

		key = '\0';
		system("cls");
	}
}

void cGameManager::ShowStockList()
{
	int numberOfStocks;
	int listPage; /* 한 페이지 당 10개의 주식을 출력합니다. */
	char key = '\0';

	system("cls");

	listPage = 1;
	if (cPlayer::GetInstance()->GetStock_info()->GetStockNumber() <= 0)
	{
		printf("\n 주식이 없습니다.\n");
		Sleep(600);
	}
	else
	{
		/* 유저는 A, D, Q 키를 입력합니다				*/
		/* 주식은 한 페이지 당 10개 씩 출력합니다		*/
		/* A키를 입력하면 이전 페이지를 출력합니다		*/
		/* D키를 입력하면 다음 페이지를 출력합니다		*/
		/* Q키를 입력하면 이 반복문을 중지합니다		*/
		while (key != 'Q' && key != 'q')
		{
			system("cls");
			titleLine("주식 목록 보기");

			printf("\n [ A, D로 더 보실 수 있습니다. ]\n\n");

			numberOfStocks = 1;
			/* 주식 연결리스트를 순회하면서 가지고 있는 회사 주식 가격을 출력합니다 */
			for (cNode *pNow = cPlayer::GetInstance()->GetStock_info()->GetStock().GetHead()->GetNextNode(); pNow != NULL; pNow = pNow->GetNextNode())
			{
				if (numberOfStocks >= listPage && numberOfStocks < listPage + 10) /* 주식을 한 페이지 당 10개씩 출력합니다. */
					printf("\n %d. 회사 : %-20s, 가격 : %d원, 개수 : %d개",
						numberOfStocks,
						cCompanyManager::GetInstance()->GetCompany(pNow->GetCompanyNumber()).GetCompanyName(),
						pNow->GetPrice(),
						pNow->GetAmount());

				numberOfStocks++;
			}
			printf("\n 돌아가려면 Q를 누르세요.\n");

			key = (char)_getch();
			if (key == 'D' || key == 'd')
			{
				listPage += 10;
			}
			else if (key == 'A' || key == 'a')
			{
				if (listPage > 10)
					listPage -= 10;
			}
		}
	}
	system("cls");
}
}