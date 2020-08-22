#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string str)
    {
        if (str.empty() || str.size() == 1)
            return str;

        vector<vector<int>> dp(str.size(), vector<int>(str.size()));
        for (int i = 0; i < str.size(); i++)
        {
            dp[i][i] = 1;
        }

        string res = "";
        for (int i = 0; i <= str.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (str[j] == str[i] && (j - i < 2 || dp[i - 1][j + 1] == 1))
                {
                    if (j, i - j + 1 > res.size())
                        res = str.substr(j, i - j + 1);
                }
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
    cout << s.longestPalindrome(str) << endl;
    return 0;
}