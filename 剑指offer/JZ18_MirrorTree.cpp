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
    int refval;

public:
    Solution(int r) : refval(r) {}

    TreeNode *creat()
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
            t->left = creat();
            t->right = creat();
            return t;
        }
    }

    void Mirror(TreeNode *pRoot)
    {
        if (pRoot == NULL || (pRoot != NULL && pRoot->left == NULL && pRoot->right == NULL))
            return;

        TreeNode *tmp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = tmp;
        Mirror(pRoot->left);
        Mirror(pRoot->right);
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

    void Mirror1(TreeNode *pRoot)
    {
        queue<TreeNode *> que;
        que.push(pRoot);
        while (!que.empty())
        {
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = que.front();
                que.pop();
                if (node == NULL)
                    continue;

                que.push(node->left);
                que.push(node->right);

                TreeNode *tmp = node->left;
                node->left = node->right;
                node->right = tmp;
            }
        }
    }
};

int main()
{
    Solution *s = new Solution(0);

    TreeNode *root = s->creat();
    s->preorder(root);
    s->Mirror1(root);
    s->preorder(root);
    return 0;
}
