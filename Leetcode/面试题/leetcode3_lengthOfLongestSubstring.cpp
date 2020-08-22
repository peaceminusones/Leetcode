#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    // 无重复字符串的最长字串
    int lengthOfLongestSubstring(string s)
    {
        if (s.empty())
            return 0;
        // 用于存储eg: {a:1}，a如果再次出现，要把left移动到1位置
        unordered_map<char, int> appear;
        int res = 0;
        int left = 0, right = 0;
        for (; right < s.size(); right++)
        {
            left = max(left, appear[s[right]]);
            appear[s[right]] = right + 1;
            res = max(res, right - left + 1);
        }
        return res;
    }
};

int main()
{
    return 0;
}