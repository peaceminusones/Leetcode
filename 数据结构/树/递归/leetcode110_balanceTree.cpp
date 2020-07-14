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
    int refval;

public:
    Solution(int r) : refval(r) {}

    TreeNode *creat()
    {
        int item;
        cin >> item;
        if (item == refval)
            return NULL;
        else
        {
            TreeNode *t = new TreeNode(item);
            t->left = creat();
            t->right = creat();
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
     * 自顶向下（有很多冗余）
    */
    bool isBalanced(TreeNode *root)
    {
        if (root == NULL)
            return true;

        return abs(depth(root->left) - depth(root->right)) < 2 && isBalanced(root->left) && isBalanced(root->right);
    }

    int depth(TreeNode *t)
    {
        if (t == NULL)
            return 0;
        return max(depth(t->left), depth(t->right)) + 1;
    }

    /**
     * 自底向上
    */
    bool isBalanced_up(TreeNode *root)
    {
        return helper(root) >= 0;
    }

    int helper(TreeNode *t)
    {
        if (t == NULL)
            return 0;
        int left = helper(t->left) + 1;
        int right = helper(t->right) + 1;
        if (abs(left - right) > 1)
            return -1;
        return max(left, right);
    }
};

int main()
{
    Solution *s = new Solution(0);
    TreeNode *root = s->creat();
    s->preorder(root);
    cout << endl;

    bool res = s->isBalanced_up(root);
    cout << res << endl;
    return 0;
}