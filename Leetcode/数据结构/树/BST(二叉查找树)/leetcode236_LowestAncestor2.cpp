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

    // 重点是理解后序遍历！！！
    // 递归！：因为是递归，使用函数后可认为左右子树已经算出结果
    // 定义子问题：左右子树分别包括p、q
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL || root->val == p->val || root->val == q->val)
            return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        // left和right同时为空，说明左右子树都不含p，q
        if (left == NULL && right == NULL)
            return NULL;
        // left==NULL，说明p，q都不在左子树中
        if (left == NULL)
            return right;
        // right==NULL，说明p，q都不在右子树中
        if (right == NULL)
            return left;
        // left和right同时不为NULL，说明p，q分布在root的两侧，因此root为最近的公共祖先，返回root
        return root;

        /*
        上面的写法可以合并为：
        if (left == NULL)
            return right;
        if (right == NULL)
            return left;
        return root;
        */
    }
};

int main()
{
    Solution *s = new Solution(-1);
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