#pragma once

namespace GameSystem 
{
class cMarket
{
public:
	cMarket() {};
	virtual ~cMarket() {};

public:
	virtual bool					BuyStock(int order, int amount) = 0;
	virtual void					SellStock(int indexStock, int amount) = 0;
	
};

class cPlayerMarket : public cMarket
{
public:
	cPlayerMarket() {};
	virtual ~cPlayerMarket() {};

public:
	bool					BuyStock(int order, int amount);
	void					SellStock(int indexStock, int amount);

};
}

