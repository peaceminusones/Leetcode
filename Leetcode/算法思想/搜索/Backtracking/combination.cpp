#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combination(int n, int k)
    {
        vector<vector<int>> res;
        if (n == 0)
            return res;
        if (k == 0)
        {
            res.push_back({0});
            return res;
        }

        vector<int> cur;
        backtrack(n, k, 1, cur, res);
        return res;
    }

    void backtrack(int n, int k, int start, vector<int> &cur, vector<vector<int>> &res)
    {
        if (cur.size() == k)
        {
            res.push_back(cur);
            return;
        }

        for (int i = start; i <= n; i++)
        {
            cur.push_back(i);
            backtrack(n, k, i + 1, cur, res);
            cur.pop_back();
        }
    }
};

int main()
{
    int n, k;
    cin >> n >> k;

    Solution s;
    vector<vector<int>> res = s.combination(n, k);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[0].size(); j++)
        {
            cout << res[i][j];
        }
        cout << endl;
    }
    return 0;
}