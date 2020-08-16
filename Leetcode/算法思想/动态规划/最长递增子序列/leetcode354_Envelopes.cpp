#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Soltuion
{
public:
    // 方法一：动态规划
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        if (envelopes.empty())
            return 0;

        sort(envelopes.begin(), envelopes.end(), cmp);

        int res = 0;
        vector<int> dp(envelopes.size(), 1);
        for (int i = 0; i < envelopes.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (envelopes[j][1] < envelopes[i][1])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            res = max(dp[i], res);
        }
        return res;
    }

    static bool cmp(const vector<int> &a, const vector<int> &b)
    {
        return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
    }

    // 方法二：优化！ 动态规划＋二分法
    int maxEnvelopes1(vector<vector<int>> &envelopes)
    {
        if (envelopes.empty())
            return 0;

        sort(envelopes.begin(), envelopes.end(), cmp);

        vector<int> dp;
        for (auto en : envelopes)
        {
            /*
            // 从dp中二分查找第一个大于或等于en[1]的数字，并返回该数字的位置
            // 不存在则返回end
            auto it = upper_bound(dp.begin(), dp.end(), en[1]);
            if (it == dp.end())
                dp.emplace_back(en[1]);
            else
            {
                // 如果存在比en[1]大的数字，则把
                int idx = it - dp.begin();
                dp[idx] = en[1];
            }
            */
            int idx = binarySearch(dp, en[1]);
            if (idx == dp.size())
                dp.push_back(en[1]);
            else
                dp[idx] = en[1];
        }

        return dp.size();
    }

    int binarySearch(vector<int> &dp, int val)
    {
        int i = 0, j = dp.size();
        while (i < j)
        {
            int mid = i + (j - i) / 2;
            if (dp[mid] == val)
                return mid;
            else if (dp[mid] < val)
                i = mid + 1;
            else
                j = mid;
        }
        return i;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> envelopes;
    for (int i = 0; i < n; i++)
    {
        vector<int> en;
        int item1, item2;
        cin >> item1 >> item2;
        en.push_back(item1);
        en.push_back(item2);
        envelopes.push_back(en);
    }

    Soltuion s;
    cout << s.maxEnvelopes1(envelopes) << endl;

    return 0;
}