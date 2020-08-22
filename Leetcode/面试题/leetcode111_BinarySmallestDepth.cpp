#include <iostream>
#include <vector>
#include <queue>
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
public:
    TreeNode *create()
    {
        int item;
        cin >> item;
        if (item == 0)
        {
            return NULL;
        }
        else
        {
            TreeNode *root = new TreeNode(item);
            root->left = create();
            root->right = create();
            return root;
        }
    }

    void preorder(TreeNode *root)
    {
        if (root)
        {
            cout << root->val << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    // 递归方法
    int minDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL)
            return 1;

        int depthleft = minDepth(root->left);
        int depthright = minDepth(root->right);

        if (depthleft == 0 || depthright == 0)
            return depthleft + depthright + 1;

        return min(depthleft, depthright) + 1;
    }

    // 非递归方法
    int minDepth_que(TreeNode *root)
    {
        queue<TreeNode *> que;
        que.push(root);
        int level = 0;
        while (!que.empty())
        {
            level++;
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = que.front();
                que.pop();
                if (node == NULL)
                    continue;
                if (node->left == NULL && node->right == NULL)
                    return level;

                que.push(node->left);
                que.push(node->right);
            }
        }
        return level;
    }
};

int main()
{
    Solution s;
    TreeNode *root = s.create();
    s.preorder(root);
    cout << endl;

    cout << s.minDepth_que(root) << endl;

    return 0;
}