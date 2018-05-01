/*
* Header file : Stock.h
* Author : Naissoft
* Stock 자료구조 이중 연결 리스트
* Remark : 2018.04.29 조경제.
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
