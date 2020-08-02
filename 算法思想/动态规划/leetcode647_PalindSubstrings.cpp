#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int countSubstrings(string s)
    {
        vector<vector<int>> dp(s.size(), vector<int>(s.size()));
        int res = 0;

        for (int i = 0; i < s.size(); i++)
        {
            dp[i][i] = 1;
            res++;
        }

        for (int j = 0; j < s.size(); j++)
        {
            for (int i = 0; i < j; i++)
            {
                if (s[i] == s[j] && dp[i + 1][j - 1])
                {
                    dp[i][j] = 1;
                    res++;
                }
            }
        }
        return res;
    }

    int countSubstrings1(string s)
    {
        vector<vector<int>> dp(s.size(), vector<int>(s.size()));
        int res = 0;

        for (int j = 0; j < s.size(); j++)
        {
            for (int i = 0; i <= j; i++)
            {
                if (s[i] == s[j] && (j - i < 2 || dp[i][j]))
                {
                    dp[i][j] = 1;
                    res++;
                }
            }
        }
        return res;
    }

    int countSubstrings2(string s)
    {
        int center_count = s.size() * 2 - 1;
        int res = 0;
        for (int i = 0; i < center_count; i++)
        {
            int left = i / 2;
            int right = i % 2 + left;
            while (left >= 0 && right < s.size() && s[left] == s[right])
            {
                res++;
                left--;
                right++;
            }
        }
        return res;
    }
};

int main()
{
    string str;
    cin >> str;

    Solution s;
    int res = s.countSubstrings2(str);
    cout << res << endl;
    return 0;
}