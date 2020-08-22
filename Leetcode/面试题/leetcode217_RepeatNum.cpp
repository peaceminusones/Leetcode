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
        for (int i = 0; i < nums.size(); i++)
        {
            map[nums[i]]++;
            if (map[nums[i]] > 1)
                return true;
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
    cout << s.containsDuplicate(nums) << endl;

    return 0;
}