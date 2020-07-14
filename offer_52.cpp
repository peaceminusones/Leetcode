#include <iostream>
#include <string>
using namespace std;

/*
    【字符串匹配】
    '.'表示任意一个字符
    '*'表示前面的字符可以出现任意次（包含0次
*/
class Solution
{
public:
    bool match(char *str, char *pattern)
    {
        if (*str == '\0' && *pattern == '\0')
            return true;
        if (*str != '\0' && *pattern == '\0')
            return false;

        // 如果pattern下个字符不为‘*’
        if (*(pattern + 1) != '*')
        {
            if (*str == *pattern || (*str != '\0' && *pattern == '.')) // 当前字符相同，或者pattern当前位是‘.’
            {
                return match(str + 1, pattern + 1); // 同时往后移动一位
            }
            else
            {
                return false;
            }
        }
        // 如果pattern的下个字符为‘*’
        else
        {
            if (*str == *pattern || (*str != '\0' && *pattern == '.')) // 当前字符相同，或者pattern当前位是‘.’
            {
                // 三种情况：
                //     str与0个当前位匹配；
                //     str与1个当前位置匹配；
                //     str与多个当前位置匹配。
                return match(str, pattern + 2) || match(str + 1, pattern + 2) || match(str + 1, pattern);
            }
            else
            {
                // str当前位与pattern当前位不匹配，则利用符号‘*’的特性，忽略当前位
                return match(str, pattern + 2);
            }
        }
    }
};

int main()
{

    char str[100];
    cin.getline(str, 100);
    int i = 0;
    // while (str[i] != '\0')
    //     cout << str[i++] << endl;

    char pattern[100];
    cin.getline(pattern, 100);
    int j = 0;
    // while (pattern[j] != '\0')
    //     cout << pattern[j++] << endl;
    Solution s;
    bool res = s.match(str, pattern);
    cout << res << endl;

    return 0;
}