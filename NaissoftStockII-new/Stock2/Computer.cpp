#include "Computer.h"
#include "Company.h"
#pragma once;
namespace GameSystem {
	struct ComStock {
		int amount;
		int company;
		int price;
	};
	struct ComStock comStock[10];
	int computer_money = 5000000;

	void cComputer::Init() {
		for (int i = 0; i < 10; i++) {
			comStock[i].amount = 0;
			comStock[i].company = i;
			comStock[i].price = 0;
		}
	}
	void cComputer::setComMoney(int _money) {
		computer_money = _money;
	}
	int cComputer::getComMoney() {
		return computer_money;
	}
	void cComputer::ComputerBuyStock() {
		int i, j = -1, max = 0;


		//전날 대비 최대 가격 상승한 주식 찾기
		for (i = 0; i < 10; i++) {
			GameSystem::cCompanyManager::GetInstance()->mCompany[i];
			if (GetStockPrice(i) - GetPrevStockPrice(i) > max) {
				max = GetStockPrice(i) - GetPrevStockPrice(i);
				j = i;
			}
		}

		//돈이 없으면 컴퓨터는 자동으로 구매 취소
		if ((GetStockPrice(j) > computer_money) || (j < 0))
			return;

		//여기서 comStock[j].company변수는 컴퓨터가 그 회사의 주식을 산 개수를 의미함
		comStock[j].amount = computer_money / GetStockPrice(j);

		//컴퓨터가 산 주식의 당시 가격을 저장
		comStock[j].price = GetStockPrice(j);

		//구매한 비용만큼 컴퓨터가 가진 비용 차감
		setComMoney(computer_money - GetStockPrice(j) * comStock[j].amount);
		return;
	}
	void cComputer::ComputerSellStock() {
		int i;

		//컴퓨터가 산 주식 중에 이득을 조금이라도 봤거나
		//10%이상 손해가 나면 바로 판매
		//그 이외의 조건은 그대로 진행
		for (i = 0; i < 10; i++) {

			if ((comStock[i].price < GetStockPrice(i)) || (comStock[i].price * 9 / 10 >= GetStockPrice(i))) {
				setComMoney(computer_money + GetStockPrice(i) * comStock[i].amount);
				comStock[i].amount = 0;
				comStock[i].price = 0;
			}
		}
		return;
	}
}