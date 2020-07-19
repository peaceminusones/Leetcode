#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // 递归回溯！！错了！！！！！！
    // int findMaxForm(vector<string> &strs, int m, int n)
    // {
    //     int res = 0;
    //     int count = 0;
    //     dfs(strs, 0, m, n, res, count);
    //     return res;
    // }
    // void dfs(vector<string> &strs, int index, int m, int n, int &res, int &count)
    // {
    //     if (m < 0 && n < 0)
    //         return;

    //     res = max(res, count);

    //     for (int i = index; i < strs.size(); i++)
    //     {
    //         if (nums_zero(strs[i]) != 0 && nums_one(strs[i]) != 0 && m - nums_zero(strs[i]) > 0 && n - nums_one(strs[i]) < 0)
    //             continue;
    //         if (nums_zero(strs[i]) != 0 && nums_one(strs[i]) != 0 && m - nums_zero(strs[i]) < 0 && n - nums_one(strs[i]) > 0)
    //             continue;
    //         if (nums_zero(strs[i]) != 0 && nums_one(strs[i]) != 0 && m - nums_zero(strs[i]) < 0 && n - nums_one(strs[i]) < 0)
    //             continue;

    //         if (m > 0 || n > 0)
    //         {
    //             count++;
    //             dfs(strs, i + 1, m - nums_zero(strs[i]), n - nums_one(strs[i]), res, count);
    //             count--;
    //         }
    //     }
    // }

    // int nums_one(string &str)
    // {
    //     int count = 0;
    //     for (auto s : str)
    //     {
    //         if (s == '1')
    //             count++;
    //     }
    //     return count;
    // }

    // int nums_zero(string &str)
    // {
    //     int count = 0;
    //     for (auto s : str)
    //     {
    //         if (s == '0')
    //             count++;
    //     }
    //     return count;
    // }

    // 动态规划
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (auto str : strs)
        {
            vector<int> count = countzerosones(str);
            for (int i = m; i >= count[0]; i--)
            {
                for (int j = n; j >= count[1]; j--)
                {
                    dp[i][j] = max(dp[i][j], dp[i - count[0]][j - count[1]] + 1);
                }
            }
        }
        return dp[m][n];
    }

    vector<int> countzerosones(string &str)
    {
        vector<int> count(2);
        for (auto s : str)
        {
            count[s - '0']++;
        }
        return count;
    }

    // 两个容量的01背包，最大问题，和元素顺序无关
    int findMaxForm_final(vector<string> &strs, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (auto str : strs)
        {
            vector<int> acount = countzerosones(str);
            for (int i = m; i >= acount[0]; i--)
            {
                for (int j = n; j >= acount[1]; j--)
                {
                    dp[i][j] = max(dp[i][j], dp[i - acount[0]][j - acount[1]] + 1);
                }
            }
        }
        return dp[m][n];
    }
};

int main()
{
    vector<string> strs;
    string s;
    while (cin >> s)
    {
        strs.push_back(s);
        if (cin.get() == '\n')
            break;
    }

    int m, n;
    cin >> m >> n;

    Solution sol;
    int res = sol.findMaxForm_final(strs, m, n);
    cout << res << endl;
    return 0;
}