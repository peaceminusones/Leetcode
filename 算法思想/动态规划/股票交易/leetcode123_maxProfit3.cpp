#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.empty() || prices.size() < 2)
            return 0;
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(3, vector<int>(2)));
        for (int k = 0; k < 3; k++)
        {
            dp[0][k][0] = 0;
            dp[0][k][1] = -prices[0];
        }

        for (int i = 1; i < prices.size(); i++)
        {
            for (int k = 2; k >= 1; k--)
            {
                dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
                dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]);
            }
        }

        return dp[prices.size() - 1][2][0];
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