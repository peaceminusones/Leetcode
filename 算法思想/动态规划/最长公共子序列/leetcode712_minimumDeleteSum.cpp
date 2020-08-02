#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int minimumDeleteSum(string s1, string s2)
    {
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1));
        // 处理边界
        for (int i = 1; i <= s1.size(); i++)
            dp[i][0] = dp[i - 1][0] + s1[i - 1];
        for (int j = 1; j <= s2.size(); j++)
            dp[0][j] = dp[0][j - 1] + s2[j - 1];

        // 当s1[i-1] == s2[j-1]，不需要删除字符，dp[i][j] == dp[i-1][j-1]
        // 当s1[i-1] != s2[j-1]，比较dp[i-1][j] + s1[i-1]和dp[i][j-1] + s2[j-1]大小，选择删除s1[i-1]或者s2[j-1]
        for (int i = 1; i <= s1.size(); i++)
        {
            for (int j = 1; j <= s2.size(); j++)
            {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
            }
        }

        return dp[s1.size()][s2.size()];
    }
};

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    Solution s;
    int res = s.minimumDeleteSum(s1, s2);
    cout << res << endl;
    return 0;
}