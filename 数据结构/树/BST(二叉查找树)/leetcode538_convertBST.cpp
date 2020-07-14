#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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

    int lastval = 0;
    TreeNode *convertBST(TreeNode *root)
    {
        if (root == NULL)
            return NULL;

        convertBST(root->right);
        root->val += lastval;
        lastval = root->val;
        convertBST(root->left);

        return root;
    }
};

int main()
{
    Solution *s = new Solution(0);
    TreeNode *root = s->create();
    s->preorder(root);
    cout << endl;

    TreeNode *res = s->convertBST(root);
    s->preorder(res);

    return 0;
}