/*
* Data.h
*
* Data ���� save, load
*
* Created on : 2018-05-18
*     Author : Jeong Ji-ung
*/
#pragma once

namespace Core
{

class cData : public cSingleton<cData>
{
public:
	//TODO:: cData�۾� �ʿ�
	void					Save();
	void					Load();
};

}