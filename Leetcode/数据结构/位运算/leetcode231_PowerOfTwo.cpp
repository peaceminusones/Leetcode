#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // 2的n次方用二进制表示的话只有一个1，所以可以利用n&(n-1)，去掉最低为的1，即唯一的1
    // 所以如果n&(n-1)为0，说明是2的n次方
    bool isPowerOfTwo(int n)
    {
        return n > 0 && (n & (n - 1)) == 0;
    }
};

int main()
{
    int num;
    cin >> num;

    Solution s;
    bool res = s.isPowerOfTwo(num);
    cout << res << " ";
    return 0;
}