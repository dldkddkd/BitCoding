/*
 * GameManager.h
 *
 * 霸烙 风橇 包访 贸府
 *
 * Created on : 2018-05-01
 *     Author : Jeong Ji-ung
 */
#pragma once

namespace GameSystem
{

class cDrawGame
{
public:
	cDrawGame() 
	{
<<<<<<< HEAD
		mStockViewMode		= 0;
=======
		mStockViewMode = 0;
>>>>>>> add_stock_system
	}
	virtual ~cDrawGame() {}

private:
	int						mStockViewMode;

public:
	void					ShowMain();

	void					SetStockViewMode(int _mode);
	int						GetStockViewMode();
};

class cGameManager : public Core::cSingleton<cGameManager>
{
public:
	cGameManager() 
	{
		mSelect				= '\0';
		mSelectComp			= 0;
	}
	virtual ~cGameManager() {}

private:
	char					mSelect;
	int						mSelectComp;

	cDrawGame				mDrawGame;

	cPlayerMarket			mPlayerMarket;
	
private:
	void					InitGame();

	void					SelectStartMenu();
	void					SelectGameMenu();
	void					SelectPauseMenu();

	void					GetKey(char* c);

	void					BuyMenu();
	void					SellMenu();

	void					ShowStockList();

	void					ShowStatistics();

public:
	void					onStart();
};

}
