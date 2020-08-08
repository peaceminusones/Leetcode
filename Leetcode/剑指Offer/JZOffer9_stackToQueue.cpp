#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class CQueue
{
    stack<int> st1;
    stack<int> st2;

public:
    CQueue() {}

    void appendTail(int value)
    {
        st1.push(value);
    }

    int deleteHead()
    {
        if (st1.empty() && st2.empty())
            return -1;
        
        int val = 0;
        if (st2.empty())
        {
            while (!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }

        val = st2.top();
        st2.pop();
        return val;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */