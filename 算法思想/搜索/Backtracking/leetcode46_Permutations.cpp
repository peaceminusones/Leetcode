#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        if (nums.empty())
            return res;

        vector<int> visited(nums.size());
        vector<int> cur;
        backtracking(nums, visited, cur, res);

        return res;
    }

    void backtracking(vector<int> &nums, vector<int> &visited, vector<int> &cur, vector<vector<int>> &res)
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
                visited[i] = 1;
                cur.push_back(nums[i]);
                backtracking(nums, visited, cur, res);
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
    vector<vector<int>> res = s.permute(nums);
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