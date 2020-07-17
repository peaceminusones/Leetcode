#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        sort(pairs.begin(), pairs.end(), cmp);
        vector<int> dp(pairs.size() + 1, 1);
        for (int i = 1; i < pairs.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (pairs[j][1] < pairs[i][0])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }

    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[0] < b[0];
    }
};

int main()
{
    vector<vector<int>> intervals;
    vector<int> interval;
    int item;
    while (cin >> item)
    {
        interval.push_back(item);
        if (cin.get() == '\n')
        {
            intervals.push_back(interval);
            interval.clear();
        }
        if (cin.peek() == '\n')
        {
            intervals.push_back(interval);
        }
    }

    Solution s;
    int res = s.findLongestChain(intervals);
    cout << res << endl;
    return 0;
}