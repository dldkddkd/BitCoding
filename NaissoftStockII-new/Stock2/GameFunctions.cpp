#include "GameFunctions.h"

int month, day, hour, achour;

int viewmode, timemode;

char *Tips[MAX_TIP] =
{
	"�ְ��� �� �� �ż��ϰ� ��� �� �ŵ��ؼ� ������ ������!",
	"������ ���� ���� ���� �Ǿ����!",
	"1�޸��� ������ ���ϴ�. ��� ��ٸ��ٰ� �Ļ��� �� ������ �����ϼ���!",
	"���� ȸ���� �ֽ��� �� �� �ֽ��ϴ�. ȸ�� ����� Ȯ���ϼ���!",
};

char *GoodNews[MAX_NEWS] =
{
	"�� �� ��ǰ, �α���� ��",
	"�� ������ �̲� �� CEO�� �濵ö��...",
	"�� �������� �� ����",
	", ȯ�� �޵����� �ְ� ����",
	"�� �ܱ����� ��Ը� ���ڷ� ȣ��",
};

char *BadNews[MAX_NEWS] =
{
	"�� �� ��ǰ �� ����... CEO ���� ����",
	", ���� �߼��δ� �����ϴ� - ������ �м�",
	"�� ����... �ñ��� ��å ���� �ʿ�",
	", ȯ���� ���� �ɰ��� ����",
	" �ֽ� ����.. �ܱ��� ��Ը� �ŵ��� �ְ� �޶�",
};

char *Infos[MAX_COMPANY] =
{
	" Naissoft�� ��Ī ���ѹα� �ִ� �Ը��� ����Ʈ���� ���� ��ü�Դϴ�.\n ��ƿ��Ƽ, ���� �� ���� ���� ���α׷����� �����ϰ� ����.",
	" HawTech�� Naissoft�� ������� �̷�� ����Ʈ���� ��ü�Դϴ�.",
	" �ϰܳ���� �������� �� ����� �̽��� �۹��� ������ �����ϰ� ��ǰ�� ����� ȸ���Դϴ�.\n Ư���� �̸��� ȸ�� �����ÿ� ������ ����.\n �ֱ��� ���� �� ��ⱸ�� �����ϰ� �ִ�ϴ�.",
	" MK Electronics�� ������ǰ ���� ȸ���Դϴ�.\n TV, PC, ����Ʈ��, ����� ���� ��������.",
	" ���뱺���� ���� ���� ���� ��ü�Դϴ�.\n �̸���� ��ź�� �ַ� �����ϴ� ȸ�翹��.",
	" CJ ���ϼտ���� �н�Ʈ Ǫ�� ��ü�Դϴ�.\n �տ���� ���� ��(��), ��ġ ��(��), �� ��(�) ��,\n �׻� �Դ� ��ġ�� �������� ���̶�� �ǹ̶��ϴ�.",
	" KJS �ý����� ���, ������ ����Ʈ��� �����ϴ� ȸ���Դϴ�.\n �ַ� ���� �ӽ�, ������ ���� ���� ������.",
	" Fruit�� ������ ����� ��� ȸ���Դϴ�.\n �º�, ����Ʈ��, ����Ʈ ��ġ ���� �����ϰ� �־��.\n Grand Theft Auto V�⿡ �⿬�� ���� �ִ�ϴ�.",
	" ������ ���ͽ��� �ڵ����� ����/�����ϴ� ��ü�Դϴ�.\n �������� ������ ���� ���̸�, ������ �ڵ��� ȸ���� ���� ���Դϴ�.",
	" ����������� ��߱׷� ������ �߰��� ȸ���, �踦 ����� ȸ����ϴ�.",
};

char *goodHeadline[MAX_HEADLINE] =
{
	", ���� ���� ������ ��",
	"��(��) ���� �츰��",
	", ������ �����ϳ�",
	" �濵������ ������ ����",
	" �ְ� ������� ��",
};

char *badHeadline[MAX_HEADLINE] =
{
	" ���� ��ȭ ����",
	", ��¼�� �̷��� �Ƴ�",
	" �ְ� �޶��� ��",
	" ��Ȳ, �� ��������",
	", �̴�� ���ٰ� �Ļ�",
};

