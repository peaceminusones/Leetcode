#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Solution
{
public:
    string convertToBase7(int num)
    {
        string res = "";

        int n = abs(num);
        while (n)
        {
            res = to_string(n % 7) + res;
            n /= 7;
        }

        if (num < 0)
            res = "-" + res;
        return res;
    }

    // 递归
    string convertToBase7_recur(int num)
    {
        if (num < 0)
            return "-" + convertToBase7_recur(-num);
        if (num < 7)
            return to_string(num);
        return convertToBase7_recur(num / 7) + to_string(num % 7);
    }
};

int main()
{
    int num;
    cin >> num;
    Solution s;
    string res = s.convertToBase7_recur(num);
    cout << res << endl;
    return 0;
}