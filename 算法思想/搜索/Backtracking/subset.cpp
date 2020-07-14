#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> nums)
    {
        vector<vector<int>> res;
        if (nums.empty())
            return res;
        vector<int> cur;
        backtrack(nums, cur, 0, res);
        return res;
    }

    void backtrack(vector<int> &nums, vector<int> &cur, int start, vector<vector<int>> &res)
    {

        res.push_back(cur);
        // return;

        for (int i = start; i < nums.size(); i++)
        {
            cur.push_back(nums[i]);
            backtrack(nums, cur, i + 1, res);
            cur.pop_back();
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
    vector<vector<int>> res = s.subsets(nums);
    for (int i = 1; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}