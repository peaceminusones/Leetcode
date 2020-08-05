#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findComplement(int num)
    {
        if (num == 0)
            return 1;
        int mask = 1 << 30;
        // 找到最高位的1的位置
        while ((num & mask) == 0)
            mask >>= 1;
        // 得到1到该最高位都为1的掩码
        mask = (mask << 1) - 1;

        return num ^ mask;
    }
};

int main()
{
    int num;
    cin >> num;

    Solution s;
    int res = s.findComplement(num);
    cout << res << " ";
    return 0;
}