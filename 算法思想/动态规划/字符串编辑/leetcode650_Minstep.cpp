#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution
{
public:
    // 递归
    int minSteps(int n)
    {
        if (n == 1)
            return 0;
        for (int i = 2; i <= sqrt(n); i++)
        {
            // 不是素数
            if (n % i == 0)
                return minSteps(i) + minSteps(n / i); // 可简化为: i + minSteps(n / i)
        }
        return n;
    }

    // 动态规划
    int minSteps_dp(int n)
    {
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = i;
            for (int j = 2; j <= sqrt(i); j++)
            {
                if (i % j == 0)
                {
                    dp[i] = dp[j] + dp[i / j];
                    break;
                }
            }
        }
        return dp[n];
    }

    // 数学！素数之和
    int minSteps_math(int n)
    {
        if (n < 2)
            return 0;

        int res = 0;
        int i = 2;
        while (i <= n)
        {
            if (n % i == 0)
            {
                res += i;
                n /= i;
            }
            else
            {
                i++;
            }
        }
        return res;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution s;
    int res = s.minSteps_math(n);
    cout << res << endl;
    return 0;
}