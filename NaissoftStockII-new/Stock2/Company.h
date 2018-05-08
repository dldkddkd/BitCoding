/*
 * Company.h
 *
 * ȸ�� ���� ������ �� ó��
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
	void					SetPrice(int _price);			// ���ο��� Price�� PrevPrice ������ ó��.

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