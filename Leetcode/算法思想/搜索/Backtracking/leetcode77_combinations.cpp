#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> res;
        if (n == 0)
            return res;
        if (k == 0)
        {
            res.push_back({1});
            return res;
        }
        vector<int> cur;
        backtrack(n, k, res, 1, cur);
        return res;
    }

    // 从start开始，从n个数里选k个
    void backtrack(int n, int k, vector<vector<int>> &res, int start, vector<int> &cur)
    {
        if (cur.size() == k)
        {
            res.push_back(cur);
            return;
        }

        for (int i = start; i <= n; i++)
        {
            cur.push_back(i);
            // 因为i已经被选过了，所以从i+1(start)开始，继续选择
            backtrack(n, k, res, i + 1, cur);
            cur.pop_back();
        }
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    Solution s;
    vector<vector<int>> res = s.combine(n, k);
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