#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        if (candidates.empty())
            return res;
        sort(candidates.begin(), candidates.end());
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

        for (int i = start; i < candidates.size(); i++)
        {
            // 大剪枝
            if (target - candidates[i] < 0)
                return;

            // 小剪枝
            if (i > start && candidates[i - 1] == candidates[i])
                continue;

            cur.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, cur, res);
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
    vector<vector<int>> res = s.combinationSum2(candidates, target);
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