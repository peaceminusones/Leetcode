#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        // 窗口内每个字符出现的次数
        unordered_map<int, int> count;
        // 窗口内次数最多的字符出现数
        int maxCount = 0;
        int left = 0, right = 0;
        int res = 0;
        for (right = 0; right < s.size(); right++)
        {
            count[s[right] - 'A']++;
            maxCount = max(maxCount, count[s[right] - 'A']);
            // 如果重复字符加上替换个数k，已经小于窗口值了，则平移窗口
            if (maxCount + k < right - left + 1)
            {
                // 去掉左边字符
                count[s[left] - 'A']--;
                left++;
            }
            // 如果重复字符加上替换个数k，大于等于窗口值，则扩展窗口大小
            // 并记录当前最大值(即窗口大小)
            else
            {
                res = max(res, right - left + 1);
            }
        }

        return res;
    }
};

int main()
{
    return 0;
}