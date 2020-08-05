#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // 异或操作+右移操作
    int hammingDistance(int x, int y)
    {
        int count = 0;
        // 异或
        int z = x ^ y;
        while (z != 0)
        {
            if (z & 1 == 1)
                count++;
            z >>= 1;
        }
        return count;
    }

    // 使用z&(z-1)取出z的最低位置的1
    int hammingDistance1(int x, int y)
    {
        int count = 0;
        // 异或
        int z = x ^ y;
        while (z != 0)
        {
            z &= (z - 1);
            count++;
        }
        return count;
    }
};

int main()
{
    int x, y;
    cin >> x >> y;
    Solution s;
    int res = s.hammingDistance1(x, y);
    cout << res << endl;
    return 0;
}