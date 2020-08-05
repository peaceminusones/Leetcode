#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int rob(vector<int> nums)
    {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];
        vector<int> dp(nums.size());
        dp[0] = nums[0];               // 如果只有1个住户，则偷窃这个房屋
        dp[1] = max(nums[0], nums[1]); // 如果有2个住户，只能偷其中最大的
        for (int i = 2; i < nums.size(); i++)
        {
            // 当前房屋偷 vs 当前房屋不偷
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }

        return dp[nums.size() - 1];
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
    int res = s.rob(nums);
    cout << res << endl;
    return 0;
}