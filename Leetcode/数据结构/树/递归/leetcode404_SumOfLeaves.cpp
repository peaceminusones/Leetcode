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
     * 方法一：前序遍历，且用一个标志位来表示是否是左节点 ==================================================================
    */
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (root == NULL || (root->left == NULL && root->right == NULL))
            return 0;

        int res = 0;
        helper(root, res, 0);
        return res;
    }

    // tips:用一个标志位来判断是否是左节点！！！！！
    void helper(TreeNode *t, int &res, int mark)
    {
        if (t == NULL)
            return;
        if (t->left == NULL && t->right == NULL && mark == 1)
        {
            res += t->val;
            return;
        }

        helper(t->left, res, 1);
        helper(t->right, res, 0);
    }

    /**
     * 方法二：分治法递归 =========================================================================================
     * 【以A为根的树的左叶子之和 = A的左子树的左叶子之和 + A的右子树的左叶子之和】
     * 终止条件有三个
     * 1.当前节点为空节点：返回0
     * 2.当前节点的左节点为空：返回右子树的递归解
     * 3.当前节点的左节点为叶子节点：返回左节点的值 + 右子树的递归解
     * 
     * 4.其他情况都返回：左子树的递归解 + 右子树的递归解
    */
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        if (root->left == NULL)
            return sumOfLeftLeaves(root->right);
        if (root->left->left == NULL && root->left->right == NULL)
            return root->left->val + sumOfLeftLeaves(root->right);

        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};

int main()
{
    Solution *s = new Solution(0);
    TreeNode *t = s->create();
    s->preorder(t);
    cout << endl;

    int res = s->sumOfLeftLeaves(t);
    cout << res << endl;
    return 0;
}