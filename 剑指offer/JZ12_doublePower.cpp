#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution
{
public:
    double Power(double base, int exponent)
    {
        if (base == 0)
            return 0;
        if (exponent == 0)
            return 1;

        if (exponent < 0)
        {
            exponent = -exponent;
            base = 1 / base;
        }

        return PowerHelper(base, exponent);
    }

    // 快速幂
    double PowerHelper(double base, int exponent)
    {
        if (exponent == 0)
            return 1.0;

        double res = 1;
        while (exponent)
        {
            if (exponent % 2 == 1)
            {
                res *= base;
            }

            base *= base;
            exponent /= 2;
        }

        return res;
    }
};

int main()
{
    double base;
    int exponent;
    cin >> base >> exponent;
    Solution s;
    double res = s.Power(base, exponent);
    cout << res << endl;

    return 0;
}
