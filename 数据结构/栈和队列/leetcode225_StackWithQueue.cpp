#include <iostream>
#include <queue>
using namespace std;

class MyStack
{
    queue<int> que;

public:
    MyStack() {}

    void push(int x)
    {
        que.push(x);
        for (int i = 0; i < que.size() - 1; i++)
        {
            que.push(que.front());
            que.pop();
        }
    }

    int pop()
    {
        int top = que.front();
        que.pop();
        return top;
    }

    int top()
    {
        return que.front();
    }

    bool empty()
    {
        return que.empty();
    }
};

int main()
{
    MyStack *mystack = new MyStack();
    mystack->push(1);
    mystack->push(2);
    cout << mystack->pop() << endl;
    cout << mystack->top() << endl;
    cout << mystack->empty() << endl;
    return 0;
}