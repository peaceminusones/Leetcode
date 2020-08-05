#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // 第i层台阶组合 = i-1层台阶组合数 + i-2层台阶组合数
    int climbStairs(int n)
    {
        vector<int> dp(n+1);
        dp[0] = 1; // 0级台阶
        dp[1] = 1; // 1级台阶
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

int main()
{
    int n;
    cin >> n;

    Solution s;
    int res = s.climbStairs(n);
    cout << res << endl;
    return 0;
}