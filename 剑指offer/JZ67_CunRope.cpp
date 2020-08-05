#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int cutRope(int number)
    {
        if (number == 2)
            return 1;
        else if (number == 3)
            return 2;

        return backtrack(number);
    }

    int backtrack(int n)
    {
        if (n <= 4)
            return n;

        int res = 0;
        for (int i = 1; i < n; i++)
        {
            res = max(res, i * backtrack(n - i));
        }
        return res;
    }

    int cutRope_dp(int number)
    {
        if (number == 2)
            return 1;
        else if (number == 3)
            return 2;

        vector<int> dp(number + 1, -1);
        for (int i = 1; i <= 4; i++)
            dp[i] = i;

        for (int i = 5; i <= number; i++)
        {
            for (int j = 1; j <= i / 2; j++)
            {
                dp[i] = max(dp[i], dp[j] * dp[i - j]);
            }
        }
        return dp[number];
    }
};

int main()
{
    int n;
    cin >> n;
    Solution s;
    cout << s.cutRope_dp(n) << endl;
    return 0;
}