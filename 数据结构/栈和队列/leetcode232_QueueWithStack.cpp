#include <iostream>
#include <stack>
using namespace std;

class MyQueue
{
    stack<int> in;
    stack<int> out;

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        in.push(x);
    }

    int pop()
    {
        in2out();
        int top = out.top();
        out.pop();
        return top;
    }

    void in2out()
    {
        if (out.empty())
        {
            while (!in.empty())
            {
                out.push(in.top());
                in.pop();
            }
        }
    }

    int peek()
    {
        in2out();
        return out.top();
    }

    bool empty()
    {
        return in.empty() && out.empty();
    }
};

int main()
{
    MyQueue *queue = new MyQueue();
    queue->push(1);
    queue->push(2);
    cout << queue->peek() << endl;
    cout << queue->pop() << endl;
    cout << queue->empty() << endl;
    return 0;
}