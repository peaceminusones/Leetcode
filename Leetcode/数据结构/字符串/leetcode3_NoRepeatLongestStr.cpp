#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.empty())
            return 0;

        unordered_map<char, int> appear; // 用于记录窗口中每个字符出现的位置
        int res = 0;
        int left = 0, right = 0;
        for (right = 0; right < s.size(); right++)
        {
            // left = max(left, appear[s[right]]);
            // appear[s[right]] = right + 1;
            // res = max(res, right - left + 1);
            //如果s[right]出现过了，且出现的位置在滑动窗口中
            if (appear.find(s[right]) != appear.end() && appear[s[right]] > left)
            {
                // 移动窗口左边
                left = appear[s[right]];
                // 更新s[right]的位置
                appear[s[right]] = right + 1;
            }
            else // 如果s[right]还没有出现过，或者出现的位置在滑动窗口之外
            {
                // 则添加，并扩展窗口大小
                appear[s[right]] = right + 1;
                // 记录当前不重复子串的最大值
                res = max(res, right - left + 1);
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
    cout << sol.lengthOfLongestSubstring(s) << endl;
    return 0;
}