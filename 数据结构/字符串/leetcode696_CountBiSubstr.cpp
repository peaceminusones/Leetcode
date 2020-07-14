#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    // 按照字符分组计数
    int countBinarySubstrings(string s)
    {
        int res = 0;
        int preCount = 0, curCount = 1;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i - 1] == s[i])
                curCount++;
            else
            {
                res += min(preCount, curCount);
                preCount = curCount;
                curCount = 1;
            }
        }
        return res + min(preCount, curCount);
    }

    // 从中心扩散
    int countBinarySubstrings_center(string s)
    {
        int res = 0;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i - 1] == s[i])
                continue;

            int left = i - 1, right = i;
            char l = s[left], r = s[right];
            while (left >= 0 && right < s.size() && s[left] == l && s[right] == r)
            {
                left--;
                right++;
                res++;
            }
        }
        return res;
    }
};

int main()
{
    string s;
    cin >> s;

    Solution sol;
    int res = sol.countBinarySubstrings_center(s);
    cout << res << endl;
    return 0;
}