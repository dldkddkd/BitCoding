/*
 * Header file : GameFunctions.h
 * Game 기능 관련 함수 및 디파인 선언.
 * Created by Jeong Ji-ung on 2018-05-01.
 *
 * 2018-04-21 정지웅.
 * TODO:: 해당 헤더파일 내에 있는 모든 함수들 클래스화 필요.
 *	      지나치게 많은 전역변수 제거 및 헝가리안 표기법에 의한 이름 변경 필요.
 *	      옵저버 패턴 적용하여 하나의 객체로 게임 루프 관리 예정.
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

// 2018-04-21 정지웅.
// TODO:: 아래 함수들은 플레이어 관련 함수이므로 따로 클래스로 만들어 관리할 예정.
//		  cPlayerManager
void showStats();

void loanMenu();

// 2018-04-21 정지웅.
// TODO:: 아래 함수들은 게임 시스템(Game Loop)적인 기능으로서, 따로 클래스로 만들어 관리할 예정.
//		  cGameLoopManager
void init();

void load();

void save();

void settingMenu();

void ShowMain();

void showTipNews();


// 2018-04-21 정지웅.
// TODO:: 해당 함수는 Lib.h로 이동할 예정.
void getKey(char *);

// 2018-04-21 정지웅.
// TODO:: 주식 구매, 판매, 정보 관련 함수들.
//		  추후 아래 함수들을 클래스화 하여 관리.
//		  cCompanyStockManager
void BuyMenu(int);

void SellMenu();

void showCompanyInfo();

void showCompanyReport(int);

void drawNewspaper(int);

void DrawGraph(int);