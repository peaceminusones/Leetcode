#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int res = 0;
        for (int i = 1; i <= nums.size(); i++)
        {
            res ^= nums[i - 1] ^ i;
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
    cout << s.missingNumber(nums) << endl;
    return 0;
}