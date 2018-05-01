/*
 * Singleton.cpp
 *
 * ΩÃ±€≈Ê ∆–≈œ
 *
 * Created on : 2018-05-01
 *     Author : Jeong Ji-ung
 */
#include "global.h"

namespace Core
{

	namespace DeignPattern
	{

template <class T>
T* cSingleton<T>::mpInstance	= nullptr;

template <class T>
T* cSingleton<T>::GetInstance()
{
	if (mpInstance == nullptr)
		mpInstance			= new T();

	return mpInstance;
}

	}

}