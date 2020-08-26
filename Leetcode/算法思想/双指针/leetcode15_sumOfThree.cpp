#include <bits/stdc++.h>
using namespace std;

// template <typename T>
class Solution
{
public:
    // 固定一个数，去找另外两个数之和
    // 难点在于去重
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
                break;

            // 避免第一个数重复出现
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // 从后面的数中找到两个数的和为sum的
            int l = i + 1, r = nums.size() - 1;
            while (l < r)
            {
                if (nums[i] + nums[l] + nums[r] == 0)
                {
                    // 把结果存储下来
                    res.push_back({nums[i], nums[l], nums[r]});
                    // 判断左界和右界是否重复，去除重复
                    while (l < r && nums[l] == nums[l + 1])
                        l++;
                    while (l < r && nums[r - 1] == nums[r])
                        r--;
                    l++;
                    r--;
                }
                else if (nums[i] + nums[l] + nums[r] < 0)
                    l++;
                else
                    r--;
            }
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
    vector<vector<int>> res = s.threeSum(nums);
    for (int i = 0; i < res.size(); i++)
    {
        for (auto r : res[i])
            cout << r << " ";
        cout << endl;
    }
    return 0;
}
