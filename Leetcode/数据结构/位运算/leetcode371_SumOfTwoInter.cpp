#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int getSum(int a, int b)
    {
        // if (!(a & b))
        //     return a ^ b;                                   // 当进位为0时，返回两数相加不进位的加法结果
        // return getSum(a ^ b, ((unsigned int)(a & b)) << 1); // 否则，递归计算不进位加法结果与进位之和

        // while (b)
        // {
        //     int carry = unsigned(a & b) << 1;
        //     a ^= b;
        //     b = carry;
        // }
        // return a;

        // 注意leetcode规定int左移时最高为必须为0，否则左移报错(INT_MIN最高位1)
        return (a & b) == 0 ? (a | b) : getSum(a ^ b, (unsigned int)(a & b) << 1);
    }
};

int main()
{
    int a, b;
    cin >> a >> b;

    Solution s;
    int res = s.getSum(a, b);
    cout << res << endl;
    return 0;
}