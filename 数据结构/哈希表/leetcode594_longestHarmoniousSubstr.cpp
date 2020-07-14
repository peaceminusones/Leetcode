#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

class Solution
{
public:
    // 重点是auto关键字的使用！！！
    int findLHS(vector<int> &nums)
    {
        unordered_map<int, int> map;
        for (int n : nums)
            map[n]++;

        int res = 0;
        for (auto p : map)
        {
            auto it = map.find(p.first + 1);
            if (it != map.end())
            {
                res = max(res, p.second + it->second);
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

    Solution s;
    int res = s.findLHS(nums);
    cout << res << endl;

    return 0;
}