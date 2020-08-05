#include <iostream>
#include <vector>
#include <stack>
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

    bool hasPathSum(TreeNode *root, int sum)
    {
        if (root == NULL)
            return false;

        if (root->left == NULL && root->right == NULL)
            return sum - root->val == 0;

        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }

    bool hasPathSum1(TreeNode *root, int sum)
    {
        if (root == NULL)
            return false;

        int res = 0;
        return helper(root, res, sum);
    }

    bool helper(TreeNode *t, int res, int sum)
    {
        if (t == NULL)
            return false;

        if (t->left == NULL && t->right == NULL)
        {
            if ((res + t->val) == sum)
                return true;
            return false;
        }

        if (helper(t->left, res + t->val, sum))
            return true;
        if (helper(t->right, res + t->val, sum))
            return true;

        return false;
    }
};

int main()
{
    Solution *s = new Solution(0);
    TreeNode *root = s->create();
    s->preorder(root);
    cout << endl;

    int sum;
    cin >> sum;
    bool res = s->hasPathSum(root, sum);
    cout << res << endl;

    return 0;
}