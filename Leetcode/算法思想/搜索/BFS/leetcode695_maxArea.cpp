#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int maxarea = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    int area = 0;
                    bfs(grid, i, j, area);
                    maxarea = max(maxarea, area);
                }
            }
        }
        return maxarea;
    }

    void dfs(vector<vector<int>> &grid, int i, int j, int &area)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0)
        {
            return;
        }

        grid[i][j] = 0;
        area++;
        dfs(grid, i + 1, j, area);
        dfs(grid, i - 1, j, area);
        dfs(grid, i, j + 1, area);
        dfs(grid, i, j - 1, area);
    }

    void bfs(vector<vector<int>> &grid, int i, int j, int &area)
    {
        queue<pair<int, int>> que;
        que.push({i, j});
        grid[i][j] = 0;
        area++;
        while (!que.empty())
        {
            pair<int, int> front = que.front();
            int x = front.first;
            int y = front.second;
            que.pop();
            if (x + 1 < grid.size() && grid[x + 1][y] == 1)
            {
                que.push({x + 1, y});
                grid[x + 1][y] = 0;
                area++;
            }
            if (x - 1 >= 0 && grid[x - 1][y] == 1)
            {
                que.push({x - 1, y});
                grid[x - 1][y] = 0;
                area++;
            }
            if (y + 1 < grid[0].size() && grid[x][y + 1] == 1)
            {
                que.push({x, y + 1});
                grid[x][y + 1] = 0;
                area++;
            }
            if (y - 1 >= 0 && grid[x][y - 1] == 1)
            {
                que.push({x, y - 1});
                grid[x][y - 1] = 0;
                area++;
            }
        }
    }
};

int main()
{
    return 0;
}