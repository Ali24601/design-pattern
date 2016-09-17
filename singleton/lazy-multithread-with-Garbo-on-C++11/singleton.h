#pragma once
class Singleton
{
private:
	static Singleton* m_instance;
	Singleton() {};
	//只需声明，无需实现
	Singleton(const Singleton &tmp);//声明为私有，避免类外调用默认的复制构造函数
	Singleton& operator =(const Singleton &tmp);//声明为私有，避免类外调用默认的赋值运算符

	class CGarbo // 它的唯一工作就是在析构函数中删除CSingleton的实例
	{
	public:
		~CGarbo();
	};
	// 声明一个静态成员，在程序结束时，系统会调用它的析构函数，
	//注意这里仅仅是声明，还需要在相应的cpp文件中对静态成员进行定义哦。
	static CGarbo Garbo;
public:
	static Singleton& getInstance(int i);
};