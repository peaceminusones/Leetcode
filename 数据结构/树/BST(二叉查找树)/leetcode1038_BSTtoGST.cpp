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
    TreeNode *bstToGst(TreeNode *root)
    {
        if (root == NULL)
            return NULL;

        // 1、遍历右子树
        bstToGst(root->right);

        // 2、访问当前节点，加上前一个节点更新后的值，然后更新最后一次访问的节点值
        root->val += lastval;
        lastval = root->val;

        // 3、遍历左子树
        bstToGst(root->left);

        return root;
    }
};

int main()
{
    Solution *s = new Solution(-1);
    TreeNode *root = s->create();
    s->preorder(root);
    cout << endl;

    TreeNode *res = s->BSTtoGST(root);
    s->preorder(res);

    return 0;
}