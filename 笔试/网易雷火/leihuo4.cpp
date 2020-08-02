#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution
{
public:
    /**
     * 方法一：
     * 用递归实现的dfs  ===================================================================
    */
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        if (grid.empty())
            return 0;

        vector<vector<int>> visited(grid.size(), vector<int>(grid.size()));
        int maxarea = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                int area = 0;
                int val = grid[i][j];
                dfs(i, j, grid, visited, area, val);
                // maxarea = max(maxarea, area);
            }
        }

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }

        return maxarea;
    }

    void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &visited, int &area, int val)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != val || visited[i][j] == 1)
            return;
        cout << i << " " << j << endl;
        cout << grid[i][j] << endl;
        grid[i][j] = 0;
        visited[i][j] == 1;
        area++;
        dfs(i - 1, j, grid, visited, area, val);
        dfs(i + 1, j, grid, visited, area, val);
        dfs(i, j - 1, grid, visited, area, val);
        dfs(i, j + 1, grid, visited, area, val);
        // if (area < 3)
        // {
        //     grid[i][j] = val;
        // }
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

    // for (int i = 0; i < grids.size(); i++)
    // {
    //     for (int j = 0; j < grids[0].size(); j++)
    //     {
    //         cout << grids[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    Solution s;
    int res = s.maxAreaOfIsland(grids);
    cout << res << endl;

    return 0;
}