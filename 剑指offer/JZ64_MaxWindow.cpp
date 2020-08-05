#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution
{
public:
    vector<int> maxInWindows(const vector<int> &num, unsigned int size)
    {
        vector<int> res;
        if (size > num.size() || size == 0)
            return res;

        deque<int> dq;

        for (int i = 0; i < num.size(); i++)
        {
            // 从后往前依次弹出比num[i]小的值
            while (dq.size() && num[dq.back()] <= num[i])
                dq.pop_back();

            dq.push_back(i);

            // 判断队列头的下标是否过期
            // 如果当前位置i与窗口的开始位置dq.front()差大于窗口值，需要把队列头pop
            if (dq.front() + size <= i)
                dq.pop_front();

            // 当滑动窗口的位置到达size之后才开始存储
            if (i + 1 >= size)
                res.push_back(num[dq.front()]);
        }

        return res;
    }
};

int main()
{
    return 0;
}