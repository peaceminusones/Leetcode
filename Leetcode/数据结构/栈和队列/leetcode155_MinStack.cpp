#include <iostream>
#include <stack>
using namespace std;

class MinStack
{
    int minim = INT_MAX;
    stack<int> datastack;
    stack<int> ministack;

public:
    MinStack() {}

    void push(int x)
    {
        datastack.push(x);
        minim = min(x, minim);
        ministack.push(minim);
    }

    void pop()
    {
        datastack.pop();
        ministack.pop();
        minim = ministack.empty() ? INT_MAX : ministack.top();
    }

    int top()
    {
        return datastack.top();
    }

    int getMin()
    {
        return ministack.top();
    }
};

int main()
{
    MinStack *minStack = new MinStack;
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    cout << minStack->getMin() << endl;
    minStack->pop();
    cout << minStack->top() << endl;
    cout << minStack->getMin() << endl;
    return 0;
}