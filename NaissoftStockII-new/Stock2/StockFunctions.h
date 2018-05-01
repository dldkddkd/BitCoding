/*
* Header file : StockFunctions.h
* Stock ��� �Լ� ����
* Remark : 2018.04.29 ������.
* 
*/
 
#include "Arts.h"

#define DEF_STOCK 9000
#define DEF_MONEY 500000000
#define MAX_COMPANY 10

extern int companyOrder[MAX_COMPANY];
extern int GraphData[MAX_COMPANY][48];

void ChangeStockPrice();

void ShowStockPrice(int);

void PrintStockPrice(int);

void Loan(int);

void Interest();

void Payback();

void BuyStock(int, int);

void SellStock(int);

void ShowStockList();

void UpdateGraphData();