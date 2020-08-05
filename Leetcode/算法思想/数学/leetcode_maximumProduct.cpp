#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    // 有正有负.共有两种情况可以产生最大解，其一：三个最大数；其二：一个最大数，两个最小数
    int maximumProduct(vector<int> &nums)
    {
        if (nums.size() < 3)
            return 0;

        sort(nums.begin(), nums.end());
        // 三个最大数
        int len = 3;
        int i = nums.size() - 1;
        int res1 = 1;
        while (len)
        {
            res1 *= nums[i--];
            len--;
        }

        // 一个最大数，两个最小数
        len = 2;
        i = 0;
        int res2 = 1;
        while (len)
        {
            res2 *= nums[i++];
            len--;
        }
        res2 *= nums[nums.size() - 1];

        return max(res1, res2);
    }
};

int main()
{
    vector<int> nums;
    int item;
    while (cin >> item)
    {
        nums.push_back(item);
        if (cin.get() == '\n')
            break;
    }

    Solution s;
    int res = s.maximumProduct(nums);
    cout << res << endl;
    return 0;
}