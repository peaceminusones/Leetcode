#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void quicksort(vector<int> &nums, int l, int r)
    {
        if (l < r)
        {
            int mid = parition(nums, l, r);
            quicksort(nums, l, mid - 1);
            quicksort(nums, mid + 1, r);
        }
    }

    int parition(vector<int> &nums, int l, int r)
    {
        int mid = nums[l];
        int i = l, j = r;
        while (i < j)
        {
            while (i < j && nums[j] >= mid)
                j--;
            while (i < j && nums[i] <= mid)
                i++;

            if (i < j)
                swap(nums[i], nums[j]);
        }
        swap(nums[i], nums[l]); //!!一开始这里错了！
        return i;
    }

    void mergesort(vector<int> &nums, int l, int r)
    {
        if (l < r)
        {
            int m = l + (r - l) / 2;
            mergesort(nums, l, m);
            mergesort(nums, m + 1, r);
            merge(nums, l, m, r);
        }
    }

    void merge(vector<int> &nums, int l, int m, int r)
    {
        int i = l, j = m + 1;
        vector<int> res;
        while (i <= m && j <= r)
        {
            if (nums[i] <= nums[j])
            {
                res.push_back(nums[i]);
                i++;
            }
            else
            {
                res.push_back(nums[j]);
                j++;
            }
        }

        if (i <= m)
            res.insert(res.end(), nums.begin() + i, nums.begin() + m + 1);
        if (j <= r)
            res.insert(res.end(), nums.begin() + j, nums.begin() + r);

        // while (i <= m)
        // {
        //     res.push_back(nums[i++]);
        // }
        // while (j <= r)
        // {
        //     res.push_back(nums[j++]);
        // }

        for (int i = 0; i < res.size(); i++)
        {
            nums[l + i] = res[i];
        }
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
    // s.quicksort(nums, 0, nums.size() - 1);
    s.mergesort(nums, 0, nums.size() - 1);

    for (auto n : nums)
        cout << n << " ";
    return 0;
}