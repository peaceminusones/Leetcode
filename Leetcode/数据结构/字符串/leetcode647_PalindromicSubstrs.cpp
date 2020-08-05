#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    // 从中心向外扩展
    // 注意这个中心！！！
    int countSubstrings(string s)
    {
        int res = 0;
        int n_center = 2 * s.size() - 1;
        for (int center = 0; center < n_center; center++)
        {
            int left = center / 2;
            int right = center % 2 + left;
            while (left >= 0 && right < s.size() && s[left] == s[right])
            {
                left--;
                right++;
                res++;
            }
        }
        return res;
    }

    // 动态规划
    int countSubstrings_dp(string s)
    {
        vector<vector<int>> dp(s.size(), vector<int>(s.size()));
        int res = 0;

        for (int j = 0; j < s.size(); j++)
        {
            for (int i = 0; i <= j; i++)
            {
                if (s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1]))
                {
                    dp[i][j] = 1;
                    res++;
                }
            }
        }

        return res;
    }
};

int main()
{
    string s;
    cin >> s;

    Solution sol;
    int res = sol.countSubstrings_dp(s);
    cout << res << endl;
    return 0;
}