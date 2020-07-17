#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution
{
public:
    // 动态规划
    // dp[i]表示i拆分之后得到的乘积最大值
    int integerBreak(int n)
    {
        vector<int> dp(n + 1, 1);
        dp[2] = 1;
        for (int i = 3; i <= n; i++)
        {
            for (int j = 1; j < i; j++)
            {
                dp[i] = max(dp[i], max(j * dp[i - j], j * (i - j)));
            }
        }
        return dp[n];
    }

    // 3连乘最大，根据余数再加几个2
    int integerBreak_math(int n)
    {
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;
        int res = 1;

        int x = n / 3;
        int y = n % 3;
        if (y == 0) // eg: 9 [pow(3,3)]
        {
            return pow(3, x);
        }
        else if (y == 1) // eg: 10 [pow(3,2)*2*2]
        {
            return 2 * 2 * pow(3, x - 1);
        }
        else // eg: 11 [pow(3,3)*2]
        {
            return 2 * pow(3, x);
        }
    }
};

int main()
{
    int n;
    cin >> n;
    Solution s;
    int res = s.integerBreak_math(n);
    cout << res << endl;
    return 0;
}