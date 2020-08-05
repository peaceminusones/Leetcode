#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    // DFS 超出时间限制！！！=================================================================================
    // int minPathSum(vector<vector<int>> &grid)
    // {
    //     int res = INT_MAX;
    //     vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size()));
    //     int val = 0;
    //     dfs(grid, visited, val, 0, 0, res);
    //     return res;
    // }

    // void dfs(vector<vector<int>> &grid, vector<vector<int>> &visited, int &val, int i, int j, int &res)
    // {
    //     if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || visited[i][j] == 1)
    //         return;

    //     visited[i][j] = 1;
    //     val += grid[i][j];
    //     if (i == grid.size() - 1 && j == grid[0].size() - 1)
    //     {
    //         res = min(res, val);
    //     }
    //     dfs(grid, visited, val, i + 1, j, res);
    //     dfs(grid, visited, val, i - 1, j, res);
    //     dfs(grid, visited, val, i, j + 1, res);
    //     dfs(grid, visited, val, i, j - 1, res);
    //     val -= grid[i][j];
    //     visited[i][j] = 0;
    // }

    // 动态规划
    int minPathSum(vector<vector<int>> &grid)
    {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size()));
        dp[0][0] = grid[0][0];
        int i, j;
        for (i = 0; i < grid.size(); i++)
        {
            for (j = 0; j < grid[0].size(); j++)
            {
                if (i == 0 && j == 0)
                    continue;
                else if (i == 0)
                    // 从（0，0）到（i，j-1）的最小总和路径加上（i，j）处的值
                    dp[i][j] = dp[i][j - 1] + grid[i][j];
                else if (j == 0)
                    // 从（0，0）到（i-1，j）的最小总和路径加上（i，j）处的值
                    dp[i][j] = dp[i - 1][j] + grid[i][j];
                else
                    // 从（0，0）到min(（i，j-1），（i-1，j）)的最小总和路径加上（i，j）处的值
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[i - 1][j - 1];
    }
};

int main()
{
    vector<vector<int>> grids;
    vector<int> grid;
    int item;
    while (cin >> item)
    {
        grid.push_back(item);
        if (cin.get() == '\n')
        {
            grids.push_back(grid);
            grid.clear();
        }
        if (cin.peek() == '\n')
            grids.push_back(grid);
    }

    for (int i = 0; i < grids.size(); i++)
    {
        for (int j = 0; j < grids[0].size(); j++)
        {
            cout << grids[i][j] << " ";
        }
        cout << endl;
    }

    Solution s;
    int res = s.minPathSum(grids);
    cout << res << endl;
    return 0;
}