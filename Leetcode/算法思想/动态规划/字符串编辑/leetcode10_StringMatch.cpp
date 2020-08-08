#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // 超时了！！！
    bool isMatch(string s, string p)
    {
        if (s.empty() && p.empty())
            return true;
        if (!s.empty() && p.empty())
            return false;

        if (p[1] == '*')
        {
            if (s[0] == p[0] || (s[0] != '\0' && p[0] == '.'))
            {
                // 匹配0个当前字符
                // 匹配1个当前字符
                // 匹配多个当前字符
                return isMatch(s.substr(0), p.substr(2)) || isMatch(s.substr(1), p.substr(2)) || isMatch(s.substr(1), p.substr(0));
            }
            else
            {
                // 当前字符不相等，用*去掉
                return isMatch(s.substr(0), p.substr(2));
            }
        }
        else
        {
            if (s[0] == p[0] || (s[0] != '\0' && p[0] == '.'))
                return isMatch(s.substr(1), p.substr(1));
            else
                return false;
        }
    }

    /**
     * 动态规划！！！！！！！！
    */
    bool isMatch_dp(string s, string p)
    {
        if (s.empty() && p.empty())
            return true;
        if (!s.empty() && p.empty())
            return false;

        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1));
        // initial base!!!!!!
        dp[0][0] = 1;
        for (int j = 1; j <= p.size(); j++)
        {
            // 对于"a"、"c*a*b*"这种特殊情况
            if (p[j - 1] == '*')
                dp[0][j] = dp[0][j - 2];
        }

        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 1; j <= p.size(); j++)
            {
                if (p[j - 1] == '*')
                {
                    if (s[i - 1] == p[j - 2] || p[j - 2] == '.')
                        // 匹配多个p的当前字符 || 匹配1个p的当前字符 || 匹配0个p的当前字符
                        dp[i][j] = dp[i - 1][j] || dp[i][j - 1] || dp[i][j - 2];
                    else
                        dp[i][j] = dp[i][j - 2];
                }
                // p[j - 1] != '*'
                else
                {
                    if (s[i - 1] == p[j - 1] || p[j - 1] == '.')
                        dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    string s, p;
    cin >> s >> p;
    Solution Sol;
    cout << Sol.isMatch_dp(s, p) << endl;
    
    return 0;
}