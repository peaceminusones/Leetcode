#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int firstNocur(vector<int> nums)
    {
        int n = nums.size();
        vector<int> res(nums[n - 1] * 2);
        for (auto num : nums)
        {
            res[num] = 1;
        }

        for (int i = 1; i < res.size(); i++)
        {
            if (res[i] == 0)
                return i;
        }

        return 0;
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
    int res = s.firstNocur(nums);
    cout << res << endl;
    return 0;
}