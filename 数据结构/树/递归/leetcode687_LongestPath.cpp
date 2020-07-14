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
     * 在求树的深度的算法上进行修改
     * 不同的就是需要判断值是否相等才能深度加1
    */
    int longestUnivaluePath(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int res = 0;
        helper(root, res);
        return res;
    }

    int helper(TreeNode *root, int &res)
    {
        if (root == NULL)
            return 0;

        int left = helper(root->left, res);
        int right = helper(root->right, res);

        int leftpath = 0, rightpath = 0;

        if (root->left != NULL && root->left->val == root->val)
            leftpath = left + 1;
        if (root->right != NULL && root->right->val == root->val)
            rightpath = right + 1;
        res = max(res, leftpath + rightpath);

        return max(leftpath, rightpath);
    }
};

int main()
{
    Solution *s = new Solution(0);
    TreeNode *t = s->create();
    s->preorder(t);
    cout << endl;

    int res = s->longestUnivaluePath(t);
    cout << res << endl;
    return 0;
}