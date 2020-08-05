#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() == 0)
            return 0;
        int curmin = prices[0];
        int maxv = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < curmin)
                curmin = prices[i];
            else
                maxv = max(maxv, prices[i] - curmin);
        }
        return maxv;
    }
};

int main()
{
    vector<int> prices;
    int item;
    while (cin >> item)
    {
        prices.push_back(item);
    }

    Solution s;
    int res = s.maxProfit(prices);
    cout << res << endl;

    return 0;
}