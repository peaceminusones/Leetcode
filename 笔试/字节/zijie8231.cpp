#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int N = 2e5 + 10;
    int MOD = 1e9 + 7;
    int count(int n, int l, int r)
    {
        int pos = l % 3;
        int k = (r - l + 1) / 3;
        int num = (r - l + 1) - 3 * k;
        vector<int> cnt(3);
        vector<vector<int>> dp(N, vector<int>(3));
        cnt[0] = cnt[1] = cnt[2] = k;
        while (num--)
            cnt[pos % 3]++, pos++;
        dp[1][0] = cnt[0], dp[1][1] = cnt[1], dp[1][2] = cnt[2];
        for (int i = 2; i <= n; i++)
        {
            dp[i][0] = (dp[i - 1][1] * cnt[2] + dp[i - 1][2] * cnt[1] + dp[i - 1][0] * cnt[0]) % MOD;
            dp[i][1] = (dp[i - 1][1] * cnt[0] + dp[i - 1][2] * cnt[2] + dp[i - 1][0] * cnt[1]) % MOD;
            dp[i][2] = (dp[i - 1][1] * cnt[1] + dp[i - 1][2] * cnt[0] + dp[i - 1][0] * cnt[2]) % MOD;
        }

        return dp[n][0];
    }
};

int main()
{
    int n, l, r;
    cin >> n >> l >> r;

    Solution s;
    cout << s.count(n, l, r) << endl;
    return 0;
}