#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        if (nums.size() < 1)
            return;

        // 从后往前找到第一个升序的元素对
        int i = nums.size() - 2, j = nums.size() - 1;
        while (i >= 0 && nums[i] >= nums[j])
        {
            i--;
            j--;
        }

        // 没有找到升序的元素对，说明全是降序，已经是最大
        // 返回最小排列
        if (i < 0)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        // 找到了升序的元素对
        // 再从后往前找到第一个比nums[i]大的值
        int k = nums.size() - 1;
        while (k >= 0 && nums[i] >= nums[k])
            k--;
        swap(nums[i], nums[k]);

        // 把j后面的元素（包括j）全部升序排列
        for (int i = j, j = nums.size() - 1; i < j; i++, j--)
            swap(nums[i], nums[j]);
    }
};

int main()
{
    return 0;
}