#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> res;
        // 当前最大值的索引信息
        deque<int> deq;
        for (int i = 0; i < nums.size(); i++)
        {
            // 从后往前，弹出比num[i]小的位置
            while (deq.size() && nums[deq.back()] <= nums[i])
                deq.pop_back();

            // 把nums[i]的位置放入双向队列中
            deq.push_back(i);

            // 判断队列头的下标是否过期
            if (deq.front() + k <= i)
                deq.pop_front();

            // 当滑动窗口的位置i到达k以后，才开始存储结果
            if (i + 1 >= k)
                res.push_back(nums[deq.front()]);
        }

        return res;
    }
};

int main()
{
    return 0;
}