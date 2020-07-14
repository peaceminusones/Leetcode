#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution
{
public:
    int findCircleNum(vector<vector<int>> &M)
    {
        if (M.empty())
            return 0;

        int num = 0;
        for (int i = 0; i < M.size(); i++)
        {
            for (int j = 0; j < M[0].size(); j++)
            {
                if (M[i][j] == 1)
                {
                    num++;
                    dfs(i, j, M);
                }
            }
        }
        return num;
    }

    void dfs(int i, int j, vector<vector<int>> &M)
    {
        if (i < 0 || i >= M.size() || j < 0 || j >= M[0].size() || M[i][j] == 0)
            return;
        M[i][j] = 0;
        M[j][i] = 0;
        for (int k = 1; k < M.size(); k++)
        {
            dfs(i - k, j, M);
            dfs(i + k, j, M);
            dfs(i, j - k, M);
            dfs(i, j + k, M);
        }
    }

    // void dfs_stack(int i, int j, vector<vector<int>> &M)
    // {
    //     stack<pair<int, int>> st;
    //     st.push({i, j});
    //     M[i][j] = 0;
    //     M[j][i] = 0;
    //     while (!st.empty())
    //     {
    //         int x = st.top().first;
    //         int y = st.top().second;

    //         for (int k = 1; k < M.size(); k++)
    //         {
    //             if (x - k >= 0 && M[x - k][y] == 1)
    //             {
    //                 st.push({x - k, y});
    //                 M[x - k][y] = 0;
    //                 M[y][x - k] = 0;
    //                 continue;
    //             }
    //             if (x + k < M.size() && M[x + k][y] == 1)
    //             {
    //                 st.push({x + k, y});
    //                 M[x + k][y] = 0;
    //                 M[y][x + k] = 0;
    //                 continue;
    //             }
    //             if (y - k >= 0 && M[x][y - k] == 1)
    //             {
    //                 st.push({x, y - k});
    //                 M[x][y - k] = 0;
    //                 M[y - k][x] = 0;
    //                 continue;
    //             }
    //             if (y + k < M.size() && M[x][y + k] == 1)
    //             {
    //                 st.push({x, y + k});
    //                 M[x][y + k] = 0;
    //                 M[y + k][x] = 0;
    //                 continue;
    //             }
    //         }

    //         st.pop();
    //     }
    // }

    void bfs(int i, int j, vector<vector<int>> &M)
    {
        queue<pair<int, int>> que;
        que.push({i, j});
        M[i][j] = 0;
        M[j][i] = 0;
        int count = 0;
        while (!que.empty())
        {
            count++;
            int x = que.front().first;
            int y = que.front().second;
            que.pop();
            for (int k = 1; k < M.size(); k++)
            {
                if (x - k >= 0 && M[x - k][y] == 1)
                {
                    que.push({x - k, y});
                    M[x - k][y] = 0;
                    M[y][x - k] = 0;
                }
                if (x + k < M.size() && M[x + k][y] == 1)
                {
                    que.push({x + k, y});
                    M[x + k][y] = 0;
                    M[y][x + k] = 0;
                }
                if (y - k >= 0 && M[x][y - k] == 1)
                {
                    que.push({x, y - k});
                    M[x][y - k] = 0;
                    M[y - k][x] = 0;
                }
                if (y + k < M.size() && M[x][y + k] == 1)
                {
                    que.push({x, y + k});
                    M[x][y + k] = 0;
                    M[y + k][x] = 0;
                }
            }
        }
    }

    /**
     * 查并集
    */
    int count = 0;
    int find(vector<int> &parent, int i)
    {
        return (parent[i] == i) ? i : parent[i] = find(parent, parent[i]);
    }

    void to_union(vector<int> &parent, int i, int j)
    {
        int rooti = find(parent, i);
        int rootj = find(parent, j);
        if (rooti != rootj)
        {
            parent[rooti] = rootj;
            count--;
        }
    }

    int findCircleNum_bjs(vector<vector<int>> &M)
    {
        int n = M.size();
        vector<int> parent;

        for (int i = 0; i < n; i++)
        {

            parent.push_back(i);
            count++;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (M[i][j] == 1)
                {
                    to_union(parent, i, j);
                }
            }
        }

        return count;
    }
};

int main()
{
    vector<vector<int>> M;
    vector<int> m;
    int item;
    while (cin >> item)
    {
        m.push_back(item);
        if (cin.get() == '\n')
        {
            M.push_back(m);
            m.clear();
        }
        if (cin.peek() == '\n')
            M.push_back(m);
    }

    Solution s;
    int res = s.findCircleNum_bjs(M);
    cout << res << endl;
    return 0;
}