#include <iostream>
#include <vector>
#include <deque> // 双向队列
using namespace std;

class Solution
{
public:
    vector<int> maxInWindows(const vector<int> &num, unsigned int size)
    {
        // vector<int> res;
        // if (num.empty() || size == 0)
        //     return res;

        // // 双向队列，用来记录每个窗口的最大值下标
        // deque<int> dq;

        // for (int i = 0; i < num.size(); i++)
        // {
        //     // 从后往前依次弹出队列中比当前值num[i]小的
        //     // 同时保证队首是当前窗口的最大值下标
        //     while (dq.size() && num[dq.back()] <= num[i])
        //         dq.pop_back();

        //     // 如果 “当前位置i - 队首的位置 > 窗口大小”，则需要把队首移除
        //     if (dq.size() && i - dq.front() + 1 > size)
        //         dq.pop_front();

        //     dq.push_back(i);

        //     if (i + 1 >= size) // 当滑动窗口的首地址i开始大于窗口大小（size）时，才开始写入结果res
        //         res.push_back(num[dq.front()]);
        // }

        // return res;

        vector<int> res;
        if (num.empty() || size == 0)
            return res;

        deque<int> deq;
        for (int i = 0; i < num.size(); i++)
        {
            while (deq.size() && num[deq.back()] < num[i])
                deq.pop_back();
            if (deq.size() && i - deq.front() + 1 > size)
                deq.pop_front();

            deq.push_back(i);

            if (i + 1 >= size)
                res.push_back(num[deq.front()]);
        }
        return res;
    }
};

int main()
{
    vector<int> num;
    int item;
    while (cin >> item)
        num.push_back(item);
    cin.clear();
    cin.ignore();

    int size;
    cin >> size;

    Solution s;
    vector<int> res = s.maxInWindows(num, size);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;

    return 0;
}