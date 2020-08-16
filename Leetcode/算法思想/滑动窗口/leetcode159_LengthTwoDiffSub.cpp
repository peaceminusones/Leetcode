#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstringTwoDistinct(string s)
    {
        int left = 0, right = 0;
        int res = 0;
        for (right = 0; right < s.size(); right++)
        {
            int count = diff(s.substr(left, right - left + 1));
            if (count <= 2)
                res = max(res, right - left + 1);
            else if (count > 2)
                left++;
        }
        return res;
    }

    int diff(string str)
    {
        unordered_map<char, bool> count;
        int sum = 0;
        for (auto s : str)
        {
            if (!count[s])
            {
                sum++;
                count[s] = 1;
            }
        }
        return sum;
    }

    // 优化！！！
    int lengthOfLongestSubstringTwoDistinct1(string s)
    {
        int left = 0, right = 0;
        unordered_map<char, int> count; // 用来记录当前窗口中不同字符的数量
        int diffstr = 0;                // 窗口中包含的不同字符的数量
        int res = 0;
        for (right = 0; right < s.size(); right++)
        {
            count[s[right]]++;
            if (count[s[right]] == 1) // 如果数量为1，说明是新加入的，不同的字符数量加一
                diffstr++;
            while (diffstr > 2) // 如果不同的字符数量大于2了
            {
                count[s[left]]--;        // 从左边界开始删除
                if (count[s[left]] == 0) // 如果s[left]的数量变为0了，就可以把不同的字符数量减一
                    diffstr--;
                left++; // 向右移动左边界
            }
            // 当前窗口的长度：right-left+1
            res = max(res, right - left + 1);
        }
        return res;
    }
};

int main()
{
    string str;
    cin >> str;
    Solution s;
    cout << s.lengthOfLongestSubstringTwoDistinct1(str) << endl;
    return 0;
}