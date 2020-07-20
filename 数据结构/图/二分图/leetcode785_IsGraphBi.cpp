#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    // bfs
    bool isBipartite(vector<vector<int>> &graph)
    {
        queue<int> que;
        vector<int> visited(graph.size());

        for (int i = 0; i < graph.size(); i++) // 遍历每个顶点
        {
            if (visited[i] != 0) // 已经染过色，跳过
                continue;

            que.push(i);
            visited[i] = 1;
            while (!que.empty()) // 遍历节点i的所有邻接节点
            {
                int curnode = que.front();
                que.pop();
                int curcolor = visited[curnode]; // 当前节点的颜色
                int neighborcolor = -curcolor;   //邻居节点的颜色应该相反
                for (int j = 0; j < graph[curnode].size(); j++)
                {
                    int neighbor = graph[curnode][j]; // 取出邻居节点
                    if (visited[neighbor] == 0)       // 如果邻居节点没有访问过
                    {
                        visited[neighbor] = neighborcolor;
                        que.push(neighbor);
                    }
                    else // 如果邻居节点访问过
                    {
                        // 但是颜色和neighborcolor不相同
                        if (visited[neighbor] != neighborcolor)
                            return false;
                    }
                }
            }
        }

        return true;
    }

    // dfs
    bool isBipartite_dfs(vector<vector<int>> &graph)
    {
        vector<int> visited(graph.size());
        for (int i = 0; i < graph.size(); i++)
        {
            if (visited[i] == 0 && !dfs(graph, visited, 1, i))
                return false;
        }
        return true;
    }
    bool dfs(vector<vector<int>> &graph, vector<int> &visited, int color, int curnode)
    {
        if (visited[curnode] != 0)
            return visited[curnode] == color;

        visited[curnode] = color;
        for (auto node : graph[curnode])
        {
            if (!dfs(graph, visited, -color, node))
                return false;
        }
        return true;
    }

    // 并查集
    bool isBipartite_djset(vector<vector<int>> &graph)
    {
        vector<int> nums(graph.size());
        for (int i = 0; i < graph.size(); i++)
            nums[i] = i;

        for (int i = 0; i < graph.size(); i++)
        {
            for (auto node : graph[i])
            {
                if (isConnected(nums, i, node))
                    return false;
                merge(nums, graph[i][0], node);
            }
        }
        return true;
    }

    int find(vector<int> &nums, int i)
    {
        return nums[i] == i ? i : find(nums, nums[i]);
    }

    bool isConnected(vector<int> &nums, int a, int b)
    {
        return find(nums, a) == find(nums, b);
    }

    void merge(vector<int> &nums, int a, int b)
    {
        int roota = find(nums, a);
        int rootb = find(nums, b);
        nums[roota] = rootb;
    }
};

int main()
{
    vector<vector<int>> graphs;
    vector<int> graph;
    int g;
    while (cin >> g)
    {
        graph.push_back(g);
        if (cin.get() == '\n')
        {
            graphs.push_back(graph);
            graph.clear();
        }
        if (cin.peek() == '\n')
        {
            graphs.push_back(graph);
        }
    }

    Solution s;
    bool res = s.isBipartite(graphs);
    cout << res << endl;
    bool res1 = s.isBipartite_dfs(graphs);
    cout << res1 << endl;
    bool res2 = s.isBipartite_djset(graphs);
    cout << res2 << endl;
    return 0;
}