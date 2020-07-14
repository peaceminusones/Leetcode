#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // 有重复元素的全排列
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> res;
        if (nums.empty())
            return res;

        sort(nums.begin(), nums.end());

        vector<int> cur;
        vector<int> visited(nums.size());
        backtrack(nums, visited, cur, res);

        return res;
    }

    void backtrack(vector<int> &nums, vector<int> &visited, vector<int> &cur, vector<vector<int>> &res)
    {
        if (cur.size() == nums.size())
        {
            res.push_back(cur);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (visited[i] == 0)
            {
                // 同一层递归中不能选择同一个数字!!!!!!
                // visited[i-1]=0，说明在遍历时刚被撤销选择，所以如果nums[i - 1] == nums[i]，不能再选择，不然就重复了
                if (i > 0 && nums[i - 1] == nums[i] && visited[i - 1] == 0)
                    continue;

                visited[i] = 1;
                cur.push_back(nums[i]);
                backtrack(nums, visited, cur, res);
                cur.pop_back();
                visited[i] = 0;
            }
        }
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

    Solution s;
    vector<vector<int>> res = s.permuteUnique(nums);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[0].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}