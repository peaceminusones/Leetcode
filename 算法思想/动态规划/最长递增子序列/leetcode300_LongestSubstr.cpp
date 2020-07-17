#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // 动态规划
    int lengthOfLIS(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        vector<int> dp(nums.size() + 1, 1);
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }

    // 上面的时间复杂度为O(N2)，可以使用二分查找将时间复杂度降低为 O(NlogN)
    // 【优化】动态规划 ＋ 二分查找
    // 定义一个 tails 数组，其中 tails[i] 存储长度为 i + 1 的最长递增子序列的最后一个元素
    // 对于一个元素 x：
    //          如果它大于 tails 数组所有的值，那么把它添加到 tails 后面，表示最长递增子序列长度加 1；
    //          如果 tails[i-1] < x <= tails[i]，那么更新 tails[i] = x
    int lengthOfLIS2(vector<int> &nums)
    {
        vector<int> tail(nums.size());
        int len = 0;
        for (auto n : nums)
        {
            int index = binarySearch(tail, len, n);
            tail[index] = n;
            if (index == len)
            {
                len++;
            }
        }
        return len;
    }

    int binarySearch(vector<int> tail, int len, int key)
    {
        int l = 0, r = len;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (tail[mid] == key)
                return mid;
            else if (tail[mid] > key)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};

int main()
{
    vector<int> nums;
    int item;
    while (cin >> item)
    {
        nums.push_back(item);
    }

    Solution s;
    int res = s.lengthOfLIS2(nums);
    cout << res << endl;

    return 0;
}