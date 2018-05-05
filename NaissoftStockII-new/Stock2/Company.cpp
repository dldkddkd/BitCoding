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
void cCompany::UpdatePrice()
{
	// 회사 상태에 따른 주식 가격 업데이트
	// 진입 시기 : 1초에 한번
	mPrevPrice				= mPrice;

	if (mCompStatus == true)
	{
		if ((rand() % 2) == 0)
			mPrice			+= (rand() % 1000);
		else
			mPrice			-= (rand() % 100);
	}
	else
	{
		if ((rand() % 2) == 0)
			mPrice			+= (rand() % 500);
		else
			mPrice			-= (rand() % 1000);
	}

	// 각 회사의 주식 가격은 2000 이하로 떨어지지 않는다.
	if (mPrice < 2000)
		mPrice				= 2000;
	// 가격의 일자리 수는 내림.
	mPrice					= mPrice / 10 * 10;
}

void cCompany::UpdateStatus()
{

}

void cCompany::Update()
{

}

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

void cCompanyManager::Init()
{
	for (int i = 0; i < MAX_COMPANY; i++)
	{
		mCompany[i].SetCompanyName(CompanyName[i]);
		mCompany[i].SetCompanyStatus(true);
		mCompany[i].SetPrice(9000);
	}
}

void cCompanyManager::UpdateAllCompany()
{

}

cCompany cCompanyManager::GetCompany(int _num)
{
	return mCompany[_num];
}

	}
}