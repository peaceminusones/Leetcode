#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    int refval;

    TreeNode *create()
    {
        int item;
        cin >> item;
        if (item == refval)
            return NULL;
        else
        {
            TreeNode *node = new TreeNode(item);
            node->left = create();
            node->right = create();
            return node;
        }
    }

    int getDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int left = getDepth(root->left); // 从下往上遍历，所以先一路往树的左下遍历
        if (left == -1)                  // -1表示左子树右子树的高度差大于1
            return -1;
        int right = getDepth(root->right);
        if (right == -1) // -1表示左子树右子树的高度差大于1
            return -1;

        if (abs(left - right) > 1) // 左右子树的深度差大于1，则返回-1
            return -1;
        else
            return max(left, right) + 1; // 深度查为1或0，则加1
    }

    bool IsBalanced_Solution(TreeNode *pRoot)
    {
        if (pRoot == NULL)
            return 1;
        int depth = getDepth(pRoot);

        return depth != -1;
    }
};

int main()
{
    Solution s;
    s.refval = 0;
    TreeNode *root = s.create();
    bool res = s.IsBalanced_Solution(root);
    cout << res << endl;

    return 0;
}