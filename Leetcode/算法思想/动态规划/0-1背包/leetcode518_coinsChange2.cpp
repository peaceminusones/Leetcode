#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // 递归！！超时
    int change(int amount, vector<int> &coins)
    {
        return dfs(coins, amount, 0);
    }
    int dfs(vector<int> &coins, int amount, int start)
    {
        if (amount < 0)
            return 0;
        if (amount == 0)
            return 1;

        int res = 0;
        for (int i = start; i < coins.size(); i++)
        {
            if (amount >= coins[i])
                res += dfs(coins, amount - coins[i], i);
        }
        return res;
    }

    // 动态规划，二维
    int change_dp(int amount, vector<int> &coins)
    {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1));
        for (int i = 0; i <= coins.size(); i++)
            dp[i][0] = 1;
        for (int i = 1; i <= coins.size(); i++)
        {
            for (int j = 0; j <= amount; j++)
            {
                if (j >= coins[i - 1])
                {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[coins.size()][amount];
    }

    // 动态规划优化，一维
    int change_dp2(int amount, vector<int> &coins)
    {
        vector<int> dp(amount + 1);
        dp[0] = 1;
        for (int i = 1; i <= coins.size(); i++)
        {
            for (int j = coins[i - 1]; j <= amount; j++)
            {
                dp[j] = dp[j] + dp[j - coins[i - 1]];
            }
        }
        return dp[amount];
    }

    // 完全背包，组合问题，和元素顺序无关
    int change_dp3(int amount, vector<int> &coins)
    {
        vector<int> dp(amount + 1);
        dp[0] = 1;

        for (auto coin : coins)
        {
            for (int i = coin; i <= amount; i++)
            {
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
};

int main()
{
    int amount;
    cin >> amount;

    vector<int> coins;
    int item;
    while (cin >> item)
    {
        coins.push_back(item);
        if (cin.get() == '\n')
            break;
    }

    Solution s;
    int res = s.change_dp3(amount, coins);
    cout << res << endl;
    return 0;
}