#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        if (k > nums.size())
            return 0;

        // quicksort(nums, 0, nums.size() - 1);
        mergesort(nums, 0, nums.size() - 1);
        // for (int i = 0; i < nums.size(); i++)
        //     cout << nums[i] << " ";
        // cout << endl;

        return nums[nums.size() - k];
    }

    /*
     * 排序 =============================================================
     * 快速排序
    */
    void quicksort(vector<int> &nums, int l, int r)
    {
        if (l < r)
        {
            int m = partition(nums, l, r);
            quicksort(nums, l, m - 1);
            quicksort(nums, m + 1, r);
        }
    }
    int partition(vector<int> &nums, int l, int r)
    {
        int mid = nums[l];
        int i = l, j = r;
        while (i < j)
        {
            while (i < j && nums[j] >= mid)
                j--;
            while (i < j && nums[i] <= mid)
                i++;

            swap(nums[i], nums[j]);
        }
        swap(nums[l], nums[j]);
        return j;
    }

    /*
     * 排序 =============================================================
     * 归并排序
    */
    void mergesort(vector<int> &nums, int l, int r)
    {
        if (l < r)
        {
            int m = (l + r) / 2;
            mergesort(nums, l, m);
            mergesort(nums, m + 1, r);
            merge(nums, l, m, r);
        }
    }
    void merge(vector<int> &nums, int l, int m, int r)
    {
        vector<int> res;
        int i = l, j = m + 1;
        while (i <= m && j <= r)
        {
            if (nums[i] < nums[j])
                res.push_back(nums[i++]);
            else
                res.push_back(nums[j++]);
        }
        while (i <= m)
            res.push_back(nums[i++]);
        while (j <= r)
            res.push_back(nums[j++]);
        for (int k = 0; k < res.size(); k++)
            nums[l + k] = res[k];
    }

    /*
     * 大顶堆！
    */
    int findKthLargest_queue(vector<int> &nums, int k)
    {
        // priority_queue<int, vector<int>, greater<int>> q;  // greater:小顶堆 less:大顶堆；默认是less（大顶堆）
        priority_queue<int, vector<int>, greater<int>> q; // 小顶堆
        for (int i = 0; i < nums.size(); i++)
        {
            q.push(nums[i]);

            if (q.size() > k)
                q.pop();
        }

        return q.top();
    }

    /*
     * 快速选择
    */
    int findKthLargest_quickSelect(vector<int> &nums, int k)
    {
        k = nums.size() - k;
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int m = partition(nums, l, r);   // 将nums分成两半，nums[l]左边都比它小，右边都比它大
            if (m == k)
                return nums[m];
            else if (m < k)
                l = m + 1;
            else
                r = m - 1;
        }
        return nums[k];
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
    cin.clear();
    cin.ignore();

    int k;
    cin >> k;

    Solution s;
    int res = s.findKthLargest_quickSelect(nums, k);
    cout << res << endl;
    return 0;
}