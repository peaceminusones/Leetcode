#include <iostream>
#include <vector>
using namespace std;

class NumArray
{
    vector<int> sum;

public:
    // sum[k]表示[0,k]的和 ================================================================
    // NumArray(vector<int> &nums)
    // {
    //     if (nums.size() == 0)
    //     {
    //         sum = nums;
    //         return;
    //     }
    //     sum.resize(nums.size());
    //     sum[0] = nums[0];
    //     for (int i = 1; i < nums.size(); i++)
    //     {
    //         sum[i] = sum[i - 1] + nums[i];
    //     }
    // }

    // int sumRange(int i, int j)
    // {
    //     if (i == 0)
    //         return sum[j];

    //     return sum[j] - sum[i - 1];
    // }

    // sum[k]表示[0,k-1]的和 =============================================================
    NumArray(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            sum = nums;
            return;
        }
        sum.resize(nums.size() + 1);
        sum[0] = nums[0];
        for (int i = 1; i <= nums.size(); i++)
        {
            sum[i] = sum[i - 1] + nums[i - 1];
        }
    }

    int sumRange(int i, int j)
    {
        return sum[j + 1] - sum[i];
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

    NumArray *num = new NumArray(nums);
    int i, j;
    cin >> i >> j;
    int res = num->sumRange(i, j);
    cout << res << endl;
    return 0;
}