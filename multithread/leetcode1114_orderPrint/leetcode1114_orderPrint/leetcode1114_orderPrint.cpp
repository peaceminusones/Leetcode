#include <iostream>
#include <vector>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <functional>
using namespace std;

class Foo
{
	mutex m_mutex;
	condition_variable m_cond;
	bool m_flag1;
	bool m_flag2;

public:
	Foo()
	{
		m_flag1 = false;
		m_flag2 = false;
	}

	void first(function<void()> printFisrt)
	{
		unique_lock<mutex> lock(m_mutex);
		printFisrt();
		m_flag1 = true;
		m_cond.notify_all();
	}

	void second(function<void()> printSecond)
	{
		unique_lock<mutex> lock(m_mutex);
		while (!m_flag1)
		{
			m_cond.wait(lock);
		}
		printSecond();
		m_flag2 = true;
		m_cond.notify_all();
	}

	void third(function<void()> printThrird)
	{
		unique_lock<mutex> lock(m_mutex);
		while (!m_flag2)
		{
			m_cond.wait(lock);
		}
		printThrird();
	}
};

void printfirst()
{
	cout << "printfirst" << endl;
}

void printsecond()
{
	cout << "printsecond" << endl;
}

void printthird()
{
	cout << "printthird" << endl;
}

int main()
{
	// 输入调用顺序
	vector<int> nums;
	int item;
	for (int i = 0; i < 3; i++)
	{
		cin >> item;
		nums.push_back(item);
	}

	Foo foo;
	thread threads[3];
	
	//类成员函数需要绑定该类的this指针  
	threads[0] = thread(&Foo::first, &foo, &printfirst);
	threads[1] = thread(&Foo::second, &foo, &printsecond);
	threads[2] = thread(&Foo::third, &foo, &printthird);

	// 按照nums中的输入顺序调用
	for (auto n : nums)
		threads[n - 1].join();

	return 0;
}