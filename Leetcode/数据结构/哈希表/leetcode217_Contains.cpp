#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> map;
        for (int n : nums)
        {
            if (map[n] != 0)
                return true;
            map[n]++;
        }
        return false;
    }
};

int main()
{
    vector<int> nums;
    int item;
    while (cin >> item)
        nums.push_back(item);

    Solution s;
    bool res = s.containsDuplicate(nums);
    cout << res << endl;
    return 0;
}