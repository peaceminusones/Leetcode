#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    // dfs
    bool possibleBipartition(int N, vector<vector<int>> &dislikes)
    {
        vector<vector<int>> graph(N, vector<int>(N));
        vector<int> visited(N);
        for (auto dislike : dislikes)
        {
            graph[dislike[0] - 1][dislike[1] - 1] = 1;
            graph[dislike[1] - 1][dislike[0] - 1] = 1;
        }

        for (int i = 0; i < N; i++)
        {
            if (visited[i] == 0 && !dfs(graph, visited, 1, i))
                return false;
        }
        return true;
    }

    bool dfs(vector<vector<int>> &graph, vector<int> &visited, int color, int i)
    {
        visited[i] = color;
        for (int j = 0; j < graph.size(); j++)
        {
            if (graph[i][j] == 1)
            {
                if (visited[i] == visited[j])
                    return false;
                if (visited[j] == 0 && !dfs(graph, visited, -color, j))
                    return false;
            }
        }
        return true;
    }

    // bfs
    bool possibleBipartition_bfs(int N, vector<vector<int>> &dislikes)
    {
        vector<vector<int>> graph(N, vector<int>(N));
        for (auto dislike : dislikes) // 构建图关系，1表示两者之间互相不喜欢
        {
            graph[dislike[0] - 1][dislike[1] - 1] = 1;
            graph[dislike[1] - 1][dislike[0] - 1] = 1;
        }

        queue<int> que;
        vector<int> visited(N);
        for (int i = 0; i < N; i++)
        {
            if (visited[i] != 0)
                continue;
            que.push(i);
            visited[i] = 1;
            while (!que.empty())
            {
                int curnode = que.front();
                que.pop();
                int curcolor = visited[curnode];
                for (int j = 0; j < N; j++)
                {
                    if (graph[curnode][j] == 1)
                    {
                        if (visited[j] == curcolor)
                            return false;
                        else if (visited[j] == 0)
                        {
                            visited[j] = -curcolor;
                            que.push(j);
                        }
                    }
                }
            }
        }

        return true;
    }

    // 并查集
    bool possibleBipartition_djset(int N, vector<vector<int>> &dislikes)
    {
        vector<vector<int>> graph(N);
        // 通过讨厌的人，构建邻接表
        for (auto dislike : dislikes)
        {
            int a = dislike[0];
            int b = dislike[1];
            graph[a - 1].push_back(b - 1);
            graph[b - 1].push_back(a - 1);
        }

        vector<int> nums(N);
        for (int i = 0; i < N; i++)
            nums[i] = i;

        for (int i = 0; i < N; i++)
        {
            if (!graph[i].empty())
            {
                for (auto node : graph[i])
                {
                    if (isConnected(nums, i, node))
                        return false;
                    merge(nums, graph[i][0], node); // 讨厌的人连接到一起
                }
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
    int N;
    cin >> N;
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
    bool res = s.possibleBipartition(N, graphs);
    cout << res << endl;
    bool res1 = s.possibleBipartition_bfs(N, graphs);
    cout << res1 << endl;
    bool res2 = s.possibleBipartition_djset(N, graphs);
    cout << res2 << endl;
    return 0;
}