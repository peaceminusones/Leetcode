#include <iostream>
#include "threadpool.h"
using namespace std;

mutex mutx;

void testfunc()
{
	for (int i = 0; i < 4; i++)
	{
		lock_guard<mutex> lock(mutx);
		cout << "testfunc()" << i << " at thread" << this_thread::get_id() << " output" << endl;
	}
}

int main()
{
	{
		ThreadPool threadpool(5);

		for (int i = 0; i < 5; i++)
			threadpool.addTask(testfunc);

		getchar();
	}

	getchar();
	return 0;
}