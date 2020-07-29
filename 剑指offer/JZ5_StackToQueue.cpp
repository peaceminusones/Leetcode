#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
    stack<int> stack1;
    stack<int> stack2;

public:
    void push(int node)
    {
        stack1.push(node);
    }

    int pop()
    {
        int val = 0;
        if (stack2.empty())
        {
            while (!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        val = stack2.top();
        stack2.pop();

        return val;
    }
};

int main()
{

    return 0;
}