char *goodArticle[MAX_ARTICLE] = 
{
	"��(��) ���� ���� ������\n\
����ϰ� �ִ�. ���� �������� ���ͺ信 \n\
�� �谩�� �ؽ´� �濵�а� �������� \"\n\
���� ��������� ����쳪 ���� ���弼��\n\
��� ������ ��\"�̶�� �亯�ߴ�. �� �� \n\
���� ȯ���� ��� ȸ�� ���� ���� ������\n\
������ ���忡 �ۿ��ߴٰ� �����ϰ� �ִ�",
	
	"�� ����ǰ�� ū �α⸦\n\
���� �ִ�. �� �� ����� �� ��ǰ�� ȸ\n\
�� �濵������ �ݴ븦 �������� �����  \n\
ǰ�̴�. ���� �ʹݺ��� ������ �������� \n\
����� ��Ÿ���� ȸ���� ��ǥ �𵨷� �� \n\
���ű��ϴ� ���̴�.",

	"��(��)\n���� ������ �����̴�.\n\
ڸ �Һ��ڴ�ü NSC�� ���� ��� �ٸ� ȸ \n\
����� ��� ��ġ�� ������ ���� 1����  \n\
�޼��Ͽ�����, �̿� ���� �Ǹŷ��� ���� \n\
�� �þ�� �ִ�. �̷� �߼���� �� �� \n\
�� ���嵵 ����� �� ���� ������ ������\n\
��.",
};

int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

void init()
{
	Money = DEF_MONEY;
	for (int i = 0; i < MAX_COMPANY; i++) StockPrice[i] = 9000;
	for (int i = 0; i < MAX_COMPANY; i++) ifGood[i] = true;
	Stocks = StockDeal = 0;
	loanMoney = 0;
	ChangeStockPrice();
	hour++;
	viewmode = timemode = 0;
}

void ShowMain()
{
	gotoxy(0, 1);
	printf(" Stock II - Naissoft �ֽ� ���� 2\n ver �� 1.3.0128\n\n B ���, S �ȱ�, V ���, E ����, I ȸ�� ����, 8 / 2 ȸ�� ����, Esc �޴�");
	if (timemode == 1) printf("\n W ��ٸ���");
	gotoxy(0, 5);
	printf("\n ���� �� �� : %d��, ���ƾ� �� �� : %d��\n\n\n\n", Money, loanMoney);

	ShowStockPrice(viewmode);

	printf("\n %d�� %d�� %d��", month + 1, day + 1, hour);
	printf("\n\n �̹� �� ������ ������ %d���Դϴ�. %d�� ���ҽ��ϴ�.\n", TAX(Money), days[month] - day);
}

void load()
{
	int stocks = 0;
	Stock tmp;

	FILE *save = fopen("save.ns3", "rb");
	if (save == NULL)
	{
		init();
		return;
	}

	fscanf(save, "%d ", &stocks);
	stocks = _rotr(stocks, 1);

	for (int i = 0; i < stocks; i++)
	{
		gNow = gHead;

		fscanf(save, "%d %d ", &tmp.company, &tmp.price);
		tmp.company = _rotr(tmp.company, 1); tmp.price = _rotr(tmp.price, 1);
		InsertStock(gNow, &tmp);
	}

	for (int i = 0; i < MAX_COMPANY; i++)
	{
		fscanf(save, "%d ", &StockPrice[i]);
		StockPrice[i] = _rotr(StockPrice[i], 1);
	}

	for (int i = 0; i < MAX_COMPANY; i++)
	{
		fscanf(save, "%d ", &ifGood[i]);
		ifGood[i] = _rotr(ifGood[i], 1);
	}

	fscanf(save, "%d %d %d %d %d %d %d %d %d", &Money, &loanMoney, &Stocks, &StockDeal, &month, &day, &hour, &viewmode, &timemode);
	Money = _rotr(Money, 1); loanMoney = _rotr(loanMoney, 1); Stocks = _rotr(Stocks, 1);
	StockDeal = _rotr(StockDeal, 1); month = _rotr(month, 1); day = _rotr(day, 1); hour = _rotr(hour, 1);

	fclose(save);
}

