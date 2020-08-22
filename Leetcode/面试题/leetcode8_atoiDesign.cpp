#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    int myAtoi(string str)
    {
        regex reg1("[a-zA-Z\\.\\+\\-\\s]$");
        // 字符串为空，或者字符串只有一个空格
        if (regex_match(str, reg1))
            return 0;

        // 如果第一个字符就是字母，则直接返回0
        regex reg("[a-zA-Z\\.]+[\\d]*$");
        if (regex_match(str, reg))
            return 0;

        long long res = 0;
        int flag = 1;

        regex reg2("[a-zA-Z\\s\\.]+[\\d]*$");
        for (int i = 0; i < str.size() && !regex_match(str.substr(i), reg2); i++)
        {
            if (str[i] == ' ')
                continue;
            if (str[i] == '+')
                continue;
            if (str[i] == '-')
            {
                flag = -1;
                continue;
            }
            if (res >= INT_MAX && flag == 1)
                return INT_MAX;
            if (res > INT_MAX && flag == -1)
                return INT_MIN;

            res = res * 10 + str[i] - '0';
        }
        return flag * res;
    }
};

int main()
{
    string str;
    cin >> str;
    Solution s;
    cout << s.myAtoi(str) << endl;
    return 0;
}