#include <iostream>
#include <vector>
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
    TreeNode *create()
    {
        char item;
        cin >> item;
        if (item == '#')
            return NULL;
        else
        {
            TreeNode *t = new TreeNode(item);
            t->left = create();
            t->right = create();
            return t;
        }
    }

    // 超时了！！！！！！！！！！！！！！！！！
    // int res = 0;
    // int longestZigZag(TreeNode *root)
    // {
    //     if (root == NULL)
    //         return 0;
    //     else
    //     {
    //         longestZigZag(root->left);
    //         longestZigZag(root->right);
    //         res = max(res, max(helper(root, 0), helper(root, 1)) - 1);
    //     }
    //     return res;
    // }

    // // 0：表示上个是左子树
    // // 1：表示上个是右子树
    // int helper(TreeNode *root, bool flag)
    // {
    //     if (root == NULL)
    //         return 0;

    //     if (flag)
    //         return 1 + helper(root->right, 0);

    //     return 1 + helper(root->left, 1);
    // }

    int longestZigZag(TreeNode *root)
    {
        int res = 0;
        dfs(root->left, 0, 0, res);
        dfs(root->right, 1, 0, res);
        return res;
    }

    // 0：左孩子，1：右孩子
    void dfs(TreeNode *root, int dir, int len, int &res)
    {
        if (root == NULL)
        {
            return;
        }

        res = max(res, len);
        if (dir) // 当前节点是其父节点的右孩子
        {
            dfs(root->right, 1, 1, res);      // 仍然搜索右孩子，长度重新从1开始
            dfs(root->left, 0, len + 1, res); // 搜索左孩子，交错长度加1
        }
        else // 当前节点是其父节点的左孩子
        {
            dfs(root->right, 1, len + 1, res); // 搜索右孩子，交错长度加1
            dfs(root->left, 0, 1, res);        // 仍然搜索左孩子，长度重新从1开始
        }
    }
};

int main()
{
    Solution s;
    TreeNode *root = s.create();
    cout << s.longestZigZag(root) << endl;

    return 0;
}