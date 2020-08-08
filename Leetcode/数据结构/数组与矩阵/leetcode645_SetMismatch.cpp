#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // 方法一：map！
    vector<int> findErrorNums(vector<int> &nums)
    {
        unordered_map<int, int> map(nums.size() + 1);
        for (auto n : nums)
        {
            map[n]++;
        }

        int two, zero;
        for (int i = 1; i <= nums.size(); i++)
        {
            auto it = map.find(i);
            if (it == map.end())
                zero = i;
            else if (it->second == 2)
                two = i;
        }
        return {two, zero};
    }

    // 方法二：异或运算(error) ========================================================
    vector<int> findErrorNums1(vector<int> &nums)
    {
        vector<int> res;
        sort(nums.begin(), nums.end());
        for (int i = 1; i <= nums.size(); i++)
        {

            if ((i ^ nums[i - 1]) != 0)
            {
                res.push_back(nums[i - 1]);
                res.push_back(i);
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
    cout << (1 ^ 2 ^ 2 ^ 4) << endl;
    Solution s;
    vector<int> res = s.findErrorNums(nums);
    for (auto r : res)
        cout << r << " ";
    return 0;
}