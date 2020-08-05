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

    // 中序遍历！！
    int kthSmallest(TreeNode *root, int k)
    {
        if (root == NULL)
            return 0;
        int res;
        int num = 0;
        inorder(root, k, num, res);
        return res;
    }

    void inorder(TreeNode *root, int k, int &num, int &res)
    {
        if (root != NULL)
        {
            inorder(root->left, k, num, res);
            num++;
            if (num == k)
            {
                res = root->val;
                return;
            }
            inorder(root->right, k, num, res);
        }
    }

    // 分治法
    int kthSmallest1(TreeNode *root, int k)
    {
        if (root == NULL)
            return 0;

        int n = nodeCount(root->left);
        if (n + 1 == k)
            return root->val;
        else if (n + 1 < k) // 在右子树
            return kthSmallest1(root->right, k - n - 1);
        else
            return kthSmallest1(root->left, k);
    }

    int nodeCount(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        return 1 + nodeCount(root->left) + nodeCount(root->right);
    }
};

int main()
{
    Solution *s = new Solution(0);
    TreeNode *root = s->create();
    s->preorder(root);
    cout << endl;

    int k;
    cin >> k;

    int res = s->kthSmallest1(root, k);
    cout << res << endl;

    return 0;
}