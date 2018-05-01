#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>

#include "StockFunctions.h"
#include "Stock.h"

unsigned long Money;
int StockPrice[MAX_COMPANY], PrevStockPrice[MAX_COMPANY], Stocks, StockDeal, loanMoney, companyOrder[MAX_COMPANY];
int GraphData[MAX_COMPANY][48] = { 0 };
bool ifGood[MAX_COMPANY];

// Listed Companies
char *CompanyName[MAX_COMPANY] =
{
	"Naissoft",
	"HawTech",
	"�ϰܳ��",
	"MK Electronics",
	"���뱺��",
	"CJ ���ϼտ���",
	"KJS �ý���",
	"Fruit",
	"������ ���ͽ�",
	"�������",
};

/** Change each company's stock price
* ���� ȸ�� ��Ȳ�� ���ٸ� (ifGood) 50% Ȯ���� 0 ~ 1000 �� �����մϴ�
* �ƴϸ� 50% Ȯ���� 0 ~ 100�� �����մϴ�.
* ���� ȸ�� ��Ȳ�� �����ٸ� (ifBad) 50% Ȯ���� 0 ~ 500 �� �����մϴ�
* �ƴϸ� 50% Ȯ���� 0 ~ 1000�� �����մϴ�.
*
* @return void
*/
void ChangeStockPrice()
{
	// ȸ���� ���¿� ���� �������� �̿��Ͽ� �ֽ� ���� ������ ����.
	srand((int)time(NULL));

	for (int i = 0; i < MAX_COMPANY; i++)
	{
		if (ifGood[i] == true)
		{
			if ((rand() % 2) == 0)
			{
				StockPrice[i] += (rand() % 1000);
			}
			else
			{
				StockPrice[i] -= (rand() % 100);
			}
		}
		else
		{
			if ((rand() % 2) == 0)
			{
				StockPrice[i] += (rand() % 500);
			}
			else
			{
				StockPrice[i] -= (rand() % 1000);
			}
		}
		if (StockPrice[i] < 2000) /* �� ȸ���� �ֽ� ������ 2000���Ϸ� �� �������ϴ� */
			StockPrice[i] = 2000;
		StockPrice[i] = StockPrice[i] / 10 * 10; /* ������ ���ڸ� ���� ���� �մϴ� */
	}
}

/** Draw stock price on console
*
* @param mode
* Mode is view mode
* ���� ��尡 0�̸� ���ӿ��� ������ ������ �ֽ� ������ ����մϴ�
* ���� ��尡 1�̸� ������������ �����Ͽ� �ֽ� ������ ����մϴ�
* ���� ��尡 2�̸� ������������ �����Ͽ� �ֽ� ������ ����մϴ�
*
* @return void
*/
void ShowStockPrice(int mode)
{
	int order[MAX_COMPANY];
	int temp;

	if (mode == 0)
	{
		for (int i = 0; i < MAX_COMPANY; i++)
		{
			PrintStockPrice(i);
			companyOrder[i] = i;
		}
		return;
	}

	for (int i = 0; i < MAX_COMPANY; i++) 
		order[i] = StockPrice[i];

	if (mode == 1)
	{
		/* Sort in ascending order */
		for (int i = 0; i < MAX_COMPANY; i++)
		{
			for (int j = 0; j < MAX_COMPANY; j++)
			{
				if (order[i] > order[j])
				{
					temp = order[i];
					order[i] = order[j];
					order[j] = temp;
				}
			}
		}
		for (int i = 0; i < MAX_COMPANY; i++)
		{
			for (int j = 0; j < MAX_COMPANY; j++)
			{
				if (order[i] == StockPrice[j])
				{
					PrintStockPrice(j);
					order[i] = 0;
					companyOrder[i] = j;
				}
			}
		}
	}
	if (mode == 2)
	{
		/* Sort in descending order */
		for (int i = 0; i < MAX_COMPANY; i++)
		{
			for (int j = 0; j < MAX_COMPANY; j++)
			{
				if (order[i] < order[j])
				{
					temp = order[i];
					order[i] = order[j];
					order[j] = temp;
				}
			}
		}
		for (int i = 0; i < MAX_COMPANY; i++)
		{
			for (int j = 0; j < MAX_COMPANY; j++)
			{
				if (order[i] == StockPrice[j])
				{
					PrintStockPrice(j);
					order[i] = 0;
					companyOrder[i] = j;
				}
			}
		}
	}
}

