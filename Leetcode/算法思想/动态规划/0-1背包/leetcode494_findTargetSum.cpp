#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution
{
public:
    // dfs
    int findTargetSumWays(vector<int> &nums, int S)
    {
        return dfs(nums, S, 0);
    }
    int dfs(vector<int> &nums, long S, int index)
    {
        if (index == nums.size())
        {
            return S == 0 ? 1 : 0;
        }

        return dfs(nums, S - nums[index], index + 1) + dfs(nums, S + nums[index], index + 1);
    }

    // 动态规划
    int findTargetSumWays_dp(vector<int> &nums, int S)
    {
        long sum = accumulate(nums.begin(), nums.end(), 0);
        if ((S + sum) % 2 == 1 || S > sum)
            return 0;

        int target = (S + sum) / 2;
        int N = nums.size();
        vector<vector<int>> dp(N + 1, vector<int>(target + 1));
        for (int i = 0; i <= N; i++)
            dp[i][0] = 1;

        for (int i = 1; i <= N; i++)
        {
            for (int j = 0; j <= target; j++)
            {
                if (j >= nums[i - 1])
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[N][target];
    }

    // 动态规划,空间压缩，一维dp
    int findTargetSumWays_dp_1(vector<int> &nums, int S)
    {
        long sum = accumulate(nums.begin(), nums.end(), 0);
        if ((S + sum) % 2 == 1 || S > sum)
            return 0;

        int target = (S + sum) / 2;
        int N = nums.size();
        vector<int> dp(target + 1);
        dp[0] = 1;

        for (int i = 1; i <= N; i++)
        {
            for (int j = target; j >= nums[i - 1]; j--)
            {
                dp[j] = dp[j] + dp[j - nums[i - 1]];
            }
        }

        return dp[target];
    }

    // 01背包，组合问题，不需要考虑元素之间的顺序问题
    int findTargetSumWays_final(vector<int> &nums, int S)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if ((sum + S) % 2 == 1)
            return 0;

        S = (sum + S) / 2;
        vector<int> dp(S + 1);
        dp[0] = 1;
        for (auto num : nums)
        {
            for (int j = S; j >= 0; j--)
            {
                if (j >= num)
                    dp[j] += dp[j - num];
            }
        }
        return dp[S];
    }
};

struct A
{
    int i;
    short s;
    char c;
};

void A(int *p)
{
    cout << p[0] << p[1] << endl;
}

int main()
{
    // vector<int> nums;
    // int item;
    // while (cin >> item)
    // {
    //     nums.push_back(item);
    // }
    // cin.clear();
    // cin.ignore();

    // int S;
    // cin >> S;

    // Solution s;
    // int res = s.findTargetSumWays_final(nums, S);
    // cout << res << endl;
    // cout << sizeof(L"Maxhub我们") << endl;
    // int res2 = s.findTargetSumWays_dp(nums, S);
    // cout << res2 << endl;
    // int res3 = s.findTargetSumWays_dp_1(nums, S);
    // cout << res3 << endl;
    int p[] = {1, 2, 3};
    A(p+1);
    return 0;
}