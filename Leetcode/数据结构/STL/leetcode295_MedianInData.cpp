#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

/**
 * 方法一：优先队列！！！！
*/
class MedianFinder
{
    // 优先队列
    priority_queue<int, vector<int>, less<int>> p;    // 大顶堆，维护左一半儿
    priority_queue<int, vector<int>, greater<int>> q; // 小顶堆，维护右一半儿
public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (p.empty() || num <= p.top())
            p.push(num);
        else
            q.push(num);

        if (p.size() == q.size() + 2)
        {
            q.push(p.top());
            p.pop();
        }
        else if (p.size() + 1 == q.size())
        {
            p.push(q.top());
            q.pop();
        }
    }

    double findMedian()
    {
        return p.size() == q.size() ? (p.top() + q.top()) / 2.0 : p.top();
    }
};

/**
 * 方法一：multiset
*/
class MedianFinder1
{
    multiset<int> data;
    multiset<int>::iterator it;

public:
    MedianFinder1() {}

    void addNum(int num)
    {
        data.insert(num);
        if (data.size() == 1)
        {
            it = data.begin();
        }
        else
        {
            if (data.size() % 2 == 0) // 现在有偶数个数据（之前有奇数个数据）
            {
                if (num < *it) // 如果是插入在it左边，则it-1，让它指向两个中位数左边的那个
                {
                    it--;
                }
                // 如果是插入在it右边，则不用处理，it指向的就是中位数左边的那个
            }
            else // 现在有奇数个数据（之前有偶数个数据）
            {
                // 如果插入在it右边，则需要移动it，插入在左边不需要
                if (num >= *it)
                    it++;
            }
        }
    }

    double findMedian()
    {
        return data.size() % 2 == 0 ? (*it + *next(it)) / 2.0 : *it;
    }
};

int main()
{
    return 0;
}