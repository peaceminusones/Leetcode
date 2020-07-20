#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> indegrees(numCourses);         // 入度表
        vector<vector<int>> adjacency(numCourses); // 邻接表

        for (auto pre : prerequisites)
        {
            indegrees[pre[0]]++;
            adjacency[pre[1]].push_back(pre[0]);
        }

        // 入度为0的进入队列和最终结果
        queue<int> que;
        for (int i = 0; i < indegrees.size(); i++)
        {
            if (indegrees[i] == 0)
                que.push(i);
        }

        vector<int> res;
        while (!que.empty())
        {
            int curcourse = que.front();
            que.pop();
            res.push_back(curcourse);
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

        if (numCourses != 0)
            res.clear();

        return res;
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
    vector<int> res = s.findOrder(numCourses, prerequisites);
    for (auto r : res)
        cout << r << " ";

    return 0;
}