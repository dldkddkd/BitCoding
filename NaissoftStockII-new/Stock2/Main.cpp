//
// Stock II
// (c) 2016~2018 Naissoft.
//

#include "GameFunctions.h"

int main(void)
{
	// 메인 함수에서 초기 게임 메뉴 선택 및 게임 루프 전체 처리.
	// TODO:: 메뉴, 게임 루프 기능별 캡슐화 및 클래스화 필요.
	int menu, cnt, order;
	char c, pausemenu;

	system("title Stock 2 - 주식 게임 2");

	system("mode con: cols=120 lines=40");

	startLogo();

	printMainMenu();
	scanf("%d", &menu);

	InitStock();
	init();
	cnt = month = day = hour = order = 0;

	// 게임 메뉴 선택 루틴
	switch (menu)
	{
	case 1:
		ChangeStockPrice();
		save();
		break;
	case 2:
		load();
		break;
	case 3:
		exit(0);
		break;
	default:
		break;
	}

	system("cls");
	
	// 게임 루프 시작
	drawNewspaper(companyOrder[order]);
	
	while (true)
	{	
		ShowMain();
		DrawGraph(companyOrder[order]);
		showCompanyReport(companyOrder[order]);
		
		if (Money <= 0)
		{
			printf("\n 파산... 3000원 대출해 드리겠습니다.");
			getchar();
			loan(3000);
			system("cls");
		}
		
		gotoxy(57, 10 + order - 1);
		printf("  ");
		gotoxy(57, 10 + order + 1);
		printf("  ");
		gotoxy(57, 10 + order);
		printf("◀");

		c = '\0';
		getKey(&c);

		// 입력 값에 따른 메뉴 선택 및 처리
		switch (c)
		{
		case 'b':
		case 'B':
			buyMenu(companyOrder[order]);
			break;
		case 'v':
		case 'V':
			showStockList();
			break;
		case 27:
			system("cls");
			titleLine("일시 정지");
			printf(" 1. 통  계\n\n 2. 대  출\n\n 3. 갚  기\n\n 4. 설  정\n\n 5. 끝내기\n\n Esc 돌아가기");

			pausemenu = (char)_getch();
			
			switch (pausemenu)
			{
			case '1':
				showStats();
				break;
			case '2':
				loanMenu();
				break;
			case '3':
				payback();
				break;
			case '4':
				settingMenu();
				break;
			case '5':
				system("cls");
				printf("\n 종료하시겠습니까? 저장되지 않은 정보는 사라집니다.\n Y / N");
				char ch;
				ch = (char)_getch();
				if (ch == 'Y' || ch == 'y') return 0;
				break;
			case 27:
				break;
			default:
				break;
			}
			system("cls");
			Sleep(100);
			break;
		case 's':
		case 'S':
			sellMenu();
			break;
		case 'E':
		case 'e':
			system("cls");
			save();
			printf("\n 게임이 저장되었습니다.");
			Sleep(300);
			break;
		case 'W':
		case 'w':
			if (timemode == 1)
			{
				while (cnt % 20 != 0) cnt++;	// HACK:: 반복문으로 증가 말고 필요한 값 만큼 더해줘서 조건에 만족시키도록 한다.
				cnt += 20;
				Sleep(100);
			}
			break;
		case 'I':
		case 'i':
			showCompanyInfo();
			break;
		case '2':
			if (order < MAX_COMPANY - 1) order++;
			drawNewspaper(companyOrder[order]);
			break;
		case '8':
			if (order > 0) order--;
			drawNewspaper(companyOrder[order]);
			break;
		default:
			break;
		}

		// HACK:: 1초에 한번만 처리하도록 수정할 필요 있음.
		for (int i = 0; i < MAX_COMPANY; i++)
			PrevStockPrice[i] = StockPrice[i];

		if (cnt % 20 == 0)
		{
			// 1초에 한번식 진입.
			ChangeStockPrice();
			UpdateGraphData();
		}
		
		// 1초 = 1시간
		if (cnt % 20 == 0) hour++;
		
		// 3초에 한번씩 팁 갱신
		if (cnt % 60 == 0) showTipNews();

		// 매일 1시에 회사에 대한 전문가 의견 변경.
		if (hour == 1)
		{
			for (int i = 0; i < MAX_COMPANY; i++)
			{
				if (rand() % 2 == 0) ifGood[i] = true;
				else ifGood[i] = false;
			}
		}

		// 하루가 지났을 경우 처리
		if (hour > 23)
		{
			hour = 0;
			interest();
			day++;
		}

		// 한 달이 지났을 경우 처리
		if (day > days[month] - 1)
		{
			day = 0;
			month++;
			Money -= TAX(Money);
		}
		if (month > 11) month = 0;

		if (timemode == 0)
		{
			clearbuffer();
			Sleep(DELAY);
			cnt++;
		}
		else if (timemode == 1)
		{
			clearbuffer();
			Sleep(DELAY);
		}
	}
	getchar();
	UnInitStock();
	return 0;
}
