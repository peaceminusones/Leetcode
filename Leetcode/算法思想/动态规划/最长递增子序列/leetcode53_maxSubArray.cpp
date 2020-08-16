#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int curmax = nums[0];
        int res = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            curmax = curmax > 0 ? curmax + nums[i] : nums[i];
            res = max(res, curmax);
        }
        return res;
    }

    int maxSubArray2(vector<int> &nums)
    {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            res = max(dp[i], res);
        }

        return res;
    }
};

int main()
{
    return 0;
}