#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // 十叉树的dfs
    vector<int> lexicalOrder(int n)
    {
        vector<int> res;
        // 如果n小于9，则分叉个数为n，如果n大于等于9，则分叉个数为9，其他节点在第三层
        int end = min(n, 9);
        for (int i = 1; i <= end; i++)
        {
            dfs(n, i, res);
        }
        return res;
    }

    void dfs(int n, int curRootNum, vector<int> &res)
    {
        if (curRootNum > n)
            return;

        res.push_back(curRootNum);
        // 位运算方法乘10
        int nextBase = (curRootNum << 3) + (curRootNum << 1);
        for (int i = 0; i < 10; i++)
        {
            if (nextBase + i <= n)
            {
                dfs(n, nextBase + i, res);
            }
            else
                break;
        }
    }
};

int main()
{
    int n;
    cin >> n;
    Solution s;
    vector<int> res = s.lexicalOrder(n);
    for (auto r : res)
        cout << r << " ";
    return 0;
}