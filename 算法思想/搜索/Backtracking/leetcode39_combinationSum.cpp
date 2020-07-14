#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> res;
        if (candidates.empty())
            return res;
        vector<int> cur;
        backtrack(candidates, target, 0, cur, res);
        return res;
    }

    void backtrack(vector<int> &candidates, int target, int start, vector<int> &cur, vector<vector<int>> &res)
    {
        if (target == 0)
        {
            res.push_back(cur);
            return;
        }

        if (target < 0)
            return;

        for (int i = start; i < candidates.size(); i++)
        {
            cur.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i, cur, res);
            cur.pop_back();
        }
    }
};

int main()
{
    vector<int> candidates;
    int item;
    while (cin >> item)
    {
        candidates.push_back(item);
    }
    cin.clear();
    cin.ignore();

    int target;
    cin >> target;

    Solution s;
    vector<vector<int>> res = s.combinationSum(candidates, target);
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