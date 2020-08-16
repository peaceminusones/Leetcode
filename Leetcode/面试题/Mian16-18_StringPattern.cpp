#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool patternMatching(string pattern, string value)
    {
        if (pattern.empty() && value.empty())
            return true;
        if (pattern.empty())
            return false;

        // 模式串中a的数量，b的数量
        int ca = 0, cb = 0;
        for (auto p : pattern)
        {
            if (p == 'a')
                ca++;
            else
                cb++;
        }

        // pattern为空，value不为空
        if (!pattern.empty() && value.empty())
            if (ca == 0 || cb == 0) // 如果只有a或者只有b，则返回true
                return true;
            else // 如果ab都有，则返回false；
                return false;

        int len_a = 0, len_b = 0;
        if (ca != 0)
            len_a = value.size() / ca; // 如果都用a来匹配，a可匹配的长度最长为len_a
        if (cb != 0)
            len_b = value.size() / cb; // 如果都用b来匹配，b可匹配的长度最长为len_b

        for (int i = 0; i <= len_a; i++)
        {
            for (int j = 0; j <= len_b; j++)
            {
                // 如果（a可匹配的长度）*(a的数量)+（b可替换的长度）*（b的数量）== value的大小
                if (i * ca + j * cb == value.size())
                {
                    string sa = ""; // 表示a匹配的字符串
                    string sb = ""; // 表示b匹配的字符串
                    int index = 0;  // index表示value中的开始位置
                    // 遍历模式串pattern
                    for (int k = 0; k < pattern.size(); k++)
                    {
                        if (pattern[k] == 'a') // 如果pattern是'a'
                        {
                            // 给a匹配的字符串赋值
                            if (sa.empty())
                                sa = value.substr(index, i);       // i是a可匹配的长度
                            else if (sa != value.substr(index, i)) // 这次a匹配的字符串和上次不一样，则跳出循环
                                break;
                            index += i; // 开始位置增加了a的长度
                        }
                        else
                        {
                            // 给b匹配的字符串赋值
                            if (sb.empty())
                                sb = value.substr(index, j);       // j是b可匹配的长度
                            else if (sb != value.substr(index, j)) // 这次b匹配的字符串和上次不一样，则跳出循环
                                break;
                            index += j; // 开始位置增加了b的长度
                        }
                    }
                    // 如果遍历到结尾了，且sa和sb字符串还不相等，则返回true
                    if (index == value.size() && sa != sb)
                        return true;
                }
            }
        }

        return false;
    }
};

int main()
{
    string pattern, value;
    cin >> pattern >> value;
    Solution s;
    cout << s.patternMatching(pattern, value) << endl;

    return 0;
}