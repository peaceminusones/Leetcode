#include <iostream>
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
    int refval;

public:
    Solution(int r) : refval(r) {}

    TreeNode *create()
    {
        int item;
        cin >> item;
        if (item == refval)
        {
            return NULL;
        }
        else
        {
            TreeNode *t = new TreeNode(item);
            t->left = create();
            t->right = create();
            return t;
        }
    }

    void preorder(TreeNode *t)
    {
        if (t != NULL)
        {
            cout << t->val << " ";
            preorder(t->left);
            preorder(t->right);
        }
    }

    /**
     * 找二叉树中（第二小！！）的节点
    */
    int findSecondMinimumValue(TreeNode *root)
    {
        if (root == NULL)
            return -1;
        if (root->left == NULL && root->right == NULL)
            return -1;

        int res = -1;        // 默认第二小节点目前为-1
        int min = root->val; // 最小节点一定为为root的值
        // 分别查看左右子树是否存在（大于min的第二小值）
        helper(root->left, res, min);
        helper(root->right, res, min);
        return res;
    }

    void helper(TreeNode *t, int &res, int &min)
    {
        if (t == NULL)
            return;

        if (t->val > min)
        {
            // 1、res = -1，说明之前还没有发现比根节点大的值
            // 2、如果res != -1，且t->val < res（res为当前第二小值）
            // 即min < t->val < res，需要更新当前第二小值res
            if (res == -1 || t->val < res)
            {
                res = t->val;
            }
        }

        helper(t->left, res, min);
        helper(t->right, res, min);
    }
};

int main()
{
    Solution *s = new Solution(0);
    TreeNode *t = s->create();
    s->preorder(t);
    cout << endl;

    int res = s->findSecondMinimumValue(t);
    cout << res << endl;
    return 0;
}