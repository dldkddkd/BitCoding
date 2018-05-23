/*
* Bank.cpp
*
* 은행 관련 처리 (대출, 상환)
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
		printf("소지금이 부족하여 대출금을 상환할 수 없습니다.\n");
		return false;
	}

	if (_money_info->GetLoan() < _payback)
	{
		// 빌린 돈 만큼만 갚을 수 있게 설정.
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
	
	titleLine("대  출");
	printf("\n 얼마를 대출받으시겠습니까?");
	scanf("%d", &loan_money);
	
	Loan(cPlayer::GetInstance()->GetMoney_info(), loan_money);
}

void cBank::Proc_payback()
{
	//TODO:: 기존 대출 상환처럼 할지, 아니면 새롭게 구현할지 논의 필요.

	int						payback_money;

	system("cls");

	titleLine("상  환");
	printf("\n 얼마를 상환 하시겠습니까?");
	scanf("%d", &payback_money);

	while (getchar() != '\n');

	Payback(cPlayer::GetInstance()->GetMoney_info(), payback_money);

}

}