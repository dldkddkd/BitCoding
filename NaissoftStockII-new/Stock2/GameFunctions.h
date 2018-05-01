/*
Header file : GameFunctions.h
Game ��� ���� �Լ� �� ������ ����.
Remark : 2018.04.16 ������.

2018-04-21 ������.
TODO:: �ش� ������� ���� �ִ� ��� �Լ��� Ŭ����ȭ �ʿ�.
	   ����ġ�� ���� �������� ���� �� �밡���� ǥ����� ���� �̸� ���� �ʿ�.
	   ������ ���� �����Ͽ� �ϳ��� ��ü�� ���� ���� ���� ����.
*/

#include "Stock.h"
#include "StockFunctions.h"

#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>

#define DELAY 50

#define MAX_TIP 4
#define MAX_NEWS 5
#define MAX_HEADLINE 5
#define MAX_ARTICLE 3

#define TAX(money) (30000 + ((money) / 100))

extern FILE input, output;
extern int month, day, hour, achour;
extern char *Tips[MAX_TIP], *GoodNews[MAX_NEWS], *BadNews[MAX_NEWS];
extern int days[12];

extern int StockPrice[MAX_COMPANY], PrevStockPrice[MAX_COMPANY], Stocks, StockDeal, loanMoney;
extern unsigned long Money;
extern bool ifGood[MAX_COMPANY];
extern char *CompanyName[MAX_COMPANY];
extern Stock *gHead, *gHow, gTmp;

extern int viewmode, timemode;

// 2018-04-21 ������.
// TODO:: �Ʒ� �Լ����� �÷��̾� ���� �Լ��̹Ƿ� ���� Ŭ������ ����� ������ ����.
//		  cPlayerManager
void showStats();

void loanMenu();

// 2018-04-21 ������.
// TODO:: �Ʒ� �Լ����� ���� �ý���(Game Loop)���� ������μ�, ���� Ŭ������ ����� ������ ����.
//		  cGameLoopManager
void init();

void load();

void save();

void settingMenu();

void ShowMain();

void showTipNews();


// 2018-04-21 ������.
// TODO:: �ش� �Լ��� Lib.h�� �̵��� ����.
void getKey(char *);

// 2018-04-21 ������.
// TODO:: �ֽ� ����, �Ǹ�, ���� ���� �Լ���.
//		  ���� �Ʒ� �Լ����� Ŭ����ȭ �Ͽ� ����.
//		  cCompanyStockManager
void BuyMenu(int);

void SellMenu();

void showCompanyInfo();

void showCompanyReport(int);

void drawNewspaper(int);

void DrawGraph(int);