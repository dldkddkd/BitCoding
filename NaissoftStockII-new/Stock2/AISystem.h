/*
* AISystem.h
*
* AI ���� ó��. ������ �º��ϴ� �ΰ�����
*
* Created on : 2018-05-25
*     Author : Jeong Ji-ung
*/
#pragma once

namespace GameSystem
{

class cAIPlayer : public cPlayData, public Core::cSingleton<cAIPlayer>
{
public:
	cAIPlayer()
	{

	}

	virtual ~cAIPlayer()
	{

	}

private:

public:
	void					onUpdate();

};

}