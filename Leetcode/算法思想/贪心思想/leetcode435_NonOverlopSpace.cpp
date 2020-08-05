#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    /*
     * 【从起始点的动态规划】
     * 
     * 使用一个dp数组，其中dp[i]存储着只考虑从一开始到第i个区间（包括其本身），最大可能的区间数
     * 当计算dp[i+1]时，不能只考虑dp[i]的值，因为前面的i个区间都可能与第i+1个区间发生重叠
     * 
     * 因此我们需要考虑的是：
     *     使得j<=i且与i+1个区间不发生重叠的所有dp[j]中的最大值，状态转移方程为：dp[i+1] = max(dp[j])+1
     *     其中对于所有j<=i，第i个和第j个区间不发生重叠
     * 
     * 最后，为了计算最终列表中区间的最大区间数量，我们需要找到dp数组中的最大值，最终结果为区间总数减去这个最大值
    */
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        if (intervals.size() == 0)
            return 0;

        sort(intervals.begin(), intervals.end(), cmp1); // 按照[a,b]中a的大小排序
        // for (int i = 0; i < intervals.size(); i++)
        //     cout << intervals[i][0] << " " << intervals[i][1] << endl;

        vector<int> dp(intervals.size());
        dp[0] = 1; //dp[0] = 1
        int res = 1;
        for (int i = 1; i < dp.size(); i++)
        {
            int maxv = 0;
            for (int j = i - 1; j >= 0; j--)
            {
                // 从当前位置往前遍历，判断
                if (!isoverlapping(intervals[j], intervals[i]))
                    maxv = max(dp[j], maxv);
            }
            dp[i] = maxv + 1;
            res = max(res, dp[i]);
        }

        return intervals.size() - res;
    }

    static bool cmp1(vector<int> &inter1, vector<int> &inter2)
    {
        return inter1[0] < inter2[0];
    }

    bool isoverlapping(vector<int> inter1, vector<int> inter2)
    {
        return inter1[1] > inter2[0];
    }

    /*
     * 【从终点的动态规划】
    */
    int eraseOverlapIntervals_end(vector<vector<int>> &intervals)
    {
        if (intervals.size() == 0)
            return 0;

        sort(intervals.begin(), intervals.end(), cmp2); // 按照[a,b]中b的大小排序
        // for (int i = 0; i < intervals.size(); i++)
        //     cout << intervals[i][0] << " " << intervals[i][1] << endl;

        vector<int> dp(intervals.size());
        dp[0] = 1;
        int res = 1;
        for (int i = 1; i < intervals.size(); i++)
        {
            int maxv = 0;
            for (int j = i - 1; j >= 0; j--)
            {
                if (!isoverlapping(intervals[j], intervals[i]))
                {
                    maxv = max(dp[j], maxv);
                    break;
                }
            }
            dp[i] = max(maxv + 1, dp[i - 1]);
            res = max(res, dp[i]);
        }

        return intervals.size() - res;
    }

    static bool cmp2(vector<int> &inter1, vector<int> &inter2)
    {
        return inter1[1] < inter2[1];
    }

    /*
     * 贪心算法
     * 
    */
    int eraseOverlapIntervals_greedy(vector<vector<int>> &intervals)
    {
        if (intervals.size() == 0)
            return 0;

        sort(intervals.begin(), intervals.end(), cmp2); // 按照[a,b]中b的大小，从小到大排序

        int count = 1;
        int end = intervals[0][1];
        for (int i = 0; i < intervals.size(); i++)
        {
            if (intervals[i][0] < end)
                continue;
            end = intervals[i][1];
            count++;
        }
        return intervals.size() - count;
    }
};

int main()
{
    vector<vector<int>> intervals;

    int item1, item2;
    while (cin >> item1 >> item2)
    {
        vector<int> interval;
        interval.push_back(item1);
        interval.push_back(item2);
        intervals.push_back(interval);
    }

    Solution s;
    int res = s.eraseOverlapIntervals_end(intervals);
    cout << res << endl;

    return 0;
}