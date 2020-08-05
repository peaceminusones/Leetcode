#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    /*
     * 二分查找
    */
    int findMin(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[r]) // 转折点在右边，或者最小值在右边(递减序列)
                l = mid + 1;
            else // (nums[mid] < nums[r]) 转折点在左边，或者最小值在左边（递增序列），或者mid是最小值
                r = mid;
        }
        return nums[l];
    }

    /*
     * 双指针
    */
    int findMin_1(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;
        if (nums[l] < nums[r])
            return nums[l];

        while (l <= r)
        {
            if (nums[l] > nums[r])
                l++;
            else
                r--;
        }
        return nums[l];
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
    int res = s.findMin_1(nums);
    cout << res << endl;
    return 0;
}