#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int res = 0;
        int length = 0;
        for (auto n : nums)
        {
            if (n == 0)
            {
                res = max(res, length);
                length = 0;
                continue;
            }
            length++;
        }
        return max(res, length);
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
    int res = s.findMaxConsecutiveOnes(nums);
    cout << res << endl;
    return 0;
}