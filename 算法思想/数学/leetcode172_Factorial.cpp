#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // 太大了！！！用其他方法
    // int trailingZeroes(int n)
    // {
    //     if (n == 0)
    //         return 0;
    //     n = factorial(n);
    //     int count = 0;
    //     while (n % 10 == 0)
    //     {
    //         count++;
    //         n /= 10;
    //     }
    //     return count;
    // }

    // int factorial(int n)
    // {
    //     if (n == 1)
    //         return 1;
    //     return n * factorial(n - 1);
    // }

    // 计算因子5出现次数
    int trailingZeroes(int n)
    {
        int count = 0;
        while (n > 0)
        {
            count += (n / 5);
            n /= 5;
        }
        return count;
    }

    int trailingZeroes2(int n)
    {
        int count = 0;
        while (n > 0)
        {
            count += (n / 2);
            n /= 2;
        }
        return count;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution s;
    int res = s.trailingZeroes2(n);
    cout << res << endl;
    return 0;
}