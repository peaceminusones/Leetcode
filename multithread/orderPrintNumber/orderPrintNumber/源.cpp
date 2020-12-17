#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

class OrderPrint
{
	int n = 0;
	int num = 0;
	mutex m_mtx;
	condition_variable m_cond;

public:
	OrderPrint(int x) :num(x) {}

	void func0()
	{
		for (int i = 0; i < num; i++)
		{
			unique_lock<mutex> lock(m_mtx);
			while (n % 3 != 0)
			{
				m_cond.wait(lock);
			}
			cout << n << endl;
			n++;
			m_cond.notify_all();
		}
		
	}

	void func1()
	{
		for (int i = 0; i < num; i++)
		{
			unique_lock<mutex> lock(m_mtx);
			while (n % 3 != 1)
			{
				m_cond.wait(lock);
			}
			cout << n << endl;
			n++;
			m_cond.notify_all();
		}
	}

	void func2()
	{
		for (int i = 0; i < num; i++)
		{
			unique_lock<mutex> lock(m_mtx);
			while (n % 3 != 2)
			{
				m_cond.wait(lock);
			}
			cout << n << endl;
			n++;
			m_cond.notify_all();
		}
	}
};

int main()
{
	OrderPrint op(12);

	thread threads[3];

	threads[0] = thread(&OrderPrint::func0, &op);
	threads[1] = thread(&OrderPrint::func1, &op);
	threads[2] = thread(&OrderPrint::func2, &op);
	
	threads[0].join();
	threads[1].join();
	threads[2].join();

	return 0;
}