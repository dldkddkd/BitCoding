#pragma once

namespace GameSystem
{
class cMarket
{
public:
	cMarket() {};
	virtual ~cMarket() {};

public:
	bool					BuyStock(int order, int amount);
	void					SellStock(int indexStock, int amount);
	
};

}

