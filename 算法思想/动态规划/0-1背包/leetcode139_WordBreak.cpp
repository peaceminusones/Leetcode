#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // 动态规划
    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<bool> dp(s.size() + 1);
        dp[0] = 1;
        for (int i = 0; i < s.size() + 1; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                auto it = find(wordDict.begin(), wordDict.end(), s.substr(j, i - j));
                if (dp[j] && it != wordDict.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }

    // 动态规划2
    bool wordBreak2(string s, vector<string> &wordDict)
    {
        vector<bool> dp(s.size() + 1);
        dp[0] = 1;
        for (int i = 0; i < s.size() + 1; i++)
        {
            for (int j = i + 1; j < s.size() + 1; j++)
            {
                auto it = find(wordDict.begin(), wordDict.end(), s.substr(i, j - i));
                if (dp[i] && it != wordDict.end())
                {
                    dp[j] = true;
                }
            }
        }
        return dp[s.size()];
    }

    // 递归回溯(超时)
    bool wordBreak_backtrack(string s, vector<string> &wordDict)
    {
        return backtracking(s, wordDict, 0);
    }

    bool backtracking(string s, vector<string> &wordDict, int index)
    {
        if (index == s.size())
            return true;

        for (int i = index + 1; i <= s.size(); i++)
        {
            auto it = find(wordDict.begin(), wordDict.end(), s.substr(index, i - index));
            if (it != wordDict.end())
            {
                if (backtracking(s, wordDict, i))
                    return true;
            }
        }
        return false;
    }

    // 完全背包，和元素顺序有关，true-false问题
    bool wordBreak_final(string s, vector<string> &wordDict)
    {
        vector<bool> dp(s.size() + 1);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                auto it = find(wordDict.begin(), wordDict.end(), s.substr(j, i - j));
                if (dp[j] && it != wordDict.end())
                    dp[i] = true;
            }
        }
        return dp[s.size()];
    }
};

int main()
{
    string s;
    cin >> s;
    vector<string> wordDict;
    string word;
    while (cin >> word)
    {
        wordDict.push_back(word);
        if (cin.get() == '\n')
            break;
    }

    Solution sol;
    bool res = sol.wordBreak_final(s, wordDict);
    cout << res << endl;
    return 0;
}