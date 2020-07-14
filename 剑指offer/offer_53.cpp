#include <iostream>
#include <cstring>
using namespace std;

class Solution
{
public:
    bool isNumeric(char *string)
    {
        if (string == NULL)
            return false;
        if (strlen(string) == 1 && (*string == '+' || *string == '-' || *string == 'e' || *string == 'E'))
            return false;

        // 三个标志位：符号、小数点、e是否出现过
        bool sign = false, decimal = false, hase = false;
        for (int i = 0; i < strlen(string); i++) // strlen(str) 其中最后一个'\0'也算进去了
        {

            if (string[i] == 'e' || string[i] == 'E')
            {
                if (i == 0 || (i > 0 && (string[i - 1] < '0' || string[i - 1] > '9'))) // e在第一个，或者e前面不是数字
                    return false;
                if (i == strlen(string) - 1) // e后面什么都没有，是错误表达
                    return false;
                if (hase) // 出现了两个e，是错误表达
                    return false;

                hase = true;
            }

            else if (string[i] == '+' || string[i] == '-')
            {
                // 第一次出现'+''-'符号，且不是在开头，则必须跟在e之后
                if (!sign && i > 0 && string[i - 1] != 'e' && string[i - 1] != 'E')
                    return false;
                // 第一次出现'+''-'符号，则必须跟在e之后
                if (sign && string[i - 1] != 'e' && string[i - 1] != 'E')
                    return false;

                sign = true;
            }

            else if (string[i] == '.')
            {
                // 小数点不能出现在e后面，且不能出现多次
                if (hase || decimal)
                    return false;

                decimal = true;
            }

            else if (string[i] < '0' || string[i] > '9') // 不合法字符
                return false;
        }

        return true;
    }
};

int main()
{
    char string[100];
    cin.getline(string, 100);
    Solution s;
    bool res = s.isNumeric(string);
    cout << res << endl;
    return 0;
}