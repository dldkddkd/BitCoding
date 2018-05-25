/*
 * Singleton.cpp
 *
 * ΩÃ±€≈Ê ∆–≈œ
 *
 * Created on : 2018-05-01
 *     Author : Jeong Ji-ung
 */
namespace Core
{

template <typename T>
T* cSingleton<T>::mpInstance	= nullptr;

template <typename T>
T* cSingleton<T>::GetInstance()
{
	if (mpInstance == nullptr)
		mpInstance			= new T();

	return mpInstance;
}

}