#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> res;
        if (n == 0)
            return res;

        vector<string> cur(n, string(n, '.'));

        backtrack(0, cur, res);
        return res;
    }

    void backtrack(int row, vector<string> &cur, vector<vector<string>> &res)
    {
        if (row == cur.size())
        {
            res.push_back(cur);
            return;
        }

        for (int col = 0; col < cur.size(); col++)
        {
            if (validate(cur, row, col))
            {
                cur[row][col] = 'Q';
                backtrack(row + 1, cur, res);
                cur[row][col] = '.';
            }
        }
    }

    bool validate(vector<string> cur, int row, int col)
    {
        int size = cur.size();
        // 上
        for (int i = row; i >= 0; i--)
        {
            if (cur[i][col] == 'Q')
                return false;
        }

        // 右上
        for (int i = row - 1, j = col + 1; i >= 0 && j < size; i--, j++)
        {
            if (cur[i][j] == 'Q')
                return false;
        }

        // 左上
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (cur[i][j] == 'Q')
                return false;
        }

        return true;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution s;
    vector<vector<string>> res = s.solveNQueens(n);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << endl;
        }
        cout << endl;
    }
    return 0;
}