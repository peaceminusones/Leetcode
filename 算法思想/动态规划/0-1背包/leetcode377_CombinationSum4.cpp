#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // 递归回溯，超时!!!
    // int combinationSum4(vector<int> &nums, int target)
    // {
    //     int sum = 0;
    //     int res = 0;
    //     sort(nums.begin(), nums.end());
    //     backtrack(nums, target, sum, res);
    //     return res;
    // }
    // void backtrack(vector<int> &nums, int target, int &sum, int &res)
    // {
    //     if (sum == target)
    //     {
    //         res++;
    //         return;
    //     }
    //     if (sum > target)
    //         return;

    //     for (int i = 0; i < nums.size(); i++)
    //     {
    //         sum += nums[i];
    //         backtrack(nums, target, sum, res);
    //         sum -= nums[i];
    //     }
    // }

    // 动态规划
    int combinationSum4_dp(vector<int> &nums, int target)
    {
        vector<double> dp(target + 1);
        dp[0] = 1;

        for (int i = 1; i <= target; i++)
        {
            for (auto num : nums)
            {
                if (i >= num)
                    dp[i] += dp[i - num];
            }
        }
        return dp[target];
    }
};

int main()
{
    vector<int> nums;
    int item;
    while (cin >> item)
    {
        nums.push_back(item);
        if (cin.get() == '\n')
            break;
    }

    int target;
    cin >> target;

    Solution s;
    int res = s.combinationSum4_dp(nums, target);
    cout << res << endl;
    return 0;
}