#pragma once
class Singleton
{
private:
	static Singleton* m_instance;
	Singleton() {};
	//ֻ������������ʵ��
	Singleton(const Singleton &tmp);//����Ϊ˽�У������������Ĭ�ϵĸ��ƹ��캯��
	Singleton& operator =(const Singleton &tmp);//����Ϊ˽�У������������Ĭ�ϵĸ�ֵ�����

	class CGarbo // ����Ψһ��������������������ɾ��CSingleton��ʵ��
	{
	public:
		~CGarbo();
	};
	// ����һ����̬��Ա���ڳ������ʱ��ϵͳ�������������������
	//ע���������������������Ҫ����Ӧ��cpp�ļ��жԾ�̬��Ա���ж���Ŷ��
	static CGarbo Garbo;
public:
	static Singleton& getInstance(int i);
};