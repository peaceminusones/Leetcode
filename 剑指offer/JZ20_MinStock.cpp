#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
    stack<int> st1;
    stack<int> st2; // 辅助栈，存储当前最小值

public:
    void push(int value)
    {
        st1.push(value);

        if (st2.empty())
        {
            st2.push(value);
        }
        else
        {
            int minv = std::min(st2.top(), value);
            st2.push(minv);
        }
    }
    void pop()
    {
        if (!st1.empty())
        {
            st1.pop();
            st2.pop();
        }
    }

    int top()
    {
        return st1.top();
    }

    int min()
    {
        return st2.top();
    }
};

int main()
{

    return 0;
}
