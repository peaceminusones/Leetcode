#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int s, vector<int> &nums)
    {
        int left = 0, right = 0;
        int sum = 0;
        int res = nums.size() + 1;
        while (left < nums.size())
        {
            if (sum < s && right < nums.size())
            {
                sum += nums[right];
                right++;
            }
            else
            {
                if (sum >= s)
                {
                    res = min(res, right - left);
                    sum -= nums[left];
                }
                left++;
            }
        }
        return res == nums.size() + 1 ? 0 : res;
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

    int s;
    cin >> s;

    Solution sol;
    cout << sol.minSubArrayLen(s, nums) << endl;

    return 0;
}