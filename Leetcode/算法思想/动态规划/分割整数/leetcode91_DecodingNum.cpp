#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    // 想错啦！！！！！！！！！，，
    // int numDecodings(string s)
    // {
    //     vector<int> dp(s.size() + 1);
    //     for (int i = 0; i < s.size(); i++)
    //     {
    //         for (int j = 0; j <= i; j++)
    //         {
    //             if (stoi(s.substr(i, j + 1)) >= 1 && stoi(s.substr(i, j + 1)) <= 26)
    //             {
    //                 dp[i] += dp[i - j] + 1;
    //             }
    //         }
    //     }
    //     return dp[s.size() - 1];
    // }

    int numDecodings(string s)
    {
        if (s[0] == '0')
            return 0;

        vector<int> dp(s.size() + 1);
        dp[0] = 1;
        if (s[1] == '0' && stoi(s.substr(0, 2)) > 26)
            return 0;
        else if (s[1] == '0' && stoi(s.substr(0, 2)) <= 26)
            dp[1] = 1;
        else if (s[1] != '0' && stoi(s.substr(0, 2)) > 26)
            dp[1] = 1;
        else if (s[1] != '0' && stoi(s.substr(0, 2)) <= 26)
            dp[1] = 2;

        for (int i = 2; i < s.size(); i++)
        {
            if (s[i] == '0')
            {
                if (s[i - 1] == '0' || stoi(s.substr(i - 1, 2)) > 26)
                    return 0;
                else
                {
                    dp[i] = dp[i - 2];
                }
            }
            else
            {
                if (s[i - 1] == '0' || (s[i - 1] != '0' && stoi(s.substr(i - 1, 2)) > 26))
                    dp[i] = dp[i - 1];
                else
                {
                    dp[i] = dp[i - 1] + dp[i - 2];
                }
            }
            // if (s[i] == '0' && s[i - 1] == '0')
            //     return 0;
            // if (s[i] == '0' && stoi(s.substr(i - 1, 2)) > 26)
            //     return 0;
            // if (s[i] == '0' && stoi(s.substr(i - 1, 2)) <= 26)
            //     dp[i] = dp[i - 2];
            // if (s[i] != '0' && s[i - 1] == '0')
            //     dp[i] = dp[i - 1];
            // if (s[i] != '0' && s[i - 1] != '0' && stoi(s.substr(i - 1, 2)) > 26)
            //     dp[i] = dp[i - 1];
            // if (s[i] != '0' && s[i - 1] != '0' && stoi(s.substr(i - 1, 2)) <= 26)
            //     dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[s.size() - 1];
    }
};

int main()
{
    string s;
    cin >> s;
    Solution sol;
    int res = sol.numDecodings(s);
    cout << res << endl;

    return 0;
}