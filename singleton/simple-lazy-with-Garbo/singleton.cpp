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
		//测试发现，多线程下，这里不能给Singleton::m_instance赋空，
		//否则子进程会调用getInstance()，重新new一个Singleton又不能释放
}
Singleton* Singleton::m_instance = NULL;
Singleton::CGarbo Singleton::Garbo;
