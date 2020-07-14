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
     * 该题的重点是递归的结束条件
     * 【！！！叶子节点是指没有子节点的节点，这句话的意思是{1,0,2,0,0}中1不是叶子节点】
     * 当root为NULL时，返回0
     * 当root的左右孩子都为NULL时，返回1
     * 当root左右孩子有一个为NULL时，返回不空孩子节点的深度
     * 当root左右孩子都不为NULL时，返回左右孩子较小深度的节点值
    */
    int minDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL)
            return 1;

        int left = minDepth(root->left);
        int right = minDepth(root->right);

        // left和right其中一个为0，说明有一个为当前节点有一个孩子为空，那么返回的是有子树的那个深度
        // 因为当前节点并不是根节点，所以还没到终点
        if (left == 0 || right == 0)
            return left + right + 1;

        // 当前节点的左孩子右孩子都存在，所以选择最小值加1即可
        return min(left, right) + 1;
    }
};

int main()
{
    Solution *s = new Solution(0);
    TreeNode *t = s->create();
    s->preorder(t);
    cout << endl;

    int res = s->minDepth(t);
    cout << res << endl;
    return 0;
}