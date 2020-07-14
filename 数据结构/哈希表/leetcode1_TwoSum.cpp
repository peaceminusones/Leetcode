#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> map;
        unordered_map<int, int>::iterator it;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            int diff = target - nums[i];
            it = map.find(diff);
            if (it == map.end())
            {
                map[nums[i]] = i;
            }
            else
            {
                res = {map[diff], i};
                return res;
            }
        }
        return res;
    }
};

int main()
{
    vector<int> nums;
    int item;
    while (cin >> item)
        nums.push_back(item);
    cin.clear();
    cin.ignore();

    int target;
    cin >> target;

    Solution s;
    vector<int> res = s.twoSum(nums, target);
    for (int r : res)
        cout << r << " ";
    return 0;
}