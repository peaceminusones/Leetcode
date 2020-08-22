#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int missingElement(vector<int> &nums, int k)
    {
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] - nums[i - 1] - 1 >= k)
                return nums[i - 1] + k;

            k = k - (nums[i] - nums[i - 1] - 1);
        }

        return nums[nums.size() - 1] + k;
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
    int k;
    cin >> k;

    Solution s;
    cout << s.missingElement(nums, k) << endl;
    return 0;
}