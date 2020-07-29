#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    // string longestPalindrome(string s)
    // {
    //     string res = "";
    //     int n_center = 2 * s.size() - 1;
    //     for (int center = 0; center < n_center; center++)
    //     {
    //         int left = center / 2;
    //         int right = center % 2 + left;

    //         while (left >= 0 && right < s.size() && s[left] == s[right])
    //         {
    //             if (right - left + 1 > res.size())
    //             {
    //                 res = s.substr(left, right - left + 1);
    //             }
    //             left--;
    //             right++;
    //         }
    //     }
    //     return res;
    // }

    string longestPalindrome(string s)
    {
        vector<vector<int>> dp(s.size(), vector<int>(s.size()));
        string res = "";
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (s[i] == s[j] && (i - j < 2 || dp[i - 1][j + 1] > 0))
                {
                    dp[i][j] = 1;
                    if (i - j + 1 > res.size())
                        res = s.substr(j, i - j + 1);
                }
            }
        }
        return res;
    }

    // string longestPalindrome(string s)
    // {
    //     string res = "";
    //     int n_center = 2 * s.size() - 1;
    //     for (int center = 0; center < n_center; center++)
    //     {
    //         int left = center / 2;
    //         int right = center % 2 + left;

    //         while (left >= 0 && right < s.size() && s[left] == s[right])
    //         {
    //             if (right - left + 1 > res.size())
    //             {
    //                 res = s.substr(left, right - left + 1);
    //             }
    //             left--;
    //             right++;
    //         }
    //     }
    //     return res;
    // }

    string longestPalindrome_dp(string s)
    {
        vector<vector<int>> dp(s.size(), vector<int>(s.size()));
        string res = "";
        for (int j = 0; j < s.size(); j++)
        {
            for (int i = 0; i <= j; i++)
            {
                if (s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1]))
                {
                    dp[i][j] = 1;
                    if (j - i + 1 > res.size())
                        res = s.substr(i, j - i + 1);
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
    string res = sol.longestPalindrome(s);
    cout << res << endl;
    return 0;
}