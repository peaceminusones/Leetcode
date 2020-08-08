#include <iostream>
#include <stack>
#include <cstdlib>
using namespace std;

template <typename T>
class minmaxStack
{
public:
    bool empty()
    {
        return st.empty();
    }

    size_t size()
    {
        return st.size();
    }

    void push(int x)
    {
        if (minStack.empty() || x < minStack.top())
            minStack.push(x);
        if (maxStack.empty() || x > maxStack.top())
            maxStack.push(x);
        st.push(x);
    }

    void pop()
    {
        if (st.empty())
            return;
        if (st.top() == minStack.top())
            minStack.pop();
        if (st.top() == maxStack.top())
            maxStack.pop();
        st.pop();
    }

    int getMin()
    {
        if (st.empty())
            return -1;
        return minStack.top();
    }

    int getMax()
    {
        if (st.empty())
            return -1;
        return maxStack.top();
    }

    int top()
    {
        return st.top();
    }

private:
    stack<int> st;
    stack<int> minStack;
    stack<int> maxStack;
};

template <typename T>
class myqueue
{
public:
    bool empty()
    {
        return in.empty() && out.empty();
    }

    size_t size()
    {
        return in.size() + out.size();
    }

    int getMax()
    {
        if (in.empty() && out.empty())
            return -1;
        if (in.empty())
            return out.getMax();
        if (out.empty())
            return in.getMax();
        return max(in.getMax(), out.getMax());
    }

    int getMin()
    {
        if (in.empty() && out.empty())
            return -1;
        if (in.empty())
            return out.getMin();
        if (out.empty())
            return in.getMin();
        return min(in.getMin(), out.getMin());
    }

    void push(int x)
    {
        in.push(x);
    }

    void pop()
    {
        if (in.empty() && out.empty())
            return;
        if (out.empty())
        {
            while (!in.empty())
            {
                out.push(in.top());
                in.pop();
            }
        }
        out.pop();
    }

private:
    minmaxStack<int> in;
    minmaxStack<int> out;
};

int main()
{
    myqueue<int> q;
    for (int i = 0; i < 15; i++)
    {
        int index = rand() % 100 + 1;
        cout << index << ' ';
        q.push(index);
    }
    cout << endl;
    cout << q.getMax() << endl;
    cout << q.getMin() << endl;
}