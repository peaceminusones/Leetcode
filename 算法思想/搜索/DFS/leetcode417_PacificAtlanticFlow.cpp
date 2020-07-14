#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution
{
    vector<vector<int>> direction = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

public:
    // 分别从太平洋的大西洋边界位置出发遍历
    // 同时被他们都遍历到的位置，就是答案
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix)
    {
        if (matrix.empty())
            return matrix;

        int m = matrix.size();
        int n = matrix[0].size();
        // 存储太平洋（从小数到大数）可以访问到的点
        // 如果pacifc[i][j]==1，说明可以该点可以流入太平洋
        vector<vector<int>> pacifc(m);
        for (int i = 0; i < m; i++)
            pacifc[i].resize(n);
        // 存储大西洋（从小数到大数）可以访问到的点
        // atlantic[i][j]==1同上
        vector<vector<int>> atlantic(m);
        for (int i = 0; i < m; i++)
            atlantic[i].resize(n);

        // 上边界（太平洋），下边界（大西洋）
        for (int i = 0; i < n; i++)
        {
            bfs(0, i, matrix, pacifc);       //太平洋
            bfs(m - 1, i, matrix, atlantic); // 大西洋
        }

        // 左边界（太平洋），右边界（大西洋）
        for (int i = 0; i < m; i++)
        {
            bfs(i, 0, matrix, pacifc);
            bfs(i, n - 1, matrix, atlantic);
        }

        // 如果某个点从太平洋，从大西洋都可以遍历到，则取出来
        vector<vector<int>> res;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (pacifc[i][j] == 1 && atlantic[i][j] == 1)
                {
                    vector<int> pos;
                    pos.push_back(i);
                    pos.push_back(j);
                    res.push_back(pos);
                }
            }
        }

        return res;
    }

    void dfs(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &tmp)
    {
        tmp[i][j] = 1;
        for (int k = 0; k < direction.size(); k++)
        {
            int newi = i + direction[k][0];
            int newj = j + direction[k][1];
            if (newi < 0 || newj < 0 || newi >= matrix.size() || newj >= matrix[0].size())
                continue;
            if (matrix[newi][newj] < matrix[i][j] || tmp[newi][newj] == 1)
                continue;
            dfs(newi, newj, matrix, tmp);
        }
    }

    void dfs_stack(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &tmp)
    {
        stack<pair<int, int>> st;
        st.push({i, j});
        tmp[i][j] = 1;
        while (!st.empty())
        {
            int x = st.top().first;
            int y = st.top().second;

            if (x - 1 >= 0 && tmp[x - 1][y] == 0 && matrix[x][y] <= matrix[x - 1][y])
            {
                st.push({x - 1, y});
                tmp[x - 1][y] = 1;
                continue;
            }
            if (x + 1 < matrix.size() && tmp[x + 1][y] == 0 && matrix[x][y] <= matrix[x + 1][y])
            {
                st.push({x + 1, y});
                tmp[x + 1][y] = 1;
                continue;
            }
            if (y - 1 >= 0 && tmp[x][y - 1] == 0 && matrix[x][y] <= matrix[x][y - 1])
            {
                st.push({x, y - 1});
                tmp[x][y - 1] = 1;
                continue;
            }
            if (y + 1 < matrix[0].size() && tmp[x][y + 1] == 0 && matrix[x][y] <= matrix[x][y + 1])
            {
                st.push({x, y + 1});
                tmp[x][y + 1] = 1;
                continue;
            }

            st.pop();
        }
    }

    void bfs(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &tmp)
    {
        queue<pair<int, int>> que;
        que.push({i, j});
        tmp[i][j] = 1;
        while (!que.empty())
        {
            int x = que.front().first;
            int y = que.front().second;
            que.pop();
            if (x - 1 >= 0 && tmp[x - 1][y] == 0 && matrix[x][y] <= matrix[x - 1][y])
            {
                que.push({x - 1, y});
                tmp[x - 1][y] = 1;
            }
            if (x + 1 < matrix.size() && tmp[x + 1][y] == 0 && matrix[x][y] <= matrix[x + 1][y])
            {
                que.push({x + 1, y});
                tmp[x + 1][y] = 1;
            }
            if (y - 1 >= 0 && tmp[x][y - 1] == 0 && matrix[x][y] <= matrix[x][y - 1])
            {
                que.push({x, y - 1});
                tmp[x][y - 1] = 1;
            }
            if (y + 1 < matrix[0].size() && tmp[x][y + 1] == 0 && matrix[x][y] <= matrix[x][y + 1])
            {
                que.push({x, y + 1});
                tmp[x][y + 1] = 1;
            }
        }
    }
};

int main()
{
    vector<vector<int>> matrix;
    vector<int> m;
    int item;
    while (cin >> item)
    {
        m.push_back(item);
        if (cin.get() == '\n')
        {
            matrix.push_back(m);
            m.clear();
        }

        if (cin.peek() == '\n')
            matrix.push_back(m);
    }

    Solution s;
    vector<vector<int>> res = s.pacificAtlantic(matrix);
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