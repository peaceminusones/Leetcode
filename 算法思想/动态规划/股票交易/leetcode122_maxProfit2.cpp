#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size(), vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[prices.size() - 1][0];
    }

    // 优化，一维dp
    int maxProfit2(vector<int> &prices)
    {
        vector<int> dp(2);
        dp[0] = 0;
        dp[1] = -prices[0];
        int preCash = dp[0];
        int preStock = dp[1];
        for (int i = 1; i < prices.size(); i++)
        {
            dp[0] = max(dp[0], preStock + prices[i]);
            dp[1] = max(dp[1], preCash - prices[i]);

            preCash = dp[0];
            preStock = dp[1];
        }
        return dp[0];
    }
};

int main()
{
    vector<int> prices;
    int item;
    while (cin >> item)
    {
        prices.push_back(item);
        if (cin.get() == '\n')
            break;
    }

    Solution s;
    int res = s.maxProfit2(prices);
    cout << res << endl;
    return 0;
}