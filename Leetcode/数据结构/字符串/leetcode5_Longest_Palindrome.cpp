#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string palindrome(string str)
    {
        string res = "";
        vector<vector<int>> dp(str.size(), vector<int>(str.size()));
        for (int i = 0; i < str.size(); i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (str[j] == str[i] && (i - j < 2 || dp[j + 1][i - 1]))
                {
                    dp[i][j] = 1;
                    if (i - j + 1 > res.size())
                        res = str.substr(j, i - j + 1);
                }
            }
        }
        return res;
    }

    string palindrome2(string str)
    {
        string res = "";
        int centercount = 2 * str.size() - 1;
        for (int center = 0; center < centercount; center++)
        {
            int left = center / 2;
            int right = center % 2 + left;
            while (left >= 0 && right < str.size() && str[left] == str[right])
            {
                if (right - left + 1 > res.size())
                    res = str.substr(left, right - left + 1);
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
    cout << s.palindrome2(str) << endl;
    return 0;
}