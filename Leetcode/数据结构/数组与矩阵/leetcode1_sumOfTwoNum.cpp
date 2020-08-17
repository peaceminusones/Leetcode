#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> res;
        unordered_map<int, int> map; // 存储nums[i]和target的差，和相应的位置
        for (int i = 0; i < nums.size(); i++)
        {
            int diff = target - nums[i];
            if (map.find(diff) == map.end()) // 如果nums[i]和target的差没有出现过
                map[nums[i]] = i;
            else // 出现过，则得到了结果
                res = {map[diff], i};
        }
        return res;
    }
};

int main()
{

    return 0;
}