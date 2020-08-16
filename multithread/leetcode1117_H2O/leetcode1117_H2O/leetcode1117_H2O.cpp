#include <iostream>
#include <thread>
#include <condition_variable>
#include <functional>
#include <vector>
using namespace std;

class H2O 
{
	int h_count;
	int o_count;
	mutex m_mutex;
	condition_variable m_cond;

public:
	H2O() 
	{
		h_count = 0;
		o_count = 0;
	}

	// 生产H
	void hydrogen(function<void()> releaseHydrogen) 
	{
		unique_lock<mutex> lock(m_mutex);
		// 如果生产h的数量大于等于2了，则阻塞
		while (h_count >= 2)
			m_cond.wait(lock);
		// releaseHydrogen() outputs "H". Do not change or remove this line.
		releaseHydrogen();
		h_count++;
		// 如果刚好生成h2o了，则清零
		if (h_count == 2 && o_count == 1) 
		{
			h_count = 0;
			o_count = 0;
		}
		m_cond.notify_all();
	}

	// 生产O
	void oxygen(function<void()> releaseOxygen) 
	{
		unique_lock<mutex> lock(m_mutex);
		// 如果生成o的数量大于等于1了，则阻塞
		while (o_count >= 1)
			m_cond.wait(lock);
		// releaseOxygen() outputs "O". Do not change or remove this line.
		releaseOxygen();
		o_count++;
		// 如果刚好生成h2o了，则清零
		if (h_count == 2 && o_count == 1) 
		{
			h_count = 0;
			o_count = 0;
		}
		m_cond.notify_all();
	}
};


void releaseHydrogen()
{
	cout << "H";
}

void releaseOxygen()
{
	cout << "O";
}

int main()
{
	string str;
	cin >> str;

	vector<thread> threads(str.size());
	
	H2O ho;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == 'H')
		{
			threads[i] = thread(&H2O::hydrogen, &ho, &releaseHydrogen);
		}
		else
		{
			threads[i] = thread(&H2O::oxygen, &ho, &releaseOxygen);
		}
	}

	for (int i = 0; i < threads.size(); i++)
		threads[i].join();

	return 0;
}