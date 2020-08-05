#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class DisJSet
{
private:
    vector<int> parent;
    int count;

public:
    DisJSet(vector<vector<char>> &grid)
    {
        count = 0;
        int row = grid.size();
        int col = grid[0].size();
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == '1')
                {
                    parent.push_back(i * col + j);
                    count++; // 一开始有多少个1就有多少个岛屿
                }
                else
                {
                    parent.push_back(-1);
                }
            }
        }
    }

    int Find(int i)
    {
        return parent[i] == i ? i : Find(parent[i]);
    }

    void merge(int x, int y)
    {
        int rootx = Find(x);
        int rooty = Find(y);
        if (rootx != rooty)
        {
            parent[rootx] = rooty;
            count--; // 每合并一个，岛屿数量就减一
        }
    }

    int getCount()
    {
        return count;
    }

    bool is_same(int x, int y)
    {
        return Find(x) == Find(y);
    }
};

class Solution
{
public:
    /**
     * 方法一：
     * 递归dfs
    */
    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.empty())
            return 0;

        int res = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1') // 找到为1的陆地，调用dfs，使之变为大海0；
                {
                    res++; // 记录调用的次数
                    dfs(i, j, grid);
                }
            }
        }
        return res;
    }

    void dfs(int i, int j, vector<vector<char>> &grid)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        dfs(i - 1, j, grid); // 上
        dfs(i + 1, j, grid); // 下
        dfs(i, j - 1, grid); // 左
        dfs(i, j + 1, grid); // 右
    }

    /**
     * 方法二：bfs
     * 为了求出岛屿的数量，我们可以扫描整个二维网格。
     * 如果一个位置为1，则将其加入队列，开始进行广度优先搜索。
     * 在广度优先搜索的过程中，每个搜索到的1都会被重新标记为0。直到队列为空，搜索结束
     * 
     * 最终岛屿的数量就是我们进行广度优先搜索的次数
    */
    int numIslands_bfs(vector<vector<char>> &grid)
    {
        if (grid.empty())
            return 0;

        queue<pair<int, int>> que;
        int nums = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1') // 如果一个位置为1，则将其加入队列，开始进行广度优先搜索
                {
                    nums++; // 进行广度优先搜索的次数
                    bfs(i, j, grid, que);
                }
            }
        }

        return nums;
    }

    void bfs(int i, int j, vector<vector<char>> &grid, queue<pair<int, int>> &que)
    {
        int row = grid.size(), col = grid[0].size();

        grid[i][j] == '0';
        que.push({i, j});
        while (!que.empty())
        {
            // 队首元素拿出来，判断其上下左右是否有1，如果有放入队列中，并把该位置置为0
            int x = que.front().first;
            int y = que.front().second;
            que.pop();
            // 上
            if (x - 1 >= 0 && grid[x - 1][y] == '1')
            {
                que.push({x - 1, y});
                grid[x - 1][y] = '0';
            }
            // 下
            if (x + 1 < row && grid[x + 1][y] == '1')
            {
                que.push({x + 1, y});
                grid[x + 1][y] = '0';
            }
            // 左
            if (y - 1 >= 0 && grid[x][y - 1] == '1')
            {
                que.push({x, y - 1});
                grid[x][y - 1] = '0';
            }
            // 右
            if (y + 1 < col && grid[x][y + 1] == '1')
            {
                que.push({x, y + 1});
                grid[x][y + 1] = '0';
            }
        }
    }

    /**
     * 方法三：并查集 ===================================================
    */
    int numIslands_union(vector<vector<char>> &grid)
    {
        if (grid.empty())
            return 0;

        DisJSet *djs = new DisJSet(grid);

        int row = grid.size();
        int col = grid[0].size();
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == '1')
                {
                    grid[i][j] = '0';
                    if (i - 1 >= 0 && grid[i - 1][j] == '1')
                    {
                        djs->merge(i * col + j, (i - 1) * col + j);
                    }
                    if (i + 1 < row && grid[i + 1][j] == '1')
                    {
                        djs->merge(i * col + j, (i + 1) * col + j);
                    }
                    if (j - 1 >= 0 && grid[i][j - 1] == '1')
                    {
                        djs->merge(i * col + j, i * col + j - 1);
                    }
                    if (j + 1 < col && grid[i][j + 1] == '1')
                    {
                        djs->merge(i * col + j, i * col + j + 1);
                    }
                }
            }
        }

        return djs->getCount();
    }
};

int main()
{
    vector<vector<char>> grids;
    vector<char> grid;
    char item;
    while (cin >> item)
    {
        if (item == '#')
            break;
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
    int res = s.numIslands_union(grids);
    cout << res << endl;
    return 0;
}