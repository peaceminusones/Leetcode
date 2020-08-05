#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> res;
        if (nums.empty())
            return res;

        map<int, int> m; // 存储{数值：位置}
        map<int, int>::iterator it;
        for (int i = 0; i < nums.size(); i++)
        {
            int diff = target - nums[i]; // 求target和当前值的差
            it = m.find(diff);
            if (it != m.end()) // 如果能在字典中找到这个差，则返回
            {
                res.push_back(m[diff]);
                res.push_back(i);
                return res;
            }
            else // 如果没找到这个差，把当前值和对应的位置存储到字典中
            {
                m[nums[i]] = i;
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
    {
        nums.push_back(item);
    }
    cin.clear();
    cin.ignore();

    int target;
    cin >> target;

    Solution s;
    vector<int> res = s.twoSum(nums, target);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";

    return 0;
}