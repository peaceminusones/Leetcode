#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        // 不断的把n的最后一位输送到res的最后一位，res再不断的左移
        uint32_t res = 0;
        for (int i = 0; i < 32; i++)
        {
            res <<= 1;
            res += (n & 1);
            n >>= 1;
        }
        return res;
    }

    // 如果函数需要被多次调用，则拆成4个byte，然后拼接起来
    // uint32_t reverseBits2(uint32_t n)
    // {
    //     uint32_t res = 0;
    //     for (int i = 0; i < 4; i++)
    //     {
    //         res <<= 8;
    //         res += reverseBitshelper((n & 0b1111111));
    //         n >>= 8;
    //     }
    //     return res;
    // }

    // uint8_t reverseBitshelper(uint8_t n)
    // {
    //     // 不断的把n的最后一位输送到res的最后一位，res再不断的左移
    //     uint8_t res = 0;
    //     uint8_t b = n;
    //     for (int i = 0; i < 8; i++)
    //     {
    //         res <<= 1;
    //         res += (b & 1);
    //         b >>= 1;
    //     }
    //     return res;
    // }
};

int main()
{
    uint32_t n;
    cin >> n;

    Solution s;
    uint32_t res = s.reverseBits2(n);
    cout << res << " ";

    return 0;
}