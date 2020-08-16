#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
using namespace std;

class ZeroEvenOdd
{
private:
	int n;
	bool zero_flag;
	bool odd_flag;
	mutex m_mutex;
	condition_variable m_cond;

public:
	ZeroEvenOdd(int n)
	{
		this->n = n;
		zero_flag = true;
		odd_flag = true;
	}

	// 打印0
	void zero(function<void(int)> printNumber)
	{
		for (int i = 0; i < n; i++)
		{
			unique_lock<mutex> lock(m_mutex);
			// 如果不可以带你0，则等待
			while (!zero_flag)
				m_cond.wait(lock);
			printNumber(0);
			zero_flag = false;
			m_cond.notify_all();
		}
	}

	// 打印偶数
	void even(function<void(int)> printNumber)
	{
		for (int i = 2; i <= n; i += 2)
		{
			unique_lock<mutex> lock(m_mutex);
			// 如果可以打印0，或者可以打印奇数，则等待
			while (zero_flag || odd_flag)
				m_cond.wait(lock);
			printNumber(i);
			zero_flag = true;
			odd_flag = true;
			m_cond.notify_all();
		}
	}

	// 打印奇数
	void odd(function<void(int)> printNumber)
	{
		for (int i = 1; i <= n; i += 2)
		{
			unique_lock<mutex> lock(m_mutex);
			// 如果可以打印0，或者不可以打印奇数，则等待
			while (zero_flag || !odd_flag)
				m_cond.wait(lock);
			printNumber(i);
			zero_flag = true;
			odd_flag = false;
			m_cond.notify_all();
		}
	}
};


void print(int i)
{
	cout << i << endl;
}

int main()
{
	int n;
	cin >> n;
	ZeroEvenOdd zeo(n);

	thread t1(bind(&ZeroEvenOdd::zero, &zeo, &print));
	thread t2(bind(&ZeroEvenOdd::odd, &zeo, &print));
	thread t3(bind(&ZeroEvenOdd::even, &zeo, &print));

	t1.join();
	t2.join();
	t3.join();


	return 0;
}



/* 信号量实现 ==========================================================================*/

//#include <iostream>
//#include <thread>
//#include <mutex>
//#include <condition_variable>
//#include <functional>
//using namespace std;
//
//class semaphore
//{
//private:
//	int count;  // 等待线程数量
//	mutex m_mutex; // 互斥锁
//	condition_variable m_cond; // 条件变量
//
//public:
//	semaphore(int value = 0) :count(value) {}
//
//	void wait()
//	{
//		unique_lock<mutex> lock(m_mutex);
//		if (--count < 0) // 资源不足，挂起线程
//		{
//			m_cond.wait(lock);
//		}
//	}
//
//	void signal()
//	{
//		// if (++count <= 0) 说明count在++之前<0，而count的初始值，也即信号量的值为无符号数，只可能>=0。
//		// 那么<0的情况也只可能是因为先调用了wait。因此，便可以确定此时有线程在等待，故可以调用notify_one了。
//		unique_lock<mutex> lock(m_mutex);
//		if (++count <= 0) // 有线程挂起，唤醒一个
//			m_cond.notify_all();
//	}
//
//};
//
///*
//	桌子有一只盘子，只允许放一个水果，父亲专向盘子放苹果，母亲专向盘子放桔子 儿子专等吃盘子的桔子，女儿专等吃盘子的苹果。
//	只要盘子为空，父亲或母亲就可以向盘子放水果， 仅当盘子有自己需要的水果时，儿子和女儿可从盘子取出。
//	请给出四个人之间的同步关系，并用 pv操作实现四个人的正确活动的问题。
//*/
//
//semaphore plate(1), apple(0), orange(0);
//
//int n = 10;
//int i = 0;
//
//void father()
//{
//	while (i < 10)
//	{
//		plate.wait();
//		cout << "往盘子中放一个苹果" << endl;
//		i++;
//		apple.signal();
//	}
//}
//
//void mother()
//{
//	while (i < 10)
//	{
//		plate.wait();
//		cout << "往盘子中放一个橘子" << endl;
//		i++;
//		orange.signal();
//	}
//}
//
//void son()
//{
//	while (i < 10)
//	{
//		apple.wait();
//		cout << "儿子吃苹果" << endl;
//		i++;
//		plate.signal();
//	}
//}
//
//void daughter()
//{
//	while (i < 10)
//	{
//		orange.wait();
//		cout << "女儿吃橘子" << endl;
//		i++;
//		plate.signal();
//	}
//}
//
//int main()
//{
//	thread f(father), m(mother), s(son), d(daughter);
//	f.join();
//	m.join();
//	s.join();
//	d.join();
//
//	return 0;
//}
//
