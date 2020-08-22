#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> missingTwo(vector<int> &nums)
    {
        nums.push_back(-1);
        nums.push_back(-1);
        for (int i = 0; i < nums.size(); i++)
        {
            while (nums[i] > 0 && nums[nums[i] - 1] != nums[i])
                swap(nums[nums[i] - 1], nums[i]);
        }

        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == -1)
                res.push_back(i + 1);
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
    vector<int> res = s.missingTwo(nums);
    for (auto r : res)
        cout << r << " ";
    cout << endl;
    return 0;
}