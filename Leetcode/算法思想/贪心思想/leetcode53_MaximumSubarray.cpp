#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    /*
     * 对数组进行遍历，当前最大连续子序列和为curmax，结果为res
     * 如果curmax>0，则说明curmax对结果有增益作用，则curmax保留并加上当前遍历数字
     * 如果curmax<0，则说明curmax对结果无增益作用，则curmax直接更新为当前遍历的数字
     * 
     * 每次都比较curmax和res的大小，将最大值置为res
    */
    int maxSubArray(vector<int> &nums)
    {
        int curmax = nums[0]; // 当前最大连续子数组的和
        int res = nums[0];    // 结果（最大的连续子数组的和）
        for (int i = 1; i < nums.size(); i++)
        {
            curmax = curmax > 0 ? curmax + nums[i] : nums[i];
            res = max(res, curmax);
        }
        return res;
    }
};

int main()
{
    vector<int> nums;
    int item;
    while (cin >> item)
    {
        nums.push_back(item);
    }

    Solution s;
    int res = s.maxSubArray(nums);
    cout << res << endl;

    return 0;
}