void save()
{
	int stocks = 0;
	FILE *save = fopen("save.ns3", "wb");

	for (gNow = gHead->next; gNow; gNow = gNow->next) stocks++;
	fprintf(save, "%d ", _rotl(stocks, 1));

	for (gNow = gHead->next; gNow; gNow = gNow->next)
		fprintf(save, "%d %d ", _rotl(gNow->company, 1), _rotl(gNow->price, 1));

	for (int i = 0; i < MAX_COMPANY; i++)
		fprintf(save, "%d ", _rotl(StockPrice[i], 1));

	for (int i = 0; i < MAX_COMPANY; i++)
		fprintf(save, "%d ", _rotl(ifGood[i], 1));

	fprintf(save, "%d %d %d %d %d %d %d %d %d", _rotl(Money, 1), _rotl(loanMoney, 1), _rotl(Stocks, 1), _rotl(StockDeal, 1),
		_rotl(month, 1), _rotl(day, 1), _rotl(hour, 1), viewmode, timemode);

	fclose(save);
}

void showTipNews()
{
	gotoxy(0, 8);
	for (int i = 0; i < 80; i++) printf(" ");
	gotoxy(0, 8);
	if (rand() % 4 == 0)
		printf(" �� : %s", Tips[rand() % MAX_TIP]);
	else
	{
		int comp = rand() % MAX_COMPANY;
		if (ifGood[comp] == true) printf(" NEWS : %s%s", CompanyName[comp], GoodNews[rand() % MAX_NEWS]);
		else printf(" NEWS : %s%s", CompanyName[comp], BadNews[rand() % MAX_NEWS]);
	}
}

/** Move a stock buy menu to buy stocks
*
* @param order
* Company number to identify companies
*
* @return void
*/
void BuyMenu(int order)
{
	// HACK:: �������μ��� ���� �ʿ�. ������ ���� �ݺ����� ���鼭 �ϳ��� �����ϰ� ����.
	int amountOfStocks;

	system("cls");
	titleLine("�ֽ� ���");

	printf(" ���� %s ȸ���� �ְ��� %d���Դϴ�.\n\n �� ���� �����Ͻðڽ��ϱ�? (��� : 0)"
		, CompanyName[order], StockPrice[order]);

	scanf("%d", &amountOfStocks);
	if (amountOfStocks > 0)
	{
		BuyStock(order, amountOfStocks);
		printf("\n\n �����Ͽ����ϴ�.");
		Sleep(2000);
	}
	system("cls");
	return;
}

/** Move a stock sell menu to sell stocks
*
* @return void
*/
void SellMenu()
{
	int idx;
	int numberOfStocks;
	int listPage;
	int profitOnSale;
	char key;
	Stock *selectStock;

	key = '\0';
	listPage = idx = 1;
	system("cls");

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

		numberOfStocks = 1;
		/* �ֽ� ���Ḯ��Ʈ�� ��ȸ�ϸ鼭 ������ �ִ� ȸ�� �ֽ� ������ ����մϴ� */
		for (gNow = gHead->next; gNow != NULL; gNow = gNow->next)
		{
			/* �ֽ��� �� ������ �� 10���� ����մϴ�. */
			if (numberOfStocks >= listPage && numberOfStocks < listPage + 10)
				printf("\n %d. ȸ�� : %-20s, ���� : %d��"
					, numberOfStocks, CompanyName[gNow->company], gNow->price);

			numberOfStocks++;
		}
		printf("\n ���ư����� Q�� ��������.\n");

		selectStock = FindStock(idx - 1);
		if (selectStock == NULL) {
			system("cls");
			return;
		}

		profitOnSale = StockPrice[selectStock->company] - selectStock->price;
		printf("\n [ ���� �ֽ� ���� ]\n\n ��ȣ : %d\n ȸ�� : %s\n ���� : %d\n ���� ���� : %d\n �ŵ� ���� : %d"
			, idx, CompanyName[selectStock->company]
			, selectStock->price, StockPrice[selectStock->company]
			, profitOnSale);

		key = getch();

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
			SellStock(idx);
			break;
		}

		key = '\0';
		system("cls");
	}
}

void showStats()
{
	system("cls");
	titleLine("��  ��");
	printf("\n �ֽ��� ��ų� �� Ƚ�� : %d\n ���� ���� �� : %d��\n �ֽ� ���� : %d\n\n ���ư����� Enter�� ��������.\n", StockDeal, Money, Stocks);
	getchar();
	system("cls");
}

void getKey(char *c)
{
	if (!timemode)
	{
		if (_kbhit()) *c = (char)_getch();
	}
	else *c = (char)_getch();
}

