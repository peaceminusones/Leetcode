#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        if (s.empty())
            return res;

        // 动态规划预处理字符串left位置到right位置是否为回文
        vector<vector<int>> dp(s.size());
        for (int i = 0; i < s.size(); i++)
            dp[i].resize(s.size());
        for (int right = 0; right < s.size(); right++)
        {
            for (int left = 0; left < right + 1; left++)
            {
                if (s[left] == s[right] && (right - left <= 2 || dp[left + 1][right - 1] == 1))
                    dp[left][right] = 1;
            }
        }

        vector<string> cur;
        backtrack(s, 0, cur, res, dp);
        return res;
    }

    void backtrack(string s, int start, vector<string> &cur, vector<vector<string>> &res, vector<vector<int>> &dp)
    {
        if (start == s.size())
        {
            res.push_back(cur);
            return;
        }

        for (int i = start; i < s.size(); i++)
        {
            // string tmp = s.substr(start, i - start + 1);
            if (dp[start][i])
            {
                // cout << start << " " << i << endl;
                // cout << s.substr(start, i - start + 1) << endl;
                string tmp = s.substr(start, i - start + 1);
                cur.push_back(tmp);
                backtrack(s, i + 1, cur, res, dp);
                cur.pop_back();
            }
        }
    }

    bool validate(string s)
    {
        if (s.size() == 1)
            return true;
        int n = s.size();
        for (int i = 0; i < n / 2; i++)
        {
            if (s[i] != s[n - i - 1])
                return false;
        }
        return true;
    }
};

int main()
{
    string s;
    cin >> s;

    Solution sol;
    vector<vector<string>> res = sol.partition(s);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}