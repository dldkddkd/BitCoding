/*
* Data.h
*
* Data 관련 save, load
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
	//TODO:: cData작업 필요
	void					Save();
	void					Load();
};

}