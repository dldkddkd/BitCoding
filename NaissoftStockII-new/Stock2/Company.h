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

class cCompany
{
public:
	cCompany() {}
	virtual ~cCompany() {}
	
private:
	bool					mCompStatus;
	char					mCompanyName[32];
	int						mPrice;
	int						mPrevPrice;

public:
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
	void					init();
	
	void					SetCompanyInfo();

	cCompany				GetCompany(int _num);
	cCompany				GetCompany(char* _name);
};

	}
}