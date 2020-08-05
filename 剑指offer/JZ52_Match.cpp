#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool match(char *str, char *pattern)
    {
        if (*str == '\0' && *pattern == '\0')
            return true;
        if (*str != '\0' && *pattern == '\0')
            return false;

        if (*(pattern + 1) == '*') // 下一个字符为*
        {
            // 当前字符相等 or 当前字符不相等，当时pattern为'.'也是相同的效果
            if (*str == *pattern || (*str != '\0' && *pattern == '.'))
            {
                // str匹配了0个当前位
                // str匹配了1个当前位
                // str匹配了多个当前位
                return match(str, pattern + 2) || match(str + 1, pattern + 2) || match(str + 1, pattern);
            }
            else // 当前字符不相等，或者也没有'.'可以任意替换，则利用'*'可以出现0次的特性，直接跳过
            {
                return match(str, pattern + 2);
            }
        }
        else // 下一个符号不为*，则一个一个比较
        {
            if (*str == *pattern || (*str != '\0' && *pattern == '.'))
            {
                return match(str + 1, pattern + 1);
            }
            else // 两个字符不相等，且后面没有*可以调整次数，则不能匹配
            {
                return false;
            }
        }
    }
};

int main()
{

    char *str = new char(20);
    char *pattern = new char(20);
    cin >> str >> pattern;
    Solution s;
    cout << s.match(str, pattern) << endl;
    return 0;
}