void settingMenu()
{
	char select;
	system("cls");
	titleLine("��  ��");
	printf(" 1. ���� ��� ��ȯ\n 2. �ð� �帧 ��� ��ȯ\n Esc ���ư���");
	
	select = (char)_getch();

	switch (select)
	{
	case '1':
		viewmode++;
		if (viewmode > 2) viewmode = 0;
		switch (viewmode)
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
		timemode++;
		if (timemode > 1) timemode = 0;
		switch (timemode)
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

void loanMenu()
{
	int loanmoney;

	system("cls");
	titleLine("��  ��");
	printf("\n �󸶸� ��������ðڽ��ϱ�?");
	scanf("%d", &loanmoney);
	Loan(loanmoney);

	return;
}

void showCompanyInfo()
{
	int i = 0;
	char ch = '\0';

	system("cls");
	while (ch != 27)
	{
		system("cls");
		titleLine("ȸ�� ����");

		gotoxy(0, 5);
		printf(" %d / %d. W, S Ű�� �Ѱ� �� �� �ֽ��ϴ�. Esc�� ������\n ȸ�� : %s\n\n", i + 1, MAX_COMPANY, CompanyName[i]);
		printf("%s", Infos[i]);

		ch = (char)_getch();

		switch (ch)
		{
		case 'W':
		case 'w':
			if (i < MAX_COMPANY - 1) i++;
			break;
		case 'S':
		case 's':
			if (i > 0) i--;
			break;
		}
	}
	system("cls");
}

void DrawGraph(int company)
{
	// ���� ���� �� �ֽ� ���� ��ȭ ����
	gotoxy(0, 25);
	printf(" 24000                                                                     \n 22000                                                                     \n 20000                                                                     "
		"\n 18000                                                                     \n 16000                                                                     \n 14000                                                                     "
		"\n 12000                                                                     \n 10000                                                                     \n  8000                                                                     "
		"\n  6000                                                                     \n  4000                                                                     \n  2000                                                                     \n                                                                              ");
	gotoxy(7, 46);

	int j = 0;
	for (int i = 47; i >= 0; i--)
	{
		if (GraphData[company][i] > 0 && GraphData[company][i] < 26000)
		{
			gotoxy(7 + j, 36 - ((int)((GraphData[company][i] % 26000) / 2000) - 1));
			if (GraphData[company][i] < 2000) printf("v");
			else printf("*");
			j++;
		}
		else if (GraphData[company][i] >= 26000)
		{
			gotoxy(7 + j, 36 - ((int)(((GraphData[company][i] - 2000) % 24000) / 2000)));
			if ((GraphData[company][i] - 2000) / 24000 + 1 > 9) printf("+");
			else printf("%d", (GraphData[company][i] - 2000) / 24000 + 1);
			j++;
		}
	}
}

void showCompanyReport(int company)
{
	for (int i = 2; i < 7; i++)
	{
		gotoxy(75, i);
		printf("                     ");
	}
	gotoxy(75, 2);
	printf("ȸ�� : %s", CompanyName[company]);
	gotoxy(75, 4);
	printf("���� �ְ� : %d��", StockPrice[company]);
	gotoxy(75, 6);
	printf("������ �ǰ� : %s", ifGood[company] ? "������" : "������");
}

void drawNewspaper(int comp)
{
	// ���õ� ȸ���� ���� ���. ȸ�� ���¿� ���� �������� ������ �ٸ���.
	textcolor(112);
	
	for (int i = 0; i < 25; i++)
	{
		gotoxy(75, 10 + i);
		for (int j = 0; j < 40; j++) _putch(' ');
	}
	
	gotoxy(88, 12);
	printf("��  �  ��  ��     %d�� %d��", month + 1, day + 1);
	gotoxy(76, 13);
	printf("��������������������������������������������������������������������������");
	
	textcolor(15);
	gotoxy(76, 14);
	
	if (ifGood[comp] == true) printf(" %s%s ", CompanyName[comp], goodHeadline[rand() % MAX_HEADLINE]);
	else printf(" %s%s ", CompanyName[comp], badHeadline[rand() % MAX_HEADLINE]);
	
	textcolor(112);
	gotoxy(76, 16);
	if (ifGood[comp] == true)
	{
		int i = 0;
		int articleNo = rand() % MAX_ARTICLE;
		int cnt = 0;
		printf(" %s", CompanyName[comp]);
		while (goodArticle[articleNo][i] != '\0')
		{
			if (goodArticle[articleNo][i] == '\n')
			{
				cnt++;
				gotoxy(76, 16 + cnt);
			}
			else putchar(goodArticle[articleNo][i]);
			i++;
		}
	}
	
	textcolor(7);
}
