#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        int i = 3;
        int n = 1;
        while (n < num)
        {
            n += i;
            i += 2;
        }
        return n == num;
    }

    bool isPerfectSquare2(int num)
    {
        int n = 1;
        while (num > 0)
        {
            num -= n;
            n += 2;
        }
        return num == 0;
    }
};
int main()
{
    int num;
    cin >> num;

    Solution s;
    int res = s.isPerfectSquare2(num);
    cout << res << endl;
    return 0;
}