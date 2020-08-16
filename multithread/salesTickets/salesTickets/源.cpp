#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <chrono>
using namespace std;

condition_variable cv;
mutex mutx;

int ticket = 100;
bool isruning = true;

void consumer1(int id)
{
	while (ticket > 0)
	{
		this_thread::sleep_for(chrono::microseconds(100));
		// 管理锁的模板类，声明一个局部的lock_guard对象，在其构造函数中进行加锁
		// 出了该对象作用域的时候解锁
		lock_guard<mutex> lck(mutx);
		if (ticket > 0)
		{
			int x = (rand() % (10 - 1)) + 1;
			if (x > ticket)
				x = ticket;
			cout << "售票窗口[" << id << "]" << endl;
			ticket -= x;
			cout << "售出 " << x << "票" << endl;
			cout << "剩余 " << ticket << "票" << endl;
		}
		else
		{
			cout << "售票窗口[" << id << "]" << endl;
			cout << "票已售完......" << endl;
		}
	}
}

void consumer2(int id)
{
	while (ticket > 0)
	{
		this_thread::sleep_for(chrono::microseconds(100));
		// 管理锁的模板类，声明一个局部的lock_guard对象，在其构造函数中进行加锁
		// 出了该对象作用域的时候解锁
		lock_guard<mutex> lck(mutx);
		if (ticket > 0)
		{
			int x = (rand() % (10 - 1)) + 1;
			if (x > ticket)
				x = ticket;
			cout << "售票窗口[" << id << "]" << endl;
			ticket -= x;
			cout << "售出 " << x << "票" << endl;
			cout << "剩余 " << ticket << "票" << endl;
		}
		else
		{
			cout << "售票窗口[" << id << "]" << endl;
			cout << "票已售完......" << endl;
		}
	}
}

int main()
{
	cout << "main thread: " << this_thread::get_id() << endl;
	cout << "总票数为：" << ticket << endl;
	thread threads[2];
	threads[0] = thread(consumer1, 1);
	threads[1] = thread(consumer2, 2);
	threads[0].join();
	threads[1].join();
	/*for (int i = 0; i < 5; i++)
		threads[i] = thread(consumer1, i + 1);
	for (int i = 0; i < 5; i++)
		threads[i].join();*/
	cout << "it's over...." << endl;
	return 0;
}