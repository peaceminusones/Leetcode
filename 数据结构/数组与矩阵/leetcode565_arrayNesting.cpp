#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int arrayNesting(vector<int> &nums)
    {
        vector<int> res;
        int len = 0;
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
    }
    Solution s;
    int res = s.arrayNesting(nums);
    cout << res << endl;

    return 0;
}