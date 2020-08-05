#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> res(nums.size());
        // i左边的乘积
        int k = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            res[i] = k;
            k *= nums[i];
        }

        // 乘上i右边的乘积
        k = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            res[i] *= k;
            k *= nums[i];
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
        if (cin.get() == '\n')
            break;
    }

    Solution s;
    vector<int> res = s.productExceptSelf(nums);
    for (auto r : res)
        cout << r << " ";
    return 0;
}