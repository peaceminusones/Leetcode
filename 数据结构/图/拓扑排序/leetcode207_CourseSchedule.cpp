#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        //创建图：{0:[1,2,3]}表示要学习课程0，需要先完成课程1,2,3
        for (auto pre : prerequisites)
        {
            graph[pre[0]].push_back(pre[1]);
        }
        // 0:未被访问;-1:被其他节点启动dfs访问;1:当前节点启动dfs访问
        vector<int> visited(numCourses);
        for (int i = 0; i < numCourses; i++)
        {
            if (!dfs(graph, visited, i))
                return false;
        }
        return true;
    }

    bool dfs(vector<vector<int>> &graph, vector<int> &visited, int i)
    {
        if (visited[i] == -1)
            return true;
        if (visited[i] == 1)
            return false;

        visited[i] = 1;
        for (auto g : graph[i])
        {
            if (!dfs(graph, visited, g))
                return false;
        }
        visited[i] = -1;
        return true;
    }

    // bfs(入度表)
    bool canFinish_bfs(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> indegrees(numCourses);         // 入度表
        vector<vector<int>> adjacency(numCourses); // 邻接表
        for (auto pre : prerequisites)
        {
            indegrees[pre[0]]++;
            adjacency[pre[1]].push_back(pre[0]); // 表示在完成课程pre[0]之前需要完成pre[1]，即pre[1]-->pre[0]
        }

        // 取出入度为0的节点
        queue<int> que;
        for (int i = 0; i < numCourses; i++)
        {
            if (indegrees[i] == 0)
                que.push(i);
        }

        while (!que.empty())
        {
            int curcourse = que.front();
            que.pop();
            numCourses--;
            if (adjacency[curcourse].empty())
                continue;
            for (auto nextcourse : adjacency[curcourse])
            {
                indegrees[nextcourse]--;
                if (indegrees[nextcourse] == 0)
                    que.push(nextcourse);
            }
        }
        return numCourses == 0;
    }
};

int main()
{
    int numCourses;
    cin >> numCourses;

    vector<vector<int>> prerequisites;
    vector<int> pre;
    int item;
    while (cin >> item)
    {
        pre.push_back(item);
        if (cin.get() == '\n')
        {
            prerequisites.push_back(pre);
            pre.clear();
        }
        if (cin.peek() == '\n')
        {
            prerequisites.push_back(pre);
        }
    }

    Solution s;
    bool res = s.canFinish_bfs(numCourses, prerequisites);
    cout << res << endl;

    return 0;
}