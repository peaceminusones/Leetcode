#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // 动态规划 O(N2)
    int wiggleMaxLength(vector<int> &nums)
    {
        if (nums.size() < 2)
            return nums.size();
        vector<int> dp_up(nums.size(), 1);
        vector<int> dp_down(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i - 1] < nums[i])
                    dp_up[i] = max(dp_up[i], dp_down[j] + 1);
                if (nums[i - 1] > nums[i])
                    dp_down[i] = max(dp_down[i], dp_up[j] + 1);
            }
        }
        for (auto u : dp_up)
            cout << u << " ";
        cout << endl;
        for (auto d : dp_down)
            cout << d << " ";
        cout << endl;

        return max(*max_element(dp_up.begin(), dp_up.end()), *max_element(dp_down.begin(), dp_down.end()));
    }

    // 线性动态规划
    int wiggleMaxLength2(vector<int> &nums)
    {
        int up = 1, down = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] < nums[i])
                up = down + 1;
            else if (nums[i - 1] > nums[i])
                down = up + 1;
        }

        return max(up, down);
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
    int res = s.wiggleMaxLength2(nums);
    cout << res << endl;
    return 0;
}