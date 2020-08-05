#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
    priority_queue<int, vector<int>, less<int>> p;    // 大顶堆, 维护左边一半儿（小的）
    priority_queue<int, vector<int>, greater<int>> q; // 小顶堆，维护右边一半儿（大的）

public:
    void Insert(int num)
    {
        if (p.empty() || num <= p.top()) // 如果num小于左边一半儿的最大值，就直接插入
        {
            p.push(num);
        }
        else // 否则插入右边一半儿
        {
            q.push(num);
        }

        // 调整两个堆中的大小
        if (p.size() == q.size() + 2) // 如果左边的大小比右边的大小大了2
        {
            q.push(p.top()); // 则从左边移除一个最大数到右边
            p.pop();
        }
        if (p.size() + 1 == q.size()) // 如果右边的大小比左边打了1
        {
            p.push(q.top()); // 则从右边移除一个到左边
            q.pop();
        }

        // 即如果是奇数，左边比右边要多一个数
        // 如果是偶数，则左边右边的数相等
    }

    double GetMedian()
    {
        return (p.size() == q.size()) ? (p.top() + q.top()) / 2.0 : p.top();
    }
};

int main()
{
    return 0;
}