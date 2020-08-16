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

	// ��ӡ0
	void zero(function<void(int)> printNumber)
	{
		for (int i = 0; i < n; i++)
		{
			unique_lock<mutex> lock(m_mutex);
			// ��������Դ���0����ȴ�
			while (!zero_flag)
				m_cond.wait(lock);
			printNumber(0);
			zero_flag = false;
			m_cond.notify_all();
		}
	}

	// ��ӡż��
	void even(function<void(int)> printNumber)
	{
		for (int i = 2; i <= n; i += 2)
		{
			unique_lock<mutex> lock(m_mutex);
			// ������Դ�ӡ0�����߿��Դ�ӡ��������ȴ�
			while (zero_flag || odd_flag)
				m_cond.wait(lock);
			printNumber(i);
			zero_flag = true;
			odd_flag = true;
			m_cond.notify_all();
		}
	}

	// ��ӡ����
	void odd(function<void(int)> printNumber)
	{
		for (int i = 1; i <= n; i += 2)
		{
			unique_lock<mutex> lock(m_mutex);
			// ������Դ�ӡ0�����߲����Դ�ӡ��������ȴ�
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



/* �ź���ʵ�� ==========================================================================*/

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
//	int count;  // �ȴ��߳�����
//	mutex m_mutex; // ������
//	condition_variable m_cond; // ��������
//
//public:
//	semaphore(int value = 0) :count(value) {}
//
//	void wait()
//	{
//		unique_lock<mutex> lock(m_mutex);
//		if (--count < 0) // ��Դ���㣬�����߳�
//		{
//			m_cond.wait(lock);
//		}
//	}
//
//	void signal()
//	{
//		// if (++count <= 0) ˵��count��++֮ǰ<0����count�ĳ�ʼֵ��Ҳ���ź�����ֵΪ�޷�������ֻ����>=0��
//		// ��ô<0�����Ҳֻ��������Ϊ�ȵ�����wait����ˣ������ȷ����ʱ���߳��ڵȴ����ʿ��Ե���notify_one�ˡ�
//		unique_lock<mutex> lock(m_mutex);
//		if (++count <= 0) // ���̹߳��𣬻���һ��
//			m_cond.notify_all();
//	}
//
//};
//
///*
//	������һֻ���ӣ�ֻ�����һ��ˮ��������ר�����ӷ�ƻ����ĸ��ר�����ӷŽ��� ����ר�ȳ����ӵĽ��ӣ�Ů��ר�ȳ����ӵ�ƻ����
//	ֻҪ����Ϊ�գ����׻�ĸ�׾Ϳ��������ӷ�ˮ���� �����������Լ���Ҫ��ˮ��ʱ�����Ӻ�Ů���ɴ�����ȡ����
//	������ĸ���֮���ͬ����ϵ������ pv����ʵ���ĸ��˵���ȷ������⡣
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
//		cout << "�������з�һ��ƻ��" << endl;
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
//		cout << "�������з�һ������" << endl;
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
//		cout << "���ӳ�ƻ��" << endl;
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
//		cout << "Ů��������" << endl;
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
