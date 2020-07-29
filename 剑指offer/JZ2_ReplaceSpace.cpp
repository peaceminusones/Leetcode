#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution
{
public:
    void replaceSpace(char *str, int length)
    {
        if (str == nullptr || length <= 0)
            return;
        int cnt = 0;
        for (int i = 0; i < length; i++)
        {
            if (str[i] == ' ')
                cnt++;
        }

        if (cnt == 0)
            return;
        int newlength = length + 2 * cnt;
        for (int i = length; i >= 0; i--) // 从最后一个'\0'开始复制
        {
            if (str[i] == ' ')
            {
                str[newlength--] = '0';
                str[newlength--] = '2';
                str[newlength--] = '%';
            }
            else
            {
                str[newlength--] = str[i];
            }
        }
    }
};

int main()
{
    char *str = (char *)"We Are Happy";

    Solution s;
    s.replaceSpace(str, strlen(str));
    return 0;
}