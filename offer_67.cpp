#include <iostream>
#include <math.h>
using namespace std;

class Solution
{
public:
    int cutRope(int number)
    {
        if (number == 2)
            return 1;
        if (number == 3)
            return 2;

        int x = number % 3;
        int y = number / 3;
        if (x == 0)
        {
            return pow(3, y);
        }
        else if (x == 1)
        {
            return 2 * 2 * pow(3, y - 1);
        }
        else
        {
            return 2 * pow(3, y);
        }
    }
};

int main()
{
    int n;
    cin >> n;

    Solution s;
    int res = s.cutRope(n);
    cout << res << endl;

    return 0;
}