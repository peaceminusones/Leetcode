#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // 记录下当前位置，和当前可到达的最远位置
    bool canJump(vector<int> &nums)
    {
        int rightmax = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i <= rightmax)
            {
                rightmax = max(rightmax, i + nums[i]);
                if (rightmax >= nums.size() - 1)
                    return true;
            }
        }
        return false;
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
    cout << s.canJump(nums) << endl;
    return 0;
}