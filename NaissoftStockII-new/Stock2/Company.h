/*
 * Company.h
 *
 * 회사 관련 데이터 및 처리
 *
 * Created on : 2018-05-01
 *     Author : Jeong Ji-ung
 */
#pragma once

namespace GameSystem
{

#define MAX_TIP				4
#define MAX_NEWS			5
#define MAX_HEADLINE		5
#define MAX_ARTICLE			3
#define MAX_COMPANY			10
#define COMPANY_NAME_SIZE	32

extern char gCompanyName[MAX_COMPANY][COMPANY_NAME_SIZE];

class cCompany
{
public:
	cCompany() {}
	virtual ~cCompany() {}
	
private:
	bool					mCompStatus;
	char					mCompanyName[COMPANY_NAME_SIZE];
	int						mPrice;
	int						mPrevPrice;

public:
	void					UpdatePrice();
	void					UpdateStatus();
	void					Update();

	void					SetCompanyStatus(bool _status);
	void					SetCompanyName(char* _name);
	void					SetPrice(int _price);			// 내부에서 Price와 PrevPrice 데이터 처리.

	bool					GetCompanyStatus();
	char*					GetCompanyName();
	int						GetPrice();
	int						GetPrevPrice();

	void					DrawNewspaper();
	void					PrintStockPrice();
};

class cCompanyManager : public Core::cSingleton<cCompanyManager>
{
public:
	cCompanyManager() {}
	virtual ~cCompanyManager() {}

private:
	int						mGraphData[MAX_COMPANY][48];
	cCompany				mCompany[MAX_COMPANY];

public:
	void					Init();
	void					UpdateAllCompanyStatus();
	void					UpdateAllCompanyPrice();
	void					UpdateGraphData();

	cCompany				GetCompany(int _num);

	void					DrawNewspaper(int _selectComp);
	void					ShowStockPrice(int _viewMode);
	void					DrawGraph(int _comp);
	void					ShowCompanyReport(int _comp);
};

}