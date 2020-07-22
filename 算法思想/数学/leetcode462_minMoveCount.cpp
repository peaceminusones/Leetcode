#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        // int m = nums[nums.size() / 2];
        int m = findKthSmallest(nums, nums.size() / 2);
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            count += abs(nums[i] - m);
        }
        return count;
    }

    int findKthSmallest(vector<int> &nums, int k)
    {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int m = partition(nums, l, r);
            if (m == k)
                break;
            if (m < k)
                l = m + 1;
            else
                r = m - 1;
        }
        return nums[k];
    }

    int partition(vector<int> &nums, int l, int r)
    {
        int mid = nums[l];
        int i = l, j = r;
        while (i < j)
        {
            while (i < j && nums[j] <= mid)
                j--;
            while (i < j && nums[i] >= mid)
                i++;
            if (i < j)
                swap(nums[i], nums[j]);
        }
        swap(nums[i], nums[l]);
        return i;
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
    int res = s.minMoves2(nums);
    cout << res << endl;
    return 0;
}