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
	cDrawGame() {}
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
	cGameManager() {}
	virtual ~cGameManager() {}

private:
	int						mSelect;
	int						mSelectComp;

	cDrawGame				mDrawGame;

private:
	void					InitGame();

	void					SelectStartMenu();
	void					SelectGameMenu();
	void					SelectPauseMenu();

public:
	void					onStart();
};

}