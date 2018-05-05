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
	namespace Company
	{

#define MAX_COMPANY			10
#define COMPANY_NAME_SIZE	32

char CompanyName[MAX_COMPANY][COMPANY_NAME_SIZE] =
{
	"Naissoft",
	"HawTech",
	"암겨농업",
	"MK Electronics",
	"폭펭군수",
	"CJ 제일손연재",
	"KJS 시스템",
	"Fruit",
	"수배자 모터스",
	"기야조선",
};

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
};

class cCompanyManager : public Core::cSingleton<cCompanyManager>
{
public:
	cCompanyManager() {}
	virtual ~cCompanyManager() {}

private:
	cCompany				mCompany[MAX_COMPANY];

public:
	void					Init();
	void					UpdateAllCompany();

	cCompany				GetCompany(int _num);
};

	}
}