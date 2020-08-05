#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findLengthOfLCIS(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        vector<int> dp(nums.size());
        dp[0] = 1;
        int res = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
                dp[i] = dp[i - 1] + 1;
            else
                dp[i] = 1;
            res = max(res, dp[i]);
        }
        return res;
    }
};

int main()
{
    vector<int> nums;
    int c;
    while (cin >> c)
    {
        nums.push_back(c);
        if (cin.get() == '\n')
            break;
    }

    Solution s;
    int res = s.findLengthOfLCIS(nums);
    cout << res << endl;
    return 0;
}