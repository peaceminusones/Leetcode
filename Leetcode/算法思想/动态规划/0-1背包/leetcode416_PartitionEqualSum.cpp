#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // 0-1背包，动态规划，二维dp
    bool canPartition(vector<int> &nums)
    {
        int sum_value = accumulate(nums.begin(), nums.end(), 0);
        if (sum_value % 2 == 1)
            return false;
        int W = sum_value / 2;
        int N = nums.size();
        vector<vector<bool>> dp(N + 1, vector<bool>(W + 1));
        for (int i = 0; i <= N; i++)
            dp[i][0] = 1;

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= W; j++)
            {
                if (nums[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[N][W];
    }

    // 0-1背包，动态规划，状态压缩，一维dp
    bool canPartition2(vector<int> &nums)
    {
        int sum_value = accumulate(nums.begin(), nums.end(), 0);
        if (sum_value % 2 == 1)
            return false;

        int W = sum_value / 2;
        int N = nums.size();
        vector<bool> dp(W + 1);
        dp[0] = true;
        for (int i = 1; i <= N; i++)
        {
            for (int j = W; j >= 0; j--)
            {
                if (nums[i - 1] <= j)
                    dp[j] = dp[j] || dp[j - nums[i - 1]];
            }
        }
        return dp[W];
    }

    // 回溯法+剪枝 超出时间限制！！！
    bool canPartition_backtracking(vector<int> &nums)
    {
        int sum_value = accumulate(nums.begin(), nums.end(), 0);
        if (sum_value % 2 == 1)
            return false;

        sort(nums.begin(), nums.end());
        return backtracking(nums, 0, sum_value / 2);
    }

    bool backtracking(vector<int> &nums, int index, int sum)
    {
        if (sum == 0)
            return true;
        if (sum < 0 || index < 0)
            return false;
        for (int i = index; i < nums.size(); i++)
        {
            if (i > index && nums[i - 1] == nums[i])
                continue;
            if (sum - nums[i] < 0)
                return false;
            if (backtracking(nums, i + 1, sum - nums[i]))
                return true;
        }
        // return backtracking(nums, index - 1, sum - nums[index]) || backtracking(nums, index - 1, sum);
        return false;
    }

    // 01背包，true-false问题，与顺序无关
    bool canPartition_final(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1)
            return false;
        int target = sum / 2;
        vector<bool> dp(target + 1);
        dp[0] = 1;
        for (auto num : nums)
        {
            for (int i = target; i >= num; i--)
            {
                dp[i] = dp[i] || dp[i - num];
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
    }

    Solution s;
    bool res1 = s.canPartition(nums);
    cout << res1 << endl;
    bool res2 = s.canPartition_final(nums);
    cout << res2 << endl;
    return 0;
}