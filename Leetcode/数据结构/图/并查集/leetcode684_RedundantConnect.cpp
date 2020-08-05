#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        vector<int> nums(edges.size());
        for (int i = 0; i < nums.size(); i++)
            nums[i] = i;
        vector<int> res;
        for (auto edge : edges)
        {
            if (isconnected(nums, edge[0] - 1, edge[1] - 1))
            {
                res = edge;
                break;
            }
            merge(nums, edge[0] - 1, edge[1] - 1);
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
    vector<int> res = s.findRedundantConnection(edges);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}