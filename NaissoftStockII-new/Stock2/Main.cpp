//
// Stock II
// (c) 2016~2018 Naissoft.
//

#include "GameFunctions.h"

int main(void)
{
	// ���� �Լ����� �ʱ� ���� �޴� ���� �� ���� ���� ��ü ó��.
	// TODO:: �޴�, ���� ���� ��ɺ� ĸ��ȭ �� Ŭ����ȭ �ʿ�.
	int menu, cnt, order;
	char c, pausemenu;

	system("title Stock 2 - �ֽ� ���� 2");

	system("mode con: cols=120 lines=40");

	startLogo();

	printMainMenu();
	scanf("%d", &menu);

	InitStock();
	init();
	cnt = month = day = hour = order = 0;

	// ���� �޴� ���� ��ƾ
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
	
	// ���� ���� ����
	drawNewspaper(companyOrder[order]);
	
	while (true)
	{	
		ShowMain();
		DrawGraph(companyOrder[order]);
		showCompanyReport(companyOrder[order]);
		
		if (Money <= 0)
		{
			printf("\n �Ļ�... 3000�� ������ �帮�ڽ��ϴ�.");
			getchar();
			Loan(3000);
			system("cls");
		}
		
		gotoxy(57, 10 + order - 1);
		printf("  ");
		gotoxy(57, 10 + order + 1);
		printf("  ");
		gotoxy(57, 10 + order);
		printf("��");

		c = '\0';
		getKey(&c);

		// �Է� ���� ���� �޴� ���� �� ó��
		switch (c)
		{
		case 'b':
		case 'B':
			BuyMenu(companyOrder[order]);
			break;
		case 'v':
		case 'V':
			ShowStockList();
			break;
		case 27:
			system("cls");
			titleLine("�Ͻ� ����");
			printf(" 1. ��  ��\n\n 2. ��  ��\n\n 3. ��  ��\n\n 4. ��  ��\n\n 5. ������\n\n Esc ���ư���");

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
				Payback();
				break;
			case '4':
				settingMenu();
				break;
			case '5':
				system("cls");
				printf("\n �����Ͻðڽ��ϱ�? ������� ���� ������ ������ϴ�.\n Y / N");
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
			SellMenu();
			break;
		case 'E':
		case 'e':
			system("cls");
			save();
			printf("\n ������ ����Ǿ����ϴ�.");
			Sleep(300);
			break;
		case 'W':
		case 'w':
			if (timemode == 1)
			{
				while (cnt % 20 != 0) cnt++;	// HACK:: �ݺ������� ���� ���� �ʿ��� �� ��ŭ �����༭ ���ǿ� ������Ű���� �Ѵ�.
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

		// HACK:: 1�ʿ� �ѹ��� ó���ϵ��� ������ �ʿ� ����.
		for (int i = 0; i < MAX_COMPANY; i++)
			PrevStockPrice[i] = StockPrice[i];

		if (cnt % 20 == 0)
		{
			// 1�ʿ� �ѹ��� ����.
			ChangeStockPrice();
			UpdateGraphData();
		}
		
		// 1�� = 1�ð�
		if (cnt % 20 == 0) hour++;
		
		// 3�ʿ� �ѹ��� �� ����
		if (cnt % 60 == 0) showTipNews();

		// ���� 1�ÿ� ȸ�翡 ���� ������ �ǰ� ����.
		if (hour == 1)
		{
			for (int i = 0; i < MAX_COMPANY; i++)
			{
				if (rand() % 2 == 0) ifGood[i] = true;
				else ifGood[i] = false;
			}
		}

		// �Ϸ簡 ������ ��� ó��
		if (hour > 23)
		{
			hour = 0;
			Interest();
			day++;
		}

		// �� ���� ������ ��� ó��
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
	DeallocateStock();
	return 0;
}
