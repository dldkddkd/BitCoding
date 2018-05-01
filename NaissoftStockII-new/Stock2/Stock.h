/*
* Header file : Stock.h
* Author : Naissoft
* Stock �ڷᱸ�� ���� ���� ����Ʈ
* Remark : 2018.04.29 ������.
*
*/

struct Stock
{
	int price;
	int company;
	bool ifChecked;

	Stock *next;
	Stock *prev;
};

extern Stock *gHead, *gNow, gTmp;

void InitStock();

Stock *InsertStock(Stock *Target, Stock *aStock);

bool DeleteStock(Stock *Target);

void AppendStock(Stock);

Stock *FindStock(int);

void DeallocateStock();
