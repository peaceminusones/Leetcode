#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // 684的升级版：
    //  先找有没有入度为2的节点 node
    //  然后遍历边的时候先跳过指向 node 的边
    //  最后再遍历指向 node 的边
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges)
    {
        vector<int> nums(edges.size());
        for (int i = 0; i < nums.size(); i++)
            nums[i] = i;
        // 统计入度，并找到入度为2的节点
        vector<int> indegrees(edges.size());
        int end = -1;
        for (auto edge : edges)
        {
            indegrees[edge[1] - 1]++;
            if (indegrees[edge[1] - 1] > 1)
                end = edge[1];
        }

        vector<int> res;
        vector<vector<int>> E;
        for (auto edge : edges)
        {
            if (edge[1] == end) // 先跳过入度为2的节点
            {
                E.push_back(edge);
                continue;
            }

            if (!isconnected(nums, edge[0] - 1, edge[1] - 1)) //两个节点没有连接
                merge(nums, edge[0] - 1, edge[1] - 1);        //合并
            else                                              // 已经连接了，说明有环，存下来
                res = edge;
        }

        for (auto e : E) // 对于入度为2的节点
        {
            if (!isconnected(nums, e[0] - 1, e[1] - 1))
                merge(nums, e[0] - 1, e[1] - 1);
            else
                res = e;
        }

        return res;
    }

    int find(vector<int> &nums, int i)
    {
        return nums[i] == i ? i : find(nums, nums[i]);
    }

    bool isconnected(vector<int> &nums, int a, int b)
    {
        return find(nums, a) == find(nums, b);
    }

    void merge(vector<int> &nums, int a, int b)
    {
        int roota = find(nums, a);
        int rootb = find(nums, b);
        nums[rootb] = roota;
    }
};

int main()
{
    vector<vector<int>> edges;
    vector<int> edge;
    int item;
    while (cin >> item)
    {
        edge.push_back(item);
        if (cin.get() == '\n')
        {
            edges.push_back(edge);
            edge.clear();
        }
        if (cin.peek() == '\n')
        {
            edges.push_back(edge);
        }
    }

    Solution s;
    vector<int> res = s.findRedundantDirectedConnection(edges);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}