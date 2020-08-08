#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        set<int> s;
        for (int i = 0; i < nums.size(); i++)
        {
            if (s.size() < 3)
                s.insert(nums[i]);
            else if (s.size() == 3 && nums[i] > *(s.begin()) && s.find(nums[i]) == s.end())
            {
                s.erase(s.begin());
                s.insert(nums[i]);
            }
        }

        if (s.size() < 3)
            return *(--s.end());

        return *(s.begin());
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
    int res = s.thirdMax(nums);
    cout << res << endl;
    return 0;
}
