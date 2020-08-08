#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // int findShortestSubArray(vector<int> &nums)
    // {
    //     unordered_map<int, int> map;
    //     unordered_map<int, int> first;
    //     unordered_map<int, int> last;
    //     int d = 0;
    //     // 先记录每个数字出现了几次，还有出现的初始位置和结束位置
    //     for (int i = 0; i < nums.size(); i++)
    //     {
    //         map[nums[i]]++;
    //         if (map[nums[i]] == 1)
    //             first[nums[i]] = i;
    //         else
    //             last[nums[i]] = i;
    //         d = max(d, map[nums[i]]);
    //     }
    //     // 如果出现最大的次数只有1，则返回
    //     if (d == 1)
    //         return 1;

    //     // 再次遍历map，记录 出现次数最多的且初始位置与结束位置最近的 距离
    //     int res = nums.size() + 1;
    //     for (auto it = map.begin(); it != map.end(); it++)
    //     {
    //         if (it->second == d)
    //         {
    //             res = min(res, last[it->first] - first[it->first] + 1);
    //         }
    //     }

    //     return res;
    // }

    int findShortestSubArray(vector<int> &nums)
    {
        unordered_map<int, int> count;
        unordered_map<int, int> first;
        unordered_map<int, int> second;
        int maxcount = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            count[nums[i]]++;
            if (count[nums[i]] == 1)
            {
                first[nums[i]] = i;
            }
            else
            {
                second[nums[i]] = i;
            }

            maxcount = max(maxcount, count[nums[i]]);
        }

        if (maxcount == 0)
            return 1;

        int res = nums.size();
        for (auto it = count.begin(); it != count.end(); it++)
        {
            if (it->second == maxcount)
            {
                res = min(res, second[it->first] - first[it->first] + 1);
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
    int res = s.findShortestSubArray(nums);
    cout << res << endl;

    return 0;
}