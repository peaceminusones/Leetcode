#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_map<int, int> count;
        for (auto si : s)
            count[si]++;

        int single = 0;
        int res = 0;
        for (auto c : count)
        {
            if (c.second % 2 == 0)
            {
                res += c.second;
            }
            else
            {
                single = 1;
                res += c.second - 1;
            }
        }
        return res + single;
    }

    // 简化一下
    int longestPalindrome1(string s)
    {
        unordered_map<int, int> count;
        for (auto si : s)
            count[si]++;

        int res = 0;
        for (auto c : count)
        {
            res += (c.second / 2) * 2; // 对于偶数，相当于直接加，对于奇数，相当于加（奇数-1）
        }

        if (res < s.size())
            res++;
        
        return res;
    }
};

int main()
{
    string s;
    cin >> s;

    Solution sol;
    int res = sol.longestPalindrome1(s);
    cout << res << endl;
    return 0;
}