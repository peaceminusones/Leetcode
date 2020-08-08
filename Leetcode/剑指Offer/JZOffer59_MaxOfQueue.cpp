#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class MaxQueue
{
    queue<int> que;
    deque<int> deq;

public:
    MaxQueue() {}

    int max_value()
    {
        return deq.empty() ? -1 : deq.front();
    }

    void push_back(int value)
    {
        que.push(value);
        while (!deq.empty() && value > deq.back())
            deq.pop_back();
        deq.push_back(value);
    }

    int pop_front()
    {
        if (que.empty())
            return -1;
        int tmp = que.front();
        que.pop();
        if (tmp == deq.front())
            deq.pop_front();

        return tmp;
    }
};

int main()
{
    MaxQueue *obj = new MaxQueue();
    obj->push_back(3);
    obj->push_back(2);
    obj->push_back(5);
    int param_1 = obj->max_value();
    cout << param_1 << endl;
    obj->push_back(4);
    int param_3 = obj->pop_front();
    cout << param_3 << endl;
    return 0;
}