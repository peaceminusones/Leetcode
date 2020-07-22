#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        //dp[i][j]:word1[0..i]替换成word2[0..j]需要的最少的操作步骤
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1));
        // 第一行初始化
        for (int i = 0; i <= word2.size(); i++)
        {
            dp[0][i] = i;
        }
        // 第一列初始化
        for (int i = 0; i <= word1.size(); i++)
        {
            dp[i][0] = i;
        }

        for (int i = 1; i <= word1.size(); i++)
        {
            for (int j = 1; j <= word2.size(); j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    // 替换 | 删除 | 添加
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    Solution s;
    int res = s.minDistance(s1, s2);
    cout << res << endl;
    return 0;
}