#include <iostream>
#include <string>
using namespace std;

/*
***??????????有问题！！！！！！！！！！！！！！！
边界条件：
    数据上下 溢出
    空字符串
    只有正负号
    有无正负号
    错误标志输出
*/

class Solution
{
public:
    long long StrToInt(string str)
    {
        long long sum = 0;
        int n = str.length(), symbol = 1;
        if (!n) // 空字符
            return 0;

        if (str[0] == '-')
            symbol = -1;

        for (int i = (str[0] == '-' || str[0] == '+') ? 1 : 0; i < n; i++)
        {
            if (!('0' <= str[i] && str[i] <= '9'))
                return 0;

            sum = (sum << 1) + (sum << 3) + (str[i] & 0xf);
            cout << "::" << sum << "  " << sum * symbol << endl;
            // if (sum * symbol > INT_MAX)
            //     return INT_MAX;
            // if (sum * symbol < INT_MIN)
            //     return INT_MIN;
        }

        return sum * symbol;
    }
};

int main()
{
    string str;
    cin >> str;
    Solution s;
    long long res = s.StrToInt(str);
    cout << res << endl;
    cout << "max:" << INT_MAX << endl;
    cout << "min:" << INT_MIN << endl;
    return 0;
}

// class Solution
// {
// public:
//     int StrToInt(string str)
//     {
//         int res = 0, n = str.size(), symbol = 1;
//         if (!n)
//             return 0;

//         int start = 0;
//         // for (start = 0; start < n; start++)
//         // {
//         //     if (str[start] == '-' || str[start] == '+' || ('0' <= str[start] && str[start] <= '9'))
//         //         break;
//         // }

//         if (str[start] == '-')
//             symbol = -1;

//         for (int i = (str[start] == '-' || str[start] == '+') ? start + 1 : start; i < n; i++)
//         {
//             if (!('0' <= str[i] && str[i] <= '9'))
//                 return 0;
//             // res = res*10 + str[i] - '0';
//             res = (res << 1) + (res << 3) + (str[i] & 0xf); //这里利用位运算提高计算效率
//         }

//         return res * symbol;
//     }
// };