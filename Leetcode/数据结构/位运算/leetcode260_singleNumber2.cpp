#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int diff = 0;
        for (auto n : nums)
            diff ^= n;
        diff &= (-diff);
        vector<int> res(2);
        for (auto n : nums)
        {
            if ((n & diff) == 0)
                res[0] ^= n;
            else
                res[1] ^= n;
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
    vector<int> res = s.singleNumber(nums);
    for (auto r : res)
        cout << r << " ";
    return 0;
}