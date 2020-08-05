#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // 4的n次方用二进制表示的话同样只有一个1，所以可以利用n&(n-1)，去掉最低为的1，即唯一的1
    // 所以如果n&(n-1)为0，说明是2的n次方
    // 再利用(num & 0b01010101010101010101010101010101)是否等于0筛选
    bool isPowerOfFour(int num)
    {
        return num > 0 && (num & (num - 1)) == 0 && ((num & 0b01010101010101010101010101010101) != 0);
    }
};

int main()
{
    int num;
    cin >> num;

    Solution s;
    bool res = s.isPowerOfFour(num);
    cout << res << " ";
    return 0;
}