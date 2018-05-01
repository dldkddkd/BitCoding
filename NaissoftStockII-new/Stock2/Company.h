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
	cCompany();
	virtual ~cCompany();
	
private:
	bool					mIfGood;
	char					mCompanyName[32];
	int						mPirce;
	int						mPrevPrice;

public:
	void					SetIfGood(bool _ifGood);
	void					SetCompanyName(char* _name);
	void					SetPrice(int _price);			// 내부에서 Price와 PrevPrice 데이터 처리.

	bool					GetIfGood();
	char*					GetCompanyName();
	int						GetPrice();
	int						GetPrevPrice();
};

class cCompanyManager : public Core::cSingleton<cCompanyManager>
{
public:
	cCompanyManager();
	virtual ~cCompanyManager();

private:
	cCompany				mCompany[MAX_COMPANY];

public:
	void					init();

	cCompany				GetCompany(int _num);
	cCompany				GetCompany(char* _name);
};

	}
}