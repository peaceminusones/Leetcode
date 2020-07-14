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
    Solution(int f) : refval(f) {}

    TreeNode *create()
    {
        int item;
        cin >> item;
        if (item == refval)
            return NULL;
        else
        {
            TreeNode *t = new TreeNode(item);
            t->left = create();
            t->right = create();
            return t;
        }
    }

    void preorder(TreeNode *root)
    {
        if (root != NULL)
        {
            cout << root->val << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
            return NULL;
        if (root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        if (root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);

        return root;
    }
};

int main()
{
    Solution *s = new Solution(0);
    TreeNode *root = s->create();
    s->preorder(root);
    cout << endl;

    int a, b;
    cin >> a >> b;
    TreeNode *p = new TreeNode(a);
    TreeNode *q = new TreeNode(b);

    TreeNode *res = s->lowestCommonAncestor(root, p, q);
    cout << res->val << endl;

    return 0;
}