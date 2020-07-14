#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int wrongmail(int n)
    {
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 1;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = (i - 1) * dp[i - 2] + (i - 1) * dp[i - 1];
        }
        return dp[n];
    }
};

int main()
{
    int n;
    cin >> n;
    Solution s;
    int res = s.wrongmail(n);
    cout << res << endl;
    return 0;
}