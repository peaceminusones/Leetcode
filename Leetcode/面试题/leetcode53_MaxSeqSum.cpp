#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        vector<int> dp(nums.size() + 1);
        dp[0] = 0;
        int res = max(dp[0], 0);
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = max(nums[i] + dp[i - 1], nums[i]);
            res = max(res, dp[i]);
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
    int res = s.maxSubArray(nums);
    cout << res << endl;

    return 0;
}