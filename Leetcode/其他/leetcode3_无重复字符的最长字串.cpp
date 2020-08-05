#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Solution
{
public:
    /*
     * 滑动窗口解法
    */
    int lengthOfLongestSubstring(string s)
    {
        vector<int> m(128, 0); // m来记录一个字符如果后面出现重复时，start应该调整到的新位置（即当前位置的下一个位置！！！！）
        int maxlen = 0;        // 最大字串长度
        int start = 0;         // start：滑动窗口起始边界 end：滑动窗口结束边界
        for (int end = 0; end < s.size(); end++)
        {
            /*
             * start与当前字符位置比较，选择大的：
             *     如果字符s[end]不曾出现过，则m[s[end]]=0，那么仍然是当前的start不变
             *     如果字符s[end]曾出现过，则比较start和m[s[end]]的大小，选择大的，以防出现重新跳转回去的情况
            */
            start = max(start, m[s[end]]);
            // 记录如果字符s[end]会重复出现，则start需要调整到end+1的位置
            m[s[end]] = end + 1;
            // 更新最大长度
            maxlen = max(maxlen, end - start + 1);
        }
        return maxlen;
    }
};

int main()
{
    string s;
    cin >> s;

    Solution sol;
    int res = sol.lengthOfLongestSubstring(s);
    cout << res << endl;

    return 0;
}