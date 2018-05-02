/*
* Company.cpp
*
* 회사 관련 데이터 및 처리
*
* Created on : 2018-05-02
*     Author : Jeong Ji-ung
*/
#include "global.h"

namespace GameSystem
{
	namespace Company
	{

void cCompany::SetCompanyStatus(bool _status)
{
	mCompStatus				= _status;
}

void cCompany::SetCompanyName(char* _name)
{
	strcpy(mCompanyName, _name);
}

void cCompany::SetPrice(int _price)
{
	mPrevPrice				= mPrice;
	mPrice					= _price;
}

bool cCompany::GetCompanyStatus()
{
	return mCompStatus;
}

char* cCompany::GetCompanyName()
{
	return mCompanyName;
}

int cCompany::GetPrice()
{
	return mPrice;
}

int cCompany::GetPrevPrice()
{
	return mPrevPrice;
}

	}
}