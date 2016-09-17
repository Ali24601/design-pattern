#include <iostream>       // std::cout
#include <thread>         // std::thread
#include "singleton.h"
using namespace std;

void print_thread_id(int id) 
{
	Singleton &sig = Singleton::getInstance(id);
}

int main()
{
	std::thread threads[100];
	for (int i = 0; i<100; ++i)
		threads[i] = std::thread(print_thread_id, i + 1);

	for (auto& th : threads) th.join();

	return 0;
}