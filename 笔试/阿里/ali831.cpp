#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int longestSeq(string str)
    {
        string str1 = "";
        string str2 = "";
        for (auto s : str)
        {
            if (s == 'a' || s == 'c' || s == 'e')
                str1.push_back(s);
            else
                str2.push_back(s);
        }
        return maxLength(str1) + maxLength(str2);
    }

    int maxLength(string str)
    {
        vector<int> dp(str.size());
        dp[0] = 1;
        int res = 1;
        for (int i = 1; i < str.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (str[i] >= str[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};

int main()
{
    string str;
    cin >> str;

    Solution s;
    int res = s.longestSeq(str);
    cout << res << endl;
    return 0;
}