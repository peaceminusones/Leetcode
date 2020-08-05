#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> res;
        if (nums.empty())
            return {-1, -1};

        /*
         * 找给定目标值的下界
        */
        int l = 0, r = nums.size();
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] < target) // 没有等号！！
                l = mid + 1;
            else
                r = mid;
        }
        cout << "l:" << l << endl;
        res.push_back(l);

        /*
         * 找给定目标值的上界
        */
        l = 0, r = nums.size();
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] <= target) // 等号很重要，相当于找到比target大的数的最左边界
                l = mid + 1;
            else
                r = mid;
        }
        cout << "r:" << r << endl;
        res.push_back(r - 1);

        if (res[0] < nums.size() && res[1] < nums.size() && nums[res[0]] == target && nums[res[1]] == target)
            return res;
        else
            return {-1, -1};
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
    vector<int> res = s.searchRange(nums, target);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << endl;

    return 0;
}