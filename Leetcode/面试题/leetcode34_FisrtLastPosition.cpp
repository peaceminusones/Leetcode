#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (nums.empty())
            return {-1, -1};

        int a = firstPosition(nums, target);
        int b = lastPosition(nums, target);

        if (a >= 0 && a < nums.size() && b >= 0 && b < nums.size() && nums[a] == nums[b])
            return {a, b};

        return {-1, -1};
    }

    int firstPosition(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size();
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }

    int lastPosition(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size();
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] > target)
                r = mid;
            else
                l = mid + 1;
        }
        return l - 1;
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

    int target;
    cin >> target;

    Solution s;
    vector<int> res = s.searchRange(nums, target);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}