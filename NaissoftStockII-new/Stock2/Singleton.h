/*
 * Singleton.h
 *
 * ΩÃ±€≈Ê ∆–≈œ
 *
 * Created on : 2018-05-01
 *     Author : Jeong Ji-ung
 */
#pragma once

namespace Core
{

	namespace DeignPattern
	{

template <class T>
class cSingleton
{
public:
	cSingleton() {}
	virtual ~cSingleton()
	{
		if (mpInstance != nullptr)
			delete this;
	}

private:
	static T*				mpInstance;

public:
	static T*				GetInstance();
};

	}

}