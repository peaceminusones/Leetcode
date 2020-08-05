#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

class Solution
{
public:
    bool isNumeric(char *string)
    {
        bool sign = false, point = false, e = false;
        int i = 0;
        while (*(string + i) != '\0')
        {
            // 如果当前是e
            if (*(string + i) == 'e' || *(string + i) == 'E')
            {
                if (e)
                    return false; // 前面出现过e了
                if (*(string + i + 1) == '\0')
                    return false; // e后面什么都没有了
                if (i == 0 || (i > 0 && (*(string + i - 1) < '0' || *(string + i - 1) > '9')))
                    return false; // e在第一个，或者e前面什么都没有

                e = true;
            }
            // 如果当前是'+'or'-'
            else if (*(string + i) == '+' || *(string + i) == '-')
            {
                // 如果是第一次出现，则可以在一开始，也可以在e的后面
                // 如果它不在一开始，也不在e的后面，也不在E的后面，则是错误的
                if (!sign && i > 0 && *(string + i - 1) != 'e' && *(string + i - 1) != 'E')
                    return false;
                // 如果不是第一个出现，则只能出现在e的后面
                // 如果不在e后面，也不在E的后面，则是错的
                if (sign && *(string + i - 1) != 'e' && *(string + i - 1) != 'E')
                    return false;

                sign = true;
            }
            // 如果当前位是小数点'.'
            else if (*(string + i) == '.')
            {
                // 如果小数点出现在e后面，或者出现多次，都是错的
                if (e || point)
                    return false;

                point = true;
            }
            // 其他不合法的数字
            else if (*(string + i) < '0' || *(string + i) > '9')
                return false;

            i++;
        }

        return true;
    }
};

int main()
{
    char *str = new char(20);
    cin >> str;
    Solution s;
    cout << s.isNumeric(str) << endl;
    return 0;
}