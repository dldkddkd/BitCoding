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
		mStockViewMode		= 0;
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
	void					SelectSettingMenu();

	void					GetKey(char* c);

	void					BuyMenu();
	void					SellMenu();

	void					ShowStockList();

	void					ShowStatistics();

public:
	cDrawGame				GetDrawGame();

	void					onStart();

};

}
