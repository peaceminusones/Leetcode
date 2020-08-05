#include <iostream>
#include <math.h>
using namespace std;

class Solution
{
public:
    /*
     * 超出时间限制！！！=================================================================
    */
    // bool judgeSquareSum(int c)
    // {
    //     if (c == 0)
    //         return true;

    //     int i = 1;
    //     while (pow(i, 2) <= c)
    //     {
    //         int diff = c - pow(i, 2);
    //         if (diff == 0 || IsSqrt(diff))
    //             return true;
    //         i++;
    //     }
    //     return false;
    // }
    // bool IsSqrt(int num)
    // {
    //     for (int i = 1; num > 0; i += 2)
    //         num -= i;
    //     if (num == 0)
    //         return true;
    //     else
    //         return false;
    // }
    /*
     * ==================================================================================
    */

    // bool judgeSquareSum(int c)
    // {
    //     if (c == 0)
    //         return true;

    //     int i = 0, j = sqrt(c);
    //     while (i <= j)
    //     {
    //         if (pow(i, 2) + pow(j, 2) == c)
    //             return true;
    //         else if (pow(i, 2) + pow(j, 2) < c)
    //             i++;
    //         else if (pow(i, 2) + pow(j, 2) > c)
    //             j--;
    //     }
    //     return false;
    // }

    bool judgeSquareSum(int c)
    {
        if (c == 0)
            return true;

        int i = 1;
        while (pow(i, 2) <= c)
        {
            int diff = c - pow(i, 2);
            if (diff == 0 || double(sqrt(diff)) == int(sqrt(diff)))
                return true;
            i++;
        }
        return false;
    }
};

int main()
{
    int c;
    cin >> c;

    Solution s;
    bool res = s.judgeSquareSum(c);
    cout << res << endl;

    return 0;
}