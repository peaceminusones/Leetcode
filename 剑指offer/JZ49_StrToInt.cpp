#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int StrToInt(string str)
    {
        int flag = 1;
        int i = 0;
        if (str[0] == '-')
        {
            flag = -1;
            i = 1;
        }
        else if (str[0] == '+')
        {
            i = 1;
        }

        int sum = 0;
        for (; i < str.size(); i++)
        {
            if (str[i] < '0' || str[i] > '9')
                return 0;
            sum = sum * 10 + (str[i] - '0');
        }
        return sum * flag;
    }
};

int main()
{
    string str;
    cin >> str;
    Solution s;
    cout << s.StrToInt(str) << endl;
    return 0;
}