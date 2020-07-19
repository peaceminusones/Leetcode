#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // 完全背包!!!!!!
    // 贪心＋动态规划！
    int coinChange(vector<int> &coins, int amount)
    {
        sort(coins.begin(), coins.end(), cmp);
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, amount + 1));
        for (int i = 0; i <= coins.size(); i++)
            dp[i][0] = 0;
        for (int i = 1; i <= coins.size(); i++)
        {
            for (int j = coins[i - 1]; j <= amount; j++)
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1);
            }
        }
        return dp[coins.size()][amount] == amount + 1 ? -1 : dp[coins.size()][amount];
    }
    static bool cmp(int a, int b)
    {
        return a > b;
    }

    // 贪心＋动态规划的简化
    int coinChange2(vector<int> &coins, int amount)
    {
        sort(coins.begin(), coins.end(), cmp);
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int i = 1; i <= coins.size(); i++)
        {
            for (int j = coins[i - 1]; j <= amount; j++)
            {
                dp[j] = min(dp[j], dp[j - coins[i - 1]] + 1);
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }

    // 贪心+dfs
    int coinChange3(vector<int> &coins, int amount)
    {
        sort(coins.begin(), coins.end(), cmp);
        int res = amount + 1;
        int count = 0;
        dfs(coins, amount, 0, count, res);
        return res == amount + 1 ? -1 : res;
    }
    void dfs(vector<int> &coins, int amount, int index, int count, int &res)
    {
        if (amount <= 0 || index == coins.size())
        {
            if (amount == 0)
                res = min(res, count);
            return;
        }

        for (int nums = amount / coins[index]; nums >= 0 && nums + count < res; nums--)
        {
            dfs(coins, amount - nums * coins[index], index + 1, count + nums, res);
        }
    }

    // 完全背包，最小问题，和元素顺序无关
    int coinChange_final(vector<int> &coins, int amount)
    {
        sort(coins.begin(), coins.end(), cmp);
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (auto coin : coins)
        {
            for (int i = coin; i <= amount; i++)
            {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }

        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};

int main()
{
    vector<int> coins;
    int item;
    while (cin >> item)
    {
        coins.push_back(item);
        if (cin.get() == '\n')
            break;
    }

    int amount;
    cin >> amount;
    Solution s;
    int res = s.coinChange_final(coins, amount);
    cout << res << endl;
    return 0;
}