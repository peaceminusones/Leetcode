#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // 超时！！！！！！！！！！！！！
    int subarraySum(vector<int> &nums, int k)
    {
        int count = 0;
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size()));
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == k)
                count++;
            dp[i][i] = nums[i];
        }

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                dp[i][j] = dp[i][j - 1] + nums[j];
                if (dp[i][j] == k)
                    count++;
            }
        }
        return count;
    }

    // 
    int subarraySum(vector<int> &nums, int k)
    {

    }
};

int main()
{
    vector<int> num;
    int item;
    while (cin >> item)
    {
        num.push_back(item);
        if (cin.get() == '\n')
            break;
    }
    Solution s;
    int k;
    cin >> k;
    int res = s.subarraySum(num, k);
    cout << res << endl;
    return 0;
}