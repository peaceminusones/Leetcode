#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;  // 左节点
    TreeNode *right; // 右节点
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    bool isSymmetrical(TreeNode *pRoot)
    {
        if (pRoot == NULL || (pRoot != NULL && pRoot->left == NULL && pRoot->right == NULL))
            return true;
        return Symmetrical(pRoot->left, pRoot->right);
    }

    bool Symmetrical(TreeNode *left, TreeNode *right)
    {
        if (left == NULL && right == NULL)
            return true;
        if (left == NULL || right == NULL)
            return false;

        return (left->val == right->val) && Symmetrical(left->left, right->right) && Symmetrical(left->right, right->left);
    }
};

int main()
{
    return 0;
}