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
        {
            diff ^= n;
        }
        // 得到最低位置的1
        diff ^= (-diff);

        // 分成两组分别异或
        int res1 = 0, res2 = 0;
        for (auto n : nums)
        {
            if ((n & diff) == 0)
                res1 ^= n;
            else
                res2 ^= n;
        }

        return {res1, res2};
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
    cout << res[0] << " " << res[1] << endl;
    return 0;
}