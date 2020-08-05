#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<int> dp(intervals.size() + 1);
        dp[0] = 1;
        for (int i = 1; i < intervals.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (intervals[i][0] >= intervals[j][1])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        return intervals.size() - (*max_element(dp.begin(), dp.end()));
    }

    static bool cmp(vector<int> a, vector<int> b)
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
    int res = s.eraseOverlapIntervals(intervals);
    cout << res << endl;
    return 0;
}