/** ȸ�� �ֽ��� ����մϴ�
* ���� ����, ���� ���ݰ� ���� ���� ���̸� ����մϴ�
*
* @param indexOfCompany
* Index of company's array
*
* @return void
*/
void PrintStockPrice(int indexOfCompany)
{
	int diffOfPrice;

	printf(" ȸ�� : ");
	if (ifGood[indexOfCompany])
	{
		textcolor(10);
		printf("%-20s", CompanyName[indexOfCompany]);
		textcolor(7);
	}
	else 
	{
		textcolor(12);
		printf("%-20s", CompanyName[indexOfCompany]);
		textcolor(7);
	}
	printf(" �� ���� : %5d��  ", StockPrice[indexOfCompany]);

	diffOfPrice = StockPrice[indexOfCompany] - PrevStockPrice[indexOfCompany];
	if (diffOfPrice > 0)
	{
		textcolor(2);
		printf("��%4d�� ", diffOfPrice);
		textcolor(7);
	}
	else if(diffOfPrice < 0)
	{
		textcolor(14);
		printf("��%4d�� ", -1 * diffOfPrice);
		textcolor(7);
	}
	printf("\n");
}

/** �����մϴ�
*
* @param lmoney
* loan money
*
* @return void
*/
void Loan(int lmoney)
{
	loanMoney += lmoney;
	Money += lmoney;
}

/** ��ȯ �ݾ��� ���ڸ�ŭ �����մϴ�
* ���ڴ� 5%�Դϴ�
*
* @return void
*/
void Interest()
{
	loanMoney += (int)((double)loanMoney * 0.05);
}

/** ������ ��ȯ�մϴ�
*
* @return void
*/
void Payback()
{
	// TODO:: �ݾ��� ���ڶ� ��쿡�� ������ �������� ������, ���� -�� �Ǿ����. ���� �ʿ�.
	if (Money >= loanMoney)
	{
		Money -= loanMoney;
		loanMoney = 0;
	}
}

/** Buy stocks and insert into the stock linked list to save user's stocks
* �ֽ��� ��� ������ �ֽĵ��� �����ϱ� ���� �ֽ� ���Ḯ��Ʈ�� �����մϴ�
*
* @param order
* Company number to identify companies
*
* @param amount
* Amount of stocks
*
* @return void
*/
void BuyStock(int order, int amount)
{
	Stock temp;

	/* ������ �� �ֽ� ������ŭ �ݺ��մϴ�											*/
	/* ������ ����� �ֽ� ���ݺ��� ũ�� �ֽ��� �ϳ��� �缭 ���Ḯ��Ʈ�� �߰��մϴ�	*/
	/* ������ ���� �ֽ� ���ݺ��� ������ ���� �ʽ��ϴ�								*/
	for (int i = 0; i < amount; i++)
	{
		if (StockPrice[order] <= (int)Money)
		{
			system("cls");
			gNow = gHead;

			temp.company = order;
			temp.price = StockPrice[order];
			gNow = InsertStock(gNow, &temp);

			Stocks++;
			StockDeal++;
			printf(" %d���� �ְ� ��° �ֽ��� �����Ͽ����ϴ�. �ֽ��� %d���Դϴ�.\n"
				, StockPrice[order], Stocks);
			Money -= StockPrice[order];
			printf(" ���� ���� %d���Դϴ�.\n", Money);
		}
		else
		{
			printf(" ���� �����մϴ�. �ֽ��� �� �� �����ϴ�.\n");
		}
	}
}

/** Sell a stock and delete it on list
*
* @param indexOfStock
* index of the list of stocks the user wants to sell
*
* @return void
*/
void SellStock(int indexOfStock)
{
	Stock *saleStock = FindStock(indexOfStock - 1);
	if (saleStock == NULL) 
		return;
	
	Money += (StockPrice[saleStock->company]);
	DeleteStock(saleStock);
	
}

/** Show list of stocks that user has
*
* @return void
*/
void ShowStockList(void)
{
	int numberOfStocks;
	int listPage; /* �� ������ �� 10���� �ֽ��� ����մϴ�. */
	char key = '\0';

	system("cls");

	listPage = 1;
	if (Stocks <= 0)
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
		while (key != 'Q' || key != 'q')
		{
			system("cls");
			titleLine("�ֽ� ��� ����");

			printf("\n [ A, D�� �� ���� �� �ֽ��ϴ�. ]\n\n");

			numberOfStocks = 1;
			/* �ֽ� ���Ḯ��Ʈ�� ��ȸ�ϸ鼭 ������ �ִ� ȸ�� �ֽ� ������ ����մϴ� */
			for (gNow = gHead->next; gNow != NULL; gNow = gNow->next)
			{
				if (numberOfStocks >= listPage && numberOfStocks < listPage + 10) /* �ֽ��� �� ������ �� 10���� ����մϴ�. */
					printf("\n %d. ȸ�� : %-20s, ���� : %d��"
						, numberOfStocks, CompanyName[gNow->company], gNow->price);

				numberOfStocks++;
			}
			printf("\n ���ư����� Q�� ��������.\n");

			key = getch();
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

/** �ֽ� �׷����� �����͸� ������Ʈ�մϴ�
*
* @return void
*/
void UpdateGraphData()
{
	for (int i = 0; i < MAX_COMPANY; i++)
	{
		for (int j = 46; j >= 0; j--)
		{
			GraphData[i][j + 1] = GraphData[i][j];
		}
		GraphData[i][0] = StockPrice[i];
	}
}
