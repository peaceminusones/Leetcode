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
		// ��������ģ���࣬����һ���ֲ���lock_guard�������乹�캯���н��м���
		// ���˸ö����������ʱ�����
		lock_guard<mutex> lck(mutx);
		if (ticket > 0)
		{
			int x = (rand() % (10 - 1)) + 1;
			if (x > ticket)
				x = ticket;
			cout << "��Ʊ����[" << id << "]" << endl;
			ticket -= x;
			cout << "�۳� " << x << "Ʊ" << endl;
			cout << "ʣ�� " << ticket << "Ʊ" << endl;
		}
		else
		{
			cout << "��Ʊ����[" << id << "]" << endl;
			cout << "Ʊ������......" << endl;
		}
	}
}

void consumer2(int id)
{
	while (ticket > 0)
	{
		this_thread::sleep_for(chrono::microseconds(100));
		// ��������ģ���࣬����һ���ֲ���lock_guard�������乹�캯���н��м���
		// ���˸ö����������ʱ�����
		lock_guard<mutex> lck(mutx);
		if (ticket > 0)
		{
			int x = (rand() % (10 - 1)) + 1;
			if (x > ticket)
				x = ticket;
			cout << "��Ʊ����[" << id << "]" << endl;
			ticket -= x;
			cout << "�۳� " << x << "Ʊ" << endl;
			cout << "ʣ�� " << ticket << "Ʊ" << endl;
		}
		else
		{
			cout << "��Ʊ����[" << id << "]" << endl;
			cout << "Ʊ������......" << endl;
		}
	}
}

int main()
{
	cout << "main thread: " << this_thread::get_id() << endl;
	cout << "��Ʊ��Ϊ��" << ticket << endl;
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