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

        int maxarea = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                int area = 0;
                if (grid[i][j] == 1)
                {
                    dfs_stack(i, j, grid, area);
                    maxarea = max(maxarea, area);
                }
            }
        }
        return maxarea;
    }

    void dfs(int i, int j, vector<vector<int>> &grid, int &area)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0)
            return;
        grid[i][j] = 0;
        area++;
        dfs(i - 1, j, grid, area);
        dfs(i + 1, j, grid, area);
        dfs(i, j - 1, grid, area);
        dfs(i, j + 1, grid, area);
    }

    /**
     * 方法二：
     * 用栈实现的dfs =========================================================
    */
    void dfs_stack(int i, int j, vector<vector<int>> &grid, int &area)
    {
        stack<pair<int, int>> st;
        st.push({i, j});
        grid[i][j] = 0;
        area++;
        while (!st.empty())
        {
            int x = st.top().first;
            int y = st.top().second;
            st.pop();
            if (x - 1 >= 0 && grid[x - 1][y] == 1)
            {
                st.push({x - 1, y});
                grid[x - 1][y] = 0;
                area++;
                continue;
            }
            if (x + 1 < grid.size() && grid[x + 1][y] == 1)
            {
                st.push({x + 1, y});
                grid[x + 1][y] = 0;
                area++;
                continue;
            }
            if (y - 1 >= 0 && grid[x][y - 1] == 1)
            {
                st.push({x, y - 1});
                grid[x][y - 1] = 0;
                area++;
                continue;
            }
            if (y + 1 < grid[0].size() && grid[x][y + 1] == 1)
            {
                st.push({x, y + 1});
                grid[x][y + 1] = 0;
                area++;
                continue;
            }
            
        }
    }

    /**
     * 方法三：
     * 广度搜索算法 bfs
    */
    void bfs(int i, int j, vector<vector<int>> &grid, int &area)
    {
        queue<pair<int, int>> que;
        que.push({i, j});
        grid[i][j] = 0;
        area++;
        while (!que.empty())
        {
            int x = que.front().first;
            int y = que.front().second;
            que.pop();
            if (x - 1 >= 0 && grid[x - 1][y] == 1)
            {
                que.push({x - 1, y});
                grid[x - 1][y] = 0;
                area++;
            }
            if (x + 1 < grid.size() && grid[x + 1][y] == 1)
            {
                que.push({x + 1, y});
                grid[x + 1][y] = 0;
                area++;
            }
            if (y - 1 >= 0 && grid[x][y - 1] == 1)
            {
                que.push({x, y - 1});
                grid[x][y - 1] = 0;
                area++;
            }
            if (y + 1 < grid[0].size() && grid[x][y + 1] == 1)
            {
                que.push({x, y + 1});
                grid[x][y + 1] = 0;
                area++;
            }
        }
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
    int res = s.maxAreaOfIsland(grids);
    cout << res << endl;

    return 0;
}