#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.empty())
            return 0;
        vector<int> dp(prices.size());
        int minprice = prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            minprice = min(prices[i], minprice);
            dp[i] = max(dp[i - 1], prices[i] - minprice); // 不卖！vs 卖了
        }
        return dp[prices.size() - 1];
    }

    // 优化
    int maxProfit2(vector<int> &prices)
    {
        if (prices.empty())
            return 0;
        int minprice = prices[0];
        int maxprofit = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < minprice)
                minprice = prices[i];
            else
                maxprofit = max(maxprofit, prices[i] - minprice);
        }
        return maxprofit;
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
    int res = s.maxProfit(prices);
    cout << res << endl;
    return 0;
}