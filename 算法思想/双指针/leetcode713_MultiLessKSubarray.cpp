#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        if (nums.empty())
            return 0;

        int left = 0, right = 0;
        int res = 1;
        int count = 0;
        while (right < nums.size())
        {
            res *= nums[right];
            while (res >= k)
            {
                res /= nums[left];
                left++;
            }

            count += (right - left) + 1;
            right++;
        }
        return count;
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

    int k;
    cin >> k;

    Solution s;
    int res = s.numSubarrayProductLessThanK(nums, k);
    cout << res << endl;
    return 0;
}