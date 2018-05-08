/*
* Company.cpp
*
* ȸ�� ���� ������ �� ó��
*
* Created on : 2018-05-02
*     Author : Jeong Ji-ung
*/
#include "global.h"

namespace GameSystem
{

char gCompanyName[MAX_COMPANY][COMPANY_NAME_SIZE] =
{
	"Naissoft",
	"HawTech",
	"�ϰܳ��",
	"MK Electronics",
	"���뱺��",
	"CJ ���ϼտ���",
	"KJS �ý���",
	"Fruit",
	"������ ���ͽ�",
	"�������",
};

void cCompany::UpdatePrice()
{
	// ȸ�� ���¿� ���� �ֽ� ���� ������Ʈ
	// ���� �ñ� : 1�ʿ� �ѹ�
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

	// �� ȸ���� �ֽ� ������ 2000 ���Ϸ� �������� �ʴ´�.
	if (mPrice < 2000)
		mPrice				= 2000;
	// ������ ���ڸ� ���� ����.
	mPrice					= mPrice / 10 * 10;
}

void cCompany::UpdateStatus()
{
	// ȸ�� ���� ������Ʈ.
	// ���� �ñ� : 24�ʿ� �ѹ�(���� �ð� ���� ���� 1��)
	if (rand() % 2 == 0) 
		mCompStatus			= true;
	else 
		mCompStatus			= false;
}

void cCompany::Update()
{
	UpdateStatus();
	UpdatePrice();
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
		mCompany[i].SetCompanyName(gCompanyName[i]);
		mCompany[i].SetCompanyStatus(true);
		mCompany[i].SetPrice(9000);
	}
}

void cCompanyManager::UpdateAllCompany()
{
	// ��� ȸ�� ���� ������Ʈ.
	// ���� �ñ� : 1�ʿ� �ѹ�
	for (int i = 0; i < MAX_COMPANY; i++)
		mCompany[i].Update();
}

cCompany cCompanyManager::GetCompany(int _num)
{
	return mCompany[_num];
}

}