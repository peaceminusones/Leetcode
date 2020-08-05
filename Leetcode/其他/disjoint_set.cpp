#include <iostream>
#include <vector>
using namespace std;

/*
* 并查集简洁写法 ======================================================================
*/
class DisjSet
{
    vector<int> parent;

public:
    DisjSet(int maxsize) : parent(vector<int>(maxsize))
    {
        // 初始化每个元素的父节点都是自己
        for (int i = 0; i < maxsize; i++)
            parent[i] = i;
    }

    // 如果当前元素的父节点就是自己，说明找到了根节点返回
    // 否则继续找父节点的父节点
    int find(int x)
    {
        return parent[x] == x ? x : find(parent[x]);
    }

    // 合并两个集合，即合并两个根节点
    void to_union(int x, int y)
    {
        int p1 = parent[x];
        int p2 = parent[y];
        parent[p1] = p2;
    }

    // 判断两个元素是否属于同一个集合
    bool is_same(int x, int y)
    {
        return find(x) == find(y);
    }
};

/*
 * 并查集优化1 ======================================================================
 * "按秩合并"。实际上就是在合并两棵树时，将高度较小的树合并到高度较大的树上
*/
class DisjSet1
{
    vector<int> parent;
    vector<int> rank; // 秩 (树的高度)
public:
    DisjSet1(int maxsize) : parent(vector<int>(maxsize)), rank(vector<int>(maxsize, 0))
    {
        // 初始化每个元素的的父节点都是自己，高度为0，即秩为0
        for (int i = 0; i < maxsize; i++)
            parent[i] = i;
    }

    // 路径压缩
    // 在执行find的过程中，将路径上所有的节点都直接连接到根节点上
    int find(int x)
    {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    // 按秩合并
    void to_union(int x, int y)
    {
        int p1 = find(x);
        int p2 = find(y);
        if (rank[p1] > rank[p2])
            parent[p2] = p1; // 高度较小的树p2合并到高度较大的树p1上
        else
        {
            parent[p1] = p2; // 高度较小的树p1合并到高度较大的树p2上
            if (parent[p1] == parent[p2])
                rank[p2]++;
        }
    }

    bool is_same(int x, int y)
    {
        return find(x) == find(y);
    }
};

int main()
{
    return 0;
}