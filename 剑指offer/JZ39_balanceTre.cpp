#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    // 求树的高度
    // int depthTree(TreeNode *pRoot)
    // {
    //     if (pRoot == NULL)
    //         return 0;

    //     int left = depthTree(pRoot->left);
    //     int right = depthTree(pRoot->right);
    //     return max(left, right) + 1;
    // }

    // 对求树的高度进行修改
    bool IsBalanced_Solution(TreeNode *pRoot)
    {
        if (pRoot == NULL)
            return 0;
        return depthTree(pRoot) != -1;
    }

    int depthTree(TreeNode *pRoot)
    {
        if (pRoot == NULL)
            return 0;

        int left = depthTree(pRoot->left);
        if (left == -1)
            return -1;
        int right = depthTree(pRoot->right);
        if (right == -1)
            return -1;

        if (abs(left - right) > 1)
            return -1;

        return max(left, right) + 1;
    }

    bool IsBalanced_Solution(TreeNode *pRoot)
    {
        int minh = INT_MAX;
        int maxh = 0;
        queue<TreeNode *> que;
        que.push(pRoot);
        int level = 0;
        while (!que.empty())
        {
            level++;
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = que.front();
                que.pop();
                if (node == NULL)
                {
                    minh = min(minh, level);
                    maxh = max(maxh, level);
                    if (maxh - minh > 1)
                        return false;
                    continue;
                }

                que.push(node->left);
                que.push(node->right);
            }
        }
        return true;
    }
};

int main()
{
    return 0;
}