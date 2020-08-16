#include <iostream>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <thread>
using namespace std;

class FooBar
{
private:
	int n;
	int flag;
	mutex m_mutex;
	condition_variable m_cond;

public:
	FooBar(int n)
	{
		this->n = n;
		flag = 0;
	}

	void foo(function<void()> printFoo)
	{
		for (int i = 0; i < n; i++)
		{
			unique_lock<mutex> lock(m_mutex);
			while (flag == 1)
				m_cond.wait(lock);
			printFoo();
			flag = 1;
			m_cond.notify_one();
		}
	}

	void bar(function<void()> printBar)
	{
		for (int i = 0; i < n; i++)
		{
			unique_lock<mutex> lock(m_mutex);
			while (flag == 0)
				m_cond.wait(lock);
			printBar();
			flag = 0;
			m_cond.notify_one();
		}
	}
};

void printFoo()
{
	cout << "foo" << endl;
}

void printBar()
{
	cout << "bar" << endl;
}

int main()
{
	int n;
	cin >> n;

	FooBar fb(n);

	thread t1(bind(&FooBar::foo, &fb, &printFoo));
	thread t2(bind(&FooBar::bar, &fb, &printBar));

	t1.join();
	t2.join();

	return 0;
}