#include <iostream>
#include "singleton.h"
Singleton& Singleton::getInstance()
{
	if (NULL == m_instance)
	{
		m_instance = new Singleton;
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