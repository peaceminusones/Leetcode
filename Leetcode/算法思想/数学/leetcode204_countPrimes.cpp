#include <iostream>
#include <math.h>
#include <vector>
#include <numeric>
using namespace std;

class Solution
{
public:
    // 超时！！
    int countPrimes_error(int n)
    {
        int count = 0;
        int flag = 0;
        if (n > 2)
            count++;

        for (int i = 3; i < n; i++)
        {
            for (int j = 2; j <= sqrt(i); j++)
            {
                if (i % j == 0)
                {
                    flag = 1;
                    break;
                }
            }

            if (flag == 0)
                count++;
            else
                flag = 0;
        }
        return count;
    }

    // 埃拉托斯特尼筛选法：每找到一个素数，将素数的倍数斗排除
    int countPrimes(int n)
    {
        if (n < 2)
            return 0;
        vector<bool> isprimes(n, 1); // 初始化都是素数
        isprimes[0] = 0;
        isprimes[1] = 0; // 0和1不是素数

        for (int i = 2; i <= sqrt(n); i++)
        {
            if (isprimes[i]) // 如果当前是素数
            {
                for (int j = i * i; j < n; j += i) // 从i*i开始，以i成等差数列的都不是素数 (4,6,8,10...)(9,12,15,18...)(16,20,24...)
                    isprimes[j] = false;
            }
        }

        return accumulate(isprimes.begin(), isprimes.end(), 0);
    }
};

int main()
{
    int count;
    cin >> count;
    Solution s;
    int res = s.countPrimes(count);
    cout << res << endl;
    return 0;
}