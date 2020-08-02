#include <iostream>
#include <windows.h>
#include <thread>
using namespace std;

void print_thread_id(int id)
{
    cout << "thread # " << id << '\n';
    Sleep(1);
}

int main()
{
    thread threads[50];
    for (int i = 0; i < 50; i++)
    {
        threads[i] = thread(print_thread_id, i + 1);
    }

    for (auto &th : threads)
    {
        th.join();
        
    }

    return 0;
}
