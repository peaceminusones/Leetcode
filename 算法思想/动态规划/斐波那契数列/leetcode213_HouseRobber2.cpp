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
        if (nums.size() == 2)
            return max(nums[0], nums[1]);
        vector<int> a(nums.begin() + 1, nums.end());
        vector<int> b(nums.begin(), nums.end() - 1);
        return max(robhelper(a), robhelper(b));
    }

    int robhelper(vector<int> nums)
    {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++)
        {
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