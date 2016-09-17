#include <iostream>
#include <mutex>          // std::mutex
#include "singleton.h"
std::mutex mtx;           // mutex for critical section
Singleton& Singleton::getInstance(int i)
{
	if (NULL == m_instance)
	{
		mtx.lock();
		if (NULL == m_instance)
		{
			m_instance = new Singleton;
#ifdef _DEBUG
			std::cout << "Thread "<<i<<" "<<"Init"<<' '<<m_instance << std::endl;
#endif //_DEBUG
		}	
		else
#ifdef _DEBUG
			std::cout << "Thread " << i << " " << "Get-In" << ' ' << m_instance << std::endl;
#endif //_DEBUG
		mtx.unlock();
	}
	return *m_instance;
}
Singleton::CGarbo::~CGarbo()
{
	if (Singleton::m_instance)
		delete Singleton::m_instance;
}
Singleton* Singleton::m_instance = NULL;
Singleton::CGarbo Singleton::Garbo;