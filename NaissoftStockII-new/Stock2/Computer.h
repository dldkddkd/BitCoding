#pragma once
namespace GameSystem {
	extern struct ComStock comStock[10];
	extern int computer_money;
	class cComputer {

	public:
		void setComMoney(int);
		int  getComMoney();
		void Init();
		void ComputerBuyStock();
		void ComputerSellStock();
	};
}