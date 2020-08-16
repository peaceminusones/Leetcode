#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        if (envelopes.empty())
            return 0;

        sort(envelopes.begin(), envelopes.end(), cmp);

        int n = envelopes.size(), res = 0;
        vector<int> dp;
        for (auto en : envelopes)
        {
            int idx = lower_bound(dp.begin(), dp.end(), en[1]) - dp.begin();
            if (idx >= dp.size())
            {
                dp.emplace_back(en[1]);
            }
            else
            {
                dp[idx] = en[1];
            }
        }

        return dp.size();
    }

    static bool cmp(const vector<int> &a, const vector<int> &b)
    {
        return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
    }
};

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        vector<int> a;
        for (int j = 0; j < 2; j++)
        {
            int x;
            cin >> x;
            a.push_back(x);
        }
        ans.push_back(a);
    }

    Solution s;
    cout << s.maxEnvelopes(ans) << endl;
    return 0;
}