#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        // int res = 0;
        // for (int i = 0; i < nums.size(); i++)
        //     res ^= (i + 1);
        // for (auto n : nums)
        //     res ^= n;
        // return res;

        // 上述过程合并
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
            res = res ^ (i + 1) ^ nums[i];
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
    int res = s.missingNumber(nums);
    cout << res << endl;
    return 0;
}