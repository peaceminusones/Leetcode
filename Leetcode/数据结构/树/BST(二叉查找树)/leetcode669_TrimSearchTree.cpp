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

    // 整个函数的功能就是把范围内的节点留下
    TreeNode *trimBST(TreeNode *root, int L, int R)
    {
        if (root == NULL)
            return NULL;

        if (root->val > R)
            return trimBST(root->left, L, R);
        if (root->val < L)
            return trimBST(root->right, L, R);

        // L <= root->val <= R
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);

        return root;
    }
};

int main()
{
    Solution *s = new Solution(-1);
    TreeNode *root = s->create();
    s->preorder(root);
    cout << endl;

    int l, r;
    cin >> l, r;
    TreeNode *res = s->trimBST(root, l, r);
    cout << res->val << endl;
    s->preorder(res);

    return 0;
}