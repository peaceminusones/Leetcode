#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long MOD = 1e9 + 7;
    int subSeqNumber(long long n, long long k, vector<long long> nums)
    {
        //记录每个余数的个数，余数可以是0-k-1
        vector<int> temp(k, 0);
        for (int i = 0; i < n; i++)
        {
            temp[nums[i] % k]++;
        }

        // 子集的长度（1-n）
        int res = 1; // 空集
        // 余数从0到k
        for (int i = 1; i < n; i++)
        {
            vector<int> dp(k);
            dp[0] = temp[0]; // 余数为0的数字个数
            for (int j = 1; j < k; j++)
            {
                int l = 0, r = i;
                dp[j] = temp[j];
                while (l < r)
                {
                    dp[i] += dp[l] * dp[r];
                }
            }
        }

        int res = temp[0] == 0 ? 0 : 1; // 余数为0的
        res++;                          // 空集
        int i = 1, j = k - 1;           // 余数1和k-1的只能取一种，取数量多的那种
        while (i < j)
        {
            res = res + max(temp[i], temp[j]);
            i++;
            j--;
        }
        if (i == j && temp[i] != 0)
            res++;
        cout << res << endl;
        return res;
    }
};

int main()
{
    long long n, k;
    cin >> n >> k;

    vector<long long> nums;
    long long item;
    for (long long i = 0; i < n; i++)
    {
        cin >> item;
        nums.push_back(item);
    }

    Solution s;
    cout << s.subSeqNumber(n, k, nums) << endl;
    return 0;
}