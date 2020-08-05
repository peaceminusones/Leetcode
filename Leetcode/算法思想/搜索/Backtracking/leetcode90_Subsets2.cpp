#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> res;
        if (nums.empty())
            return res;
        sort(nums.begin(), nums.end());
        vector<int> visited(nums.size());
        vector<int> cur;
        backtrack(nums, 0, visited, cur, res);
        return res;
    }

    void backtrack(vector<int> &nums, int start, vector<int> visited, vector<int> &cur, vector<vector<int>> &res)
    {
        res.push_back(cur);

        for (int i = start; i < nums.size(); i++)
        {
            if (i > start && nums[i - 1] == nums[i] && visited[i - 1] == 0)
                continue;
            visited[i] = 1;
            cur.push_back(nums[i]);
            backtrack(nums, i + 1, visited, cur, res);
            cur.pop_back();
            visited[i] = 0;
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
    vector<vector<int>> res = s.subsetsWithDup(nums);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}