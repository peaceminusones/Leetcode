#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // 最大公约数
    int gcd(int a, int b)
    {
        return b == 0 ? a : gcd(b, a % b);
    }

    // 最小公倍数
    int lcm(int a, int b)
    {
        return (a * b) / gcd(a, b);
    }

    // 位操作+减法 最大公约数
    int gcd_bit(int a, int b)
    {
        if (a < b)
            return gcd(b, a);
        if (b == 0)
            return a;

        if (a % 2 == 0 && b % 2 == 0)
            return 2 * gcd(a >> 1, b >> 1);
        else if (a % 2 == 0 && b % 2 != 0)
            return gcd(a >> 1, b);
        else if (a % 2 != 0 && b % 2 == 0)
            return gcd(a, b >> 1);
        else
            return gcd(b, a - b);
    }
};

int main()
{
    int a, b;
    cin >> a >> b;
    Solution s;
    cout << s.gcd(a, b) << endl;
    cout << s.lcm(a, b) << endl;
    cout << s.gcd_bit(a, b) << endl;
    return 0;
}