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


		//���� ��� �ִ� ���� ����� �ֽ� ã��
		for (i = 0; i < 10; i++) {
			GameSystem::cCompanyManager::GetInstance()->mCompany[i];
			if (GetStockPrice(i) - GetPrevStockPrice(i) > max) {
				max = GetStockPrice(i) - GetPrevStockPrice(i);
				j = i;
			}
		}

		//���� ������ ��ǻ�ʹ� �ڵ����� ���� ���
		if ((GetStockPrice(j) > computer_money) || (j < 0))
			return;

		//���⼭ comStock[j].company������ ��ǻ�Ͱ� �� ȸ���� �ֽ��� �� ������ �ǹ���
		comStock[j].amount = computer_money / GetStockPrice(j);

		//��ǻ�Ͱ� �� �ֽ��� ��� ������ ����
		comStock[j].price = GetStockPrice(j);

		//������ ��븸ŭ ��ǻ�Ͱ� ���� ��� ����
		setComMoney(computer_money - GetStockPrice(j) * comStock[j].amount);
		return;
	}
	void cComputer::ComputerSellStock() {
		int i;

		//��ǻ�Ͱ� �� �ֽ� �߿� �̵��� �����̶� �ðų�
		//10%�̻� ���ذ� ���� �ٷ� �Ǹ�
		//�� �̿��� ������ �״�� ����
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