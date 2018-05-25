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

void cBank::Init()
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
	_money_info->SetInterest(mInter_rate);
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

	if (_payback >= 0) 
	{
		_money_info->SetLoan(_money_info->GetLoan() - _payback);
		_money_info->SetMoney(_money_info->GetMoney() - _payback);
	}
	return true;
}

void cBank::Proc_loan()
{
	int						loan_money;

	system("cls");
	
	titleLine("��  ��");
	printf("\n �󸶸� ��������ðڽ��ϱ�?");
	scanf("%d", &loan_money);
	
	Loan(cPlayer::GetInstance()->GetMoney_info(), loan_money);
}

void cBank::Proc_payback()
{
	int						payback_money;

	system("cls");

	titleLine("��  ȯ");
	printf("\n ���ƾ� �� �ݾ��� %d�� ���ҽ��ϴ�",
		cPlayer::GetInstance()->GetMoney_info()->GetLoan());
	printf("\n �󸶸� ��ȯ �Ͻðڽ��ϱ�?(��� : 0) ");

	scanf("%d", &payback_money);

	while (getchar() != '\n');

	Payback(cPlayer::GetInstance()->GetMoney_info(), payback_money);

}

}