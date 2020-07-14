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

    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int res = 0;
        depth(root, res);
        return res;
    }

    int depth(TreeNode *t, int &res)
    {
        if (t == NULL)
            return 0;
        int left = depth(t->left, res);
        int right = depth(t->right, res);
        res = max(res, left + right);

        return max(left, right) + 1;
    }
};

int main()
{
    Solution *s = new Solution(0);
    TreeNode *root = s->create();
    s->preorder(root);
    cout << endl;
    int res = s->diameterOfBinaryTree(root);
    cout << res << endl;
    return 0;
}