#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> res;
        if (n == 0 || k == 0)
            return res;

        vector<int> cur;
        backtrack(k, n, 1, cur, res);
        return res;
    }

    void backtrack(int k, int n, int start, vector<int> &cur, vector<vector<int>> &res)
    {
        if (cur.size() == k && n == 0)
        {
            res.push_back(cur);
            return;
        }

        for (int i = start; i < 10; i++)
        {
            if (n - i < 0)
                return;

            cur.push_back(i);
            backtrack(k, n - i, i + 1, cur, res);
            cur.pop_back();
        }
    }
};

int main()
{
    int k, n;
    cin >> k >> n;

    Solution s;
    vector<vector<int>> res = s.combinationSum3(k, n);
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