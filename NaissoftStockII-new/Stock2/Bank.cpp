/*
* Bank.cpp
*
* ���� ���� ó�� (����, ��ȯ)
*
* Created on : 2018-05-02
*     Author : Jeong Ji-ung
*/
#include "global.h"

namespace GameSystem
{
	namespace Bank
	{

void cBank::init()
{
	mInter_rate				= DEFAULT_INTER_RATE;
}

bool cBank::Loan(cMoney_info* _money_info, int _loan)
{
	if (_money_info == nullptr)
	{
		printf("[Loan] money info is null\n");
		return false;
	}
	
	_money_info->SetLoan(_money_info->GetLoan() + _loan);
	_money_info->SetInterRate(mInter_rate);
	_money_info->SetMoney(_money_info->GetMoney() + _money_info->GetLoan());
	
	return true;
}

bool cBank::Payback(cMoney_info* _money_info, int _payback)
{
	if (_money_info == nullptr)
	{
		printf("[Payback] money info is null\n");
		return false;
	}

	if (_money_info->GetMoney() < _payback)
	{
		printf("�������� �����Ͽ� ������� ��ȯ�� �� �����ϴ�.\n");
		return false;
	}

	if (_money_info->GetLoan() < _payback)
	{
		// ���� �� ��ŭ�� ���� �� �ְ� ����.
		_payback			= _money_info->GetLoan();
	}

	_money_info->SetLoan(_money_info->GetLoan() - _payback);
	_money_info->SetMoney(_money_info->GetMoney() - _payback);

	return true;
}

void cBank::Proc_loan()
{
	int						loan_money;

	system("cls");
	
	//TODO:: ���� Ÿ��Ʋ���� ���� ���� Ŭ���� �߰� �Ǹ� �� �κ� ���� �ʿ�.
	//titleLine("��  ��");
	
	printf("\n �󸶸� ��������ðڽ��ϱ�?");
	scanf("%d", &loan_money);
	
	//Loan(cPlayer::GetInstance()->GetMoney_info(), loan_money);
}

void cBank::Proc_payback()
{
	//TODO:: ���� ���� ��ȯó�� ����, �ƴϸ� ���Ӱ� �������� ���� �ʿ�.
}

	}
}