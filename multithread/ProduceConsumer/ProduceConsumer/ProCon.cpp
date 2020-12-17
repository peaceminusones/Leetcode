#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>
using namespace std;

int m_count = 0;
mutex m_mtx;
condition_variable m_cond;

void in(int id)
{
	while (true)
	{
		this_thread::sleep_for(chrono::microseconds(10000));

		unique_lock<mutex> lock(m_mtx);
		while (m_count >= 5)
			m_cond.wait(lock);
		m_count++;
		cout << "thread id:" << id << "product one" << endl;
		cout << "remain:" << m_count << endl;
		m_cond.notify_all();
	}
}

void out(int id)
{
	while (true)
	{
		this_thread::sleep_for(chrono::microseconds(10000));

		unique_lock<mutex> lock(m_mtx);
		while (m_count <= 0)
			m_cond.wait(lock);
		m_count -= 2;
		cout << "thread id:" << id << "consumer two" << endl;
		cout << "remain:" << m_count << endl;
		m_cond.notify_all();
	}
}

int main()
{
	thread thread1(in, 0);
	thread thread2(out, 1);
	thread1.join();
	thread2.join();
	return 0;
}