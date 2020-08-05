#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int cowproduction(int n)
    {
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for (int i = 4; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 3];
        }
        return dp[n];
    }
};

int main()
{
    int n;
    cin >> n;

    Solution s;
    int res = s.cowproduction(n);
    cout << res << endl;

    return 0;
}