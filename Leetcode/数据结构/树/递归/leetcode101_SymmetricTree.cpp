#include <iostream>
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

    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return true;
        return dfs(root->left, root->right);
    }

    bool dfs(TreeNode *s, TreeNode *t)
    {
        if (s == NULL && t == NULL)
            return true;
        if (s == NULL || t == NULL)
            return false;

        return s->val == t->val && dfs(s->left, t->right) && dfs(s->right, t->left);
    }

    bool isSymmetric_iter(TreeNode *root)
    {
        if (root == NULL || (root->left == NULL && root->right == NULL))
            return true;
        queue<TreeNode *> que;
        // 根节点不管，把根节点的左孩子，右孩子分别放入队列中
        que.push(root->left);
        que.push(root->right);
        while (!que.empty())
        {
            // 每次取出两个节点
            TreeNode *s = que.front();
            que.pop();
            TreeNode *t = que.front();
            que.pop();

            if (s == NULL && t == NULL)
                continue;
            if (s == NULL || t == NULL)
                return false;
            if (s->val != t->val)
                return false;

            // 左节点的左孩子，右节点的右孩子
            que.push(s->left);
            que.push(t->right);
            // 左节点的右孩子，右节点的左孩子
            que.push(s->right);
            que.push(t->left);
        }

        return true;
    }
};

int main()
{
    Solution *s = new Solution(0);
    TreeNode *t = s->create();
    s->preorder(t);
    cout << endl;

    bool res = s->isSymmetric_iter(t);
    cout << res << endl;
    return 0;
}