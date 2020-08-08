#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // 注意可能有负数
    int maximumProduct(vector<int> &nums)
    {
        if (nums.size() < 3)
            return 0;

        sort(nums.begin(), nums.end());
        int len = 3;
        int i = nums.size() - 1;
        int res1 = 1;
        while (len)
        {
            res1 *= nums[i--];
            len--;
        }

        len = 2;
        i = 0;
        int res2 = 1;
        while (len)
        {
            res2 *= nums[i];
            len--;
        }
        res2 *= nums[nums.size() - 1];

        return max(res1, res2);
    }
};

int main()
{
    return 0;
}