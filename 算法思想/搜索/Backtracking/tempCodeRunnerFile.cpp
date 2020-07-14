vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        if (s.empty())
            return res;

        // 动态规划预处理字符串i位置到j位置是否为回文
        vector<vector<int>> dp(s.size());
        for (int i = 0; i < s.size(); i++)
            dp[i].resize(s.size());
        for (int right = 0; right < s.size(); right++)
        {
            for (int left = 0; left < right + 1; left++)
            {
                if (s[left] == s[right] && (right - left <= 2 || s[left + 1] == s[right - 1]))
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
                string tmp = s.substr(start, i - start + 1);
                cur.push_back(tmp);
                backtrack(s, i + 1, cur, res, dp);
                cur.pop_back();
            }
        }
    }